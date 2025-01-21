#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;

// Define structures for Car and Customer
struct Car {
    string model;
    string made;
    int year;
    double paymentPerSecond;
    bool isAvailable;
    int totalRentals = 0; // Track how many times the car has been rented
};

struct Customer {
    string name;
    string address;
    string phone;
    bool hasRentedCar;
    Car* rentedCar;
    high_resolution_clock::time_point startTime;
    high_resolution_clock::time_point endTime;
    double totalSpent = 0.0; // Track total money spent by the customer
};

// Declare functions
void addCar(vector<Car>& cars, const string& model, const string& made, int year, double paymentPerSecond);
void displayCars(const vector<Car>& cars);
void addUser(vector<Customer>& customers);
void rentCar(vector<Car>& cars, vector<Customer>& customers);
void returnCar(vector<Customer>& customers);
void handlePayment(vector<Customer>& customers);
void generateReport(const vector<Car>& cars, const vector<Customer>& customers);

int main() {
    vector<Car> cars;
    vector<Customer> customers;
    double totalRevenue = 0.0; // Track total revenue generated

    // Preload cars
  addCar(cars, "Toyota Corolla", "Toyota", 2022, 0.01);
  addCar(cars, "Ford Mustang", "Ford", 2021, 0.02);
  addCar(cars, "Honda Civic", "Honda", 2020, 0.03);
  addCar(cars, "Chevrolet Camaro", "Chevrolet", 2019, 0.04);
  addCar(cars, "Tesla Model S", "Tesla", 2023, 0.05);
  addCar(cars, "BMW 3 Series", "BMW", 2022, 0.04);
  addCar(cars, "Mercedes-Benz C-Class", "Mercedes", 2021, 0.04);
  addCar(cars, "Audi A4", "Audi", 2021, 0.03);
  addCar(cars, "Nissan Altima", "Nissan", 2020, 0.02);
  addCar(cars, "Hyundai Sonata", "Hyundai", 2019, 0.02);
  addCar(cars, "Volkswagen Passat", "Volkswagen", 2023, 0.03);
  addCar(cars, "Kia Optima", "Kia", 2022, 0.02);
  addCar(cars, "Subaru Outback", "Subaru", 2020, 0.03);
  addCar(cars, "Mazda CX-5", "Mazda", 2021, 0.03);
  addCar(cars, "Jeep Wrangler", "Jeep", 2023, 0.05);

    while (true) {
        cout << "\n-----------------------------------" << endl;
        cout << "      Welcome to Car Rental System" << endl;
        cout << "-----------------------------------" << endl;
        cout << "1. Register a New User" << endl;
        cout << "2. View Available Cars" << endl;
        cout << "3. Rent a Car" << endl;
        cout << "4. Return a Car" << endl;
        cout << "5. Check Payment Details" << endl;
        cout << "6. Generate Report" << endl;
        cout << "7. Exit" << endl;
        cout << "-----------------------------------" << endl;
        cout << "Enter your choice (1-7): ";

        int choice;
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 7) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "\nInvalid input. Please enter a number between 1 and 7.\n" << endl;
            continue;
        }

        switch (choice) {
            case 1:
                addUser(customers);
                break;
            case 2:
                displayCars(cars);
                break;
            case 3:
                rentCar(cars, customers);
                break;
            case 4:
                returnCar(customers);
                break;
            case 5:
                handlePayment(customers);
                break;
            case 6:
                generateReport(cars, customers);
                break;
            case 7:
                cout << "\nThank you for using the Car Rental System. Have a great day!\n" << endl;
                return 0;
            default:
                cout << "\nAn unexpected error occurred. Please try again.\n" << endl;
                break;
        }
    }
    return 0;
}

// Function to add a car to the system
void addCar(vector<Car>& cars, const string& model, const string& made, int year, double paymentPerSecond) {
    cars.push_back({model, made, year, paymentPerSecond, true});
}

// Function to display all available cars
void displayCars(const vector<Car>& cars) {
    cout << "\nAvailable Cars:\n";
    cout << left << setw(15) << "Made" << setw(15) << "Model" << setw(10) << "Year" << setw(10) << "Rate ($/s)" << endl;
    for (const auto& car : cars) {
        if (car.isAvailable) {
            cout << left << setw(15) << car.made << setw(15) << car.model 
                 << setw(10) << car.year << setw(10) << car.paymentPerSecond << endl;
        }
    }
}

