#include "album.hpp"

Album::Album(const QString& title, const QSharedPointer<Artist>& author):Title(title)
{
  Authors.push_back(author);
  setText(Title);
}

Album::Album(const QString& title, const std::initializer_list<QSharedPointer<Artist>>& authors):Title(title)
{
  for(const QSharedPointer<Artist>& author:authors)
    this->Authors.push_back(author);
  setText(Title);
}

std::ostream& operator<<(std::ostream& out, const QSharedPointer<Album>& album)
{
  for(QSharedPointer<Artist> artist:album->Authors)
    out<<*artist<<", ";
  out<<"\""<<album->Title.toStdString()<<"\"";
  return out;
}
