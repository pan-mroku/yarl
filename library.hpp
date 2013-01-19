#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <QtCore/QList>
#include <QtCore/QString>

#include<odb/core.hxx>

#include "treeitem.hpp"
#include "artist.hpp"

#pragma db object pointer(*)
class Library:public TreeItem
{
public:
  std::string Name;

#pragma db transient
  QList<TreeItem*>* Artists;

  Library(std::string name="");
  Library(const Library& library);
  virtual TreeItem* Copy() const;

  virtual QString QData() const;
  virtual ItemTypes ItemType() const;

  TreeItem* AddArtist(Artist* artist);

protected:
  friend class odb::access;

private:
};

#endif
