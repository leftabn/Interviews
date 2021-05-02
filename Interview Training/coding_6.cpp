/**
 * AVL tree
 */

#include <bits/stdc++.h>

using namespace std;

typedef struct btNode {
  int v;
  struct btNode* r;
  struct btNode* l;
  int height;
} Node;

typedef struct AVL {
  Node* root;
} AVL;

void start_avl(AVL** avl) {
  *avl = (AVL*)malloc(sizeof(AVL));
  (*avl)->root = NULL;
}

int getHeight(Node* n) {
  if (n == NULL)
    return 0;
  return n->height;
}

int balanceFactor(Node* n) {
  if (n == NULL)
    return 0;
  return (getHeight(n->l) - getHeight(n->r));
}

Node* allocNode(int v) {
  Node* newNode = NULL;
  newNode = (Node*)malloc(sizeof(Node));
  newNode->v = v;
  newNode->r = NULL;
  newNode->l = NULL;
  newNode->height = 1;
  return newNode;
}

Node* L_Rotate(Node* n) {
  Node* tmp = n->r;
  Node* tmp2 = tmp->l;

  tmp->l = n;
  n->r = tmp2;

  n->height = max(getHeight(n->l), getHeight(n->r) + 1);
  tmp->height = max(getHeight(tmp->l), getHeight(tmp->r) + 1);

  return tmp;
}

Node* R_Rotate(Node* n) {
  Node* tmp = n->l;
  Node* tmp2 = tmp->r;

  tmp->r = n;
  n->l = tmp2;

  n->height = max(getHeight(n->l), getHeight(n->r) + 1);
  tmp->height = max(getHeight(tmp->l), getHeight(tmp->r) + 1);

  return tmp;
}

Node* insert(Node* n, int v) {
  if (n == NULL)
    return allocNode(v);

  if (v < n->v)
    n->l = insert(n->l, v);
  else if (v > n->v)
    n->r = insert(n->r, v);
  else
    return n;

  n->height = 1 + max(getHeight(n->l), getHeight(n->r));

  int balance = balanceFactor(n);
  if (balance > 1 && v < n->l->v)
    return R_Rotate(n);
  if (balance < -1 && v > n->r->v)
    return L_Rotate(n);

  if (balance > 1 && v > n->l->v) {
    n->l = L_Rotate(n->l);
    return R_Rotate(n);
  }
  if (balance < -1 && v < n->r->v) {
    n->r = R_Rotate(n->r);
    return L_Rotate(n);
  }

  return n;
}

void preOrderPrint(Node* n) {
  if (n == NULL)
    return;
  cout << n->v << " ";
  preOrderPrint(n->l);
  preOrderPrint(n->r);
  return;
}

int main() {
  AVL* avl = NULL;
  start_avl(&avl);
  avl->root = insert(avl->root, 10);
  avl->root = insert(avl->root, 20);
  avl->root = insert(avl->root, 50);
  avl->root = insert(avl->root, 400);
  avl->root = insert(avl->root, 110);
  avl->root = insert(avl->root, 125);
  avl->root = insert(avl->root, 200);
  avl->root = insert(avl->root, 237);
  avl->root = insert(avl->root, 80);

  preOrderPrint(avl->root);
  cout << "\n";

  return 0;
}