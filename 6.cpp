#include <iostream>
using namespace std;

class SerialNumber {
private:
    static int count; // Static data member to hold the serial number
    int serial;

public:
    SerialNumber() 
    {
        count++; // Increment count for each object created
        serial = count; // Assign serial number based on count
    }

    // Static member function to get the current count (serial number)
    static int getCount() 
    {
        return count;
    }

    // Member function to get the serial number of the current object
    int getSerial() const 
    {
        return serial;
    }
};

// Initialize static data member count
int SerialNumber::count = 0;

int main() 
{
    // Create several objects of SerialNumber class
    SerialNumber obj1, obj2, obj3;

    // Display serial numbers of each object
    cout << "Serial number of obj1: " << obj1.getSerial() << endl;
    cout << "Serial number of obj2: " << obj2.getSerial() << endl;
    cout << "Serial number of obj3: " << obj3.getSerial() << endl;

    // Get the current count (total number of objects created)
    cout << "Total objects created so far: " << SerialNumber::getCount() << endl;

    // Create more objects
    SerialNumber obj4, obj5;

    // Display serial numbers and updated count
    cout << "Serial number of obj4: " << obj4.getSerial() << endl;
    cout << "Serial number of obj5: " << obj5.getSerial() << endl;
    cout << "Total objects created so far: " << SerialNumber::getCount() << endl;

    return 0;
}
