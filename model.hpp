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

class Model:public QAbstractItemModel
{
public:
  TreeItem* Root;

  QString DatabaseFilename;

  Model(const QString& filename="yarl.db");
  ~Model();

  QModelIndex index ( int row, int column, const QModelIndex & parent = QModelIndex() ) const;
  QModelIndex parent ( const QModelIndex & index ) const;
  int rowCount ( const QModelIndex & parent = QModelIndex() ) const;
  int columnCount ( const QModelIndex & parent = QModelIndex() ) const;
  QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
  void Erase(const QModelIndex& index);
  void AddArtist(Artist* artist);


  friend std::ostream& operator<<(std::ostream& out, const Model& model);

  void NewDatabase(const QString& filename="");
  void LoadDatabase(const QString& filename="");

protected:
private:
};

#endif
