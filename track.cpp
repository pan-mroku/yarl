#include "track.hpp"

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
