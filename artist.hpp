#ifndef ARTIST_HPP
#define ARTIST_HPP

#include <ostream>
#include <string>
#include <vector>

#include <odb/core.hxx>
#include<odb/database.hxx>

#include "album.hpp"

#pragma db object
class Artist
{
public:
#pragma db unique
  std::string Name;

#pragma db value_not_null
  std::vector<Album*> Albums;

  Artist(const std::string& name);
  Artist(const Artist& other);
  ~Artist();

  bool Persist(odb::database& db) const;

protected:
#pragma db id auto
    int id;

  friend class odb::access; //ODB
  Artist(){};

private:
};

#endif
