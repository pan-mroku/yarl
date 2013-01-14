#include "artistitem.hpp"
#include "albumitem.hpp"

ArtistItem::ArtistItem(const Artist& artist):Artist(artist)
{
  Data.push_back(&Name);
  for(const Album* album:artist.Albums)
    {
      AlbumItem* albumItem=new AlbumItem(*album);
      albumItem->Parent=this;
      Children.push_back(albumItem);
    }
}
