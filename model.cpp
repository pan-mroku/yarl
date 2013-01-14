#include "model.hpp"
#include <iostream>

Model::Model(const QString& filename):DatabaseFilename(filename)
{
  // odb::sqlite::database db(DatabaseFilename.toStdString(), SQLITE_OPEN_READWRITE|SQLITE_OPEN_CREATE);
  //root=QSharedPointer<TreeItem>(new TreeItem());
  LoadDatabase();
  //odb::result<Artist> r (db.query<Artist>(odb::query<Artist>::Name=="asd"));

  //for(Artist a:r)
}

Model::~Model()
{
  delete Root;
}

void Model::NewDatabase(QString filename)
{


}

void Model::LoadDatabase(const QString& filename)
{
  if(filename!="")
    DatabaseFilename=filename;
  odb::sqlite::database db(DatabaseFilename.toStdString(), SQLITE_OPEN_READWRITE|SQLITE_OPEN_CREATE);
  odb::core::transaction t (db.begin ());

  if(Root!=NULL)
    delete Root;

  {
    odb::result<Library> r (db.query<Library>());

    for(Library library:r)
        Root=new RootItem(library);
  }
  /*  Root.RecreateChildren();
  Root.RecreateData();*/
}

QModelIndex Model::index(int row, int column, const QModelIndex& parent) const
{
  if (!hasIndex(row, column, parent))
         return QModelIndex();

     TreeItem *parentItem;

     if (!parent.isValid())
       parentItem = const_cast<RootItem*>(Root);
     else
         parentItem = static_cast<TreeItem*>(parent.internalPointer());

     TreeItem *childItem = parentItem->Children[row];
     if (childItem)
         return createIndex(row, column, childItem);
     else
         return QModelIndex();
}

QModelIndex Model::parent(const QModelIndex& index) const
{
}

int Model::rowCount(const QModelIndex& parent) const
{
}

int Model::columnCount(const QModelIndex& parent) const
{
}

QVariant Model::data(const QModelIndex& index, int role) const
{
}

std::ostream& operator<<(std::ostream& out, const Model& model)
{
  out<<*model.Root<<std::endl;
  return out;
}
