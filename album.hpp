#ifndef ALBUM_HPP
#define ALBUM_HPP

#include <QtCore/QList>
#include <QtCore/QString>

#include <odb/core.hxx>

#include "treeitem.hpp"

#pragma db object polymorphic pointer(*)
class Album:public TreeItem
{
public:

  enum Types
    {
      base=0,
      cd=1,
      mc=2
    };

  int Year;
  QString Title;

  Album(const int year, const QString& title);
  Album(const Album& other);

  virtual void AddTrack(const QString& title, const int duration, const int index=0)=0;
  virtual Types AlbumType() const;
  virtual ItemTypes ItemType() const;
  virtual QString QData() const;

protected:
  friend class odb::access;
  Album(){};

private:
  
};

#endif
