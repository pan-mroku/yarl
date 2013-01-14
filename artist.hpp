#ifndef ARTIST_HPP
#define ARTIST_HPP

#include <ostream>
#include <string>
#include <vector>

#include <odb/core.hxx>

#include "album.hpp"

#pragma db object
class Artist
{
public:
#pragma db unique
  std::string Name;

#pragma db value_not_null unordered
  std::vector<Album*> Albums;

  Artist(const std::string& name);
  Artist(const Artist& other);
  ~Artist();

  //friend std::ostream& operator<<(std::ostream& out, const Artist& artist);
protected:
#pragma db id auto
    int id;

  friend class odb::access; //ODB
  Artist(){};

private:
};

#endif
