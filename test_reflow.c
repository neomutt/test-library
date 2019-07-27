#include "config.h"
#include <string.h>
#include <unistd.h>
#include "mutt/mutt.h"
#include "mutt_window.h"
#include "reflow.h"

struct MuttWindow *RootWindow = NULL;

struct MuttWindow *MuttHelpWindow = NULL;
struct MuttWindow *MuttIndexWindow = NULL;
struct MuttWindow *MuttMessageWindow = NULL;
struct MuttWindow *MuttPagerBarWindow = NULL;
struct MuttWindow *MuttPagerWindow = NULL;
struct MuttWindow *MuttSidebarWindow = NULL;
struct MuttWindow *MuttStatusWindow = NULL;

void mutt_winlist_free(struct MuttWindowList *head)
{
  if (!head)
    return;

  struct MuttWindow *np = NULL;
  struct MuttWindow *tmp = NULL;
  TAILQ_FOREACH_SAFE(np, head, entries, tmp)
  {
    TAILQ_REMOVE(head, np, entries);
    mutt_winlist_free(&np->children);
    FREE(&np);
  }
}

void mutt_window_free(struct MuttWindow **ptr)
{
  if (!ptr || !*ptr)
    return;

  struct MuttWindow *win = *ptr;

  mutt_winlist_free(&win->children);

  FREE(ptr);
}

struct MuttWindow *mutt_window_new(enum MuttWindowOrientation orient,
                                   enum MuttWindowSize size, int rows, int cols)
{
  static int colour = 0;

  struct MuttWindow *win = mutt_mem_calloc(1, sizeof(struct MuttWindow));

  win->orient = orient;
  win->size = size;
  win->req_rows = rows;
  win->req_cols = cols;
  TAILQ_INIT(&win->children);
  win->colour = colour + 1;
  colour = (colour + 1) % 7;
  return win;
}

void win_dump2(struct MuttWindow *win, int indent)
{
  if ((win->name[2] != '\0') || win->state.hidden)
  {
    int colour = win->state.hidden ? 31 : 33;
    printf("%*s\033[1;%dm[%d,%d] %s (%d,%d)\033[0m\n", indent, "", colour, win->state.col_offset,
           win->state.row_offset, win->name, win->state.cols, win->state.rows);
  }
  else
  {
    printf("%*s[%d,%d] %s (%d,%d)\n", indent, "", win->state.col_offset,
           win->state.row_offset, win->name, win->state.cols, win->state.rows);
  }

  struct MuttWindow *np = NULL;
  TAILQ_FOREACH(np, &win->children, entries)
  {
    win_dump2(np, indent + 4);
  }
}

void goto_pos(int row, int col)
{
  printf("\033[%d;%dH", row, col);
}

void side(int colour, int row, int col, int height)
{
  height--;
  for (int i = 1; i < height; i++)
  {
    goto_pos(row + i, col);
    printf("\033[1;%dm|\033[0m", colour + 30);
  }
}

void box(const char *name, int colour, int row, int col, int height, int width)
{
  char line[256];
  row++;
  col++;

  memset(line, '-', sizeof(line));
  int len = strlen(name);
  line[0] = '+';
  line[width - 1] = '+';
  line[width] = '\0';

  goto_pos(row + height - 1, col);
  printf("\033[1;%dm%s\033[0m", colour + 30, line);
  goto_pos(row, col);
  memcpy(line + 2, name, len);
  printf("\033[1;%dm%s\033[0m", colour + 30, line);
  side(colour, row, col, height);
  side(colour, row, col + width - 1, height);
}

void cls(void)
{
  printf("\033[2J");
}

void gfx_dump(struct MuttWindow *win)
{
  if (win->state.hidden)
    return;

  if (win->name[2] != '\0')
  {
    box(win->name, win->colour, win->state.row_offset, win->state.col_offset,
        win->state.rows, win->state.cols);
  }

  struct MuttWindow *np = NULL;
  TAILQ_FOREACH(np, &win->children, entries)
  {
    gfx_dump(np);
  }
}

void mutt_window_add_child(struct MuttWindow *parent, struct MuttWindow *child)
{
  if (!parent || !child)
    return;

  TAILQ_INSERT_TAIL(&parent->children, child, entries);
  child->parent = parent;
}

