#ifndef ALBUM_HPP
#define ALBUM_HPP

#include <vector>
#include <ostream>
#include <string>

#include <odb/core.hxx>

#pragma db object
class Album
{
public:
  int Year;
  std::string Title;

  Album(const int year, const std::string& title);
  Album(const Album& other);

protected:
#pragma db id auto
  int id;

  friend class odb::access;
  Album(){};

private:
};

#endif
