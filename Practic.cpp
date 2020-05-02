#include "plant.h"
#include <conio.h> 
//#include <discpp.h>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;
using std::vector;

int k = 0;//Количество каналов управления
vector <size_t> L;//Номера используемых каналов управления
vector <double> U;//Управляющие воздействия пользователя
vector <double> X;//Измеряемые значения
size_t N = 0;//Число повторений измерений
size_t M = 0;//Номер датчика, канал опроса

//Ввод изначальных данных
void Vvod() {  
    setlocale(LC_ALL,"Russian");
    bool fl = true;
//Ввод количество каналов управления
    while (fl)
    {
        cout << "Введите количество канлов управления(1-4)" << "\n";
        cin >> k;
        if (k < 5 && k > 0)
        {
            fl = false;
        }
        else
        {
            cout << "ERROR" << "\n";
        }
    }
    L.resize(k);
    U.resize(k);
//Ввод использующихся каналов
    for (size_t i = 0; i < k; i++)
    {
        fl = true;
        while (fl)
        {
            cout << "Введите номер канала L[" << i << "] для использования(7-10)" << "\n";
            cin >> L[i];
            if (L[i] < 11 && L[i] > 6)
            {
                fl = false;
            }
            else
            {
                cout << "ERROR" << "\n";
            }
        }
    }
    fl = true;
    //Ввод числа повторений измерений
        cout << "Введите количество повторений измерений" << "\n";
        while (fl)
        {       
            cin >> N;
            if (N > 0)
            {
                fl = false;
            }
            else
            {
                cout << "ERROR Введите натуральное число" << "\n";
            }
        }             
        fl = true;
        X.resize(N);
    //Ввод номера датчика
        while (fl)
        {
            cout << "Введитк канал опроса (11-99)" << "\n";
            cin >> M;
            if (M <100 && M >10)
            {
                fl = false;
            }
            else
            {
                cout << "ERROR" << "\n";
            }
        }
        fl = true;

}
//Рассчёт среднего значения для X по N
double MiddleSize() 
{
    double s=0;
    for (size_t i = 0; i < N; i++)
    {
        s += X[i];
    }
    return(s/N);
}
//Подача значений на каналы управлений
void Control(size_t i)
{
    setlocale(LC_ALL, "Russian");
    bool fl = true;
    while (fl)
    {
        switch (L[i])
        {
        case 7:
            cout << "Введите управление (-70;70)" << "\n";
            cin >> U[i];
            if (U[i] >= -70 && U[i] <= 70)
            {
                fl = false;
            }
            else
            {
                cout << "ERROR";
            }
            break;
        case 8:
            cout << "Введите управление (-3;3)" << "\n";
            cin >> U[i];
            if (U[i] >= -3 && U[i] <= 3)
            {
                fl = false;
            }
            else
            {
                cout << "ERROR";
            }
            break;
        case 9:
            cout << "Введите управление (-5;5)" << "\n";
            cin >> U[i];
            if (U[i] >= -5 && U[i] <= 5)
            {
                fl = false;
            }
            else
            {
                cout << "ERROR";
            }
            break;
        case 10:
            cout << "Введите управление (-2.5;2.5)" << "\n";
            cin >> U[i];
            if (U[i] >= -2.5 && U[i] <= 2.5)
            {
                fl = false;
            }
            else
            {
                cout << "ERROR";
            }
            break;
        }
    }
        
}


int main() {
    setlocale(LC_ALL, "Russian");
    Plant plant;
    plant_init(plant);
    Vvod();
    bool check = true;
    while (check)
    {
        //Подача значений на каналы управлений
        for (size_t i = 0; i < k; i++)
        {   
                Control(i);
        }

        //Подача на объект управляющего воздействия
        for (size_t i = 0; i < k; i++)
        {
            plant_control(L[i], U[i], plant);
        }

        //Опрос датчиков
        for (size_t i = 0; i < N; i++)
        {
            X[i] = plant_measure(M, plant);
        }

        //Вывод Опрошенных датчиков
        for (size_t i = 0; i < N; i++)
        {
            cout << "X[" << i+1 << "]=" << X[i] << "\n";
        }

        //Вывод среднего значений опрошенных датчиков
        cout << "X=" << MiddleSize() << "\n";


        cout << "Нажмите '1' если хотите повторить или что-нибудь другое чтобы выйти"<<"\n";
        int C = 0;
        cin >> C;
        if (!(C == 1))
        {
            check = false;
        }
    }
}