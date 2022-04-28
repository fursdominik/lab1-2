#include "biblio.h"
#include <iostream>
#include <string>
#include <ios>
#include <fstream>

using namespace std;

struct Student
{
    char name[200];
    int year;
    char group_number[7];
    double phizika;
    double inform;
    double matem;
    double himia;
    double average_number;
};

void GetInformation()
{
    cout << "Введите количество студентов: " << endl;
    int n;
    cin >> n;
    Student* std = new Student[n]; //выделение места в памяти для структуры
    ofstream record("zapici.txt"); // создание объекта для записи и связываем с файлом 
    if (record) 
    {
        record << n << endl;

        for (int i = 0; i < n; i++)
        {
            cout << "ФИО: " << endl;
            cin.ignore(100, '\n'); 
            gets_s(std[i].name);
            record << std[i].name << endl;

            cout << "Год рождения: " << endl;
            cin >> std[i].year;
            record << std[i].year << endl;

            cout << "Номер группы: " << endl;
            cin >> std[i].group_number;
            record << std[i].group_number << endl;

            cout << "Физика: " << endl;
            cin >> std[i].phizika;
            record << std[i].phizika << endl;

            cout << "Информатика: " << endl;
            cin >> std[i].inform;
            record << std[i].inform << endl;

            cout << "Математика: " << endl;
            cin >> std[i].matem;
            record << std[i].matem << endl;

            cout << "Химия: " << endl;
            cin >> std[i].himia;
            record << std[i].himia << endl;

            std[i].average_number = (std[i].inform + std[i].matem + std[i].himia + std[i].phizika) / 4.;
            cout << "Средний балл: " << std[i].average_number << endl;
            record << std[i].average_number << endl;
            record << "" << endl;
        }
    }
    record.close();
}

int NumberOfStudents()
{
    ifstream number("zapici.txt");
    int n;
    if (number)
    {
        number >> n;
    }
    number.close();
    return n; // возврат переменной с количеством студентов
}

void AddInformation()
{
    cout << "Введите количество студентов: " << endl;
    int n;
    cin >> n;

    int num = NumberOfStudents() + n;
    Student* std = new Student[n];

    ofstream record("zapici.txt", ios::app); //в конец файла
    ofstream record_("zapici.txt", ios::in); //для записи в начало файла

    if (record_)
    {
        record_ << num << endl;
        if (record)
        {
            for (int i = 0; i < n; i++)
            {
                cout << "ФИО: " << endl;
                cin.ignore(100, '\n');
                gets_s(std[i].name);
                record << std[i].name << endl;

                cout << "Год рождения: " << endl;
                cin >> std[i].year;
                record << std[i].year << endl;

                cout << "Номер группы: " << endl;
                cin >> std[i].group_number;
                record << std[i].group_number << endl;

                cout << "Физика: " << endl;
                cin >> std[i].phizika;
                record << std[i].phizika << endl;

                cout << "Информатика: " << endl;
                cin >> std[i].inform;
                record << std[i].inform << endl;

                cout << "Математика: " << endl;
                cin >> std[i].matem;
                record << std[i].matem << endl;

                cout << "Химия: " << endl;
                cin >> std[i].himia;
                record << std[i].himia << endl;

                std[i].average_number = (std[i].inform + std[i].matem + std[i].himia + std[i].phizika) / 4.;
                cout << "Средний балл: " << std[i].average_number << endl;
                record << std[i].average_number << endl;
                record << "" << endl;
            }
        }
    }
    record_.close();
    record.close();
}

void ReadInformation()
{
    ifstream reading("zapici.txt");

    if (reading) //если открыт файл
    {
        string name = "";
        string year = "";
        string group = "";
        string phizika = "";
        string inform = "";
        string matem = "";
        string himia = "";
        string sr_ball = "";
        string stroka = "";
        string str;
        int n = NumberOfStudents();
        reading >> n;
        getline(reading, str);
        cout << "      Информация: " << endl;
        cout << "Общее количество студентов: " << n << endl;

        for (int i = 0; i < n; i++)
        {
            getline(reading, name);
            cout << "ФИО: " << name << endl;

            getline(reading, year);
            cout << "Год рождения: " << year << endl;

            getline(reading, group);
            cout << "Номер группы: " << group << endl;

            getline(reading, phizika);
            cout << "Физика: " << phizika << endl;

            getline(reading, inform);
            cout << "Информатика: " << inform << endl;

            getline(reading, matem);
            cout << "Математика: " << matem << endl;

            getline(reading, himia);
            cout << "Химия: " << himia << endl;

            getline(reading, sr_ball);
            cout << "Средний балл: " << sr_ball << endl;

            getline(reading, stroka);
            cout << stroka << endl;
        }
    }
    reading.close();
}

