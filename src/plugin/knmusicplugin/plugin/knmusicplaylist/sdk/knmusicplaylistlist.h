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
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef KNMUSICPLAYLISTLIST_H
#define KNMUSICPLAYLISTLIST_H

#include <QWidget>

class KNAnimationMenu;
class KNLinearSenseWidget;
class KNMusicPlaylistListView;
class KNOpacityAnimeButton;
class KNMusicPlaylistList : public QWidget
{
    Q_OBJECT
public:
    explicit KNMusicPlaylistList(QWidget *parent = 0);

signals:

public slots:

private slots:
    void retranslate();

private:
    inline KNAnimationMenu *generateEditorMenu();
    inline void configureEditor();
    enum EditorButton
    {
        Add,
        RemoveCurrent,
        Configure,
        EditorButtonCount
    };
    KNOpacityAnimeButton *m_buttons[EditorButtonCount];
    enum AddMenuAction
    {
        AddPlaylist,
        ImportPlaylist,
        AddMenuActionCount
    };
    enum ConfigureMenuAction
    {
        ExportPlaylist,
        CopyPlaylist,
        ConfigureMenuActionCount
    };
    QAction *m_addActions[AddMenuActionCount],
            *m_configureAction[ConfigureMenuActionCount];

    KNMusicPlaylistListView *m_playlistListView;
    KNLinearSenseWidget *m_playlistListEditor;
};

#endif // KNMUSICPLAYLISTLIST_H