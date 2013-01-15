#include "library.hpp"
#include "library-odb.hxx"
#include <exception>
#include <iostream>

Library::Library(std::string name)
{
  Name=name;
}

Library::Library(const Library& library)
{
  id=library.id;
  Name=library.Name;
  for(const Artist* artist:library.Artists)
    Artists.push_back(new Artist(*artist));
}

Library::~Library()
{
  for(Artist* artist:Artists)
    delete artist;
  Artists.clear();
}

bool Library::Persist(odb::database& db) const
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
