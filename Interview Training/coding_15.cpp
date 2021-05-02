/**
 * Stack Min: How would you design a stack which, in addition to push and pop,
 * has a function min which returns the minimum element? Push, pop and min
 * should all operate in 0(1) time.
 */

#include <iostream>

using namespace std;

class Node {
public:
  Node() {
    value = 0;
    next = NULL;
    nextMin = NULL;
  }
  Node(int v) {
    value = v;
    next = NULL;
    nextMin = NULL;
  }
  Node* getNext() { return next; }
  Node* getNextMin() { return nextMin; }
  int getValue() { return value; }
  void setValue(int v) { value = v; }
  void setNext(Node* n) { next = n; }
  void setNextMin(Node* n) { nextMin = n; }

private:
  int value;
  Node* next;
  Node* nextMin;
};

class Stack {
public:
  Stack() {
    top = NULL;
    min = top;
  }
  int getTop() { return (top->getValue()); }
  int getMin() { return (min->getValue()); }
  void push(Node* n) {
    if (top == NULL) {
      top = n;
      min = top;
    }
    else {
      n->setNext(top);
      top = n;
      if (n->getValue() < min->getValue()) {
        n->setNextMin(min);
        min = n;
      }
    }
  }
  void push(int v) {
    if (top == NULL) {
      top = new Node(v);
      min = top;
    }
    else {
      Node* tmp = new Node(v);
      tmp->setNext(top);
      top = tmp;
      if (v < min->getValue()) {
        tmp->setNextMin(min);
        min = tmp;
      }
    }
  }
  Node* pop() {
    Node* tmp = top;
    top = top->getNext();
    if (min == tmp) {
      min = min->getNext();
    }
    return (tmp);
  }
  void fill(int* arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
      push(new Node(arr[i]));
    }
  }
  bool isEmpty() { return (top == NULL); }
  void clear() {
    while (top != NULL) {
      Node* tmp = top;
      top = pop();
      delete tmp;
    }
  }
  void printStack() {
    Node* it = top;
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
  Node* top;
  Node* min;
};

int main() {
  Stack s1 = Stack();
  s1.push(10);
  // s1.push(2);
  s1.push(3);
  s1.push(4);
  // s1.push(1);
  cout << s1.getMin() << "\n";
  s1.clear();
  return 0;
}