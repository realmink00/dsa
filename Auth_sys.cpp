
#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

struct Employee {
    string username;
    int passwordHash;
    bool occupied;
};

Employee table[SIZE];

int hashFunction(string s) {
    int sum = 0;

    for (int i = 0; i < s.length(); i++) {
        sum = sum + s[i];
    }

    return sum % SIZE;
}

void insertEmployee(string username, string password) {
    int index = hashFunction(username);

    for (int i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

       //not really needed
        if (table[pos].occupied &&
            table[pos].username == username) {
            table[pos].passwordHash = hashFunction(password);
            cout << "Employee updated!\n";
            return;
        }
       //till here
        if (table[pos].occupied == false) {
            table[pos].username = username;
            table[pos].passwordHash = hashFunction(password);
            table[pos].occupied = true;

            cout << "Employee registered!\n";
            return;
        }
    }

    cout << "Hash table is full!\n";
}

bool authenticate(string username, string password) {
    int index = hashFunction(username);

    for (int i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        if (table[pos].occupied == false) {
            return false;
        }

        if (table[pos].username == username) {
            int enteredHash = hashFunction(password);

            return enteredHash == table[pos].passwordHash;
        }
    }

    return false;
}

int main() {
    // Register sample employees
    insertEmployee("alice", "pass123");
    insertEmployee("bob", "hello7");
    insertEmployee("charlie", "abc456");

    string username, password;

    cout << "\n--- Employee Login ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (authenticate(username, password)) {
        cout << "Authentication successful!\n";
    }
    else {
        cout << "Authentication failed!\n";
    }

    return 0;
}
