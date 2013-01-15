#include "album.hpp"

Album::Album(const int year, const QString& title):Year(year), Title(title)
{
}

Album::Album(const Album& other)
{
  id=other.id;
  Year=other.Year;
  Title=other.Title;
}

Album::Types Album::AlbumType() const
{
  return Album::Types::base;
}

Album::~Album()
{
}
