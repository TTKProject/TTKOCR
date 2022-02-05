# ***************************************************************************
# * This file is part of the TTK OCR project
# * Copyright (C) 2015 - 2022 Greedysky Studio
#
# * This program is free software; you can redistribute it and/or modify
# * it under the terms of the GNU General Public License as published by
# * the Free Software Foundation; either version 3 of the License, or
# * (at your option) any later version.
#
# * This program is distributed in the hope that it will be useful,
# * but WITHOUT ANY WARRANTY; without even the implied warranty of
# * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# * GNU General Public License for more details.
#
# * You should have received a copy of the GNU General Public License along
# * with this program; If not, see <http://www.gnu.org/licenses/>.
# ***************************************************************************

QT += core gui network
equals(QT_MAJOR_VERSION, 4){ #Qt4
    CONFIG += gcc
}

greaterThan(QT_MAJOR_VERSION, 4){ #Qt5
    QT += widgets
    equals(QT_MAJOR_VERSION, 6){ #Qt6
        QT += core5compat
    }
}

include($$PWD/TTKVersion.pri)

DESTDIR = $$OUT_PWD/../bin/$$TTKOCR

include($$PWD/TTKBuild.pri)

##openssl lib check
win32{
    SSL_DEPANDS = $$DESTDIR/ssleay32.dll
    SSL_DEPANDS = $$replace(SSL_DEPANDS, /, \\)
    exists($$SSL_DEPANDS):LIBS += -L$$DESTDIR -lssl
}
unix:!mac{
    SSL_DEPANDS = $$DESTDIR/libssleay32.so
    exists($$SSL_DEPANDS):LIBS += -L$$DESTDIR -lssl
}

win32{
    msvc{
        LIBS += -lshell32 -luser32
        LIBS += -L$$DESTDIR -lTTKUi -lTTKExtras -lzlib -lTTKZip
        contains(CONFIG, TTK_BUILD_BY_PDF):LIBS += -L$$DESTDIR -lTTKPdf
        CONFIG += c++11
        !contains(QMAKE_TARGET.arch, x86_64){
             #support on windows XP
             QMAKE_LFLAGS_WINDOWS = /SUBSYSTEM:WINDOWS,5.01
             QMAKE_LFLAGS_CONSOLE = /SUBSYSTEM:CONSOLE,5.01
        }
    }

    gcc{
        LIBS += -L$$DESTDIR -lTTKUi -lTTKExtras -lzlib -lTTKZip
        contains(CONFIG, TTK_BUILD_BY_PDF):LIBS += -L$$DESTDIR -lTTKPdf
        equals(QT_MAJOR_VERSION, 6){ #Qt6
            QMAKE_CXXFLAGS += -std=c++17
        }else{
            QMAKE_CXXFLAGS += -std=c++11
        }
        QMAKE_CXXFLAGS += -Wunused-function -Wswitch
    }

    equals(QT_MAJOR_VERSION, 4):QT += multimedia
}

unix:!mac{
    LIBS += -L$$DESTDIR -lTTKUi -lTTKExtras -lzlib -lTTKZip
    contains(CONFIG, TTK_BUILD_BY_PDF):LIBS += -L$$DESTDIR -lTTKPdf
    equals(QT_MAJOR_VERSION, 6){ #Qt6
        QMAKE_CXXFLAGS += -std=c++17
    }else{
        QMAKE_CXXFLAGS += -std=c++11
    }
    QMAKE_CXXFLAGS += -Wunused-function -Wswitch
}

DEFINES += TTK_LIBRARY

#########################################
include($$PWD/TTKCommon/TTKCommon.pri)
include($$PWD/TTKThirdParty/TTKThirdParty.pri)
#########################################
