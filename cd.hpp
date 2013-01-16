#ifndef CD_HPP
#define CD_HPP

#include <QtCore/QString>
#include <QtCore/QList>

#include <odb/core.hxx>

#include "album.hpp"
#include "track.hpp"

#pragma db object pointer(*)
class CD:public Album
{
public:

#pragma db transient
  QList<TreeItem*>* Tracks;

  CD(const int year, const QString& title);
  CD(const CD& other);

  virtual void AddTrack(const QString& title, const int duration, const int index=0);
  virtual Album::Types AlbumType() const;
  virtual TreeItem* Copy() const;

protected:
  friend class odb::access;
  CD(){};

private:
};

#endif
