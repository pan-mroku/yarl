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
      Children.push_back(new ArtistItem(*artist));
      Children.back()->Parent=*this;
    }
}

void RootItem::DetachAll()
{
  for(TreeItem* child:Children)
    delete child;
}
