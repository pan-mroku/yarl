#ifndef TREEITEM_HPP
#define TREEITEM_HPP

#include<vector>
#include<string>

#include<ostream>

class TreeItem
{
public:
  std::vector<TreeItem*> Children;
  TreeItem* Parent;

  std::vector<std::string*> Data; //wskaźnik, żeby umożliwić łączenie

  TreeItem(TreeItem* parent=NULL);
  TreeItem(const std::initializer_list<std::string>& data, TreeItem* parent=NULL);
  virtual ~TreeItem();
  
  /*  virtual int RecreateChildren()=0;
  virtual int RecreateData()=0;*/

  friend std::ostream& operator<<(std::ostream& out, const TreeItem& item); //COUT

protected:
private:
};

#endif
