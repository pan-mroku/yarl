#include "cd.hpp"
#include "cd-odb.hxx"
#include <exception>
#include <iostream>

CD::CD(const int year, const std::string& title):Album(year,title)
{
}

CD::CD(const CD& other):Album(other)
{
  for(const Track* track:other.Tracks)
    Tracks.push_back(new Track(*track));
}

CD::~CD()
{
  for(Track* track:Tracks)
    delete track;
  Tracks.clear();
}

void CD::AddTrack(const std::string& title, const int duration, const int index)
{
  Tracks.push_back(new Track(Tracks.size()+1, title, duration));
}

Album::Types CD::Type() const
{
  return Album::Types::cd;
}

bool CD::Persist(odb::database& db) const
{
  for(const Track* track:Tracks)
    if(!track->Persist(db))
      return false;

  try
    {

      db.persist(const_cast<CD&>(*this));
    }
  catch(const std::exception& e)
    {
      std::cerr<<e.what()<<std::endl;
      return false;
    }

  return true;
}
