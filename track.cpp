#include "track.hpp"
#include "track-odb.hxx"
#include <exception>
#include <iostream>

Track::Track(const int number, const QString& title, const int duration):Number(number), Title(title), DurationSeconds(duration)
{
  
}

TreeItem::ItemTypes Track::ItemType() const
{
  return ItemTypes::track;
}

TreeItem* Track::Copy() const
{
  return new Track(*this);
}

QString Track::QData() const
{
  return QString::number(Number)+" "+Title+" "+QString::number(DurationSeconds/60.0);
}

/*bool Track::Persist(odb::database& db) const
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
*/