void mutt_window_init(void)
{
  if (RootWindow)
    return;

  struct MuttWindow *w1 =
      mutt_window_new(MUTT_WIN_ORIENT_VERTICAL, MUTT_WIN_SIZE_MAXIMISE,
                      MUTT_WIN_SIZE_UNLIMITED, MUTT_WIN_SIZE_UNLIMITED);
  struct MuttWindow *w2 =
      mutt_window_new(MUTT_WIN_ORIENT_VERTICAL, MUTT_WIN_SIZE_MAXIMISE,
                      MUTT_WIN_SIZE_UNLIMITED, MUTT_WIN_SIZE_UNLIMITED);
  struct MuttWindow *w3 =
      mutt_window_new(MUTT_WIN_ORIENT_HORIZONTAL, MUTT_WIN_SIZE_MAXIMISE,
                      MUTT_WIN_SIZE_UNLIMITED, MUTT_WIN_SIZE_UNLIMITED);
  struct MuttWindow *w4 =
      mutt_window_new(MUTT_WIN_ORIENT_VERTICAL, MUTT_WIN_SIZE_MAXIMISE,
                      MUTT_WIN_SIZE_UNLIMITED, MUTT_WIN_SIZE_UNLIMITED);
  struct MuttWindow *w5 =
      mutt_window_new(MUTT_WIN_ORIENT_VERTICAL, MUTT_WIN_SIZE_MINIMISE,
                      MUTT_WIN_SIZE_UNLIMITED, MUTT_WIN_SIZE_UNLIMITED);
  struct MuttWindow *w6 =
      mutt_window_new(MUTT_WIN_ORIENT_VERTICAL, MUTT_WIN_SIZE_MAXIMISE,
                      MUTT_WIN_SIZE_UNLIMITED, MUTT_WIN_SIZE_UNLIMITED);

  MuttHelpWindow = mutt_window_new(MUTT_WIN_ORIENT_VERTICAL, MUTT_WIN_SIZE_FIXED,
                                   1, MUTT_WIN_SIZE_UNLIMITED);
  MuttIndexWindow = mutt_window_new(MUTT_WIN_ORIENT_VERTICAL, MUTT_WIN_SIZE_FIXED,
                                    5, MUTT_WIN_SIZE_UNLIMITED);
  MuttMessageWindow = mutt_window_new(MUTT_WIN_ORIENT_VERTICAL, MUTT_WIN_SIZE_FIXED,
                                      1, MUTT_WIN_SIZE_UNLIMITED);
  MuttPagerBarWindow = mutt_window_new(MUTT_WIN_ORIENT_VERTICAL, MUTT_WIN_SIZE_FIXED,
                                       1, MUTT_WIN_SIZE_UNLIMITED);
  MuttPagerWindow = mutt_window_new(MUTT_WIN_ORIENT_VERTICAL, MUTT_WIN_SIZE_MAXIMISE,
                                    MUTT_WIN_SIZE_UNLIMITED, MUTT_WIN_SIZE_UNLIMITED);
  MuttSidebarWindow = mutt_window_new(MUTT_WIN_ORIENT_HORIZONTAL, MUTT_WIN_SIZE_FIXED,
                                      MUTT_WIN_SIZE_UNLIMITED, 20);
  MuttStatusWindow = mutt_window_new(MUTT_WIN_ORIENT_VERTICAL, MUTT_WIN_SIZE_FIXED,
                                     1, MUTT_WIN_SIZE_UNLIMITED);

  RootWindow = w1;
  RootWindow->name = "r1";

  w2->name = "w2";
  w3->name = "w3";
  w4->name = "w4";
  w5->name = "w5";
  w6->name = "w6";
  MuttHelpWindow->name = "Help";
  MuttIndexWindow->name = "Index";
  MuttMessageWindow->name = "Message";
  MuttPagerBarWindow->name = "PagerBar";
  MuttPagerWindow->name = "Pager";
  MuttSidebarWindow->name = "Sidebar";
  MuttStatusWindow->name = "Status";

  mutt_window_add_child(w1, w2);
  mutt_window_add_child(w1, MuttMessageWindow);

  mutt_window_add_child(w2, MuttHelpWindow);
  mutt_window_add_child(w2, w3);

  mutt_window_add_child(w3, MuttSidebarWindow);
  mutt_window_add_child(w3, w4);

  mutt_window_add_child(w4, w5);
  mutt_window_add_child(w5, MuttIndexWindow);
  mutt_window_add_child(w5, MuttStatusWindow);

  mutt_window_add_child(w4, w6);
  mutt_window_add_child(w6, MuttPagerWindow);
  mutt_window_add_child(w6, MuttPagerBarWindow);
}

