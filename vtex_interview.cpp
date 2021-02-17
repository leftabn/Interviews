#include <bits/stdc++.h>

// FIND NEXT GREATER NUMBER WITH SAME SET OF DIGITS

#define MAX 10001

using namespace std;

void _swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int digitCount(int num)
{
	int count = 0;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return count;
}

void numToArray(int arr[MAX], int num, int length)
{
	int i;
	for (i = length; i > -1; i--)
	{
		arr[i] = (num % 10);
		num /= 10;
	}
}

int arrayToNum(int arr[MAX], int numLength)
{
	int num = 0;
	int i;
	for (i = numLength; i > -1; i--)
	{
		num += (arr[i] * pow(10, (numLength - i)));
	}
	return num;
}

int sol()
{
	int num;
	cin >> num;
	int numLength = digitCount(num);
	int arr[MAX];
	numToArray(arr, num, numLength);
	int i;
	for (i = numLength; i > 0; i--)
	{
		if (arr[i] > arr[i-1])
			break;
	}
	
	if (i == 1 && arr[i] <= arr[i-1])
	{
		return num;
	}

	int last = arr[i-1], small = i;
	int j;
	for (j = i+1; j <= numLength; j++)
	{
		if (arr[j] > last && arr[j] < arr[small])
			small = j;
	}
		
	_swap(&arr[small], &arr[i-1]);
	sort(arr + i, arr + (numLength+1));
	num = arrayToNum(arr, numLength);
	return num;
}

int main()
{
	cout << sol() << endl;
	return 0;
}