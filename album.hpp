#ifndef ALBUM_HPP
#define ALBUM_HPP

#include <vector>
#include <ostream>
#include <string>

#include <odb/core.hxx>
#include<odb/database.hxx>

#pragma db object polymorphic
class Album
{
public:

  enum Types
    {
      base=0,
      cd=1,
      mc=2
    };

  int Year;
  std::string Title;

  Album(const int year, const std::string& title);
  Album(const Album& other);
  virtual ~Album();

  virtual void AddTrack(const std::string& title, const int duration, const int index=0)=0;
  virtual Types Type() const;
  virtual bool Persist(odb::database& db) const=0;

protected:

  friend class odb::access;
  Album(){};
#pragma db id auto
  int id;

private:
  
};

#endif
