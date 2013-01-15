#include "track.hpp"
#include "track-odb.hxx"
#include <exception>
#include <iostream>

Track::Track(const int number, const std::string& title, const int duration):Number(number), Title(title), DurationSeconds(duration)
{

}

bool Track::Persist(odb::database& db) const
{
  try
    {
      db.persist(const_cast<Track&>(*this));
    }
  catch(const std::exception& e)
    {
      std::cerr<<e.what()<<std::endl;
      return false;
    }
  return true;
}