void Copy()
{
    ifstream reading("zapici.txt"); //поток для чтения
    ofstream record("newzapici.txt"); //поток для записи

    if (reading)
    {
        if (record)
        {
            string name = "";
            string year = "";
            string group = "";
            string phizika = "";
            string inform = "";
            string matem = "";
            string himia = "";
            string sr_ball = "";
            string stroka = "";
            string str;
            int n;
            reading >> n;

            record << n << endl;
            getline(reading, str);
            for (int i = 0; i < n; i++)
            {
                getline(reading, name);
                record << name << endl;

                getline(reading, year);
                record << year << endl;

                getline(reading, group);
                record << group << endl;

                getline(reading, phizika);
                record << phizika << endl;

                getline(reading, inform);
                record << inform << endl;

                getline(reading, matem);
                record << matem << endl;

                getline(reading, himia);
                record << himia << endl;

                getline(reading, sr_ball);
                record << sr_ball << endl;

                getline(reading, stroka);
                record << stroka << endl;
            }
        }
    }
    reading.close();
    record.close();
}

void Change()
{
    Copy();

    ifstream reading("newzapici.txt");
    ofstream record("zapici.txt", ios::out);

    if (reading)
    {
        if (record)
        {
            string name = "";
            string year = "";
            string group = "";
            string phizika = "";
            string inform = "";
            string matem = "";
            string himia = "";
            string sr_ball = "";
            string stroka = "";
            int n, k;
            reading >> n;

            cout << "       Введите номер записи, которую хотите изменить: " << endl;
            cin >> k;
            k--;

            record << n << endl;
            getline(reading, stroka);
            if (k >= 0 && k < n)
            {
                for (int i = 0; i < n; i++)
                {
                    if (i != k)//если не наш студент
                    {
                        getline(reading, name);
                        record << name << endl;

                        getline(reading, year);
                        record << year << endl;

                        getline(reading, group);
                        record << group << endl;

                        getline(reading, phizika);
                        record << phizika << endl;

                        getline(reading, inform);
                        record << inform << endl;

                        getline(reading, matem);
                        record << matem << endl;

                        getline(reading, himia);
                        record << himia << endl;

                        getline(reading, sr_ball);
                        record << sr_ball << endl;

                        getline(reading, stroka);
                        record << stroka << endl;
                    }
                    else {
                        Student* std = new Student[n];

                        cout << "ФИО: " << endl;
                        cin.ignore(100, '\n');
                        gets_s(std[i].name);
                        record << std[i].name << endl;

                        cout << "Год рождения: " << endl;
                        cin >> std[i].year;
                        record << std[i].year << endl;

                        cout << "Номер группы: " << endl;
                        cin >> std[i].group_number;
                        record << std[i].group_number << endl;

                        cout << "Физика: " << endl;
                        cin >> std[i].phizika;
                        record << std[i].phizika << endl;

                        cout << "Информатика: " << endl;
                        cin >> std[i].inform;
                        record << std[i].inform << endl;

                        cout << "Математика: " << endl;
                        cin >> std[i].matem;
                        record << std[i].matem << endl;

                        cout << "Химия: " << endl;
                        cin >> std[i].himia;
                        record << std[i].himia << endl;

                        std[i].average_number = (std[i].inform + std[i].matem + std[i].himia + std[i].phizika) / 4.;
                        cout << "Средний балл: " << std[i].average_number << endl;
                        record << std[i].average_number << endl;

                        //считываем те данные, которые хотим заменить
                        getline(reading, name);
                        getline(reading, year);
                        getline(reading, group);
                        getline(reading, phizika);
                        getline(reading, inform);
                        getline(reading, matem);
                        getline(reading, himia);
                        getline(reading, sr_ball);
                        getline(reading, stroka);
                    }
                }
            }
        }
    }
    reading.close();
    record.close();
    remove("newzapici.txt"); //удаление файла
}

