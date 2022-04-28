#pragma once
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include "biblio.h"

using namespace std;

int main(int argc, char* argv[])
{
    // русификация
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int s;
    while (true)
    {
        cout << "      Выберите действие:" << endl;
        cout << "       Создать запись - 1" << endl << "       Просмотр - 2" << endl
            << "       Добавить запись - 3" << endl << "       Изменить запись - 4" << endl
            << "       Удалить запись - 5" << endl << "       Индивидуальное задание - 6" << endl
            << "       Выход - 0" << endl;

        cin >> s;
        switch (s)
        {

        case 1:        //создаем запись
            system("cls"); 
            GetInformation();
            break;

        case 2:        //выводим данные из файла
            system("cls"); 
            ReadInformation();
            break;

        case 3:    //добавляем данные
            system("cls");
            AddInformation();
            break;

        case 4:      //изменение записи
            system("cls");
            Change();
            break;

        case 5:    //удаляем данные
            system("cls");
            Delete();
            break;

        case 6:  //индивидуальное задание
            system("cls");
            Search();
            Infa();
            break;

        }
        if (s == 0)
            break;
    }
    return 0;
}

