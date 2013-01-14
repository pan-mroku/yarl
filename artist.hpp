#ifndef ARTIST_HPP
#define ARTIST_HPP

#include <ostream>
#include <string>
#include <vector>

#include <odb/core.hxx>

#pragma db object
class Artist
{
public:
#pragma db unique
  std::string Name;

  //QList<Album*> Albums;

  Artist(const std::string& name);

  //friend std::ostream& operator<<(std::ostream& out, const Artist& artist);
protected:
#pragma db id auto
    int id;

  friend class odb::access; //ODB
  Artist(){};

private:
};

#endif
