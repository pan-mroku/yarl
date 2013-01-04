//#include <QApplication>
//#include "mainwindow.hpp"

#include <iostream>

#include "artist.hpp"
#include "album.hpp"

int main(int argc, char *argv[])
{
  //QApplication a(argc, argv);
  //MainWindow w;
  //w.showMaximized();
    
  //return a.exec();

  QSharedPointer<Artist> a(new Artist("asd"));

  std::cout<<*a<<std::endl;

  QSharedPointer<Album> aa(new Album("aa",a));
  QSharedPointer<Album> ab(new Album("aa",{a}));

  const_cast<QString&>(a->Name)[0]='b';

  std::cout<<aa<<std::endl;
  std::cout<<ab<<std::endl;

  return 0;
}
