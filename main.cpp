/*Nicholas Rich
 *3/5/18
 *a program that creates a max heap from a user input or from a file and then prints it out
 *(with help from Trevor Horine)
 */
#include <iostream>
#include <ctype.h>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include "node.h"
using namespace std;
node* heap[100];
node* head = new node();
void add(int toAdd, node* current);
void remove(int toRemove, node* current);
void print(node* current, int depth);

int main() {
  char* input = new char[32];//used to get the input from the user
  cout << "type in numbers, when you are done type in 'end' or if you want to remove a number type in remove" << endl;//give the user instructions
  for (int i = 0; i < 100; i++) {//go through the length of the array
    cin >> input;//write to input
    cin.get();
    if (strcmp(input, "end") == 0) {//if the input is "end"
      break;
    }
    else if (strcmp(input , "remove") == 0) {
      cout << "what number do you want to remove?" << endl;
      int in = 0;
      cin >> in;
      remove(in, head);
    }
    else {//otherwise the input is not a number
      int in = atoi(input);
      add(in, head);
    }
  }
  print(head, 0);
  return 0;
}

void add(int toAdd, node* current) {
  if (head->getValue() == 0) {
    head->setValue(toAdd);
    }
  else if (toAdd >= current->getValue()) {
    if (current->getRight() != NULL) {
      add(toAdd,current->getRight());
    }
    if(current->getRight() == NULL) {
      node* newNode = new node();
      newNode->setValue(toAdd);
      current->setRight(newNode);
    }
  }
  else {
    if (current->getLeft() != NULL) {
      add(toAdd, current->getLeft()); 
    }
    if (current->getLeft() == NULL) {
      node* newNode = new node();
      newNode->setValue(toAdd);
      current->setLeft(newNode);
    }
  }
}

void remove(int toRemove, node* current) {
  if (current->getRight() == NULL && current->getLeft() == NULL && current->getValue() == toRemove) {
    delete current;
  }
  else if (current->getRight() != NULL && current->getValue() == toRemove) {
    int temp = current->getRight()->getValue();
    current->setValue(temp);
    delete current->getRight();
    current->setRight(NULL);
  }
  else if (current->getRight() == NULL && current->getLeft() != NULL && current->getValue() == toRemove) {
    int temp = current->getLeft()->getValue();
    current->setValue(temp);
    delete current->getLeft();
    current->setLeft(NULL);
  }
  else if (toRemove >= current->getValue()) {
    add(toRemove, current->getRight());
  }
  else if (toRemove < current->getValue())  {
    add(toRemove, current->getLeft());
  }
}

void print(node* current, int depth) {
  if (current->getRight() != NULL) {//if right is not empty
    print(current->getRight(), depth+1);//go to the end of the tree right bound
  }
  int tab = depth;//keep track of the depth
  for (tab; tab > 0; tab--) {//print out the proper amount of tabs
    cout << "\t";
  }
  cout << current->getValue() << endl;//print out the value
  if (current->getLeft() != NULL) {//if the left is not empty
    print(current->getLeft(), depth+1);//call the print passing in the left
  }
}

