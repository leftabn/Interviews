/**
 * Remove Dups! Write code to remove duplicates from an unsorted linked list.
 * FOLLOW UP
 * How would you solve this problem if a temporary buffer is not allowed?
 * O(N^2), NO BUFFER
 */

#include <iostream>

using namespace std;

class Node {
public:
  Node() {
    value = 0;
    next = NULL;
  }
  Node(int v) {
    value = v;
    next = NULL;
  }
  Node *getNext() { return next; }
  int getValue() { return value; }
  void setValue(int v) { value = v; }
  void setNext(Node *n) { next = n; }

private:
  int value;
  Node *next;
};

class LinkedList {
public:
  LinkedList() {
    head = NULL;
    lastElement = head;
  }
  Node *getHead() { return head; }
  Node *getLast() { return lastElement; }
  void setHead(Node *h) { head = h; }
  void insert(Node *n) {
    if (head == NULL) {
      head = n;
      lastElement = head;
    } else {
      lastElement->setNext(n);
      lastElement = lastElement->getNext();
    }
  }
  void fill(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
      insert(new Node(arr[i]));
    }
  }
  void clear() {
    while (head != NULL) {
      Node *tmp = head;
      head = head->getNext();
      delete tmp;
    }
  }
  bool isEmpty() { return (head == NULL); }
  void printList() {
    Node *it = head;
    cout << "[";
    while (it != NULL) {
      cout << it->getValue();
      if (it->getNext())
        cout << ", ";
      it = it->getNext();
    }
    cout << "]\n";
  }

private:
  Node *head;
  Node *lastElement;
};

void removeDups(LinkedList &list) {
  Node *ptr1 = list.getHead();

  while (ptr1 != NULL) {
    Node *ptr2 = ptr1;
    while (ptr2->getNext() != NULL) {
      if (ptr1->getValue() == ptr2->getNext()->getValue()) {
        Node *tmp = ptr2->getNext();
        ptr2->setNext(ptr2->getNext()->getNext());
        delete tmp;
      } else
        ptr2 = ptr2->getNext();
    }
    ptr1 = ptr1->getNext();
  }
  return;
}

int main() {
  int arr[] = {5, 1, 1, 8, 9, 5, 7, 1};
  LinkedList list = LinkedList();
  list.fill(arr, 8);
  list.printList();
  removeDups(list);
  list.printList();
  list.clear();
  return 0;
}