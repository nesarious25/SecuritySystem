#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    int a;
    int i = 0;
    string text, old, password1, password2, pass, name, password0, age, user, word, word1;
    string creds[2], cp[2];
    cout << " security system " << endl;
    cout << "                 " << endl;
    cout << "                 " << endl;
    cout << "                 " << endl;
    cout << "   1. register   " << endl;
    cout << "   2. login      " << endl;
    cout << "   3. change password  " << endl;
    cout << "   4. end program      " << endl;

    do {
        cout << endl << endl;
        cout << "enter your choice" << endl;
        cin >> a;
        switch (a)
        {
        case 1: {
            cout << "            " << endl;
            cout << "   Register     " << endl;
            cout << "                 " << endl;
            cout << "   please enter your name   ";
            cin >> name;
            cout << "   enter the password   ";
            cin >> password0;
            cout << " please enter your age  ";
            cin >> age;

            ofstream of1;
            of1.open("file.txt");
            if (of1.is_open()) {
                of1 << name << endl;
                of1 << password0;
                cout << "registration successful" << endl;
            }
            break;
        }

        case 2: {
            i = 0;
            cout << "_______________________" << endl;
            cout << "- - - - - login - - - - -" << endl;
            cout << endl;

            ifstream if1;
            if1.open("file.txt");
            cout << "enter the username  ";
            cin >> user;
            cout << "enter the password  ";
            cin >> pass;

            if (if1.is_open()) {
                while (getline(if1, text)) {
                    istringstream iss(text);
                    iss >> word;
                    creds[i] = word;
                    i++;
                }
                if (user == creds[0] && pass == creds[1]) {
                    cout << "login successful" << endl << endl;

                    cout << " details " << endl;
                    cout << " username " << name << endl;
                    cout << " password " << pass << endl;
                    cout << "age " << age << endl;
                }
                else {
                    cout << endl << endl;
                    cout << "incorrect details" << endl;
                    cout << "1. press 2 to login" << endl;
                    cout << "2. press 3 to change password" << endl;
                    break;
                }
            }
            break;
        }

        case 3: {
            i = 0;
            cout << " change password" << endl;

            ifstream if2;
            if2.open("file.txt");
            cout << "enter the old password: ";
            cin >> old;
            if (if2.is_open()) {
                while (getline(if2, text)) {
                    istringstream iss(text);
                    iss >> word1;
                    cp[i] = word1;
                    i++;
                }
                if (old == cp[1]) {
                    if2.close();
                    ofstream of1;
                    of1.open("file.txt");
                    if (of1.is_open()) {
                        cout << "enter your new password " << endl;
                        cin >> password1;

                        cout << "enter your password again " << endl;
                        cin >> password2;
                        if (password1 == password2) {
                            of1 << cp[0] << endl;
                            of1 << password1;
                            cout << "password changed successfully" << endl;
                        }
                        else {
                            of1 << cp[0] << endl;
                            of1 << old;
                            cout << "please enter the valid password" << endl;
                            break;
                        }
                    }
                }
            }
            break;
        }

        case 4: {
            cout << "-----Thank you!-----" << endl;
            break;
        }

        default:
            cout << "Enter a Valid choice" << endl;
        }
    } while (a != 4);

    return 0;
}