void Delete()
{
    Copy();

    ifstream reading("newzapici.txt");
    ofstream record("zapici.txt", ios::out); //вывод с удалением старых данных

    if (reading)
    {
        if (record)
        {
            string name = "";
            string year = "";
            string group = "";
            string phizika = "";
            string inform = "";
            string matem = "";
            string himia = "";
            string sr_ball = "";
            string stroka = "";
            int n, k;
            reading >> n;
            int b = n - 1; //кол-во студентов после удаления

            cout << "       Введите номер записи, которую хотите изменить: " << endl;
            cin >> k;
            k--;

            record << b << endl;
            getline(reading, stroka);
            if (k >= 0 && k < n)
            {
                for (int i = 0; i < n; i++)
                {
                    if (i != k)
                    {
                        getline(reading, name);
                        record << name << endl;

                        getline(reading, year);
                        record << year << endl;

                        getline(reading, group);
                        record << group << endl;

                        getline(reading, phizika);
                        record << phizika << endl;

                        getline(reading, inform);
                        record << inform << endl;

                        getline(reading, matem);
                        record << matem << endl;

                        getline(reading, himia);
                        record << himia << endl;

                        getline(reading, sr_ball);
                        record << sr_ball << endl;

                        getline(reading, stroka);
                        record << stroka << endl;
                    }
                    else {
                        //у нас в файле есть указатели, которые показывают на опредеенные места и их надо сместить
                        //считываем инфу о студенте, чью запись удаляем
                        getline(reading, name);
                        getline(reading, year);
                        getline(reading, group);
                        getline(reading, phizika);
                        getline(reading, inform);
                        getline(reading, matem);
                        getline(reading, himia);
                        getline(reading, sr_ball);
                        getline(reading, stroka);
                    }
                }
            }
        }
    }
    reading.close();
    record.close();

    remove("newzapici.txt");
}

void Search()
{
    ifstream reading("zapici.txt"); 
    ofstream record("search.txt"); 
    ofstream counting("count.txt"); //число тех что надо

    if (reading)
    {
        if (record)
        {
            string name = "";
            string year = "";
            string group = "";
            string phizika = "";
            string inform = "";
            string matem = "";
            string himia = "";
            string sr_ball = "";
            string stroka = "";
            string str;
            int n, count = 0;
            reading >> n; //считываем из файла кол-во студентов
            cout << "Студенты, у которых балл по информатике и математике выше 4:" << endl;
            getline(reading, str);    //считываем строку с количеством студентов
            for (int i = 0; i < n; i++)
            {
                getline(reading, name);
                getline(reading, year);
                getline(reading, group);
                getline(reading, phizika);
                getline(reading, inform);
                getline(reading, matem);
                getline(reading, himia);
                getline(reading, sr_ball);
                getline(reading, stroka);
                if (inform > "4" && matem > "4")
                {
                    record << name << endl;
                    record << year << endl;
                    record << group << endl;
                    record << phizika << endl;
                    record << inform << endl;
                    record << matem << endl;
                    record << himia << endl;
                    record << sr_ball << endl;
                    record << stroka << endl;
                    count++; //кол-во студентов из одной группы
                }
            }  counting << count;
        }
    }
    reading.close();//закрываем потоки
    record.close();
}

void Infa()
{
    ifstream read("zapici.txt");
    ifstream reading("search.txt");
    ofstream record_("cash.txt"); //записываем неподходящих
    ifstream counting("count.txt");

    if (reading)
    {

        if (record_)
        {
            string name = "";
            string year = "";
            string group = "";
            string phizika = "";
            string inform = "";
            string matem = "";
            string himia = "";
            string stroka = "";
            string str;
            string s;
            int n, count;
            read >> n;
            counting >> count; //считываем кол-во студентов которое надо
            for (int i = 0; i < count; i++)
            {
                getline(reading, name);
                getline(reading, year);
                getline(reading, group);
                getline(reading, phizika);
                getline(reading, inform);
                getline(reading, matem);
                getline(reading, himia);
                getline(reading, str);
                getline(reading, stroka);
                cout << endl;
                if (inform > "4" && matem > "4")
                {
                    
                    cout << "ФИО: " << name << endl;
                    cout << "Год рождения: " << year << endl;
                    cout << "Номер группы: " << group << endl;
                    cout << "Физика: " << phizika << endl;
                    cout << "Информатика: " << inform << endl;
                    cout << "Математика: " << matem << endl;
                    cout << "Химия: " << himia << endl;
                    cout << stroka << endl;
                }
                else
                {
                    record_ << name;
                    record_ << year;
                    record_ << group;
                    record_ << phizika;
                    record_ << inform;
                    record_ << matem;
                    record_ << himia;
                    record_ << stroka;
                }
            }
        }
    }
    read.close();
    reading.close();
    record_.close();
}