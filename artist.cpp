#include "artist.hpp"
#include "cd.hpp"
#include "artist-odb.hxx"
#include <exception>
#include <iostream>

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
      if(item->ItemType()==ItemTypes::album)
        {
          const Album* album=dynamic_cast<const Album*>(item);
          
          if(album->AlbumType()==Album::Types::cd)
            Children.push_back(new CD(dynamic_cast<const CD&>(*album)));
          
          
          Children.back()->Parent=this;
        }
    }
}

/*Artist::~Artist()
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
*/
