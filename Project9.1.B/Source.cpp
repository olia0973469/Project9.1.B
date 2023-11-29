#pragma execution_character_set("utf-8")

#include <iostream> 
#include <iomanip> 
#include <string> 
#include <Windows.h>
using namespace std;

enum Special { CS, INF, MATH, PHYS, HAND };

string specialStr[] = { "��������� �����", "�����������", "���������� �� ��������", "Գ���� �� �����������", "������� ��������" };
struct Student
{
    string   prizv;
    unsigned kurs;
    Special   special;
    int phys;
    int math;
    union
    {
        int prog;
        int chisMath;
        int pedagog;
    };
};


void Create(Student* p, const int N);
void Print(Student* p, const int N);
double Math(Student* p, const int N);
double Physics(Student* p, const int N);
double Progr(Student* p, const int N);
double ChisMath(Student* p, const int N);
double Pedagog(Student* p, const int N);
int Count(Student* p, const int N);

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int N;
    cout << "������ N: "; cin >> N;

    Student* p = new Student[N];

    Create(p, N);
    Print(p, N);

    double ser = Math(p, N);
    cout << ser << endl;
    double ser1 = Physics(p,N);
    cout << ser1 << endl;
    double ser2 = Progr(p, N);
    cout << ser2 << endl;
    double ser3 = ChisMath(p, N);
    cout << ser3 << endl;
    double ser4 = Pedagog(p, N);
    cout << ser4 << endl;
    int c = Count(p, N);
    cout << c << endl;
    return 0;
}

void Create(Student* p, const int N)
{
    int spec;
    for (int i = 0; i < N; i++)
    {
        cout << "������� � " << i + 1 << ":" << endl;

        cin.get();
        cin.sync();

        cout << "    �������: "; getline(cin, p[i].prizv);
        cout << "    ����: "; cin >> p[i].kurs;
        cout << "    ������ � ����������(0-5): "; cin >> p[i].math;
        cout << "    ������ � ������(0-5): "; cin >> p[i].phys;
        cout << "    ������������ (0 - ��������� �����, 1 - �����������, 2 - ���������� �� ��������, 3 - Գ���� �� �����������, 4 - ������� ��������): ";
        cin >> spec;
        p[i].special = (Special)spec;
        switch (p[i].special)
        {
        case CS:
            cout << "    ������ � �������������(0-5): "; cin >> p[i].prog;
            break;
        case INF:
            cout << "    ������ � ��������� ������(0-5): "; cin >> p[i].chisMath;
            break;
        case MATH:
        case PHYS:
        case HAND:
            cout << "    ������ � ���������(0-5): "; cin >> p[i].pedagog;
            break;
        }
        cout << endl;
    }
}

void Print(Student* p, const int N)
{
    cout << "================================================================================================================================" << endl;
    cout << "|  �  |   �������   |  ����  |   ������������   |   Գ����   |   ����������   | ������������� | ������� ������ | ��������� |" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(3) << right << i + 1 << " ";
        cout << "| " << setw(13) << left << p[i].prizv
            << "|    " << setw(1) << right << p[i].kurs << "    "
            << "| " << setw(25) << left << specialStr[p[i].special]
            << "| " << setw(3) << right << p[i].phys << "    | " << setw(3) << right << p[i].math;

        switch (p[i].special)
        {
        case CS:
            cout << "             | " << setw(13) << right << p[i].prog << "     |" << setw(16) << right << "      |" << endl;
            break;
        case INF:
            cout << "    | " << setw(14) << right << p[i].chisMath << "  |" << setw(15) << right << "       |" << endl;
            break;
        case MATH:
        case PHYS:
        case HAND:
            cout << "             |" << setw(19) << right << "      | " << setw(14) << right << p[i].pedagog << "  |" << endl;
            break;
        }
    }
    cout <<
        "================================================================================================================================" << endl;
    cout << endl;
}

double Math(Student* p, const int N)
{
    cout << "������� ��� � ����������:" << endl;
    double b = 0, n = 0;
    for (int i = 0; i < N; i++)
    {
        b = ((p[i].math) * 1.0) + b;
    }
    return b / N;
}

double Physics(Student* p, const int N)
{
    cout << "������� ��� � ������:" << endl;
    double b = 0, n = 0;
    for (int i = 0; i < N; i++)
    {
        b = ((p[i].phys) * 1.0) + b;
    }
    return b / N;
}

double Progr(Student* p, const int N)
{
    cout << "������� ��� � �������������:" << endl;
    double b = 0, n = 0;
    for (int i = 0; i < N; i++)
    {
        if (p[i].special == CS)
        {
            n++;
            b = ((p[i].prog) + b);
        }
    }
    if (b == 0)
    {
        return 0;
    }
    return b / n;
}

double ChisMath(Student* p, const int N)
{
    cout << "������� ��� � ��������� ������:" << endl;
    double b = 0, n = 0;
    for (int i = 0; i < N; i++)
    {
        if (p[i].special == INF)
        {
            n++;
            b = ((p[i].chisMath) + b);
        }
    }
    if (b == 0)
    {
        return 0;
    }
    return b / n;
}

double Pedagog(Student* p, const int N)
{
    cout << "������� ��� � ���������:" << endl;
    double b = 0, n = 0;
    for (int i = 0; i < N; i++)
    {
        if (p[i].special == HAND)
        {
            n++;
            b = ((p[i].pedagog) + b);
        }
    }
    if (b == 0) 
    { 
        return 0; 
    }
    return b / n;
}

int Count(Student* p, const int N)
{
    cout << "ʳ������ �������� \"5 ��� 4 � ������\" (4, 5):" << endl;
    int k = 0;
    for (int i = 0; i < N; i++)
    {
        if ((p[i].phys == 4) ||
            (p[i].phys == 5))
            k++;
    }
    return k;
}