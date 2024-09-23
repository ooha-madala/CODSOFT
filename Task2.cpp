#include <iostream>
#include <limits>  // For std::numeric_limits
using namespace std;
// Function declarations
double add(double x, double y);
double subtract(double x, double y);
double multiply(double x, double y);
double divide(double x, double y);
int main() {
    double num1, num2;
    int operation;
    bool validInput = false;
    cout << "Welcome to the basic arithmetic calculator!" << endl;
    //First number
    while (!validInput) {
        cout << "Enter the first number: ";
        cin >> num1;
        if (cin.fail()) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter a numeric value." << endl;
        } 
        else {
            validInput = true;
        }
    }
    validInput = false; // reset for next input
    //Second number
    while (!validInput) {
        cout << "Enter the second number: ";
        cin >> num2;
        if (cin.fail()) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter a numeric value." << endl;
        } 
        else {
            validInput = true;
        }
    }
    // Choose operation
    cout << "\nChoose an operation:" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    while (true) {
        cout << "Enter the number of the operation (1/2/3/4): ";
        cin >> operation;
        if (cin.fail() || operation < 1 || operation > 4) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter 1, 2, 3, or 4." << endl;
        } 
        else {
            break;
        }
    }
    // Perform the operation
    double result;
    switch (operation) {
        case 1:
            result = add(num1, num2);
            cout << "\nThe result of " << num1 << " + " << num2 << " is: " << result << endl;
            break;
        case 2:
            result = subtract(num1, num2);
            cout << "\nThe result of " << num1 << " - " << num2 << " is: " << result << endl;
            break;
        case 3:
            result = multiply(num1, num2);
            cout << "\nThe result of " << num1 << " * " << num2 << " is: " << result << endl;
            break;
        case 4:
            if (num2 == 0) {
                cout << "Error: Division by zero is not allowed." << endl;
            } 
            else {
                result = divide(num1, num2);
                cout << "\nThe result of " << num1 << " / " << num2 << " is: " << result << endl;
            }
            break;
    }

    return 0;
}
// Function definitions
double add(double x, double y) {
    return x + y;
}
double subtract(double x, double y) {
    return x - y;
}
double multiply(double x, double y) {
    return x * y;
}
double divide(double x, double y) {
    return x / y;
}
