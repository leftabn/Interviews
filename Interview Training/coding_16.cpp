#include <iostream>

using namespace std;

class Node
{
public:
  Node()
  {
    value = 0;
    next = NULL;
    nextMin = NULL;
  }
  Node(int v)
  {
    value = v;
    next = NULL;
    nextMin = NULL;
  }
  Node *getNext()
  {
    return next;
  }
  Node *getNextMin()
  {
    return nextMin;
  }
  int getValue()
  {
    return value;
  }
  void setValue(int v)
  {
    value = v;
  }
  void setNext(Node *n)
  {
    next = n;
  }
  void setNextMin(Node *n)
  {
    nextMin = n;
  }

private:
  int value;
  Node *next;
  Node *nextMin;
};

class Stack
{
public:
  Stack()
  {
    top = NULL;
    min = top;
  }
  int getTop()
  {
    return (top->getValue());
  }
  int getMin()
  {
    return (min->getValue());
  }
  void push(Node *n)
  {
    if (top == NULL)
    {
      top = n;
      min = top;
    }
    else
    {
      n->setNext(top);
      top = n;
      if (n->getValue() < min->getValue())
      {
        n->setNextMin(min);
        min = n;
      }
    }
  }
  void push(int v)
  {
    if (top == NULL)
    {
      top = new Node(v);
      min = top;
    }
    else
    {
      Node *tmp = new Node(v);
      tmp->setNext(top);
      top = tmp;
      if (v < min->getValue())
      {
        tmp->setNextMin(min);
        min = tmp;
      }
    }
  }
  Node *pop()
  {
    Node *tmp = top;
    top = top->getNext();
    if (min == tmp)
    {
      min = min->getNext();
    }
    return (tmp);
  }
  void fill(int *arr, int n)
  {
    int i;
    for (i = 0; i < n; i++)
    {
      push(new Node(arr[i]));
    }
  }
  bool isEmpty()
  {
    return (top == NULL);
  }
  void clear()
  {
    while (top != NULL)
    {
      Node *tmp = top;
      pop();
      delete tmp;
    }
  }
  void printStack()
  {
    Node *it = top;
    cout << "[";
    while (it != NULL)
    {
      cout << it->getValue();
      if (it->getNext())
        cout << ", ";
      it = it->getNext();
    }
    cout << "]\n";
  }

private:
  Node *top;
  Node *min;
};

void sortStacks(Stack &in, Stack &aux)
{
  while (!in.isEmpty())
  {
    int tmp = in.getTop();
    in.pop();
    if (aux.isEmpty())
    {
      aux.push(tmp);
    }
    else
    {
      if (tmp > aux.getTop())
      {
        aux.push(tmp);
      }
      else
      {
        while (!aux.isEmpty() && aux.getTop() > tmp)
        {
          in.push(aux.getTop());
          aux.pop();
        }
        aux.push(tmp);
      }
    }
  }
  while (!aux.isEmpty())
  {
    in.push(aux.getTop());
    aux.pop();
  }
  return;
}

int main()
{
  Stack s1 = Stack();
  int arr[] = {6, 3, 1, 10, 4};
  s1.fill(arr, 5);
  Stack s2 = Stack();
  s1.printStack();
  sortStacks(s1, s2);
  s1.printStack();
  s1.clear();
  s2.clear();
  return 0;
}