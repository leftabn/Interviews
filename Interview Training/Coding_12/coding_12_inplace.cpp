/**
 * Write code to partition a linked list around a value x, such that all nodes less than x come 
 * before all nodes greater than or equal to x. If x is contained within the list, the values of x only need 
 * to be after the elements less than x (see below). The partition element x can appear anywhere in the 
 * "right partition"; it does not need to appear between the left and right partitions.
*/

#include <iostream>

using namespace std;

class Node
{
public:
  Node()
  {
    value = 0;
    next = NULL;
  }
  Node(int v)
  {
    value = v;
    next = NULL;
  }
  Node *getNext()
  {
    return next;
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

private:
  int value;
  Node *next;
};

class LinkedList
{
public:
  LinkedList()
  {
    head = NULL;
    lastElement = head;
  };
  Node *getHead()
  {
    return head;
  }
  Node *getLast()
  {
    return lastElement;
  }
  void setHead(Node *h)
  {
    head = h;
  }
  void insert(Node *n)
  {
    if (head == NULL)
    {
      head = n;
      lastElement = head;
    }
    else
    {
      lastElement->setNext(n);
      lastElement = lastElement->getNext();
    }
  }
  void fill(int *arr, int n)
  {
    int i;
    for (i = 0; i < n; i++)
    {
      insert(new Node(arr[i]));
    }
  }
  void clear()
  {
    while (head != NULL)
    {
      Node *tmp = head;
      head = head->getNext();
      delete tmp;
    }
  }
  void printList()
  {
    Node *it = head;
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
  Node *head;
  Node *lastElement;
};

void arrPartition(LinkedList list, int x)
{
  Node *it = list.getHead();
  Node *lesserHead = NULL;
  Node *greaterHead = NULL;
  Node *lesser = NULL;
  Node *greater = NULL;
  Node *tmp;
  while (it != NULL)
  {
    if (it->getValue() < x)
    {
      tmp = it;
      it = it->getNext();
      if (lesserHead == NULL)
        lesserHead = lesser = tmp;
      else
      {
        lesser->setNext(tmp);
        lesser = lesser->getNext();
      }
    }
    else
    {
      tmp = it;
      it = it->getNext();
      if (greaterHead == NULL)
        greaterHead = greater = tmp;
      else
      {
        greater->setNext(tmp);
        greater = greater->getNext();
      }
    }
  }
  greater->setNext(NULL);
  lesser->setNext(greaterHead);
}

int main()
{
  int arr[] = {3, 5, 8, 5, 10, 2, 1};
  int n = (sizeof(arr) / sizeof(arr[0]));
  LinkedList list;
  list.fill(arr, n);
  list.printList();
  arrPartition(list, 5);
  list.printList();
  return 0;
}
