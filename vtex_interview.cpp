#include <iostream>
#include <cmath>

#define MAX 10001

using namespace std;

void _swap(int arr[MAX], int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

int digitCount(int num) {
	int count = 0;
	while (num != 0) {
		num /= 10;
		count++;
	}
	return count;
}

void numToArray(int arr[MAX], int num, int length) {
	int i;
	for (i = length; i > 0; i--) {
		arr[i] = (num % 10);
		num /= 10;
	}
}

void _sort(int arr[MAX], int i, int j) {
	while (i > j) {
		_swap(arr, i, j);
		i++;
		j--;
	}
}

int arrayToNum(int arr[MAX], int numLength) {
	int num = 0;
	int i;
	for (i = numLength; i > 0; i--) {
		num += (arr[i] * pow(10,(numLength-i)));
	}
	return num;
}

int sol() {
	int num;
	cin >> num;
	int numLength = digitCount(num);
	int arr[MAX];
	numToArray(arr, num, numLength);
	int last = arr[numLength];
	int i, j;
	for (i = numLength-1; i > 0; i--) {
		if (last > arr[i]) break;
		last = arr[i];
	}
	if (i > 0) {
		for (j = numLength; j > 0; j--) {
			if (arr[j] > arr[i]) break;
		}
		_swap(arr, i, j);
		_sort(arr, i, j);
	}
	num = arrayToNum(arr, numLength);
	return num;
}

int main() {
	cout << sol() << endl;
	return 0;
}
