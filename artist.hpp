#ifndef ARTIST_HPP
#define ARTIST_HPP

#include <QtCore/QList>
#include <QtCore/QString>

#include <odb/core.hxx>

#include "album.hpp"
#include "treeitem.hpp"

#pragma db object pointer(*)
class Artist:public TreeItem
{
public:
#pragma db unique
  QString Name;

#pragma db transient
  QList<TreeItem*>* Albums;

  Artist(const QString& name);
  Artist(const Artist& other);
  virtual TreeItem* Copy() const;
  virtual QString QData() const;
  virtual ItemTypes ItemType() const;
  /*~Artist();

    bool Persist(odb::database& db) const;*/

protected:
  /*#pragma db id auto
    int id;*/

  friend class odb::access; //ODB
  Artist(){};

private:
};

#endif
