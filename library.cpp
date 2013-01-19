#include "library.hpp"

Library::Library(std::string name):TreeItem()
{
  Name=name;
  Artists=&Children;
}

Library::Library(const Library& library):TreeItem(library)
{
  Artists=&Children;
  id=library.id;
  Name=library.Name;
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

TreeItem* Library::AddArtist(Artist* artist)
{
  for(TreeItem* knownArtist:*Artists)
    {
      if(dynamic_cast<Artist*>(knownArtist)->Name==artist->Name)
        {
          knownArtist->Children.push_back(artist->Children[0]);
          knownArtist->Children.back()->Parent=knownArtist;
          artist->Children.pop_back();// żeby destruktor nie zniszczył mi albumu
          delete artist;// Bo klasy wyżej nie będą wiedziały, czy skopiowaliśmy, czy dodaliśmy artystę
          return knownArtist->Children.back();
        }
    }
  //Jeśli tu doszliśmy, to jest to nowy artysta;
  Children.push_back(artist);
  artist->Parent=this;
  return Children.back();
}
