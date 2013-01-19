#include "dialog.hpp"
#include "ui_dialog.h"
#include <QMessageBox>
#include "artist.hpp"
#include "cd.hpp"
#include <QTime>

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
    NewArtist=NULL;
}

Dialog::~Dialog()
{
  delete ui;
  delete model;
  //delete NewArtist; //Tym zajmuje się już model
}


void Dialog::Check()
{
  QString artistName, albumTitle;
  int albumYear;

  if(NewArtist!=NULL)
    {
      delete NewArtist;
      NewArtist=NULL;
    }

  artistName=ui->ArtistEdit->text();
  if(artistName.isEmpty())
    {
      QMessageBox check;
      check.setText("There were errors in the name of the artist.\nCorrect your data and try again.");
      check.exec();
      return;
    }
  NewArtist=new Artist(artistName);
  
  albumTitle=ui->TitleEdit->text();
  if(albumTitle.isEmpty())
    {
      QMessageBox check;
      check.setText("There were errors in title of the album.\nCorrect your data and try again.");
      check.exec();
      return;
    }

  bool yearOk;
  albumYear=ui->YearEdit->text().toInt(&yearOk);
  if(ui->YearEdit->text().size()==0||!yearOk)
    {
      QMessageBox check;
      check.setText("There were errors in year of production of the album.\nCorrect your data and try again.");
      check.exec();
      return;
    }
  Album* NewAlbum=new CD(albumYear, albumTitle);
  NewArtist->Children.push_back(NewAlbum);
  NewAlbum->Parent=NewArtist;


  if(model->rowCount()==0)
    {
      QMessageBox check;
      check.setText("There were errors in track list.\nCorrect your data and try again.");
      check.exec();
      return;
    }

  for(int trackIndex=0;trackIndex<model->rowCount();trackIndex++)
    {
      QString trackTitle=model->item(trackIndex,0)->text();

      if(trackTitle.isEmpty())
        {
          QMessageBox check;
          check.setText("There were errors in track list.\nCorrect your data and try again.");
          check.exec();
          return;
        }
      QTime duration=QTime::fromString(model->item(trackIndex,1)->text(), "m:s");

      if(!duration.isValid())
        {
          QMessageBox check;
          check.setText("There were errors in track list.\nCorrect your data and try again.");
          check.exec();
          return;
        }
      NewAlbum->AddTrack(trackTitle, duration.elapsed()*1000);

    }

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
