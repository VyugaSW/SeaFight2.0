#pragma once

#include <iostream>
#include <Windows.h>
using namespace std;

// ��� �����
int fieldP1[10][10];
int fieldP2[10][10];

//��������� ���� ��������� ��� �� ���������
void FieldFill() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			fieldP1[i][j] = 0;
			fieldP2[i][j] = 0;
		}
	}
}
//������ ���� 
void DrawField(int(*field)[10]) {
	cout << "    ";
	for (int i = 0; i < 10; i++) {
		cout << i << " ";
	}
	cout << endl << "   --------------------";
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << i << " | ";
		for (int j = 0; j < 10; j++) {
			cout << field[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

//����������� ������
void Attack(int x, int y, int(*field)[10]) {
	system("cls");
	if (field[y][x] == 0) {
		cout << endl << "\t������ ������\n";
		field[y][x] = 1;
	}
	else if (field[y][x] == 2) {
		cout << endl << "\t���������������� �������� � ����� ���������� �������\n";
		field[y][x] = 3;
	}
}
