#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;

// Define structure for storing car information
struct Car {
    string model;               // Car model
    string made;                // Car make (manufacturer)
    int year;                   // Car manufacture year
    double paymentPerSecond;    // Payment rate per second
    bool isAvailable;           // Availability status of the car
};

// Define structure for storing customer information
struct Customer {
    string name;                            // Customer name
    string address;                         // Customer address
    string phone;                           // Customer phone number
    bool hasRentedCar;                      // Flag to check if the customer has rented a car
    Car* rentedCar;                         // Pointer to the rented car
    high_resolution_clock::time_point startTime;   // Start time of car rental
    high_resolution_clock::time_point endTime;     // End time of car rental
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
    vector<Car> cars;            // List to store available cars
    vector<Customer> customers;  // List to store registered customers

    // Add some initial cars to the system
    addCar(cars, "Toyota Corolla", "Toyota", 2022, 0.01);
    addCar(cars, "Ford Mustang", "Ford", 2021, 0.01);
    addCar(cars, "Honda Civic", "Honda", 2020, 0.02);
    addCar(cars, "Chevrolet Camaro", "Chevrolet", 2019, 0.03);

    while (true) {
        // Display the main menu
        cout << "\n-----------------------------------" << endl;
        cout << "      Welcome to Car Rental System" << endl;
        cout << "-----------------------------------" << endl;
        cout << "1. Register a New User" << endl;
        cout << "2. View Available Cars" << endl;
        cout << "3. Rent a Car" << endl;
        cout << "4. Return a Car" << endl;
        cout << "5. Check Payment Details" << endl;
        cout << "6. Exit" << endl;
        cout << "-----------------------------------" << endl;
        cout << "Enter your choice (1-6): ";

        int choice;
        cin >> choice;

        // Check for invalid input
        if (cin.fail() || choice < 1 || choice > 6) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input. Please enter a number between 1 and 6.\n" << endl;
            continue;
        }

        // Handle user menu selection
        switch (choice) {
            case 1:
                addUser(customers);  // Register a new user
                break;
            case 2:
                displayCars(cars);  // Display available cars
                break;
            case 3:
                rentCar(cars, customers);  // Rent a car
                break;
            case 4:
                returnCar(customers);  // Return a car
                break;
            case 5:
                handlePayment(customers);  // Handle payment details
                break;
            case 6:
                cout << "\nThank you for using the Car Rental System. Have a great day!\n" << endl;
                return 0;  // Exit the program
            default:
                cout << "\nAn unexpected error occurred. Please try again.\n" << endl;
                break;
        }
    }
    return 0;
}

// Function to add a car to the system
void addCar(vector<Car>& cars, const string& model, const string& made, int year, double paymentPerSecond) {
    cars.push_back({model, made, year, paymentPerSecond, true});  // Add car to the list of cars
}

// Function to display available cars
void displayCars(const vector<Car>& cars) {
    cout << "\nAvailable Cars:\n";
    cout << left << setw(15) << "Made" << setw(15) << "Model" << setw(10) << "Year" << setw(10) << "Rate ($/s)" << endl;

    // Loop through the cars and display those that are available
    for (const auto& car : cars) {
        if (car.isAvailable) {
            cout << left << setw(15) << car.made << setw(15) << car.model
                 << setw(10) << car.year << setw(10) << car.paymentPerSecond << endl;
        }
    }
}

// Function to register a new customer
void addUser(vector<Customer>& customers) {
    string name, address, phone;
    cout << "\nEnter your name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter your address: ";
    getline(cin, address);
    cout << "Enter your phone number: ";
    cin >> phone;

    Customer* customer = nullptr;

    // Check if the phone number already exists in the system
    for (auto& cust : customers) {
        if (cust.phone == phone) {
            customer = &cust;
            break;
        }
    }

    // If user not found, register new user
    if (!customer) {
        customers.push_back({name, address, phone, false, nullptr});
        cout << "User registered successfully.\n";
        return;
    }
    else {
        cout << "Account already in use. Please check your name and phone number.\n";
    }
}

// Function to rent a car
void rentCar(vector<Car>& cars, vector<Customer>& customers) {
    string userName, model, made;
    int year;

    cout << "\nEnter your name: ";
    cin.ignore();
    getline(cin, userName);

    // Find the customer by name
    Customer* customer = nullptr;
    for (auto& cust : customers) {
        if (cust.name == userName) {
            customer = &cust;
            break;
        }
    }

    // If customer is not found, prompt to register first
    if (!customer) {
        cout << "User not found! Please register first.\n";
        return;
    }

    // Get car details to rent
    cout << "Enter the car make: ";
    getline(cin, made);
    cout << "Enter the car model: ";
    getline(cin, model);
    cout << "Enter the car year: ";
    cin >> year;

    // Find the car in the system
    Car* car = nullptr;
    for (auto& c : cars) {
        if (c.made == made && c.model == model && c.year == year && c.isAvailable) {
            car = &c;
            break;
        }
    }

    // If car is available, assign it to the customer and start rental
    if (!car) {
        cout << "Car not available or not found.\n";
        return;
    }

    customer->rentedCar = car;
    customer->hasRentedCar = true;
    customer->startTime = high_resolution_clock::now();  // Start rental time
    car->isAvailable = false;  // Mark the car as unavailable
    cout << "Car rented successfully.\n";
}

// Function to return a rented car
void returnCar(vector<Customer>& customers) {
    string userName;

    cout << "\nEnter your name: ";
    cin.ignore();
    getline(cin, userName);

    // Find the customer who has rented a car
    Customer* customer = nullptr;
    for (auto& cust : customers) {
        if (cust.name == userName && cust.hasRentedCar) {
            customer = &cust;
            break;
        }
    }

    // If no rental found, prompt the user
    if (!customer) {
        cout << "No active rental found for this user.\n";
        return;
    }

    // Record the return time and mark car as available
    customer->endTime = high_resolution_clock::now();
    customer->rentedCar->isAvailable = true;
    customer->hasRentedCar = false;
    cout << "Car returned successfully.\n";
}

// Function to handle payment based on rental duration
void handlePayment(vector<Customer>& customers) {
    string userName;

    cout << "\nEnter your name: ";
    cin.ignore();
    getline(cin, userName);

    // Find the customer who has rented a car
    Customer* customer = nullptr;
    for (auto& cust : customers) {
        if (cust.name == userName && !cust.hasRentedCar && cust.rentedCar != nullptr) {
            customer = &cust;
            break;
        }
    }

    // If no payment for this user , tell the user
    if (!customer) {
        cout << "No payment due for this user.\n";
        return;
    }

    // Calculate the abount of time for the  rental and total payment
    auto duration = duration_cast<seconds>(customer->endTime - customer->startTime);
    double totalPayment = duration.count() * customer->rentedCar->paymentPerSecond;
    cout << "Total time rented: " << duration.count() << " seconds.\n";
    cout << "Total payment: $" << totalPayment << "\n";

    customer->rentedCar = nullptr;  // Reset the rented car details
}
