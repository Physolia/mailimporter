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

#ifndef SELECTTHUNDERBIRDPROFILEWIDGET_H
#define SELECTTHUNDERBIRDPROFILEWIDGET_H

#include <QDialog>
#include "mailimporter_private_export.h"

#include <QMap>

namespace Ui {
class SelectThunderbirdProfileWidget;
}

namespace MailImporter {
class MAILIMPORTER_TESTS_EXPORT SelectThunderbirdProfileWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SelectThunderbirdProfileWidget(QWidget *parent = nullptr);
    ~SelectThunderbirdProfileWidget();

    void fillProfile(const QMap<QString, QString> &map, const QString &defaultProfile);
    Q_REQUIRED_RESULT QString selectedProfile() const;

private:
    Ui::SelectThunderbirdProfileWidget *ui = nullptr;
};

class MAILIMPORTER_TESTS_EXPORT SelectThunderbirdProfileDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SelectThunderbirdProfileDialog(QWidget *parent = nullptr);
    ~SelectThunderbirdProfileDialog();
    Q_REQUIRED_RESULT QString selectedProfile() const;
    void fillProfile(const QMap<QString, QString> &map, const QString &defaultProfile);

private:
    SelectThunderbirdProfileWidget *mSelectProfile = nullptr;
};
}

#endif // SELECTTHUNDERBIRDPROFILEWIDGET_H
