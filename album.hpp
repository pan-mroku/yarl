#ifndef ALBUM_HPP
#define ALBUM_HPP

#include <list>
#include <ostream>

//#include <QtGui/QStandardItem>
#include <QtCore/QString>

#include <odb/core.hxx>

#include "artist.hpp"

#pragma db object
class Album
{
public:
  QString Title;
#pragma db value_not_null
  std::list<QSharedPointer<Artist>> Authors;

  Album(const QString& title, const QSharedPointer<Artist>& author);
  Album(const QString& title, const std::initializer_list<QSharedPointer<Artist>>& authors); 

  friend std::ostream& operator<<(std::ostream& out, const Album& album);
protected:
#pragma db id auto
  int id;

private:
  friend class odb::access;
  Album(){};
};

#endif
