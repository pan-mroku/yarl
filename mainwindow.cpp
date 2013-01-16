#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  model=new Model();

  ui->treeView->setModel(model);

  connect(ui->LoadButton, SIGNAL(clicked()), this, SLOT(Reload()));
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

void MainWindow::on_centralWidget_customContextMenuRequested(const QPoint &pos)
{

}
