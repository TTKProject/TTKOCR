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

TEMPLATE = lib

include($$PWD/TTKModule.pri)
include($$PWD/../TTKOCR.pri)

CONFIG += plugin lib

TARGET = TTKCore

INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/ocrapplication.h \
    $$PWD/ocrapplicationobject.h

SOURCES += \
    $$PWD/ocrapplicationobject.cpp \
    $$PWD/ocrapplication.cpp
    
win32:RC_FILE = $$PWD/TTKCore.rc
