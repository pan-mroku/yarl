#include "cd.hpp"

CD::CD(const int year, const QString& title):Album(year,title)
{
  Tracks=&Children;
}

CD::CD(const CD& other):Album(other)
{
  for(const TreeItem* item:other.Children)
    {
      Children.push_back(item->Copy());
      Children.back()->Parent=this;
    }
      Tracks=&Children;
}

TreeItem* CD::Copy() const
{
  return new CD(*this);
}

void CD::AddTrack(const QString& title, const int duration, const int index)
{
  Children.push_back(new Track(Children.size()+1, title, duration));
}

Album::Types CD::AlbumType() const
{
  return Album::Types::cd;
}
