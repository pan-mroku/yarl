#include "rootitem.hpp"
#include "artistitem.hpp"

#include <iostream>

RootItem::RootItem():TreeItem()
{
  Parent=this;
}

RootItem::RootItem(const Library& library):Library(library), TreeItem()
{
  Parent=this;
  Data.push_back(&Name);
  for(const Artist* artist:Artists)
    {
      ArtistItem* artistItem=new ArtistItem(*artist);
      artistItem->Parent=this;
      Children.push_back(artistItem);
    }
}

void RootItem::DetachAll()
{
  for(TreeItem* child:Children)
    delete child;
}
