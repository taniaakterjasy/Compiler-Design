#include <iostream>
using namespace std;

bool isValidString(string str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != 'a' && str[i] != 'b') {
            return false;
        }
    }
    return true;
}


char transition(char currentState, char input) {



    if (currentState == 'A') {
        if (input == 'a') return 'B';
        if (input == 'b') return 'C';
    }
    else if (currentState == 'B') {
        if (input == 'a') return 'D';
        if (input == 'b') return 'E';
    }


    return 'F';
}


bool simulateDFA(string str) {
    char currentState = 'A';

    for (int i = 0; str[i] != '\0'; i++) {
        currentState = transition(currentState, str[i]);
    }


    return true;
}

int main() {
    string str;

    for (int i = 0; i < 5; i++) {
        cout << "Enter string " << i + 1 << ": ";
        cin >> str;

        if (!isValidString(str)) {
            cout << "Rejected (Invalid characters)\n";
        }
        else if (simulateDFA(str)) {
            cout << "Accepted\n";
        }
        else {
            cout << "Rejected\n";
        }
    }

    return 0;
}
