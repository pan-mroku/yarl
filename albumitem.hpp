#ifndef ALBUMITEM_HPP
#define ALBUMITEM_HPP

#include <QtCore/QString>

#include "treeitem.hpp"
#include "album.hpp"

class AlbumItem:public TreeItem, public Album
{
public:
  AlbumItem(const Album& album);
  virtual QString QData() const;
protected:
private:
};

#endif
