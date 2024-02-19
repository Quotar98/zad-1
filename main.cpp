#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

// Funkcja do wyznaczania mediany
double median(vector<int>& values) {
    sort(values.begin(), values.end());
    int n = values.size();
    if (n % 2 == 0) {
        int middle1 = values[n / 2 - 1];
        int middle2 = values[n / 2];
        return (middle1 + middle2) / 2.0;
    } else {
        return values[n / 2];
    }
}

// Funkcja do wyznaczania procentowej czestotliwoœci mody
void mode_percentage(vector<int>& values) {
    map<int, int> frequency;

    for (int value : values) {
        frequency[value]++;
    }

    int maxFrequency = 0;
    int modeValue = 0;

    for (const auto& entry : frequency) {
        if (entry.second > maxFrequency) {
            maxFrequency = entry.second;
            modeValue = entry.first;
        }
    }

    double percentage = static_cast<double>(maxFrequency) / values.size() * 100.0;

    cout << "Moda: " << modeValue << " z " << percentage << "% czestotliwosci" << endl;
}

int main() {
    const int size = 20;
    vector<int> array;

    // Inicjalizacja generatora liczb pseudolosowych
    srand(static_cast<unsigned int>(time(nullptr)));

    // Wypelnienie tablicy losowymi liczbami od 50 do 99
    for (int i = 0; i < size; ++i) {
        array.push_back(rand() % 50 + 50);
    }

    // Wyswietlenie uporzadkowanych wartosci
    sort(array.begin(), array.end());
    cout << "Uporzadkowane wartosci w tablicy: ";
    for (int value : array) {
        cout << value << " ";
    }
    cout << endl;

    // Wyznaczenie i wyswietlenie mediany
    cout << "Mediana: " << median(array) << endl;

    // Wyznaczenie i wyswietlenie mody w formie procentowej czestotliwosci
    mode_percentage(array);

    return 0;
}
