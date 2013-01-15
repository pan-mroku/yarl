#include "trackitem.hpp"

TrackItem::TrackItem(const Track& track):Track(track)
{
}

QString TrackItem::QData() const
{
  return (QString::number(Number)+" "+QString::fromStdString(Title)+" "+QString::number(DurationSeconds/60.0));
}
