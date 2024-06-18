#include <iostream>
#include <cmath>
#include <string>
#include <iomanip> 
using namespace std;

// Constants for cost calculation
const double CostPerHour = 18.50;
const double CostPerMinute = .40;
const double CostOfDinner = 20.70;

// Function prototypes
double calculateCostForOneServer(int minutes);
int calculateNumberOfServers(int guests);
double calculateTotalFoodCost(int guests);
double calculateAverageCostPerPerson(double totalFoodCost, int guests);
double calculateTotalCost(double totalFoodCost, double costForOneServer, int numberOfServers);
double calculateDepositAmount(double totalCost);

// Event class to encapsulate the event details
class Event {
public:
    string eventName;
    string firstName;
    string lastName;
    int numberOfGuests;
    int numberOfMinutes;

public:
    void getEventDetails() {
        cout << "Enter the name of the event: " << endl;
        cin >> eventName;
        cout << "Enter the customer's first and last name: " << endl;
        cin >> firstName >> lastName;
        cout << "Enter the number of guests: " << endl;
        cin >> numberOfGuests;
        cout << "Enter the number of minutes for the event: " << endl;
        cin >> numberOfMinutes;
    }

    int getNumberOfGuests() {
        return numberOfGuests;
    }

    int getNumberOfMinutes() {
        return numberOfMinutes;
    }
};

// Main function
int main() {
    cout << "********************EVENT MANAGEMENT SYSTEM********************" << endl;
    Event event;
    event.getEventDetails();

    int numberOfGuests = event.getNumberOfGuests();
    int numberOfMinutes = event.getNumberOfMinutes();

    int numberOfServers = calculateNumberOfServers(numberOfGuests);
    double costForOneServer = calculateCostForOneServer(numberOfMinutes);
    double totalFoodCost = calculateTotalFoodCost(numberOfGuests);
    double averageCostPerPerson = calculateAverageCostPerPerson(totalFoodCost, numberOfGuests);
    double totalCost = calculateTotalCost(totalFoodCost, costForOneServer, numberOfServers);
    double depositAmount = calculateDepositAmount(totalCost);

    // Display the cost estimation with two decimal places
    cout << fixed << setprecision(2); // Set the output to show two decimal places
    cout << "\n==================== Event estimate for: " << event.firstName << " " << event.lastName << " ====================" << endl;
    cout << "Number of Servers: " << numberOfServers << endl;
    cout << "The cost for one server: $" << costForOneServer << endl;
    cout << "The cost for food: $" << totalFoodCost << endl;
    cout << "Average cost per person: $" << averageCostPerPerson << endl;
    cout << "\nTotal cost: $" << totalCost << endl;
    cout << "Please deposit a 25% deposit to reserve the event." << endl;
    cout << "The deposit needed is: $" << depositAmount << endl;

    return 0;
}

// Function to calculate the number of servers needed
int calculateNumberOfServers(int guests) {
    return ceil(static_cast<double>(guests) / 20);
}

// Function to calculate the cost for one server
double calculateCostForOneServer(int minutes) {
    int hours = minutes / 60;
    int remainingMinutes = minutes % 60;
    return (hours * CostPerHour) + (remainingMinutes * CostPerMinute);
}

// Function to calculate the total food cost
double calculateTotalFoodCost(int guests) {
    return guests * CostOfDinner;
}

// Function to calculate the average cost per person
double calculateAverageCostPerPerson(double totalFoodCost, int guests) {
    return totalFoodCost / guests;
}

// Function to calculate the total cost
double calculateTotalCost(double totalFoodCost, double costForOneServer, int numberOfServers) {
    return totalFoodCost + (costForOneServer * numberOfServers);
}

// Function to calculate the deposit amount
double calculateDepositAmount(double totalCost) {
    return totalCost * 0.25;
}
