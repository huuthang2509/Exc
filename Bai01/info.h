#pragma once
#include <stdio.h>
#include <conio.h>
#include <string>
#include <iostream>
using namespace std;

class hocsinh
{
	string hoten;
	int dt;
	int dv;
public:
	hocsinh() {
		hoten = "Dang Huu Thang";
		dt = 10;
		dv = 5;
	}
	void xuat() {
		cout << "Ho va Ten: " << hoten << endl;
		printf("Diem toan: %d\n", dt);
		printf("Diem van: %d", dv);
	}
};