/**
 * @file
 * Account object used by POP and IMAP
 *
 * @authors
 * Copyright (C) 2000-2007,2012 Brendan Cully <brendan@kublai.com>
 *
 * @copyright
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 2 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* remote host account manipulation (POP/IMAP) */

#ifndef _MUTT_ACCOUNT_H
#define _MUTT_ACCOUNT_H

struct Url;

/**
 * enum AccountType - account types
 */
enum AccountType
{
  MUTT_ACCT_TYPE_NONE = 0,
  MUTT_ACCT_TYPE_IMAP,
  MUTT_ACCT_TYPE_POP,
  MUTT_ACCT_TYPE_SMTP,
  MUTT_ACCT_TYPE_NNTP
};

/* account flags */
#define MUTT_ACCT_PORT (1 << 0)
#define MUTT_ACCT_USER (1 << 1)
#define MUTT_ACCT_LOGIN (1 << 2)
#define MUTT_ACCT_PASS (1 << 3)
#define MUTT_ACCT_SSL (1 << 4)

#endif /* _MUTT_ACCOUNT_H */
