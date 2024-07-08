#include <iostream>
using namespace std;

class MyClass {
private:
    int value;

public:
    MyClass(int v) : value(v) {}

    // Non-const member function
    void non_const_mem_function() 
    {
        cout << "Non-const member function called. Value = " << value << endl;
        value++;
    }

    // Const member function
    void const_mem_function() const 
    {
        cout << "Const member function called. Value = " << value << endl;
        // value++; // Error: Cannot modify 'value' in a const member function
    }

    // Function to get value (for demonstration)
    int getValue() const 
    {
        return value;
    }
};

int main() 
{
    // Creating a const object
    const MyClass const_object(10);

    // i) const_object.non_const_mem_function
    // Error: Cannot call non-const member function on a const object
    // const_object.non_const_mem_function();

    // ii) const_object.const_mem_function
    const_object.const_mem_function(); // Allowed, does not modify the object

    // iii) non_const_object.non_const_mem_function
    MyClass non_const_object(20);
    non_const_object.non_const_mem_function(); // Modifies the object

    // iv) non_const_object.const_mem_function
    non_const_object.const_mem_function(); // Allowed, does not modify the object

    return 0;
}
