#include "album.hpp"

Album::Album(const QString& title, const QSharedPointer<Artist>& author):Title(title)
{
  Authors.push_back(author);
 
  //Authors.back()->appendRow(this); //trzeba poczekać aż będziemy mieli model;
}

Album::Album(const QString& title, const std::initializer_list<QSharedPointer<Artist>>& authors):Title(title)
{
  for(const QSharedPointer<Artist>& author:authors)
    {
      Authors.push_back(author);
      //Authors.back()->appendRow(this); //jak wyżej
    }
}

std::ostream& operator<<(std::ostream& out, const Album& album)
{
  for(const QSharedPointer<Artist>& artist:album.Authors)
    out<<*artist<<", ";
  out<<"\""<<album.Title.toStdString()<<"\"";
  return out;
}
