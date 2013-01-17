#include <iostream>

#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/sqlite/database.hxx>

#include "artist.hpp"
#include "library.hpp"
#include "cd.hpp"

#include <QtGui/QApplication>
#include "mainwindow.hpp"

void create(Model& m)
{
  m.NewDatabase();
}

void populate(Model& model)
{
  std::cout<<"Populating... ";
  
  odb::sqlite::database db(model.DatabaseFilename.toStdString(), SQLITE_OPEN_READWRITE|SQLITE_OPEN_CREATE);

  Library* lib=new Library("1");
  Artist* a=new Artist("asd");
  Artist* b=new Artist("bsd");
  lib->Artists->push_back(a);
  lib->Artists->push_back(b);

  Album* al=new CD(2005, "alcd");
  CD* alb=new CD(2010, "alb");
  a->Albums->push_back(alb);
  a->Albums->push_back(al);
  alb->AddTrack("Track 1", 66);

  //model.Root=lib->Copy();
  //std::cout<<*lib<<std::endl;
    
  odb::core::transaction t (db.begin ());
  odb::schema_catalog::create_schema (db);
  lib->Persist(db);
  t.commit();

  delete lib;

  std::cout<<"COMPLETE"<<std::endl;;
}

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  create(*w.model);
  populate(*w.model);

  w.showMaximized();
  return a.exec();
}
