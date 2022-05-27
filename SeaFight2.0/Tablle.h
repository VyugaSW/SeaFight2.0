#pragma once

#include <iostream>
#include <Windows.h>

using namespace std;

void StepPlayer1();
void StepPlayer2();



// Two tables
char fieldP1[10][10];
char fieldP2[10][10];

// Filling and renew
void FieldFill() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			fieldP1[i][j] = 'o';
			fieldP2[i][j] = 'o';
		}
	}
}
// Drawing table
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

// To attack
void Attack(int x, int y, char(*field)[10]) {
	system("cls");
	if (field[y][x] == 'o') {
		cout << endl << "\tПустая клетка\n";
		field[y][x] = '*';
	}
	else if (field[y][x] == '*' || field[x][y] == '-') {
		if (field == fieldP1) {
			cout << "\tНельзя!\n";
			cout << "Поле Игрока 1\n";
			DrawField(fieldP1);
			cout << "Поле игрока 2\n";
			DrawField(fieldP2);
			StepPlayer2();
		}
		else if (field == fieldP2) {
			cout << "\tНельзя!\n";
			cout << "Поле Игрока 1\n";
			DrawField(fieldP1);
			cout << "Поле игрока 2\n";
			DrawField(fieldP2);
			StepPlayer1();
		}
	}
	else if (field[y][x] == '+') {
		cout << endl << "\tБезоппозиционное попадние в часть вражеского корабля\n";
		field[y][x] = '-';
	}
}
