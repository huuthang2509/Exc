#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	int i = 10;
	int *j;
	j = &i;
	cout << i << endl;
	cout << j << endl;
	cout << *j << endl;
	_getch();
}