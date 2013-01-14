#ifndef ROOTITEM_HPP
#define ROOTITEM_HPP

#include "treeitem.hpp"
#include "library.hpp"

class RootItem:public TreeItem, public Library
{
public:
  RootItem();
  RootItem(const Library& library);

  void DetachAll();
protected:
private:
};

#endif
