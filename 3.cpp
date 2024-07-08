#include <iostream>
#include <string>
using namespace std;

class Department 
{
private:
    int deptId;
    string deptName;

public:
    // Constructor to initialize department ID and name
    Department(int id, const string& name) : deptId(id), deptName(name) 
    {
        cout << "Constructor invoked for Department " << deptId << ": " << deptName << endl;
    }

    // Destructor to display message when object goes out of scope
    ~Department() 
    {
        cout << "Destructor invoked for Department " << deptId << ": " << deptName << ". Object goes out of scope." << endl;
    }
};

int main() 
{
    // Creating Department objects
    Department dept1(101, "Engineering");
    Department dept2(201, "Human Resources");

    {
        Department dept3(301, "Marketing");
        // dept3 goes out of scope after this block
    }

    // dept1 and dept2 go out of scope at the end of main function

    return 0;
}
