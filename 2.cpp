#include <iostream>
#include <cstring> // For strlen, strcpy
using namespace std;
class StringConcat 
{
private:
    char *str;

public:
    // Constructor to allocate memory and initialize the string
    StringConcat(const char *initial = "") 
    {
        str = new char[strlen(initial) + 1]; // Allocate memory
        strcpy(str, initial); // Copy initial to str
    }

    // Destructor to free dynamically allocated memory
    ~StringConcat() 
    {
        delete[] str;
    }

    // Function to concatenate two StringConcat objects
    void join(const StringConcat &s1, const StringConcat &s2) 
    {
        delete[] str; // Free existing memory if any

        // Calculate length of concatenated string
        int len = strlen(s1.str) + strlen(s2.str) + 1;

        str = new char[len]; // Allocate memory for the concatenated string
        strcpy(str, s1.str); // Copy s1.str to str
        strcat(str, s2.str); // Concatenate s2.str to str
    }

    // Function to display the concatenated string
    void display() const 
    {
        cout << "Concatenated String: " << str << endl;
    }
};

int main() {
    // Create two StringConcat objects with initial strings
    StringConcat s1("Engineers are");
    StringConcat s2(" Creatures of logic");

    // Create a third StringConcat object to store the result
    StringConcat result;

    // Concatenate s1 and s2
    result.join(s1, s2);

    // Display the concatenated string
    result.display();

    return 0;
}
