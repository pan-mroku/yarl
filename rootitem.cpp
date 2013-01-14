#include "rootitem.hpp"
#include "artistitem.hpp"

#include <iostream>

RootItem::RootItem():TreeItem()
{

}

RootItem::RootItem(const Library& library):Library(library), TreeItem()
{
  Data.push_back(&Name);
  for(const Artist* artist:Artists)
    Children.push_back(new ArtistItem(*artist));
}

void RootItem::DetachAll()
{
  for(TreeItem* child:Children)
    delete child;
}
