#include "albumitem.hpp"
#include <iostream>

AlbumItem::AlbumItem(const Album& album):Album(album)
{
}

QString AlbumItem::QData() const
{
  std::clog<<"DEBUG2: "<<((QString::number(Year)+" "+QString::fromStdString(Title)).toStdString())<<std::endl;
  return (QString::number(Year)+" "+QString::fromStdString(Title));
}
