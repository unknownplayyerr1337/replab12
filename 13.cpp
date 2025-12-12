#include <iostream>
#include <iomanip>
#include <cstring>
#include "windows.h"
using namespace std;
struct Doctor {
    char surname[50];
    char specialization[30];
    int experience;
};
const int NUM_DOCTORS = 5;
void print_doctor(const Doctor& doc) {
    cout << setw(15) << doc.surname
        << setw(20) << doc.specialization
        << setw(10) << doc.experience << " р." << endl;
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Doctor clinic[NUM_DOCTORS] = {
        {"Ковальчук", "Хірург", 10},
        {"Мельник", "Терапевт", 5},
        {"Петренко", "Хірург", 15},
        {"Сидоренко", "Окуліст", 8},
        {"Іваненко", "Терапевт", 22}
    };
    cout << "=== Інформація про співробітників клініки ===" << endl;
    cout << "\tПрізвище\tСпеціалізація\t  Стаж" << endl;
    cout << "--------------------------------------------------------" << endl;
    for (int i = 0; i < NUM_DOCTORS; ++i) {
        print_doctor(clinic[i]);
    }
    cout << "--------------------------------------------------------" << endl;
    char target_specialization[30];
    cout << "\nВведіть спеціалізацію для пошуку: ";
    cin.getline(target_specialization, 30);
    cout << "\n=> Список лікарів за спеціалізацією \"" << target_specialization << "\":" << endl;
    int count_specialists = 0;
    for (int i = 0; i < NUM_DOCTORS; ++i) {
        if (strcmp(clinic[i].specialization, target_specialization) == 0) {
            cout << "  Прізвище: " << setw(10) << clinic[i].surname
                << ", Стаж роботи: " << clinic[i].experience << " р." << endl;
            count_specialists++;
        }
    }
    if (count_specialists == 0) {
        cout << "  Лікарі із спеціалізацією \"" << target_specialization << "\" не знайдені." << endl;
    }
    cout << "--------------------------------------------------------" << endl;
    int total_experience = 0;
    for (int i = 0; i < NUM_DOCTORS; ++i) {
        total_experience += clinic[i].experience;
    }
    double average_experience = static_cast<double>(total_experience) / NUM_DOCTORS;
    cout << "\nРозрахунок середнього стажу:" << endl;
    cout << "  Загальний стаж (сума): " << total_experience << " років" << endl;
    cout << "  Кількість лікарів: " << NUM_DOCTORS << endl;
    cout << "  **Середній стаж: "
        << fixed << setprecision(2) << average_experience << " років**" << endl;
    cout << "--------------------------------------------------------" << endl;
    system("pause");
    return 0;
}
