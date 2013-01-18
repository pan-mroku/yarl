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
    ui->listView->setModel(model);
    connect(ui->AddButton, SIGNAL(clicked()), this, SLOT(AddTrack()));
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
