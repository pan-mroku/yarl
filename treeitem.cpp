#include "treeitem.hpp"
#include "treeitem-odb.hxx"
#include <typeinfo>

#include<iostream>

TreeItem::TreeItem(TreeItem* parent)
{
  Parent=parent;
}

/*TreeItem::TreeItem(const std::initializer_list<std::string>& data, TreeItem* parent)
  {
  for(const std::string& data_element:data)
  Data.push_back(new std::string(data_element));
  Parent=parent;
  if(Parent!=NULL)
  Parent->Children.push_back(const_cast<TreeItem*>(this));
  }*/

TreeItem::TreeItem(const TreeItem& other)
{
  for(TreeItem* child:Children)
    delete child;
  Children.clear();

  for(const TreeItem* otherChild:other.Children)
    {
      /*      TreeItem* newItem;
      switch(typeid(*otherChild))
        {
        case typeid(
        }*/
      Children.push_back(otherChild->Copy());
      Children.back()->Parent=this;
    }
}

TreeItem::~TreeItem()
{
  for(TreeItem* child:Children)
    delete child;
  Children.clear();
}

int TreeItem::Row() const
{
  if (Parent!=NULL)
    for(int i=0;i<Parent->Children.size();i++)
      if(Parent->Children[i]==this)
        return i;

  return 0;
}

QString TreeItem::QData() const
{
  return "PLACEHOLDER! From TreeItem class.";
}

bool TreeItem::Persist(odb::database& db) const
{
  for(const TreeItem* item:Children)
    if(!item->Persist(db))
      return false;

  try
    {
      db.persist(const_cast<TreeItem&>(*this));
    }
  catch(const std::exception& e)
    {
      std::cerr<<e.what()<<std::endl;
      return false;
    }

  return true;
}

TreeItem::ItemTypes TreeItem::ItemType() const
{
  return ItemTypes::BASE;
}

TreeItem& TreeItem::operator=(const TreeItem& other)
{
  for(TreeItem* child:Children)
    delete child;
  Children.clear();

  for(const TreeItem* otherChild:other.Children)
    {
      Children.push_back(otherChild->Copy());
      Children.back()->Parent=this;
    }
  return *this;
}

std::ostream& operator<<(std::ostream& out, const TreeItem& item)
{
  out<<item.QData().toStdString()<<std::endl;

  if(item.Children.size()>0)
    {
      out<<std::endl<<"--->"<<std::endl;
      for(const TreeItem* child : item.Children)
        out<<"\t"<<*child;
      out<<std::endl<<"<---"<<std::endl;
    }

  return out;
}