// Function to add a new user
void addUser(vector<Customer>& customers) {
    string name, address, phone;
    cout << "\nEnter your name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter your address: ";
    getline(cin, address);
    cout << "Enter your phone number: ";
    cin >> phone;

    for (const auto& customer : customers) {
        if (customer.phone == phone) {
            cout << "A user with this phone number already exists.\n";
            return;
        }
    }

    customers.push_back({name, address, phone, false, nullptr});
    cout << "User registered successfully.\n";
}

// Function to rent a car
void rentCar(vector<Car>& cars, vector<Customer>& customers) {
    string userName, model, made;
    int year;

    cout << "\nEnter your name: ";
    cin.ignore();
    getline(cin, userName);

    Customer* customer = nullptr;
    for (auto& cust : customers) {
        if (cust.name == userName) {
            customer = &cust;
            break;
        }
    }

    if (!customer) {
        cout << "User not found! Please register first.\n";
        return;
    }

    cout << "Enter the car make: ";
    getline(cin, made);
    cout << "Enter the car model: ";
    getline(cin, model);
    cout << "Enter the car year: ";
    cin >> year;

    Car* car = nullptr;
    for (auto& c : cars) {
        if (c.made == made && c.model == model && c.year == year && c.isAvailable) {
            car = &c;
            break;
        }
    }

    if (!car) {
        cout << "Car not available or not found.\n";
        return;
    }

    customer->rentedCar = car;
    customer->hasRentedCar = true;
    customer->startTime = high_resolution_clock::now();
    car->isAvailable = false;
    car->totalRentals++;
    cout << "Car rented successfully.\n";
}

// Function to return a rented car
void returnCar(vector<Customer>& customers) {
    string userName;

    cout << "\nEnter your name: ";
    cin.ignore();
    getline(cin, userName);

    Customer* customer = nullptr;
    for (auto& cust : customers) {
        if (cust.name == userName && cust.hasRentedCar) {
            customer = &cust;
            break;
        }
    }

    if (!customer) {
        cout << "No active rental found for this user.\n";
        return;
    }

    customer->endTime = high_resolution_clock::now();
    customer->rentedCar->isAvailable = true;
    customer->hasRentedCar = false;
    cout << "Car returned successfully.\n";
}

// Function to generate report
void generateReport(const vector<Car>& cars, const vector<Customer>& customers) {
    cout << "\n--- Rental System Report ---\n";

    // Total revenue
    double totalRevenue = 0.0;
    for (const auto& customer : customers) {
        totalRevenue += customer.totalSpent;
    }
    cout << "Total Revenue: $" << totalRevenue << "\n";

    // Car rental stats
    cout << "\nCar Rental Statistics:\n";
    cout << left << setw(15) << "Made" << setw(15) << "Model" << setw(10) << "Year" << setw(15) << "Total Rentals" << endl;
    for (const auto& car : cars) {
        cout << left << setw(15) << car.made << setw(15) << car.model 
             << setw(10) << car.year << setw(15) << car.totalRentals << endl;
    }

    // Top customers
    cout << "\nTop Customers:\n";
    cout << left << setw(20) << "Name" << setw(15) << "Phone" << setw(15) << "Total Spent" << endl;
    for (const auto& customer : customers) {
        cout << left << setw(20) << customer.name << setw(15) << customer.phone << setw(15) << customer.totalSpent << endl;
    }
}
void handlePayment(vector<Customer>& customers) {
    string userName;

    cout << "\nEnter your name: ";
    cin.ignore();
    getline(cin, userName);

    Customer* customer = nullptr;
    for (auto& cust : customers) {
        if (cust.name == userName && !cust.hasRentedCar && cust.rentedCar != nullptr) {
            customer = &cust;
            break;
        }
    }

    if (!customer) {
        cout << "No pending payment found for this user.\n";
        return;
    }

    auto duration = duration_cast<seconds>(customer->endTime - customer->startTime);
    double totalPayment = duration.count() * customer->rentedCar->paymentPerSecond;

    // Display payment details
    cout << "\nPayment Details:\n";
    cout << "-----------------------------------\n";
    cout << "Car Model: " << customer->rentedCar->model << "\n";
    cout << "Car Make: " << customer->rentedCar->made << "\n";
    cout << "Rental Duration: " << duration.count() << " seconds\n";
    cout << "Rate (per second): $" << customer->rentedCar->paymentPerSecond << "\n";
    cout << "Total Payment: $" << fixed << setprecision(2) << totalPayment << "\n";
    cout << "-----------------------------------\n";

    // Reset customer rental details
    customer->rentedCar = nullptr;
    customer->startTime = {};
    customer->endTime = {};

    cout << "Payment completed successfully. Thank you!\n";
}
