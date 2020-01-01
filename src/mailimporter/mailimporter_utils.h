/*
  Copyright (c) 2012-2020 Laurent Montel <montel@kde.org>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License along
  with this program; if not, write to the Free Software Foundation, Inc.,
  51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef MAILIMPORTER_UTILS_H
#define MAILIMPORTER_UTILS_H

#include <QString>

namespace MailImporter {
/**
 * Glorified QString[N] for (a) understandability (b) older gcc compatibility.
 */
template<unsigned int size> class FolderStructureBase
{
public:
    typedef QString NString[size];
    /** Constructor. Need a default constructor for QValueList. */
    FolderStructureBase()
    {
    }

    /** Constructor. Turn N QStrings into a folder structure
     *   description.
     */
    FolderStructureBase(const NString &s)
    {
        for (unsigned int i = 0; i < size; i++) {
            d[i] = s[i];
        }
    }

    /** Copy Constructor. */
    FolderStructureBase(const FolderStructureBase &s)
    {
        for (unsigned int i = 0; i < size; i++) {
            d[i] = s[i];
        }
    }

    /** Assignment operator. Does the same thing as
     *   the copy constructor.
     */
    FolderStructureBase &operator =(const FolderStructureBase &s)
    {
        for (unsigned int i = 0; i < size; i++) {
            d[i] = s[i];
        }
        return *this;
    }

    /** Access the different fields. There doesn't seem to
     *   be a real semantics for the fields.
     */
    const QString operator [](unsigned int i) const
    {
        if (i < size) {
            return d[i];
        } else {
            return QString();
        }
    }

    /** Access the different fields, for writing. */
    QString &operator [](unsigned int i)
    {
        Q_ASSERT(i < size);
        if (i < size) {
            return d[i];
        } else {
            return d[0];
        }
    }

private:
    QString d[size];
};
}

#endif /* MAILIMPORTER_UTILS_H */
