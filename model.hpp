#ifndef MODEL_HPP
#define MODEL_HPP

#include <ostream>

#include <QtCore/QAbstractItemModel>
#include <QtCore/QString>
#include <QtCore/QList>

#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/sqlite/database.hxx>

#include "library.hpp"
#include "library-odb.hxx"
#include "treeitem.hpp"
#include "treeitem-odb.hxx"
//#include "artist.hpp"
//#include "artist-odb.hxx"
//#include "album.hpp"
//#include "album-odb.hxx"

//#include "rootitem.hpp"

class Model:public QAbstractItemModel
{
public:
  TreeItem* Root;

  //QList<Artist*> Artists;
  //QList<QSharedPointer<Album>> Albums
  QString DatabaseFilename;
  //std::list<QSharedPointer<Artist>> Artists; //utwór

  Model(const QString& filename="test.db");
  ~Model();

  void NewDatabase(QString filename="");
  void LoadDatabase(const QString& filename="");


  QModelIndex index ( int row, int column, const QModelIndex & parent = QModelIndex() ) const;
  QModelIndex parent ( const QModelIndex & index ) const;
  int rowCount ( const QModelIndex & parent = QModelIndex() ) const;
  int columnCount ( const QModelIndex & parent = QModelIndex() ) const;
  QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;


  friend std::ostream& operator<<(std::ostream& out, const Model& model);
protected:
private:
};

#endif
