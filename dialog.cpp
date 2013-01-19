#include "dialog.hpp"
#include "ui_dialog.h"
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setLayout(ui->verticalLayout);
    model=new QStandardItemModel();
    model->setHorizontalHeaderLabels(QStringList({"Title", "Duration"}));
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setResizeMode(QHeaderView::Stretch);

    connect(ui->AddButton, SIGNAL(clicked()), this, SLOT(AddTrack()));
    connect(ui->RemoveButton, SIGNAL(clicked()), this, SLOT(DelTrack()));
    connect(ui->UpButton, SIGNAL(clicked()), this, SLOT(PopTrack()));
    connect(ui->DownButton, SIGNAL(clicked()), this, SLOT(PushTrack()));
}

Dialog::~Dialog()
{
    delete ui;
  delete model;
}


void Dialog::Check()
{
  if(ui->ArtistEdit->text().size()==0)
    return;
  if(ui->TitleEdit->text().size()==0)
    return;
  if(ui->YearEdit->text().size()==0)
    return;
  if(model->rowCount()==0)
    return;

  QMessageBox check;
  check.setText("check");
  check.exec();
  emit Ok();
}

void Dialog::AddTrack()
{
  QStandardItem track(2,1);
 model->appendRow(&track);
}

void Dialog::DelTrack()
{
  QModelIndexList indexList=ui->tableView->selectionModel()->selectedIndexes();
  if(indexList.size()==0)
    return;
  model->removeRows(indexList[0].row(),1);
}

void Dialog::PopTrack()
{
  QModelIndexList indexList=ui->tableView->selectionModel()->selectedIndexes();
  if(indexList.size()==0)
    return;

  if(indexList[0].row()==0)
    return;

  QList<QStandardItem*> pushed=model->takeRow(indexList[0].row());
  model->insertRow(indexList[0].row()-1, pushed);
}

void Dialog::PushTrack()
{
  QModelIndexList indexList=ui->tableView->selectionModel()->selectedIndexes();
  if(indexList.size()==0)
    return;

  if(indexList[0].row()==model->rowCount()-1)
    return;

  QList<QStandardItem*> pushed=model->takeRow(indexList[0].row());
  model->insertRow(indexList[0].row()+1, pushed);
}
