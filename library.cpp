#include "library.hpp"
#include "library-odb.hxx"
#include <exception>
#include <iostream>

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
      if(item->ItemType()==ItemTypes::artist)
        {
          Children.push_back(new Artist(dynamic_cast<const Artist&>(*item)));
          Children.back()->Parent=this;
        }
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

/*Library::~Library()
{
  for(Artist* artist:Artists)
    delete artist;
  Artists.clear();
  }*/

/*bool Library::Persist(odb::database& db) const
{
  for(const Artist* artist:Artists)
    if(!artist->Persist(db))
      return false;

  try
    {
      db.persist(const_cast<Library&>(*this));
    }
  catch(const std::exception& e)
    {
      std::cerr<<e.what()<<std::endl;
      return false;
    }

  return true;
}
*/
