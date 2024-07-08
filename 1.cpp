#include <iostream>
#include <iomanip>

using namespace std;

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    // Constructors
    Time() 
    {
        hour = 0;
        minute = 0;
        second = 0;
    }

    Time(int h, int m, int s) 
    {
        hour = h;
        minute = m;
        second = s;
    }

    // Function to add two Time objects and return the result
    Time add_time(const Time& t) 
    {
        Time temp;
        temp.second = second + t.second;
        temp.minute = minute + t.minute + temp.second / 60;
        temp.hour = hour + t.hour + temp.minute / 60;

        temp.second %= 60;
        temp.minute %= 60;
        temp.hour %= 24;

        return temp;
    }

    // Function to display time in 12-hour format
    void display_12_hour_format() 
    {
        int h = hour;
        string period = "AM";

        if (h >= 12) 
        {
            period = "PM";
            if (h > 12)
                h = h-12;
        }

        if (h == 0)
            h = 12;

        cout << setw(2) << setfill('0') << h << ":"
             << setw(2) << setfill('0') << minute << ":"
             << setw(2) << setfill('0') << second << " " << period << endl;
    }

    // Function to display time in 24-hour format
    void display_24_hour_format() 
    {
        cout << setw(2) << setfill('0') << hour << ":"
             << setw(2) << setfill('0') << minute << ":"
             << setw(2) << setfill('0') << second << endl;
    }
};

int main() {
    // Example usage
    Time t1(10, 30, 45);
    Time t2(3, 15, 20);

    cout << "Time 1 (24-hour format): ";
    t1.display_24_hour_format();
    cout << "Time 1 (12-hour format): ";
    t1.display_12_hour_format();

    cout << "Time 2 (24-hour format): ";
    t2.display_24_hour_format();
    cout << "Time 2 (12-hour format): ";
    t2.display_12_hour_format();

    Time t3 = t1.add_time(t2);
    cout << "Time 1 + Time 2 (24-hour format): ";
    t3.display_24_hour_format();
    cout << "Time 1 + Time 2 (12-hour format): ";
    t3.display_12_hour_format();

    return 0;
}
