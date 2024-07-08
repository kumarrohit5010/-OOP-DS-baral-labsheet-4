#include <iostream>
using namespace std;

class ParkingCharge {
private:
    int num_vehicle;
    int hour;
    double rate;

public:
    // Constructor with initialization and discount calculation
    ParkingCharge(int vehicles, int hrs, double r) 
    {
        num_vehicle = vehicles;
        hour = hrs;
        rate = r;

        // Apply 10% discount if num_vehicle exceeds 10
        if (num_vehicle > 10) 
        {
            rate *= 0.9;
        }
    }

    // Copy constructor for deep copy
    ParkingCharge(const ParkingCharge& other) 
    {
        num_vehicle = other.num_vehicle;
        hour = other.hour;
        rate = other.rate;
    }

    // Function to calculate and display total charge
    void calculateCharge() 
    {
        double total = hour * rate * num_vehicle;
        cout << "Total Charge: $" << total << endl;
    }
};

int main() 
{
    // Create an object with initial values
    ParkingCharge charge1(8, 2, 5.0);
    
    // Display total charge for charge1
    cout << "Charge 1: ";
    charge1.calculateCharge();

    // Create a copy of charge1 using the copy constructor
    ParkingCharge charge2(charge1);

    // Display total charge for charge2
    cout << "Charge 2 (copy of Charge 1): ";
    charge2.calculateCharge();

    return 0;
}
