/**
 * Check Balanced: Implement a function to check if a binary tree is balanced.
 * For the purposes of this question, a balanced tree is defined to be a tree
 * such that the heights of the two subtrees of any node never differ by more
 * than one.
 */

#include <iostream>

using namespace std;

int _max(int a, int b) { return a > b ? a : b; }

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
  BTNode* getRight() { return right; }
  BTNode* getLeft() { return left; }
  int getValue() { return value; }
  int getDepth() { return depth; }
  void setValue(int v) { value = v; }
  void setRight(BTNode* n) { right = n; }
  void setLeft(BTNode* n) { left = n; }
  void setDepth(int v) { depth = v; }

private:
  int value;
  int depth;
  BTNode* right;
  BTNode* left;
};

class BinaryTree {
public:
  BinaryTree() { root = NULL; };
  void insert(int v) {
    if (root != NULL) {
      BTNode* aux = root;
      while (aux->getLeft() != NULL && aux->getRight() != NULL) {
        if (aux->getRight()) {
          aux = aux->getLeft();
        }
        else {
          aux = aux->getRight();
        }
      }
      BTNode* newNode = new BTNode(v);
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
  BTNode* getRoot() { return root; }

private:
  BTNode* root;
};

int walkbyTree(BTNode* n) {
  if (n == NULL) {
    return 0;
  }
  return 1 + _max(walkbyTree(n->getLeft()), walkbyTree(n->getRight()));
}

int checkBalance(BinaryTree& bt) {
  int leftHeight;
  int rightHeight;

  if (bt.getRoot() == NULL) {
    return 1;
  }
  leftHeight = walkbyTree(bt.getRoot()->getLeft());
  rightHeight = walkbyTree(bt.getRoot()->getRight());
  if (abs(leftHeight - rightHeight) <= 1) {
    return 1;
  }

  return 0;
}

int main() {
  BinaryTree bt = BinaryTree();
  bt.insert(5);
  bt.insert(2);
  bt.insert(7);
  bt.insert(15);
  bt.insert(11);
  bt.getRoot()->getLeft()->getLeft()->setRight(new BTNode(80));
  cout << checkBalance(bt) << "\n";
  return 0;
}