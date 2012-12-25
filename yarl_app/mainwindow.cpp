#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    person *p=new person("asd","asd",24);
    //model.appendRow(p);


    QStandardItem *parentItem = model.invisibleRootItem();
    for (int i = 0; i < 4; ++i)
    {
        QStandardItem *item = new QStandardItem(QString("item %0").arg(i));
        parentItem->appendRow(item);
        parentItem = item;
    }
    parentItem->appendRow(p);

    ui->treeView->setModel(&model);
}

MainWindow::~MainWindow()
{
    delete ui;
    model.clear();
}

void MainWindow::on_centralWidget_customContextMenuRequested(const QPoint &pos)
{

}
