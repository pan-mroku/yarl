//#include <QApplication>
//#include "mainwindow.hpp"

#include <iostream>

#include "artist.hpp"

int main(int argc, char *argv[])
{
  //QApplication a(argc, argv);
  //MainWindow w;
  //w.showMaximized();
    
  //return a.exec();
  Artist a("asd");
  const_cast<QString&>(a.Name())[0]='b';
  std::cout<<a.Name().toStdString() <<std::endl;
  return 0;
}
