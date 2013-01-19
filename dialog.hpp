#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QStandardItemModel>

#include "artist.hpp"

namespace Ui {
  class Dialog;
}

class Dialog : public QDialog
{
  Q_OBJECT
    
public:
  explicit Dialog(QWidget *parent = 0);
  ~Dialog();
  QStandardItemModel *model;
  Artist* NewArtist;

public slots:
  void Check();
  void AddTrack();
  void DelTrack();
  void PopTrack();
  void PushTrack();
              
signals:
  void Ok();
    
private:
  Ui::Dialog *ui;
};

#endif // DIALOG_H
