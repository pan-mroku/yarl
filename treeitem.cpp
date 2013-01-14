#include "treeitem.hpp"

#include<iostream>

TreeItem::TreeItem(TreeItem* parent)
{
  Parent=parent;
  if(Parent!=NULL)
    Parent->Children.push_back(const_cast<TreeItem*>(this));
}

TreeItem::TreeItem(const std::initializer_list<std::string>& data, TreeItem* parent)
{
  for(const std::string& data_element:data)
    Data.push_back(new std::string(data_element));
  Parent=parent;
  if(Parent!=NULL)
    Parent->Children.push_back(const_cast<TreeItem*>(this));
}

TreeItem::~TreeItem()
{
  for(TreeItem* child:Children)
    delete child;
  Children.clear();

  /*  for(std::string* data_element:Data)
      delete data_element;*/
  Data.clear();
}

std::ostream& operator<<(std::ostream& out, const TreeItem& item)
{
  for (const std::string* data:item.Data)
    out<<*data<<std::endl;

  if(item.Children.size()>0)
    {
      out<<"--->"<<std::endl;
      for(const TreeItem* child : item.Children)
        out<<"\t"<<*child;
      out<<"<---";
    }

  return out;
}
