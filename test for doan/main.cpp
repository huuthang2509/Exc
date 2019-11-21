

#include <iostream>
#include <stdio.h> 
#include <conio.h>
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 


using namespace std;

int **d1, **d2, x, y, **d;

void create(int x, int y);// nhap input
int staging(int x, int y);// bat dau thuc hien phuong phap Quine-McCluskey
int duplication(int x, int y);// loai bo cac dong bi trung
void decode(int x, int y3);// in ra man hinh ket qua




void create(int x, int y)
{
	int i, j, a;
	for (i = 0; i < y; i++) {
		cout << endl;
		cout << "Nhap hoi so cap thu " << i << "(nhap dang nhi phan cua tung bien): " << endl;
		for (j = 0; j < x; j++)
		{
			cin >> d[i][j];
			d1[i][j] = d[i][j];
		}
		d[i][x] = d1[i][x] = 8;
	}
}



int staging(int x, int y)// bat dau thuc hien cac phep dan
{
	int i1, j1, k1, t1, i2, j2, t2, c; i2 = 0; c = 0;
	for (i1 = 0; i1 < (y - 1); i1++) {
		for (j1 = i1 + 1; j1 < y; j1++) {
			t1 = 0;
			for (k1 = 0; k1 < x; k1++) {
				if (d1[i1][k1] != d1[j1][k1]) {
					t1++;
					t2 = k1;
				}
			}
			if (t1 == 1) {
				for (j2 = 0; j2 < t2; j2++)
					d2[i2][j2] = d1[i1][j2];
				d2[i2][t2] = 3;
				for (j2 = t2 + 1; j2 < y; j2++)
					d2[i2][j2] = d1[i1][j2];
				d2[i2][x] = 8;
				d1[i1][x] = 9;
				d1[j1][x] = 9;
				i2++;
			}
		}
	} 
	for (i1 = 0; i1 < y; i1++) {
		if (d1[i1][x] == 8) {
			for (j1 = 0; j1 <= x; j1++)
				d2[i2][j1] = d1[i1][j1];
			i2++;
		}
	}
	for (j1 = 0; j1 < x; j1++) {
		if (d1[0][j1] == d2[0][j1]) c++;
	}
	if (c < x) {
		d1 = (int **)malloc(i2 * sizeof(int *));
		for (i1 = 0; i1 < i2; i1++) d1[i1] = (int *)malloc((x + 1) * sizeof(int));
		for (i1 = 0; i1 < i2; i1++) {
			for (j1 = 0; j1 <= x; j1++) d1[i1][j1] = d2[i1][j1];// tra ket qua ve bang d1
		}
		staging(x, i2);
	}
	else return(i2);
}

int duplication(int x, int y)// kiem tra o bang cuoi ket qua nao bi trung
{
	int i1, i2, j, c, t; t = 0;
	for (i1 = 0; i1 < (y - 1); i1++) {
		for (i2 = i1 + 1; i2 < y; i2++) {
			c = 0;
			for (j = 0; j < x; j++) {
				if (d1[i1][j] == d1[i2][j]) c++;
			}
			if (c == x) d1[i2][x] = 9;
		}
	}
	for (i1 = 0; i1 < y; i1++) {
		if (d1[i1][x] == 9) t++;
	}
	i2 = y - t;
	d2 = (int **)malloc(i2 * sizeof(int *));
	for (j = 0; j < i2; j++) d2[j] = (int *)malloc((x + 1) * sizeof(int));
	i2 = 0;
	for (i1 = 0; i1 < y; i1++)// loai bo cac hoi bi trung, chep ket qua sau khi loai sang bang d2 lai
		if (d1[i1][x] == 8) {
			for (j = 0; j <= x; j++) d2[i2][j] = d1[i1][j];
			i2++;
		}
	return(i2);
}




void decode(int x, int y3)
{
	for (int m = 0; m < y3; m++)
	{
		for (int n = 0; n < x; n++)
		{
			if (d2[m][n] == 0)
			{
				cout << "a[" << n << "]'";
			}
			if (d2[m][n] == 1)
			{
				cout << "a[" << n << "]";
			}
		}
		cout << " v ";
	}
}

int main()
{
	int i, j, y1, y2, y3, a, q;
	printf("\n Nhap so bien: ");
	cin >> x;
	printf("\n Nhap so hoi so cap: ");
	cin >> y;
	d = d1 = (int **)malloc(y * sizeof(int *));// d la bang goc, d1 la bang dung de thao tac
	for (i = 0; i < y; i++) d[i] = d1[i] = (int *)malloc((x + 1) * sizeof(int));// them 1 cot de danh dau
	create(x, y);
	y1 = y * (y + 1) / 2;
	d2 = (int **)malloc(y1 * sizeof(int *));// d2 la bang luu cac hoi so cap da duoc gian trong qua trinh chay, va luu ket qua thu gon cuoi cung khi chay xong
	for (i = 0; i < y1; i++) d2[i] = (int *)malloc((x + 1) * sizeof(int));// them 1 cot de danh dau
	y2 = staging(x, y);
	y3 = duplication(x, y2);
	printf("\n\nCong thuc da thuc toi thieu:\n\n");
	decode(x, y3);
	_getch();
	return 0;
}