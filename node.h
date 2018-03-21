#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

class node {
 public:
  node();
  ~node();
  void setValue(int newInt);
  int getValue();
  void setPrev(node* newNode);
  node* getPrev();
  void setLeft(node*newNode);
  node* getLeft();
  void setRight(node* newNode);
  node* getRight();
 private:
  int value;
  node* prev;
  node* left;
  node* right;
};
#endif
