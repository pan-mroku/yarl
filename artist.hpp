#ifndef ARTIST_HPP
#define ARTIST_HPP

#include <QtGui/QStandardItem>
#include <QtCore/QString>

#include <odb/core.hxx>

#pragma db object
class Artist:public QStandardItem
{
private:
  friend class odb::access;
  Artist(){};

#pragma db id auto
  int id;

  QString name;

public:
  Artist(const QString& Name);

  const QString& Name() const;

};

#endif