int main(int argc, char *argv[])
{
#if 1
  struct MuttWindow *parent = NULL;
  struct MuttWindow *first = NULL;
#endif

  mutt_window_init();
  RootWindow->state.cols = 80;
  RootWindow->state.rows = 24;

#if 1
  cls();
  window_reflow(RootWindow);
  gfx_dump(RootWindow);
  printf("\n");
  win_dump2(RootWindow, 0);

  sleep(2);
#endif

#if 1
  MuttIndexWindow->req_rows = MUTT_WIN_SIZE_UNLIMITED;
  MuttIndexWindow->size = MUTT_WIN_SIZE_MAXIMISE;
  MuttIndexWindow->parent->size = MUTT_WIN_SIZE_MAXIMISE;
  MuttPagerWindow->parent->state.hidden = true;

  cls();
  window_reflow(RootWindow);
  gfx_dump(RootWindow);
  printf("\n");
  win_dump2(RootWindow, 0);

  sleep(2);

  MuttIndexWindow->req_rows = 5;
  MuttIndexWindow->size = MUTT_WIN_SIZE_FIXED;
  MuttIndexWindow->parent->size = MUTT_WIN_SIZE_MINIMISE;
  MuttPagerWindow->parent->state.hidden = false;

  cls();
  window_reflow(RootWindow);
  gfx_dump(RootWindow);
  printf("\n");
  win_dump2(RootWindow, 0);

  sleep(2);
#endif

#if 1
  MuttSidebarWindow->state.hidden = true;

  cls();
  window_reflow(RootWindow);
  gfx_dump(RootWindow);
  printf("\n");
  win_dump2(RootWindow, 0);

  sleep(2);

  MuttSidebarWindow->state.hidden = false;

  cls();
  window_reflow(RootWindow);
  gfx_dump(RootWindow);
  printf("\n");
  win_dump2(RootWindow, 0);

  sleep(2);
#endif

#if 1
  MuttIndexWindow->req_rows = MUTT_WIN_SIZE_UNLIMITED;
  MuttIndexWindow->size = MUTT_WIN_SIZE_MAXIMISE;
  MuttIndexWindow->parent->size = MUTT_WIN_SIZE_MAXIMISE;
  MuttIndexWindow->parent->parent->orient = MUTT_WIN_ORIENT_HORIZONTAL;
  MuttSidebarWindow->state.hidden = true;

  cls();
  window_reflow(RootWindow);
  gfx_dump(RootWindow);
  printf("\n");
  win_dump2(RootWindow, 0);

  sleep(2);

  MuttIndexWindow->req_rows = 5;
  MuttIndexWindow->size = MUTT_WIN_SIZE_FIXED;
  MuttIndexWindow->parent->size = MUTT_WIN_SIZE_MINIMISE;
  MuttIndexWindow->parent->parent->orient = MUTT_WIN_ORIENT_VERTICAL;
  MuttSidebarWindow->state.hidden = false;

  cls();
  window_reflow(RootWindow);
  gfx_dump(RootWindow);
  printf("\n");
  win_dump2(RootWindow, 0);

  sleep(2);
#endif

#if 1
  parent = MuttSidebarWindow->parent;
  first = TAILQ_FIRST(&parent->children);
  // Swap the Sidebar and the Container of the Index/Pager
  TAILQ_REMOVE(&parent->children, first, entries);
  TAILQ_INSERT_TAIL(&parent->children, first, entries);

  cls();
  window_reflow(RootWindow);
  gfx_dump(RootWindow);
  printf("\n");
  win_dump2(RootWindow, 0);

  sleep(2);

  parent = MuttSidebarWindow->parent;
  first = TAILQ_FIRST(&parent->children);
  // Swap the Sidebar and the Container of the Index/Pager
  TAILQ_REMOVE(&parent->children, first, entries);
  TAILQ_INSERT_TAIL(&parent->children, first, entries);

  cls();
  window_reflow(RootWindow);
  gfx_dump(RootWindow);
  printf("\n");
  win_dump2(RootWindow, 0);

  sleep(2);
#endif

#if 1
  parent = MuttHelpWindow->parent;
  first = TAILQ_FIRST(&parent->children);
  // Swap the HelpLine and the Container of the Sidebar/Index/Pager
  TAILQ_REMOVE(&parent->children, first, entries);
  TAILQ_INSERT_TAIL(&parent->children, first, entries);

  parent = MuttIndexWindow->parent;
  first = TAILQ_FIRST(&parent->children);
  // Swap the Index and the Status Windows
  TAILQ_REMOVE(&parent->children, first, entries);
  TAILQ_INSERT_TAIL(&parent->children, first, entries);

  parent = MuttPagerWindow->parent;
  first = TAILQ_FIRST(&parent->children);
  // Swap the Pager and Pager Bar Windows
  TAILQ_REMOVE(&parent->children, first, entries);
  TAILQ_INSERT_TAIL(&parent->children, first, entries);

  cls();
  window_reflow(RootWindow);
  gfx_dump(RootWindow);
  printf("\n");
  win_dump2(RootWindow, 0);

  sleep(2);

  parent = MuttHelpWindow->parent;
  first = TAILQ_FIRST(&parent->children);
  // Swap the HelpLine and the Container of the Sidebar/Index/Pager
  TAILQ_REMOVE(&parent->children, first, entries);
  TAILQ_INSERT_TAIL(&parent->children, first, entries);

  parent = MuttIndexWindow->parent;
  first = TAILQ_FIRST(&parent->children);
  // Swap the Index and the Status Windows
  TAILQ_REMOVE(&parent->children, first, entries);
  TAILQ_INSERT_TAIL(&parent->children, first, entries);

  parent = MuttPagerWindow->parent;
  first = TAILQ_FIRST(&parent->children);
  // Swap the Pager and Pager Bar Windows
  TAILQ_REMOVE(&parent->children, first, entries);
  TAILQ_INSERT_TAIL(&parent->children, first, entries);

  cls();
  window_reflow(RootWindow);
  gfx_dump(RootWindow);
  printf("\n");
  win_dump2(RootWindow, 0);

  sleep(2);
#endif

  return 0;
}
