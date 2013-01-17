#ifndef TREEITEM_HPP
#define TREEITEM_HPP

#include <QtCore/QString>
#include <QtCore/QList>

#include<ostream>
#include <odb/core.hxx>
#include <odb/database.hxx>

#pragma db object no_id polymorphic pointer(*)
class TreeItem
{
public:
  enum ItemTypes
    {
      BASE=0, library, artist, album, track
    };

  QList<TreeItem*> Children;
  
  //Wyświetlanie w QT zależy od parenta
  TreeItem* Parent; 

  TreeItem(TreeItem* parent=NULL);
  TreeItem(const TreeItem& other);
  virtual TreeItem* Copy() const=0;
  virtual ~TreeItem();

  int Row() const;

  virtual QString QData() const;
  virtual bool Persist(odb::database& db);
  virtual void Erase(odb::database& db);
  virtual void Update(odb::database& db);

  virtual ItemTypes ItemType() const;

  TreeItem& operator=(const TreeItem& other);
  
  friend std::ostream& operator<<(std::ostream& out, const TreeItem& item); //COUT

protected:
  friend class odb::access;
#pragma db id auto
  unsigned int id;

private:
};

#endif
