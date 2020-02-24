#include "plant.h"

//#include <discpp.h>

#include <cmath>
#include <vector>
#include <iostream>
using namespace std;
using std::vector;

size_t k = 0;
vector <size_t> L;
vector <float> U;
vector <double> X;
size_t N = 0;
size_t M = 0;
bool fl = true;
void Vvod() {  
//Ввод количество каналов управления
    while (fl)
    {
        cout << "Vvedite kolinchestvo kanalov ypravlenia(1-4)" << "\n";
        cin >> k;
        if (k < 5 && k > 0)
        {
            fl = false;
        }
        else
        {
            cout << "ERROR nepravilniy diapazon" << "\n";
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
            cout << "Vvedite nomer kanala L[" << i << "] dlya ispolzovania(7-10)";
            cin >> L[i];
            if (L[i] < 11 && L[i] > 6)
            {
                fl = false;
            }
            else
            {
                cout << "ERROR nepravilniy diapazon" << "\n";
            }
        }
    }
    fl = true;
    //Ввод числа повторений измерений
        cout << "Vvedite kol-vo povtoreniy";
        cin >> N;
        X.resize(N);
    //Ввод номера датчика
        while (fl)
        {
            cout << "Vvedite nomer  datchika  (1-6)";
            cin >> M;
            if (M < 7 && M > 0)
            {
                fl = false;
            }
            else
            {
                cout << "ERROR nepravilniy diapazon" << "\n";
            }
        }
        fl = true;

}
//Рассчёт среднего значения
double MiddleSize() 
{
    double s=0;
    for (size_t i = 0; i < N; i++)
    {
        s += X[i];
    }
    return(s/N);
}


int main() {
    // Инициализация ОУ.
    Plant plant;
    plant_init(plant);
    /*// Получение экспериментальных данных.
    const int channel = 64;
    const size_t steps = 100;

    vector<double> xs(steps);
    vector<double> ys(steps);

    for (size_t i = 0; i < steps; i++) {
        xs[i] = i;
        ys[i] = plant_measure(channel, plant);
        cout << ys[i] << '\t'; //Вывод результатов измерений в консоль
    }*/
    Vvod();

    //Подача значений на каналы управлений
    for (size_t i = 0; i < k; i++)
    {
        fl = true;
        while (fl)
        {
            switch (L[i])
            {               
            case 7:
                cout << "Vvedite ypravlenie(-70;70)";
                cin >>U[i];
                if (U[i]>=-70 && U[i]<=70)
                {
                    fl = false;
                }
                else
                {
                    cout << "ERROR nepravilniy diapozon";
                }
                break;
            case 8:
                cout << "Vvedite ypravlenie(-3;3)";
                cin >> U[i];
                if (U[i] >= -3 && U[i] <= 3)
                {
                    fl = false;
                }
                else
                {
                    cout << "ERROR nepravilniy diapozon";
                }
                break;
            case 9:
                cout << "Vvedite ypravlenie(-5;5)";
                cin >> U[i];
                if (U[i] >= -5 && U[i] <= 5)
                {
                    fl = false;
                }
                else
                {
                    cout << "ERROR nepravilniy diapozon";
                }
                break;
            case 10:
                cout << "Vvedite ypravlenie(-70;70)";
                cin >> U[i];
                if (U[i] >= -2.5 && U[i] <= 2.5)
                {
                    fl = false;
                }
                else
                {
                    cout << "ERROR nepravilniy diapozon";
                }
                break;
            }
        }
    }
    //Конец подачи на конал управления
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
    for (size_t i = 0; i < N; i++)
    {
    cout << X[i];
    }
    cout << MiddleSize();
}

