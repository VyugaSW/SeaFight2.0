#pragma once

#include <iostream>
#include <Windows.h>

using namespace std;

// ��� �����
char fieldP1[10][10];
char fieldP2[10][10];

//��������� ���� ��������� ��� �� ���������
void FieldFill() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			fieldP1[i][j] = 'o';
			fieldP2[i][j] = 'o';
		}
	}
}
//������ ���� 
void DrawField(char(*field)[10]) {
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
void Attack(int x, int y, char(*field)[10]) {
	system("cls");
	if (field[y][x] == 'o') {
		cout << endl << "\t������ ������\n";
		field[y][x] = '*';
	}
	else if (field[y][x] == '+') {
		cout << endl << "\t���������������� �������� � ����� ���������� �������\n";
		field[y][x] = '-';
	}
}
