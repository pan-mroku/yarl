#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QStandardItemModel>

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

public slots:
  void Check();
  void AddTrack();
              
signals:
  void Ok();
    
private:
  Ui::Dialog *ui;
};

#endif // DIALOG_H
