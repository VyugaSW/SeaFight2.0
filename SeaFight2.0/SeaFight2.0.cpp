#include <iostream>
#include <Windows.h>
#include "Tablle.h"


using namespace std;
// - 0 - пустая клетка 
// - 1 - клетка затронутая ядром
// - 2 - причастность к клетке корабля
// - 3 - подбитая доля корабля

// - o - пустая клетка 
// - * - клетка затронутая ядром
// - + - причастность к клетке корабля
// - - - подбитая доля корабля

bool flag = true;

//Расставляем корабли на поле
void ShipRankingOnField(char(*field)[10]) {
    srand(time(NULL));
    int i, j;
    int j1, i1;
    int k;
    int s;
    // Четырёхпалубный
    s = rand() % 2;

    // Горизонтально
    if (s) {
        i = rand() % 10;
        j = rand() % 7;
        field[i][j] = '+';
        field[i][j + 1] = '+';
        field[i][j + 2] = '+';
        field[i][j + 3] = '+';
    }
    // Вертикально
    else {
        i = rand() % 7;
        j = rand() % 10;
        field[i][j] = '+';
        field[i + 1][j] = '+';
        field[i + 2][j] = '+';
        field[i + 3][j] = '+';
    }


    // Трёхпалубные
    k = 0;
    while (k < 2) {
        s = rand() % 2;
        // Горизонтально
        if (s) {
            i = rand() % 10;
            j = rand() % 8;
            j1 = j + 2;
            i1 = i;
            if (field[i - 1][j - 1] == 'o' && field[i + 1][j + 1] == 'o'
                && field[i][j - 1] == 'o'
                && field[i + 1][j - 1] == 'o' && field[i - 1][j + 1] == 'o'
                && field[i + 1][j] == 'o' && field[i - 1][j] == 'o'
                && field[i1 - 1][j1] == 'o' && field[i1 + 1][j1 + 1] == 'o'
                && field[i1][j1 + 1] == 'o' && field[i1 + 1][j1] == 'o'
                && field[i1 - 1][j1] == 'o' && field[i + 1][j1 - 1] == 'o' && field[i - 1][j1 + 1] == '0') {

                field[i][j] = '+';
                field[i1][j1] = '+';
                field[i1][j + 1] = '+';
                k++;
            }
            else continue;
        }
        // Вертикально
        else {
            i = rand() % 8;
            j = rand() % 10;
            i1 = i + 2;
            j1 = j;
            if (field[i - 1][j - 1] == 'o' && field[i + 1][j + 1] == 'o'
                && field[i][j - 1] == 'o'
                && field[i + 1][j - 1] == 'o' && field[i - 1][j + 1] == 'o'
                && field[i + 1][j] == 'o' && field[i - 1][j] == 'o'
                && field[i1][j1 - 1] == 'o' && field[i1 + 1][j1 + 1] == 'o'
                && field[i1 + 1][j1] == 'o' && field[i1][j1 + 1] == 'o'
                && field[i1][j1 - 1] == 'o') {

                field[i][j] = '+';
                field[i1][j1] = '+';
                field[i + 1][j] = '+';
                k++;
            }
            else continue;
        }
    }


    // Двупалобные
    k = 0;
    while (k < 3) {
        s = rand() % 2;
        // Горизонтально
        if (s) {
            i = rand() % 10;
            j = rand() % 9;
            j1 = j + 1;
            i1 = i;
            if (field[i - 1][j - 1] == 'o' && field[i + 1][j + 1] == 'o'
                && field[i][j - 1] == 'o'
                && field[i + 1][j - 1] == 'o' && field[i - 1][j + 1] == 'o'
                && field[i + 1][j] == 'o' && field[i - 1][j] == 'o'
                && field[i1 - 1][j1] == 'o' && field[i1 + 1][j1 + 1] == 'o'
                && field[i1][j1 + 1] == 'o' && field[i1 + 1][j1] == 'o'
                && field[i1 - 1][j1] == 'o'
                && field[i1 + 1][j1 - 1] == 'o' && field[i1 - 1][j1 + 1] == 'o') {
                field[i][j] = '+';
                field[i1][j1] = '+';
                k++;
            }
            else continue;
        }
        // Вертикально
        else {
            i = rand() % 9;
            j = rand() % 10;
            j1 = j;
            i1 = i + 1;
            if (field[i - 1][j - 1] == 'o' && field[i + 1][j + 1] == 'o'
                && field[i][j - 1] == 'o'
                && field[i + 1][j - 1] == 'o' && field[i - 1][j + 1] == 'o'
                && field[i + 1][j] == 'o' && field[i - 1][j] == 'o'
                && field[i1 - 1][j1] == 'o' && field[i1 + 1][j1 + 1] == 'o'
                && field[i1][j1 + 1] == 'o' && field[i1 + 1][j1] == 'o'
                && field[i1][j1 - 1] == 'o'
                && field[i1 + 1][j1 - 1] == 'o' && field[i1 - 1][j1 + 1] == 'o') {
                field[i][j] = '+';
                field[i1][j1] = '+';
                k++;
            }
            else continue;
        }
    }


    // Однопалубные
    k = 0;
    while (k < 4) {
        i = rand() % 10;
        j = rand() % 10;
        if (field[i - 1][j - 1] == 'o' && field[i + 1][j + 1] == 'o'
            && field[i][j + 1] == 'o' && field[i][j - 1] == 'o'
            && field[i + 1][j] == 'o' && field[i - 1][j] == 'o'
            && field[i + 1][j - 1] == 'o' && field[i - 1][j + 1] == 'o') {
            field[i][j] = '+';
            k++;
        }
        else continue;
    }


}


// Ход
void StepPlayer1() {
    int x, y;
    cout << "Ход Игрока 1\n";
    cout << "Задайте координату x - "; cin >> x;
    cout << "Задайте координату y - "; cin >> y;
    Attack(x, y, fieldP2);
    cout << "Поле Игрока 1\n";
    DrawField(fieldP1);
    cout << "Поле игрока 2\n";
    DrawField(fieldP2);
}
void StepPlayer2() {
    int x, y;
    cout << "Ход Игрока 2\n";
    cout << "Задайте координату x - "; cin >> x;
    cout << "Задайте координату y - "; cin >> y;
    Attack(x, y, fieldP1);
    cout << "Поле Игрока 1\n";
    DrawField(fieldP1);
    cout << "Поле Игрока 2\n";
    DrawField(fieldP2);;
}



//Проверка на победу и сама победа
void Win(string name) {
    cout << "Победа " << name << "!!" << endl;
    ::flag = false;
}
void WinCheck(char(*field)[10], string name) {
    int c = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (field[i][j] == '+') c++;
        }
    }
    if (c == 0) Win(name);
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    

    char f;

    cout << "\t\t|||Морской Бой|||\t\t\t\n\n\n";
    cout << "Желаете начать? (y/n)\n";
    cin >> f;
    if (f == 'y') {
        int x, y;
        FieldFill();
        cout << "Поле Игрока 1\n";
        ShipRankingOnField(fieldP1);
        DrawField(fieldP1);
        cout << "Поле игрока 2\n";
        ShipRankingOnField(fieldP2);
        DrawField(fieldP2);
        while (flag) {
            StepPlayer1();
            StepPlayer2();
            WinCheck(fieldP2,"Игрока 1");
            WinCheck(fieldP1,"Игрока 2");
        }
    }
    else {
        cout << "Good Bye, о необходимость";
    }



}
