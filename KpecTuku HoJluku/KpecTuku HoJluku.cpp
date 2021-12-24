#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251); /*Используется для корректного вывода имён, которые введёт 
                               пользовтель, если они будут на русском языке*/
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");
    const int N = 3;
    int Str, Stolb, k, vybor;
    char A[N][N], krest, nol;
    string s, a, b, name1, name2;
    a = "НОЛИКИ";
    b = "КРЕСТИКИ";
    nol = 'О';
    krest = 'X';
    cout << "\t\t\t\t\tИГРА КРЕСТИКИ-НОЛИКИ\n" << endl;
checkname:
    cout << "Введите имя первого игрока: ";
    getline(cin, name1);
    cout << "Введите имя второго игрока: ";
    getline(cin, name2);
    if (name1 == name2) //Делаем проверку на повторяющееся имя
    {
        cout << "Имя повторяется, измените одно из имён!\n\n";
        goto checkname;
    }
    cout << "За кого будет ходить " << name1 << " ? (введите цифру) : " << endl;
    cout << "О: 1" << endl;
    cout << "X: 2" << endl;
    cout << "Цифра: ";
    cin >> vybor;
    for (int i = 0; i < N; i++) //Вывод игрового поля
    {
        for (int j = 0; j < N; j++)
        {
            A[i][j] = '*';
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 9; i++)
    {
        if ((!(i % 2)) && (vybor == 1) || (i % 2) && (vybor == 2)) 
        {
            s = a;
        }
        if ((!(i % 2)) && (vybor == 2) || (i % 2) && (vybor == 1)) 
        {
            s = b;
        }
    mylabel:
        cout << "Сделайте ваш ход (" << s << ")" << endl;
        cout << "Строка: ";
        cin >> Str;
        cout << "Столбец: ";
        cin >> Stolb;
        Str--;
        Stolb--;
        if (A[Str][Stolb] != '*') //Проверка на занятость позиции
        {
            system("cls");
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    cout << A[i][j] << " ";
                }
                cout << endl;
            }
            cout << "Данная позиция занята!" << endl;
            goto mylabel;
        }
        if ((!(i % 2)) && (vybor == 1) || (i % 2) && (vybor == 2)) 
        {
            A[Str][Stolb] = nol;
        }
        if ((!(i % 2)) && (vybor == 2) || (i % 2) && (vybor == 1)) 
        {
            A[Str][Stolb] = krest;
        }
        system("cls");
        k = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
        if (((A[0][0] == 'О') && (A[0][1] == 'О') && (A[0][2] == 'О')) ||
            ((A[1][0] == 'О') && (A[1][1] == 'О') && (A[1][2] == 'О')) ||
            ((A[2][0] == 'О') && (A[2][1] == 'О') && (A[2][2] == 'О')) ||
            ((A[0][0] == 'О') && (A[1][0] == 'О') && (A[2][0] == 'О')) ||
            ((A[0][1] == 'О') && (A[1][1] == 'О') && (A[2][1] == 'О')) ||
            ((A[0][2] == 'О') && (A[1][2] == 'О') && (A[2][2] == 'О')) ||
            ((A[0][0] == 'О') && (A[1][1] == 'О') && (A[2][2] == 'О')) ||
            ((A[2][0] == 'О') && (A[1][1] == 'О') && (A[0][2] == 'О')) ||
            ((A[0][0] == 'X') && (A[0][1] == 'X') && (A[0][2] == 'X')) ||
            ((A[1][0] == 'X') && (A[1][1] == 'X') && (A[1][2] == 'X')) ||
            ((A[2][0] == 'X') && (A[2][1] == 'X') && (A[2][2] == 'X')) ||
            ((A[0][0] == 'X') && (A[1][0] == 'X') && (A[2][0] == 'X')) ||
            ((A[0][1] == 'X') && (A[1][1] == 'X') && (A[2][1] == 'X')) ||
            ((A[0][2] == 'X') && (A[1][2] == 'X') && (A[2][2] == 'X')) ||
            ((A[0][0] == 'X') && (A[1][1] == 'X') && (A[2][2] == 'X')) ||
            ((A[2][0] == 'X') && (A[1][1] == 'X') && (A[0][2] == 'X')))
        {
            k++; /* Счётчик победы.Если он будет равен нулю, то в строке проверки на ничью
                                                    аргумент if будет true из-за логического отрицания*/
            cout << "Игра закончена! Игрок ";
            if ((A[Str][Stolb] == nol) && (vybor == 1) || (A[Str][Stolb] == krest) && (vybor == 2)) 
            {
                cout << name1 << " победил!" << endl;
            }
            if ((A[Str][Stolb] == krest) && (vybor == 1) || (A[Str][Stolb] == nol) && (vybor == 2)) 
            {
                cout << name2 << " победил!" << endl;
            }
            break;
        }
    }
    if (!(k)) cout << "Игра закончилась вничью!" << endl; //Проверка на ничью
    system("pause");
    return 0;
}