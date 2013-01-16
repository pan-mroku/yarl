#ifndef TRACK_HPP
#define TRACK_HPP

#include <QtCore/QString>

#include <odb/core.hxx>

#include "treeitem.hpp"

#pragma db object pointer(*)
class Track:public TreeItem
{
public:
  int Number;
  QString Title;
  int DurationSeconds;

  Track(const int number, const QString& title, const int duration);
  virtual ItemTypes ItemType() const;
  virtual QString QData() const;
  virtual TreeItem* Copy() const;
  
protected:
  friend class odb::access;
  Track(){};

private:
};

#endif
