#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QStandardItemModel>
#include "model.hpp"
#include "treeitem.hpp"

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
    
public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  Model* model;
public slots:
  void Reload();
  void Save();

private slots:
  void on_centralWidget_customContextMenuRequested(const QPoint &pos);
 

private:
  Ui::MainWindow *ui;
};

#endif
