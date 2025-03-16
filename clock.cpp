#include <iostream>//to input and output

#include <iomanip> //to (setfill and setw)

#include <thread> //to spead of run code

using namespace std;

int main() {
    int h, m, s;

    // take hours
    do {
        cout << "Enter hours (0-23): ";
        cin >> h;
        if (cin.fail() || h < 0 || h > 23) {
            cin.clear(); 
            cin.ignore(1000, '\n');
            h = -1; 
        }
    } while (h < 0 || h > 23);
    
    // take minutes
    do {
        cout << "Enter minutes (0-59): ";
        cin >> m;
        if (cin.fail() || m < 0 || m > 59) {
            cin.clear();
            cin.ignore(1000, '\n');
            m = -1;
        }
    } while (m < 0 || m > 59);
    
    // take seconds
    do {
        cout << "Enter seconds (0-59): ";
        cin >> s;
        if (cin.fail() || s < 0 || s > 59) {
            cin.clear();
            cin.ignore(1000, '\n');
            s = -1;
        }
    } while (s < 0 || s > 59);

    //running clock
    while (true) {
        cout << "\033[2J\033[1;1H"; // ANSI 

        // time in HH:MM:SS 
    cout<<"######## clock ########"<<endl<<endl;
        cout <<"\t"<<setfill('0') << setw(2) << h << ":"
             << setfill('0') << setw(2) << m << ":"
             << setfill('0') << setw(2) << s << endl;

        // Increment seconds
        s++;

        // Handle overflow of seconds, minutes, and hours
        if (s == 60) {
            s = 0;
            m++;
        }
        if (m == 60) {
            m = 0;
            h++;
        }
        if (h == 24) {
            h = 0;
        }

        // Pause for one second
        this_thread::sleep_for(chrono::seconds(1));
        }
    return 0;
}