#ifndef ARTISTITEM_HPP
#define ARTISTITEM_HPP

#include "treeitem.hpp"
#include "artist.hpp"

class ArtistItem:public TreeItem, public Artist
{
public:
  ArtistItem(const Artist& artist);
protected:
private:
};

#endif
