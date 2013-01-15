#include "cditem.hpp"
#include "trackitem.hpp"


CDItem::CDItem(const CD& cd):AlbumItem(cd)
{
  for(const Track* track:cd.Tracks)
    Children.push_back(new TrackItem(*track));
}
