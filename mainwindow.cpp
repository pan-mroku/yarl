#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  model=new Model();

  ui->treeView->setModel(model);
}

MainWindow::~MainWindow()
{
  delete ui;
  delete model;
}

void MainWindow::on_centralWidget_customContextMenuRequested(const QPoint &pos)
{

}
