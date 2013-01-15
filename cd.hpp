#ifndef CD_HPP
#define CD_HPP

#include <vector>
#include <string>

#include <odb/core.hxx>
#include<odb/database.hxx>

#include "album.hpp"
#include "track.hpp"

#pragma db object
class CD:public Album
{
public:
#pragma db value_not_null
  std::vector<Track*> Tracks;

  CD(const int year, const std::string& title);
  CD(const CD& other);
  ~CD();

  virtual void AddTrack(const std::string& title, const int duration, const int index=0);
  virtual Album::Types Type() const;
  virtual bool Persist(odb::database& db) const;

protected:
  friend class odb::access;
  CD(){};

private:
/* Jeśli cd ma takie same pola (kolekacja wskaźników się nie liczy), co album,
 * to SELECT głupieje. */
bool _hack;
};

#endif
