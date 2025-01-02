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
   git clone https://github.com/admarspia/car-rental-system.git

    Navigate to the Project Directory:

cd car-rental-system

Compile the Program: Use a C++ compiler like g++:

g++ -o car_rental car_rental.cpp

Run the Program:

    ./car_rental

## Usage Guide

### 1. Start the Program
- When you run the program, the system will display a menu with options:
    - **1. Register a New User**: Allows a new customer to register by entering their name, address, and phone number.
    - **2. View Available Cars**: Displays a list of cars that are currently available for rent, along with their details (make, model, year, and rental rate).
    - **3. Rent a Car**: Allows the user to rent a car by entering their name and selecting a car (make, model, and year).
    - **4. Return a Car**: Allows the user to return a rented car and mark it as available again.
    - **5. Check Payment Details**: Displays the total payment due for a car rental based on the rental duration.
    - **6. Exit**: Exits the program.

---

### 2. Register a New User
- Choose option **1** to register a new user.
- The system will prompt you to enter your **name**, **address**, and **phone number**.
- If the phone number is already registered, you will be notified, and no new account will be created.
- If registration is successful, a confirmation message will be displayed.

---

### 3. View Available Cars
- Choose option **2** to view the list of available cars.
- The system will display the following information for each available car:
  - **Make**: The brand of the car (e.g., Toyota, Ford, Honda).
  - **Model**: The specific model (e.g., Corolla, Mustang, Civic).
  - **Year**: The car's year of manufacture.
  - **Rate**: The car's rental rate per second.

---

### 4. Rent a Car
- Choose option **3** to rent a car.
- You will be asked to enter your **name** (which must match an existing registered user).
- Then, provide the **make**, **model**, and **year** of the car you wish to rent.
- If the car is available, the system will record the start time of the rental, assign the car to you, and mark the car as unavailable.
- A success message will confirm that the car is rented.

---

### 5. Return a Car
- Choose option **4** to return a rented car.
- You will need to enter your **name** (which must match the name of a user who has rented a car).
- If a car is successfully rented, the system will record the end time of the rental, calculate the total rental duration, and make the car available for others.
- A success message will confirm the car has been returned.

---

### 6. Check Payment Details
- Choose option **5** to check the payment details for a rental.
- Enter your **name** to view the payment details for the car you rented.
- The system will display:
  - The total time you rented the car (in seconds).
  - The total payment due, calculated by multiplying the rental time by the car's rate.
- Once the payment is processed, the car rental details will be cleared.

---

### Example Interaction
#### Scenario 1: Register a User


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
