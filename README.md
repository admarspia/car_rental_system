# Car Rental System

A simple and interactive car rental system implemented in C++. This project allows users to register, view available cars, rent a car, return it, and calculate payment based on the duration of the rental.

## Features
- **User Registration**: Allows new customers to register with their details.
- **View Available Cars**: Displays all cars available for rent, including their make, model, year, and rental rate.
- **Rent a Car**: Users can rent a car by specifying the car's make, model, and year.
- **Return a Car**: Users can return rented cars and make them available for others.
- **Payment Calculation**: Calculates the total payment based on the duration of the rental and the car's rate.

## Technologies Used
- Language: **C++**
- Libraries:
  - `<iostream>` for input and output.
  - `<string>` for string manipulations.
  - `<vector>` for managing dynamic lists of cars and customers.
  - `<algorithm>` for sorting and searching.
  - `<chrono>` for handling time-based calculations.
  - `<iomanip>` for formatted output.

## How to Run
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/car-rental-system.git

    Navigate to the Project Directory:

cd car-rental-system

Compile the Program: Use a C++ compiler like g++:

g++ -o car_rental car_rental.cpp

Run the Program:

    ./car_rental

Usage

    Run the program.
    Choose from the menu options:
        Register a new user.
        View available cars.
        Rent a car by specifying its make, model, and year.
        Return a rented car.
        Check payment details.
    Follow on-screen prompts for input.

Example Interaction

    Register a user with their name, address, and phone number.
    View a list of available cars for rent.
    Rent a car by specifying its details.
    Return the car and see the total payment calculated based on the time rented.

Code Overview
Main Components

    Structs:
        Car: Represents a car with details like model, make, year, rate, and availability.
        Customer: Represents a customer with personal details and rental information.
    Functions:
        addCar: Adds cars to the system.
        displayCars: Displays all available cars.
        addUser: Registers new customers.
        rentCar: Assigns a car to a user and starts the rental timer.
        returnCar: Returns the car and ends the rental timer.
        handlePayment: Calculates and displays the payment details.

Future Enhancements

    Add support for multiple branches (e.g., different locations for car rentals).
    Implement database integration for persistent data storage.
    Introduce a graphical user interface (GUI) for enhanced user experience.
    Add features like advanced search filters for cars and customer rental history.

## Example Output

```plaintext

    -----------------------------------
        Welcome to Car Rental System
    -----------------------------------
    1. Register a New User
    2. View Available Cars
    3. Rent a Car
    4. Return a Car
    5. Check Payment Details
    6. Exit
    -----------------------------------
    Enter your choice (1-6): 1
    
    Enter your name: Hanan
    Enter your address: dessie
    Enter your phone number: 09********
    User registered successfully.
  
    -----------------------------------
  
    Enter your choice (1-6): 2
    
    Available Cars:
    Made           Model          Year      Rate ($/s)
    Toyota         Toyota Corolla 2022      0.01      
    Ford           Ford Mustang   2021      0.01      
    Honda          Honda Civic    2020      0.02      
    Chevrolet      Chevrolet Camaro2019      0.03   

    -----------------------------------
                    -
    -----------------------------------
                    -
    -----------------------------------
```

---



Contributing

Contributions are welcome! If you'd like to contribute, please:

    Fork the repository.
    Create a feature branch: git checkout -b feature-name.
    Commit your changes: git commit -m 'Add feature-name'.
    Push to the branch: git push origin feature-name.
    Open a pull request.

Contact

For questions or feedback, please contact:

    Name: [Admarspis]
    Email: 1admarspias@gmail.com
    GitHub: https://github.com/admarspia

Happy Coding!

Feel free to customize the placeholders, like the repository link or any additional features you'd like to highlight!
