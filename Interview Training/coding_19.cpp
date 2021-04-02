/**
 *  Validate BST: Implement a function to check if a binary tree is a binary search tree. 
*/

#include <iostream>
#include <limits.h>

using namespace std;

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
        }
        else {
          aux = aux->getRight();
        }
      }
      BTNode *newNode = new BTNode(v);
      newNode->setDepth(aux->getDepth() + 1);
      if (aux->getLeft() == NULL) {
        aux->setLeft(newNode);
      }
      else {
        aux->setRight(newNode);
      }
    }
    else {
      root = new BTNode(v);
      root->setDepth(1);
    }
  }
  BTNode *getRoot() { return root; }

private:
  BTNode *root;
};

bool checkBSearch(BTNode* n, int last) {
  if (n) {
    if (!checkBSearch(n->getLeft(), last))
        return false;
    if (n->getValue() <= last)
        return false;
    last = n->getValue();
    return checkBSearch(n->getRight(), last);
  }
  return true;
}

int main() { 
  BinaryTree bt = BinaryTree();
  bt.insert(5);
  bt.insert(2);
  bt.insert(7);
  bt.insert(1);
  bt.insert(3);
  cout << checkBSearch(bt.getRoot(), INT_MIN) << "\n";
  return 0;
}