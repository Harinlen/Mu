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

#ifndef KNMUSICSTOREPAGESINGLESONG_H
#define KNMUSICSTOREPAGESINGLESONG_H

#include "knmusicstoreutil.h"

#include "knmusicstorepage.h"

using namespace MusicStoreUtil;

class QLabel;
class QBoxLayout;
class KNAnimeLabelButton;
class KNMusicAlbumLabel;
/*!
 * \brief The KNMusicStoreSingleSongPage class provides the interface for a
 * single song. The information of a single song contains:
 *  1. The name of the song.
 *  2. The album art.
 *  3. The artist, album of the song.
 *  4. The download link of the song.
 *  5. The text lyrics of the song.
 *  6. Some other data, which will be contained in the future.
 * All the information will be set async. This will be controlled by the backend
 * manager.
 */
class KNMusicStorePageSingleSong : public KNMusicStorePage
{
    Q_OBJECT
public:
    /*!
     * \brief Construct a KNMusicStoreSingleSongPage widget.
     * \param parent The parent page.
     */
    explicit KNMusicStorePageSingleSong(QWidget *parent = 0);

signals:

public slots:
    /*!
     * \brief Set the text at the single song page.
     * \param labelIndex The index recorded in the util class.
     * \param value The value of the label.
     */
    void setSingleSong(int labelIndex, const QVariant &value);

protected slots:
    /*!
     * \brief Reimplemented from KNMusicStorePage::onPaletteChanged().
     */
    void onPaletteChanged() Q_DECL_OVERRIDE;

private slots:
    void retranslate();

private:
    enum LabelHints
    {
        HintArtists,
        HintAlbum,
        LabelHintsCount
    };
    inline void insertArtistLabel(const QString &artistName);
    inline void updateArtistHintLabel();
    inline void updateArtistLabelPalette();
    QList<KNAnimeLabelButton *> m_artistLabels;
    QList<QLabel *> m_artistSplitLabels;
    QString m_artistHintText, m_artistsHintText;
    QLabel *m_labelHints[LabelHintsCount], *m_headerLabel, *m_subheadingLabel,
           *m_lyrics;
    QBoxLayout *m_artistLayout;
    KNAnimeLabelButton *m_albumLabel;
    KNMusicAlbumLabel *m_albumArt;
};

#endif // KNMUSICSTOREPAGESINGLESONG_H
