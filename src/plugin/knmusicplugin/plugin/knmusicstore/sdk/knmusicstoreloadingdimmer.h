/*
 * Copyright (C) Kreogist Dev Team
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef KNMUSICSTORELOADINGDIMMER_H
#define KNMUSICSTORELOADINGDIMMER_H

#include <QWidget>

class QLabel;
/*!
 * \brief The KNMusicStoreLoadingDimmer class provides the initial loading page
 * for the music store loading page.
 */
class KNMusicStoreLoadingDimmer : public QWidget
{
    Q_OBJECT
public:
    /*!
     * \brief Construct a KNMusicStoreLoadingDimmer widget.
     * \param parent The parent widget.
     */
    explicit KNMusicStoreLoadingDimmer(QWidget *parent = 0);

signals:

public slots:
    /*!
     * \brief Set darkness of the dimmer.
     * \param darkness The level of darkness, the value should between 0-1.
     */
    void setDarkness(const qreal &darkness);

protected:
    /*!
     * \brief Reimplemented from QWidget::paintEvent().
     */
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private slots:
    void retranslate();

private:
    QLabel *m_title;
    int m_blackAlpha;
};

#endif // KNMUSICSTORELOADINGDIMMER_H
