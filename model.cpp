#include "model.hpp"
#include <iostream>
#include <QString>

Model::Model(const QString& filename):DatabaseFilename(filename)
{
  Root=new Library();
}

Model::~Model()
{
  delete Root;
}

void Model::NewDatabase(const QString& filename)
{
  if(filename!="")
    DatabaseFilename=QString(filename);
  odb::sqlite::database db(DatabaseFilename.toStdString(), SQLITE_OPEN_READWRITE|SQLITE_OPEN_CREATE);
  odb::core::transaction t (db.begin ());
  odb::schema_catalog::create_schema (db);
  Root->Persist(db);
  t.commit();
}

void Model::LoadDatabase(const QString& filename)
{
  if(filename!="")
    DatabaseFilename=QString(filename);

  odb::sqlite::database db(DatabaseFilename.toStdString(), SQLITE_OPEN_READWRITE|SQLITE_OPEN_CREATE);
  odb::core::transaction t (db.begin ());

  if(Root!=NULL)
    delete Root;

  odb::result<Library> r (db.query<Library>());

 //ograniczam się do jednej bazy
  Root=r.begin()->Copy();

  //std::cout<<*Root<<std::endl;
}

QModelIndex Model::index(int row, int column, const QModelIndex& parent) const
{
  if (!hasIndex(row, column, parent))
    return QModelIndex();

  TreeItem* parentItem;

  if (!parent.isValid())
    parentItem = const_cast<TreeItem*>(Root);
  else
    parentItem = static_cast<TreeItem*>(parent.internalPointer());

  TreeItem* childItem = parentItem->Children[row];
  if (childItem)
    return createIndex(row, column, childItem);
  else
    return QModelIndex();
}

QModelIndex Model::parent(const QModelIndex& index) const
{
  if (!index.isValid())
    return QModelIndex();

  TreeItem* childItem = static_cast<TreeItem*>(index.internalPointer());
  TreeItem* parentItem = childItem->Parent;

  if (parentItem == NULL|| parentItem==Root)
    return QModelIndex();

  return createIndex(parentItem->Row(), 0, parentItem);
}

int Model::rowCount(const QModelIndex& parent) const
{
  TreeItem *parentItem;
  if (parent.column() > 0)
    return 0;

  if (!parent.isValid())
    parentItem = Root;
  else
    parentItem = static_cast<TreeItem*>(parent.internalPointer());

  return parentItem->Children.size();
}

int Model::columnCount(const QModelIndex& parent) const
{
  /*  if (parent.isValid())
    return static_cast<TreeItem*>(parent.internalPointer())->Data.size();
  else
  return Root->Data.size();*/
  return 1;

}

QVariant Model::data(const QModelIndex& index, int role) const
{
  //std::cout<<index.column()<<" "<<index.row()<<std::endl;
  if (!index.isValid())
    return QVariant();

  if (role != Qt::DisplayRole)
    return QVariant();

  TreeItem *item = static_cast<TreeItem*>(index.internalPointer());

  return item->QData();
}

std::ostream& operator<<(std::ostream& out, const Model& model)
{
  out<<*model.Root<<std::endl;
  return out;
}
