/*
 * This file Copyright (C) 2009-2014 Mnemosyne LLC
 *
 * It may be used under the GNU GPL versions 2 or 3
 * or any future license endorsed by Mnemosyne LLC.
 *
 * $Id: relocate.h 14418 2015-01-01 05:02:13Z mikedld $
 */

#ifndef RELOCATE_DIALOG_H
#define RELOCATE_DIALOG_H

#include <QDialog>
#include <QSet>

#include "ui_relocate.h"

class Session;
class TorrentModel;

class RelocateDialog: public QDialog
{
    Q_OBJECT

  public:
    RelocateDialog (Session&, const TorrentModel&, const QSet<int>& ids, QWidget * parent = 0);
    ~RelocateDialog () {}

  private slots:
    void onSetLocation ();
    void onMoveToggled (bool);

  private:
    QString newLocation () const;

  private:
    Session& mySession;
    const QSet<int> myIds;
    Ui::RelocateDialog ui;

    static bool myMoveFlag;
};

#endif
