#include "artist.hpp"
#include "cd.hpp"

Artist::Artist(const QString& name):TreeItem()
{
  Name=name;
  Albums=&Children;
}

Artist::Artist(const Artist& other):TreeItem(other)
{
  id=other.id;
  Name=other.Name;
  Albums=&Children;
}

TreeItem* Artist::Copy() const
{
  return new Artist(*this);
}

QString Artist::QData() const
{
  return Name;
}

TreeItem::ItemTypes Artist::ItemType() const
{
  return ItemTypes::artist;
}
