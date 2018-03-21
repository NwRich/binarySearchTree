#include "node.h"

node::node() {
  value = 0;
  right = NULL;
  left = NULL;
  prev = NULL;
}

node::~node() {
  prev = NULL;
  left = NULL;
  right = NULL;
  value = NULL;
}

void node::setValue(int newInt) {
  value = newInt;
}

int node::getValue() {
  return value;
}

node* node::getPrev() {
  return prev;
}

void node::setPrev(node* newNode) {
  prev = newNode;
}

node* node::getLeft() {
  return left;
}

void node::setLeft(node* newNode) {
  left = newNode;
}

node* node::getRight() {
  return right;
}

void node::setRight(node* newNode) {
  right = newNode;
}
