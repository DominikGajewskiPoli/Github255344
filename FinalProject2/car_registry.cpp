#include "car_registry.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct Car {
    string brand;
    string model;
    int year;
};

void addCar(vector<Car>& cars) {
    Car car;
    cout << "Mark: ";
    cin >> car.brand;
    cout << "Model: ";
    cin >> car.model;
    cout << "Year of production: ";
    cin >> car.year;
    cars.push_back(car);
}

void deleteCar(vector<Car>& cars) {
    int index;
    cout << "Set the number of car to be deleted: ";
    cin >> index;
    if (index >= 1 && index <= cars.size()) {
        cars.erase(cars.begin() + index - 1);
    } else {
        cout << "Wrong number.\n";
    }
}

void showCars(const vector<Car>& cars) {
    if (cars.empty()) {
        cout << "No cars to show.\n";
        return;
    }
    for (size_t i = 0; i < cars.size(); ++i) {
        cout << i + 1 << ". " << cars[i].brand << " " << cars[i].model << ", " << cars[i].year << "\n";
    }
}

void exportCars(const vector<Car>& cars, const string& filename) {
    ofstream file(filename);
    for (const auto& car : cars) {
        file << car.brand << ";" << car.model << ";" << car.year << "\n";
    }
    file.close();
    cout << "Cars saved to file.\n";
}

void importCars(vector<Car>& cars, const string& filename) {
    ifstream file(filename);
    if (!file) {
        ofstream create(filename);
        create.close();
        cout << "Created new file: " << filename << "\n";
        return;
    }

    cars.clear();
    string line;
    while (getline(file, line)) {
        size_t pos1 = line.find(';');
        size_t pos2 = line.rfind(';');
        if (pos1 != string::npos && pos2 != string::npos && pos1 != pos2) {
            Car car;
            car.brand = line.substr(0, pos1);
            car.model = line.substr(pos1 + 1, pos2 - pos1 - 1);
            car.year = stoi(line.substr(pos2 + 1));
            cars.push_back(car);
        }
    }
    file.close();
    cout << "Cars imported from file.\n";
}

void carRegistry() {
    vector<Car> cars;
    int option;
    do {
        cout << "\n--- Car Registry ---\n";
        cout << "1. Add a car\n2. Delete a car\n3. Show all cars\n";
        cout << "4. Export to file\n5. Import from file\n0. Back\nChoose: ";
        cin >> option;
        switch (option) {
            case 1: addCar(cars); break;
            case 2: deleteCar(cars); break;
            case 3: showCars(cars); break;
            case 4: exportCars(cars, "cars.txt"); break;
            case 5: importCars(cars, "cars.txt"); break;
        }
    } while (option != 0);
}