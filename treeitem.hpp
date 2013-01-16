#ifndef TREEITEM_HPP
#define TREEITEM_HPP

#include <QtCore/QString>
#include <QtCore/QList>

#include<ostream>
#include <odb/core.hxx>
#include <odb/database.hxx>

#pragma db object polymorphic pointer(*)
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
  //TreeItem(const std::initializer_list<std::string>& data, TreeItem* parent=NULL);
  virtual ~TreeItem();

  int Row() const;

  virtual QString QData() const;
  virtual bool Persist(odb::database& db) const;
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
