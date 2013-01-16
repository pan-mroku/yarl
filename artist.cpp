#include "artist.hpp"
#include "cd.hpp"

Artist::Artist(const QString& name)
{
  Name=name;
  Albums=&Children;
}

Artist::Artist(const Artist& other)
{
  id=other.id;
  Name=other.Name;
  Albums=&Children;
  for(const TreeItem* item:other.Children)
    {
      Children.push_back(item->Copy());
      Children.back()->Parent=this;
    }
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
