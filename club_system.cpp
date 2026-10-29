#include <iostream>
#include <string>
using namespace std;

struct node {
    string name;
    string prn;
    node* next;

    node(string n, string p) {
        name = n;
        prn = p;
        next = nullptr;
    }
};

class Linkedlist {
    node* head = nullptr;

public:
    void addPresident(string n, string p) {
        node* temp = new node(n, p);
        temp->next = head;
        head = temp;
    }

    void addsecratary(string n, string p) {
        node* temp = new node(n, p);

        if (head == nullptr) {
            head = temp;
            return;
        }

        node* ptr = head;

        while (ptr->next != nullptr)
            ptr = ptr->next;

        ptr->next = temp;
    }

    void addmember(string n, string p) {
        if (head == nullptr || head->next == nullptr)
            return;

        node* ptr = head;

        while (ptr->next->next != nullptr)
            ptr = ptr->next;

        node* temp = new node(n, p);
        temp->next = ptr->next;
        ptr->next = temp;
    }

    void delete_president() {
        if (head == nullptr)
            return;

        node* temp = head;
        head = head->next;
        delete temp;
    }

    void delete_secratary() {
        if (head == nullptr)
            return;

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        node* ptr = head;

        while (ptr->next->next != nullptr)
            ptr = ptr->next;

        delete ptr->next;
        ptr->next = nullptr;
    }

    void deletemember(string p) {
        if (head == nullptr)
            return;

        if (head->prn == p) {
            node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        node* ptr = head;

        while (ptr->next != nullptr && ptr->next->prn != p)
            ptr = ptr->next;

        if (ptr->next == nullptr)
            return;

        node* temp = ptr->next;
        ptr->next = temp->next;
        delete temp;
    }

    void display() {
        node* ptr = head;

        while (ptr != nullptr) {
            cout << ptr->prn << " " << ptr->name << endl;
            ptr = ptr->next;
        }
    }

    int count() {
        int cnt = 0;
        node* ptr = head;

        while (ptr != nullptr) {
            cnt++;
            ptr = ptr->next;
        }

        return cnt;
    }

    void concat(Linkedlist& other) {
        if (this == &other || other.head == nullptr)
            return;

        if (head == nullptr) {
            head = other.head;
        } else {
            node* ptr = head;

            while (ptr->next != nullptr)
                ptr = ptr->next;

            ptr->next = other.head;
        }

        other.head = nullptr;
    }
};

int main() {
    int choice, div;
    string n, p;

    Linkedlist list1, list2;

    do {
        cout << "\n1. Add President";
        cout << "\n2. Add Member";
        cout << "\n3. Add Secretary";
        cout << "\n4. Display Members";
        cout << "\n5. Delete Member";
        cout << "\n6. Delete President";
        cout << "\n7. Delete Secretary";
        cout << "\n8. Count Members";
        cout << "\n9. Concatenate Lists";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter division (1/2): ";
            cin >> div;
            cout << "Enter PRN and name: ";
            cin >> p >> n;

            if (div == 1)
                list1.addPresident(n, p);
            else
                list2.addPresident(n, p);
            break;

        case 2:
            cout << "Enter division (1/2): ";
            cin >> div;
            cout << "Enter PRN and name: ";
            cin >> p >> n;

            if (div == 1)
                list1.addmember(n, p);
            else
                list2.addmember(n, p);
            break;

        case 3:
            cout << "Enter division (1/2): ";
            cin >> div;
            cout << "Enter PRN and name: ";
            cin >> p >> n;

            if (div == 1)
                list1.addsecratary(n, p);
            else
                list2.addsecratary(n, p);
            break;

        case 4:
            cout << "Enter division (1/2): ";
            cin >> div;

            if (div == 1)
                list1.display();
            else
                list2.display();
            break;

        case 5:
            cout << "Enter division (1/2): ";
            cin >> div;
            cout << "Enter PRN to delete: ";
            cin >> p;

            if (div == 1)
                list1.deletemember(p);
            else
                list2.deletemember(p);
            break;

        case 6:
            cout << "Enter division (1/2): ";
            cin >> div;

            if (div == 1)
                list1.delete_president();
            else
                list2.delete_president();
            break;

        case 7:
            cout << "Enter division (1/2): ";
            cin >> div;

            if (div == 1)
                list1.delete_secratary();
            else
                list2.delete_secratary();
            break;

        case 8:
            cout << "Enter division (1/2): ";
            cin >> div;

            if (div == 1)
                cout << list1.count() << endl;
            else
                cout << list2.count() << endl;
            break;

        case 9:
            list1.concat(list2);
            list1.display();
            break;

        case 0:
            break;

        default:
            cout << "Invalid choice";
        }

    } while (choice != 0);

    return 0;
}