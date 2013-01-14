#include "artist.hpp"

Artist::Artist(const std::string& name)
{
  Name=name;
}

Artist::Artist(const Artist& other)
{
  id=other.id;
  Name=other.Name;
  for(const Album* album:other.Albums)
    Albums.push_back(new Album(*album));
}

Artist::~Artist()
{
  for(Album* album:Albums)
    delete album;
  Albums.clear();
}
