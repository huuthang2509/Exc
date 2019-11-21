#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

void main()
{
	int n = 9;
	int t = 10;
	int d = 0;
	int x[9] = { 11,1,2,1,1,5,10,2,3 };
	for (int i = 0; i < n; i++)
	{
		int tsr = 0;
		for (int m = i; m < n; m++)
		{
			tsr += x[m];
			if (x[m] > t) break;
			if (tsr > t)
			{
				d++;
				break;
			}
		}
	}
	cout << d;
	_getch();
}