#include "album.hpp"

Album::Album(const int year, const QString& title):Year(year), Title(title), TreeItem()
{
}

Album::Album(const Album& other):TreeItem(other)
{
  id=other.id;
  Year=other.Year;
  Title=other.Title;
}

Album::Types Album::AlbumType() const
{
  return Album::Types::base;
}

TreeItem::ItemTypes Album::ItemType() const
{
  return ItemTypes::album;
}

QString Album::QData() const
{
  switch(AlbumType())
    {
    case Types::cd:
      return QString::number(Year)+" "+Title+" CD";
    case Types::mc:
      return QString::number(Year)+" "+Title+" MC";
    }
  return QString::number(Year)+" "+Title;
}
