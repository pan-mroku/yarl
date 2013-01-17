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
  return false;
}

void MainWindow::Delete()
{
  QModelIndexList indexList=ui->treeView->selectionModel()->selectedIndexes();
  if(indexList.size()==0)
    return;
  model->Erase(indexList[0]);
  
  ui->treeView->setModel(NULL);
  ui->treeView->setModel(model);
}

void MainWindow::on_centralWidget_customContextMenuRequested(const QPoint &pos)
{

}
