/*
Author : Saurabh Singh 
Date : 11/10/2021
Description : C++ program to implement single linked list
*/
#include <bits/stdc++.h>

using namespace std;

//Structure of node
struct Node {
  int val;
  Node * next;
};

class LinkedList {
  Node * head; //pointer to head node

  public:
    LinkedList() {
      head = NULL; //intialiaze head as null i.e. empty list
    }

  bool search(int valToSearch) {
    Node * temp = head;
    //Traverse the list and see if val = valToSearch. If found return true else false
    while (temp != NULL) {
      if (temp -> val == valToSearch) {
        return true;
      }
      temp = temp -> next;
    }
    //Not found so far. Return false
    return false;
  }
  
  void insertAtBeginning(int val) {
    Node * newNode = new Node;
    newNode -> val = val;
    newNode -> next = NULL;

    //If head is null i.e. list is empty assign newNode as head
    if (head == NULL) {
      head = newNode;
    } else {
      //point next node of newNode to head and make newNode as head
      newNode -> next = head;
      head = newNode;
    }
  }

  void insertAtEnd(int val) {
    Node * newNode = new Node;
    newNode -> val = val;
    newNode -> next = NULL;

    //If head is null i.e. list is empty assign newNode as head
    if (head == NULL) {
      head = newNode;
    } else {
      Node * temp = head;
      //Loop till end of the list is reached
      while (temp -> next != NULL) {
        temp = temp -> next;
      }
      //Point temp -> next to newNode
      temp -> next = newNode;
    }
  }

  void displayList() {
    Node * temp = head;
    int i = 0;
    cout << "Displaying list: ";
    while (temp != NULL) {
      cout << temp -> val << " ";
      temp = temp -> next;
      ++i;
    }
    cout << "\nCurrent list size: " << i << endl;
  }

  void remove(int valToRemove) {
    cout << "Removing node with value: " << valToRemove << endl;
    // check if val is present in head
    if (head -> val == valToRemove) {
      Node * temp = head;
      head = head -> next;
      delete temp;
      cout << "Removed node with value: " << valToRemove << endl;
      return;
    }
    //traverse the list to find out the node with valToRemove
    Node * temp = head;
    while (temp -> next != NULL) {
      // if next node's data is to be deleted
      if (temp -> next -> val == valToRemove) {
        Node * nodeToRemove = temp -> next;
        temp -> next = nodeToRemove -> next;
        delete nodeToRemove;
        cout << "Removed node with value: " << valToRemove << endl;
        return;
      }
      temp = temp -> next;
    }
    //valToDelete not found
    cout << "Node with value to be deleted not found." << endl;
  }

};

int main() {
  LinkedList linkedList;
  linkedList.displayList();

  //Insert new node
  linkedList.insertAtBeginning(6);
  linkedList.insertAtEnd(8);
  linkedList.insertAtBeginning(4);
  linkedList.insertAtEnd(10);
  linkedList.insertAtEnd(11);
  //Display current list
  linkedList.displayList();

  linkedList.remove(10);
  linkedList.displayList();

  linkedList.remove(2);
  linkedList.displayList();

  linkedList.remove(11);
  linkedList.displayList();

  linkedList.remove(11);
  linkedList.displayList();

  //Search
  cout << "searching for 10. found? " << (linkedList.search(10) ? "Yes" : "No") << endl;
  cout << "searching for 5. found? " << (linkedList.search(5) ? "Yes" : "No") << endl;
  linkedList.insertAtBeginning(1);

  //Display current list
  linkedList.displayList();
  return 0;
}
