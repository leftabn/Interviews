/**
 * Given a binary tree, design an algorithm which creates a linked list of all
 * the nodes at each depth (e.g., if you have a tree with depth D, you'll have D
 * linked lists).
 */

#include <iostream>
#include <map>

using namespace std;

class LLNode {
public:
  LLNode() {
    value = 0;
    next = NULL;
  }
  LLNode(int v) {
    value = v;
    next = NULL;
  }
  LLNode *getNext() { return next; }
  int getValue() { return value; }
  void setValue(int v) { value = v; }
  void setNext(LLNode *n) { next = n; }

private:
  int value;
  LLNode *next;
};

class LinkedList {
public:
  LinkedList() {
    head = NULL;
    lastElement = head;
  }
  LLNode *getHead() { return head; }
  LLNode *getLast() { return lastElement; }
  void setHead(LLNode *h) { head = h; }
  void insert(LLNode *n) {
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
      insert(new LLNode(arr[i]));
    }
  }
  void clear() {
    while (head != NULL) {
      LLNode *tmp = head;
      head = head->getNext();
      delete tmp;
    }
  }
  bool isEmpty() { return (head == NULL); }
  void printList() {
    LLNode *it = head;
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
  LLNode *head;
  LLNode *lastElement;
};

class BTNode {
public:
  BTNode() {
    value = 0;
    depth = 0;
    right = NULL;
    left = NULL;
  }
  BTNode(int v) {
    value = v;
    depth = 0;
    right = NULL;
    left = NULL;
  }
  BTNode *getRight() { return right; }
  BTNode *getLeft() { return left; }
  int getValue() { return value; }
  int getDepth() { return depth; }
  void setValue(int v) { value = v; }
  void setRight(BTNode *n) { right = n; }
  void setLeft(BTNode *n) { left = n; }
  void setDepth(int v) { depth = v; }

private:
  int value;
  int depth;
  BTNode *right;
  BTNode *left;
};

class BinaryTree {
public:
  BinaryTree() { root = NULL; };
  void insert(int v) {
    if (root != NULL) {
      BTNode *aux = root;
      while (aux->getLeft() != NULL && aux->getRight() != NULL) {
        if (aux->getRight()) {
          aux = aux->getLeft();
        } else {
          aux = aux->getRight();
        }
      }
      BTNode *newNode = new BTNode(v);
      newNode->setDepth(aux->getDepth() + 1);
      if (aux->getLeft() == NULL) {
        aux->setLeft(newNode);
      } else {
        aux->setRight(newNode);
      }
    } else {
      root = new BTNode(v);
      root->setDepth(1);
    }
  }
  BTNode *getRoot() { return root; }

private:
  BTNode *root;
};

map<int, LinkedList> ans;

void walkTree(BTNode *node) {
  if (node != NULL) {
    ans[node->getDepth()].insert(new LLNode(node->getValue()));
    if (node->getLeft() != NULL) {
      walkTree(node->getLeft());
    }
    if (node->getRight() != NULL) {
      walkTree(node->getRight());
    }
  }
}

int main() {
  ans = map<int, LinkedList>(); // empty map
  BinaryTree bt = BinaryTree();
  bt.insert(5);
  bt.insert(2);
  bt.insert(7);
  bt.insert(15);
  bt.insert(11);
  walkTree(bt.getRoot());
  map<int, LinkedList>::iterator it;
  for (it = ans.begin(); it != ans.end(); it++) {
    it->second.printList();
  }
  return 0;
}