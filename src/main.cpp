/*
    SameGame
    Copyright (C) 2011  Jari Karppinen

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <QApplication>
#include <QIcon>
#include <QLibraryInfo>
#include <QLocale>
#include <QTranslator>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QString locale = QLocale::system().name();

    QTranslator qtTranslator;
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    qtTranslator.load(QString("qt_") + locale, QLibraryInfo::path(QLibraryInfo::TranslationsPath));
#else
    qtTranslator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
#endif
    app.installTranslator(&qtTranslator);

    QTranslator ownTranslator;
    ownTranslator.load(QString("samegame_") + locale, ":/translations");
    app.installTranslator(&ownTranslator);

#if defined(WIN32) || defined(_WIN32)
    app.setWindowIcon(QIcon(":/icons/samegame.png"));
#else
    app.setWindowIcon(QIcon(":/icons/samegame.svg"));
#endif

    MainWindow w;
    w.show();

    return app.exec();
}
