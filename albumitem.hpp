#ifndef ALBUMITEM_HPP
#define ALBUMITEM_HPP

#include <string>

#include "treeitem.hpp"
#include "album.hpp"

class AlbumItem:public TreeItem, public Album
{
public:
  std::string Year_str;
  AlbumItem(const Album& album);
protected:
private:
};

#endif
