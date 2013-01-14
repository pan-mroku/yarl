#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <vector>
#include <string>
#include<ostream>

#include<odb/core.hxx>

#include "artist.hpp"

#pragma db object
class Library
{
public:
  std::string Name;

#pragma db value_not_null unordered
  std::vector<Artist*> Artists;

  Library(std::string name="");
  Library(const Library& library);
  ~Library();

  //friend std::ostream& operator<<(std::ostream& out, const Library& library);
protected:
  friend class odb::access;
#pragma db id auto
  int id;

private:
};

#endif
