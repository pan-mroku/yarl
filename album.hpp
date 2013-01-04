#ifndef ALBUM_HPP
#define ALBUM_HPP

#include <list>
#include <ostream>

#include <QtGui/QStandardItem>
#include <QtCore/QString>

#include <odb/core.hxx>

#include "artist.hpp"

#pragma db object
class Album:public QStandardItem
{
public:
  QString Title;
#pragma db value_not_null
std::list<QSharedPointer<Artist>> Authors;

Album(const QString& title, const QSharedPointer<Artist>& author);
Album(const QString& title, const std::initializer_list<QSharedPointer<Artist>>& authors); 

friend std::ostream& operator<<(std::ostream& out, const QSharedPointer<Album>& album);
private:
  friend class odb::access;
  Album(){};

#pragma db unique id auto
  int id;
};

#endif
