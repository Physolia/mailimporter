/***************************************************************************
            filter_thunderbird.h  -  Thunderbird mail import
                             -------------------
    begin                : Januar 26 2005
    copyright            : (C) 2005 by Danny Kukawka
    email                : danny.kukawka@web.de
 ***************************************************************************/
/* Copyright (c) 2012-2020 Laurent Montel <montel@kde.org>                      */

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef MAILIMPORTER_FILTER_THUNDERBIRD_H
#define MAILIMPORTER_FILTER_THUNDERBIRD_H

#include "filters.h"

namespace MailImporter {
/**
 * Imports Thunderbird mail folder recursively, keeping the folder structure.
 * @author Danny Kukawka
 */
class MAILIMPORTER_EXPORT FilterThunderbird : public Filter
{
public:
    FilterThunderbird();
    ~FilterThunderbird() override;

    void import() override;
    void importMails(const QString &maildir);

    Q_REQUIRED_RESULT static QString defaultSettingsPath();
    Q_REQUIRED_RESULT static QString defaultProfile(const QString &defaultSettingPath, QWidget *parent = nullptr);
    Q_REQUIRED_RESULT static QMap<QString, QString> listProfile(QString &currentProfile, const QString &defaultSettingPath);

    Q_REQUIRED_RESULT static QString isMailerFound();

protected:
    Q_REQUIRED_RESULT virtual QString defaultInstallFolder() const;
    Q_REQUIRED_RESULT virtual QString settingsPath();
private:
    void importDirContents(const QString &, const QString &, const QString &);
    void importMBox(const QString &, const QString &, const QString &);
    Q_REQUIRED_RESULT bool excludeFiles(const QString &file);
};
}

#endif
