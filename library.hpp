#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <QtCore/QList>
#include <QtCore/QString>

#include<odb/core.hxx>

#include "treeitem.hpp"
#include "artist.hpp"

#pragma db object
class Library:public TreeItem
{
public:
  std::string Name;

#pragma db transient
  QList<TreeItem*>* Artists;

  Library(std::string name="");
  Library(const Library& library);

  virtual ItemTypes ItemType() const;
  //  ~Library();

  //bool Persist(odb::database& db) const;

protected:
  friend class odb::access;
  /*#pragma db id auto
    int id;*/

private:
};

#endif
