#ifndef TRACK_HPP
#define TRACK_HPP

#include <string>

#include <odb/core.hxx>
#include<odb/database.hxx>

#pragma db object
class Track
{
public:
  int Number;
  std::string Title;
  int DurationSeconds;

  Track(const int number, const std::string& title, const int duration);
  bool Persist(odb::database& db) const;
  
protected:
  friend class odb::access;
  Track(){};

#pragma db id auto
  int id;
private:
};

#endif
