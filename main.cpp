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
  cout << "or type in file to input from a file" << endl;//promt the user for input
  cin >> input;
  cin.get();
  if (strcmp(input, "file") == 0) {//if the input is file
    ifstream inFile;//create a file
    cout << "what is the name of the file" << endl;//promt the user for input
    cin >> input;//write to input
    inFile.open(input);//open the file
    char inputFile[500];//create an array to hold the input from the file
    inFile.getline(inputFile, 500);//write to inputFile
    inFile.close();//close the file
    char* c = strtok(inputFile, " ");//seperate based on spaces
    while (c != NULL) {//while c is not empty
      add(atoi(c), head);//pass in head and stuff
      c = strtok(NULL, " ");
    }
  }
  else {
    for (int i = 0; i < 100; i++) {//go through the length of the input
      cin >> input;//write to input
      cin.get();
      if (strcmp(input, "end") == 0) {//if the input is "end"
	break;
      }
      else if (strcmp(input , "remove") == 0) {
	cout << "what number do you want to remove?" << endl;//promt the user for an input
	print(head, 0);//show the tree
	int in = 0;//used to hold to number to delete
	cin >> in;//write to the input
	remove(in, head);//call remove
	cout << endl << endl;//create some space
	print(head,0);//show the tree after removal
      }
      else {//otherwise the input is a number
	int in = atoi(input);//cast the char to a number
	add(in, head);//add it
      }
    }
  }
  print(head, 0);//print out the tree
  return 0;//end
}

void add(int toAdd, node* current) {//used to add numbers to the tree
  if (head->getValue() == 0) {//if the head is empty
    head->setValue(toAdd);//set the value of head as toAdd
    }
  else if (toAdd >= current->getValue()) {//otherwise if the number is greater than current
    if (current->getRight() != NULL) {//and the spot to the right is not null
      add(toAdd,current->getRight());//call add recursivley moving to the right
    }
    if(current->getRight() == NULL) {//if the right node is null
      node* newNode = new node();//create a new node
      newNode->setValue(toAdd);//set the value of the new node to the number
      current->setRight(newNode);//set the currents right to the new node
    }
  }
  else {//otherwise the number is smaller
    if (current->getLeft() != NULL) {//if left is not null
      add(toAdd, current->getLeft());//go to the left of current
    }
    if (current->getLeft() == NULL) {//if the left of current is null
      node* newNode = new node();//create a new node
      newNode->setValue(toAdd);//set the value of the node to the number
      current->setLeft(newNode);//set currents left to the new number
    }
  }
}

void remove(int toRemove, node* current) {//used to remove nodes from the tree
  if (current->getRight() == NULL && current->getLeft() == NULL && current->getValue() == toRemove) {//if the node has no children and is the value you want to remove
    delete current;//delete the node
  }
  else if (current->getRight() != NULL && current->getValue() == toRemove) {//if there is a right child and is the number to remove
    int temp = current->getRight()->getValue();//create a temp variable of the right
    current->setValue(temp);//set currents value to temp
    delete current->getRight();//delete the node on the right
    current->setRight(NULL);//set the right to null
  }
  else if (current->getRight() == NULL && current->getLeft() != NULL && current->getValue() == toRemove) {//otherwise of the left isn't empty and the right is
    int temp = current->getLeft()->getValue();//create a temp variable
    current->setValue(temp);//set current to temp
    delete current->getLeft();//delete the left
    current->setLeft(NULL);//set the left to null
  }
  else if (toRemove >= current->getValue()) {//otherwise if the number to remove is greater than current
    remove(toRemove, current->getRight());//call remove with the right node
  }
  else if (toRemove < current->getValue()) {//otherwise if the number is less than current
    remove(toRemove, current->getLeft());//calll remove passing in the left node
  }
}

void print(node* current, int depth) {
  if (current->getRight() != NULL && (current->getRight()->getValue() != 0)) {//if right is not empty
    print(current->getRight(), depth+1);//go to the end of the tree right bound
  }
  int tab = depth;//keep track of the depth
  for (tab; tab > 0; tab--) {//print out the proper amount of tabs
    cout << "\t";
  }
  cout << current->getValue() << endl;//print out the value
  if (current->getLeft() != NULL && (current->getLeft()->getValue() != 0)) {//if the left is not empty
    print(current->getLeft(), depth+1);//call the print passing in the left
  }
}
