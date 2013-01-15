#include "artistitem.hpp"
#include "cditem.hpp"
#include <iostream>

ArtistItem::ArtistItem(const Artist& artist):Artist(artist)
{
  Data.push_back(&Name);
  for(const Album* album:artist.Albums)
    {
      if(album->Type()==Album::Types::cd)
        Children.push_back(new CDItem(*dynamic_cast<const CD*>(album)));

      Children.back()->Parent=*this;
    }
  std::clog<<"DEBUG: "<<*this<<std::endl;
}

