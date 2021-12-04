#ifndef OCRWIDGETUTILS_H
#define OCRWIDGETUTILS_H

/***************************************************************************
 * This file is part of the TTK OCR project
 * Copyright (C) 2015 - 2022 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

#include "ttkglobaldefine.h"

/*! @brief The class of the utils widget object namespace.
 * @author Greedysky <greedysky@163.com>
 */
namespace OCRUtils
{
    namespace Widget
    {
        /*!
         * Get pximap data.
         */
        TTK_MODULE_EXPORT QByteArray generatePixmapData(const QPixmap &pix);
        /*!
         * Get open file dialog.
         */
        TTK_MODULE_EXPORT QStringList openFilesDialog(QWidget *obj, const QString &filter);

    }
}

#endif // OCRWIDGETUTILS_H
