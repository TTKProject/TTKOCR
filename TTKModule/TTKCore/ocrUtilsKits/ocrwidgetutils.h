#ifndef OCRWIDGETUTILS_H
#define OCRWIDGETUTILS_H

/* =================================================
 * This file is part of the TTK OCR project
 * Copyright (C) 2015 - 2021 Greedysky Studio

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
 ================================================= */

class QComboBox;

#include "ocrobject.h"
#include "ttkglobaldefine.h"

/*! @brief The class of the utils widget object namespace.
 * @author Greedysky <greedysky@163.com>
 */
namespace OCRUtils
{
    namespace Widget
    {
        /*!
         * Set widget label font.
         */
        TTK_MODULE_EXPORT void setLabelFontSize(QWidget *widget, int size);
        /*!
         * Set text elided text by font.
         */
        TTK_MODULE_EXPORT QString elidedText(const QFont &font, const QString &text,
                                             Qt::TextElideMode mode, int width);
        /*!
         * Set widget transparent.
         */
        TTK_MODULE_EXPORT void setTransparent(QWidget *widget, int alpha);
        /*!
         * Set ComboBox text.
         */
        TTK_MODULE_EXPORT void setComboBoxText(QComboBox *object, const QString &text);
        /*!
         * Set widget to round by ratioX and ratioY.
         */
        TTK_MODULE_EXPORT void widgetToRound(QWidget *w, int ratioX, int ratioY);
        /*!
         * Set fusion two image.
         */
        TTK_MODULE_EXPORT void fusionPixmap(QPixmap &bg, const QPixmap &fg, const QPoint &pt);
        /*!
         * Set pixmap to round by ratio.
         */
        TTK_MODULE_EXPORT QPixmap pixmapToRound(const QPixmap &src, const QSize &size, int ratioX, int ratioY);
        /*!
         * Set pixmap to round by ratio.
         */
        TTK_MODULE_EXPORT QPixmap pixmapToRound(const QPixmap &src, const QRect &rect, int ratioX, int ratioY);
        /*!
         * Set pixmap to round by ratio.
         */
        TTK_MODULE_EXPORT QPixmap pixmapToRound(const QPixmap &src, const QPixmap &mask, const QSize &size);
        /*!
         * Get bitmap mask from rect.
         */
        TTK_MODULE_EXPORT QBitmap getBitmapMask(const QRect &rect, int ratioX, int ratioY);
        /*!
         * Get pximap data.
         */
        TTK_MODULE_EXPORT QByteArray getPixmapData(const QPixmap &pix);

        /*!
         * Rerender the custum value.
         */
        template<class T>
        TTK_MODULE_EXPORT T reRenderValue(const T &key, const T &alpha, const T &value)
        {
            if(alpha < 0) return 0;
            else if(alpha > key) return key;

            return (key - alpha)*1.0/100*value + alpha;
        }

        /*!
         * Rerender the image alpha.
         */
        TTK_MODULE_EXPORT int reRenderAlpha(int alpha, int value);
        /*!
         * Rerender the image by color burn transform.
         */
        TTK_MODULE_EXPORT void reRenderImage(int delta, const QImage *input, QImage *output);
        /*!
         * Image color burn transform.
         */
        TTK_MODULE_EXPORT int colorBurnTransform(int c, int delta);

        /*!
         * Get open file dialog.
         */
        TTK_MODULE_EXPORT QString getOpenFileDialog(QWidget *obj, const QString &title, const QString &filter);
        /*!
         * Get open file dialog.
         */
        TTK_MODULE_EXPORT QString getOpenFileDialog(QWidget *obj, const QString &filter);
        /*!
         * Get open file dialog.
         */
        TTK_MODULE_EXPORT QString getOpenFileDialog(QWidget *obj);

        /*!
         * Get open files dialog.
         */
        TTK_MODULE_EXPORT QStringList getOpenFilesDialog(QWidget *obj, const QString &title, const QString &filter);
        /*!
         * Get open files dialog.
         */
        TTK_MODULE_EXPORT QStringList getOpenFilesDialog(QWidget *obj, const QString &filter);
        /*!
         * Get open files dialog.
         */
        TTK_MODULE_EXPORT QStringList getOpenFilesDialog(QWidget *obj);

        /*!
         * Get save file dialog.
         */
        TTK_MODULE_EXPORT QString getSaveFileDialog(QWidget *obj, const QString &title, const QString &filter);
        /*!
         * Get save file dialog.
         */
        TTK_MODULE_EXPORT QString getSaveFileDialog(QWidget *obj, const QString &filter);
        /*!
         * Get save file dialog.
         */
        TTK_MODULE_EXPORT QString getSaveFileDialog(QWidget *obj);

    }
}

#endif // OCRWIDGETUTILS_H
