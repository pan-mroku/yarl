#include <iostream>

#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/sqlite/database.hxx>

#include "artist.hpp"
#include "artist-odb.hxx"
#include "library.hpp"
#include "library-odb.hxx"
#include "cd.hpp"
#include "cd-odb.hxx"

#include <QtGui/QApplication>
//#include "model.hpp"
#include "mainwindow.hpp"

void create()
{
  std::cout<<"Creation... ";
  odb::sqlite::database db("test.db", SQLITE_OPEN_READWRITE|SQLITE_OPEN_CREATE);
  //odb::connection_ptr c (db.connection ());
  //c->execute ("PRAGMA foreign_keys=OFF");

  odb::transaction t (db.begin ());
  odb::schema_catalog::create_schema (db);
  t.commit ();
  //c->execute ("PRAGMA foreign_keys=ON");
  std::cout<<"COMPLETE"<<std::endl;;
}

void populate()
{
  std::cout<<"Populating... ";
  odb::sqlite::database db("test.db", SQLITE_OPEN_READWRITE|SQLITE_OPEN_CREATE);
  
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

  //std::cout<<lib<<std::endl;
    
  odb::core::transaction t (db.begin ());
  lib->Persist(db);
  /*  db.persist(*alb);
  db.persist(*al);

  db.persist(*a);
  db.persist(*b);
  db.persist(*lib);*/

  t.commit();
  delete lib;
  std::cout<<"COMPLETE"<<std::endl;;
}

void query_artists()
{
  std::cout<<"Querying Artists... ";
  odb::sqlite::database db("test.db", SQLITE_OPEN_READWRITE|SQLITE_OPEN_CREATE);

  odb::core::transaction t (db.begin ());

  odb::result<Artist> r (db.query<Artist>());

  //for(Artist a:r)
  //std::cout<<a<<std::endl;
  std::cout<<"COMPLETE";
}


/*void query_albums()
  {
  odb::sqlite::database db("test.db", SQLITE_OPEN_READWRITE|SQLITE_OPEN_CREATE);

  odb::core::transaction t (db.begin ());

  odb::result<Album> r (db.query<Album>(odb::query<Album>::Title=="aab"));

  for(Album a:r)
  std::cout<<a<<std::endl;
  }*/

int main(int argc, char *argv[])
{

  //QApplication a(argc, argv);
  //MainWindow w;
  //w.showMaximized();
    
  //return a.exec();
  /*create();
    query_artists();
    query_albums();*/
  //  QSharedPointer<Model> m(new Model());
  //Model m;
  create();
  populate();
  //query_artists();
  /*  Model m;
      std::cout<<m<<std::endl;*/
  QApplication a(argc, argv);
  MainWindow w;
  w.showMaximized();
  return a.exec();
}
