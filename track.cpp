#include "track.hpp"
#include <QTime>

Track::Track(const int number, const QString& title, const int duration):Number(number), Title(title), DurationSeconds(duration), TreeItem()
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
  QTime zeroTime(0,0);
  return QString::number(Number)+" "+Title+" "+zeroTime.addSecs(DurationSeconds).toString("mm:ss");
}
