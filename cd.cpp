#include "cd.hpp"
#include "cd-odb.hxx"
#include <exception>
#include <iostream>

CD::CD(const int year, const QString& title):Album(year,title)
{
  Tracks=&Children;
}

CD::CD(const CD& other):Album(other)
{
  for(const TreeItem* item:other.Children)
    {
      if(item->ItemType()==ItemTypes::track)
        {
          Children.push_back(new Track(dynamic_cast<const Track&>(*item)));
          Children.back()->Parent=this;
        }
    }
      Tracks=&Children;
}

TreeItem* CD::Copy() const
{
  return new CD(*this);
}

/*CD::~CD()
{
  for(Track* track:Tracks)
    delete track;
  Tracks.clear();
  }*/

void CD::AddTrack(const QString& title, const int duration, const int index)
{
  Children.push_back(new Track(Children.size()+1, title, duration));
}

Album::Types CD::AlbumType() const
{
  return Album::Types::cd;
}

/*bool CD::Persist(odb::database& db) const
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
*/
