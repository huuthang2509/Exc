#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

void inputArray(int* &a, int &n)
{
	printf("Nhap n: ");
	scanf("%d", &n);
	int* m = new int[n];
	for (int i = 0; i < n; i++)
	{
		printf("Nhap m[%d]: ", i);
		cin >> m[i];
	}
	a = m;
}

void dellocateArray(int* &a)
{
	delete[] a;
}

void main()
{
	int *a;
	int n;
	inputArray(a, n);
	for (int j = 0; j < n; j++)
	{
		printf("m[%d]: ", j);
		cout << *(a + j) << endl;
	}
	dellocateArray(a);
	_getch();
}