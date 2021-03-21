/**
 * Return Kth to Last: Implement an algorithm to find the kth to last element of
 * a singly linked list.
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

int len(LinkedList &list) {
  int _len = 0;
  Node *aux = list.getHead();
  while (aux != NULL) {
    _len++;
    aux = aux->getNext();
  }
  return _len;
}

int sol(LinkedList &list, int kth) {
  Node *aux = list.getHead();
  int _len = len(list);
  int i;
  for (i = 0; i < (_len - kth); i++)
    aux = aux->getNext();
  return aux->getValue();
}

int main() {
  int arr[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  LinkedList list = LinkedList();
  list.fill(arr, 10);
  list.printList();
  cout << sol(list, 2) << endl;
  list.clear();
  return 0;
}