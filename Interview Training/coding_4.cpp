/**
 * 3 stack inside of an array
*/

#include <bits/stdc++.h>

const unsigned int MAX_SIZE = 10;
const unsigned int STACK_QTD = 3;

using namespace std;

int stack_arr[MAX_SIZE+2];
int top[STACK_QTD+2];
int behind[MAX_SIZE+2];

int emptySlot;

void init_stack()
{
  int i;
  for (i = 0; i < MAX_SIZE; i++)
  {
    behind[i] = i+1; // random value great than -1
  }
  behind[MAX_SIZE-1] = -1;
  emptySlot = 0;
  for (i = 0; i < STACK_QTD; i++)
  {
    top[i] = -1; // -1 represents there's no top value
  }
  return;
}

int pop(int stack_n)
{
  if (top[stack_n] == -1)
  {
    return top[stack_n];
  }
  int i = top[stack_n];
  top[stack_n] = behind[i];
  behind[i] = emptySlot;
  emptySlot = i;
  return stack_arr[i];
}

void push(int value, int stack_n)
{
  if (emptySlot == -1) {
    return;
  }
  int i = emptySlot;
  emptySlot = behind[i];
  behind[i] = top[stack_n];
  top[stack_n] = i;
  stack_arr[i] = value;
  return;
}

void sol()
{
  init_stack();
  
  push(11, 0);
  push(13, 0);
  push(15, 0);

  push(6, 1);
  push(7, 1);
  push(5, 1);

  push(4, 2);
  push(2, 2);
  push(0, 2);
 
  cout << "POP STACK 0: " << pop(0) << "\n";
  cout << "POP STACK 1: " << pop(1) << "\n";
  cout << "POP STACK 2: " << pop(2) << "\n";
  return;
}

int main()
{
  sol();
  return 0;
}