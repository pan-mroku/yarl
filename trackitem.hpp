#ifndef TRACKITEM_HPP
#define TRACKITEM_HPP

#include <QtCore/QString>

#include "treeitem.hpp"
#include "track.hpp"

class TrackItem:public TreeItem, public Track
{
public:
  TrackItem(const Track& track);
  virtual QString QData() const;
protected:
};

#endif
