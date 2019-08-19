/*
  Copyright (c) 2012-2019 Montel Laurent <montel@kde.org>

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

#ifndef MAILIMPORTER_FILTER_CLAWSMAILS_H
#define MAILIMPORTER_FILTER_CLAWSMAILS_H

#include <QHash>

#include "filtersylpheed.h"
namespace MailImporter {
/**
 * Imports Sylpheed mail folder with maildir format recursively, recreating the folder structure.
 * @author Danny Kukawka
 */
class MAILIMPORTER_EXPORT FilterClawsMail : public FilterSylpheed
{
public:
    FilterClawsMail();
    ~FilterClawsMail() override;

    Q_REQUIRED_RESULT static QString defaultSettingsPath();
    Q_REQUIRED_RESULT static QString isMailerFound();

    /* return local mail dir from folderlist.xml*/
    Q_REQUIRED_RESULT QString localMailDirPath() override;
    Q_REQUIRED_RESULT bool excludeFile(const QString &file) override;
    Q_REQUIRED_RESULT QString defaultInstallFolder() const override;
    Q_REQUIRED_RESULT QString markFile() const override;
};
}

#endif
