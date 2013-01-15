#ifndef CD_HPP
#define CD_HPP

#include <QtCore/QString>
#include <QtCore/QList>

#include <odb/core.hxx>

#include "album.hpp"
#include "track.hpp"

#pragma db object
class CD:public Album
{
public:

#pragma db transient
  QList<TreeItem*>* Tracks;

  CD(const int year, const QString& title);
  CD(const CD& other);
  //~CD();

  virtual void AddTrack(const QString& title, const int duration, const int index=0);
  virtual Album::Types AlbumType() const;
  virtual ItemTypes ItemType() const;
  //virtual bool Persist(odb::database& db) const;

protected:
  friend class odb::access;
  CD(){};

private:
/* Jeśli cd ma takie same pola (kolekacja wskaźników się nie liczy), co album,
 * to SELECT głupieje. */
bool _hack;
};

#endif
