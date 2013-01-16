#include "library.hpp"

Library::Library(std::string name)
{
  Name=name;
  Artists=&Children;
}

Library::Library(const Library& library)
{
  Artists=&Children;
  id=library.id;
  Name=library.Name;
  for(const TreeItem* item:library.Children)
    {
      Children.push_back(item->Copy());
      Children.back()->Parent=this;
    }
}

TreeItem* Library::Copy() const
{
  return new Library(*this);
}

QString Library::QData() const
{
  return "";
}

TreeItem::ItemTypes Library::ItemType() const
{
  return ItemTypes::library;
}
