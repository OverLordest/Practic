#include "plant.h"

//#include <discpp.h>

#include <cmath>
#include <vector>
#include <iostream>
using namespace std;
using std::vector;

size_t k = 0;
vector <size_t> L;
size_t N = 0;
size_t M = 0;
void Vvod() {
    bool fl = true;
//Ввод количество каналов управления
    while (fl)
    {
        cout << "Vvedite kolinchestvo kanalov ypravlenia(1-4)" << "\n";
        cin >> k;
        if (k <= 4 && k >= 1)
        {
            fl = false;
        }
        else
        {
            cout << "ERROR nepravilniy diapazon" << "\n";
        }
    }
    L.resize(k);
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
    //Ввод цисла повторений измерений
        cout << "Vvedite kol-vo povtoreniy";
        cin >> N;
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
 
}

