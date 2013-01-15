#include "artist.hpp"
#include "cd.hpp"
#include "artist-odb.hxx"
#include <exception>
#include <iostream>

Artist::Artist(const std::string& name)
{
  Name=name;
}

Artist::Artist(const Artist& other)
{
  id=other.id;
  Name=other.Name;
  for(const Album* album:other.Albums)
    if(album->Type()==Album::Types::cd)
      Albums.push_back(new CD(dynamic_cast<const CD&>(*album)));
}

Artist::~Artist()
{
  for(Album* album:Albums)
    delete album;
  Albums.clear();
}

bool Artist::Persist(odb::database& db) const
{
  for(const Album* album:Albums)
    if(!album->Persist(db))
      return false;

  try
    {
      db.persist(const_cast<Artist&>(*this));
    }
  catch(const std::exception& e)
    {
      std::cerr<<e.what()<<std::endl;
      return false;
    }

  return true;
}
