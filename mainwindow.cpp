#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QtGui/QMessageBox>

#include <iostream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  model=new Model();

  ui->treeView->setModel(model);

  connect(ui->LoadButton, SIGNAL(clicked()), this, SLOT(Reload()));
  connect(ui->DeleteButton, SIGNAL(clicked()), this, SLOT(Delete()));
  connect(ui->NewButton, SIGNAL(clicked()), this, SLOT(Add()));
  
  //gdyby mnie pokusiło na modyfikowanie drzewa myszką
  ui->treeView->setSelectionBehavior(QTreeView::SelectItems);
}

MainWindow::~MainWindow()
{
  delete ui;
  delete model;
}

void MainWindow::Reload()
{
  model->LoadDatabase();
  //HACK, ale odświerza bez zabaw w emitowanie sygnału
  ui->treeView->setModel(NULL);
  ui->treeView->setModel(model);
}

void MainWindow::Save()
{
  //model->
}

bool MainWindow::Add()
{
  Dialog dialog(this);
  return dialog.exec();
}

void MainWindow::Delete()
{
  QModelIndexList indexList=ui->treeView->selectionModel()->selectedIndexes();
  if(indexList.size()==0)
    return;
  model->Erase(indexList[0]);
  
  //powinien być slot i sygnał, ale mało już mam czasu.
  //Trzeba odwierzyć przed końcem metody. inaczj treeview próbuje się dostać do nieisteniejącego elementu
  ui->treeView->setModel(NULL);
  ui->treeView->setModel(model);
}

void MainWindow::on_centralWidget_customContextMenuRequested(const QPoint &pos)
{

}
