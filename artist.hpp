#ifndef ARTIST_HPP
#define ARTIST_HPP

#include <ostream>

#include <QtGui/QStandardItem>
#include <QtCore/QString>

#include <odb/core.hxx>

#pragma db object
class Artist:public QStandardItem
{
public:
  QString Name;

  Artist(const QString& name);

  friend std::ostream& operator<<(std::ostream& out, const Artist& artist);
private:
  friend class odb::access;
  Artist(){};

#pragma db unique id auto
  int id;
};

#endif
