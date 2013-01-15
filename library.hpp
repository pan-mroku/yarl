#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <vector>
#include <string>
#include<ostream>

#include<odb/core.hxx>
#include<odb/database.hxx>

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

  bool Persist(odb::database& db) const;

protected:
  friend class odb::access;
#pragma db id auto
  int id;

private:
};

#endif
