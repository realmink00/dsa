#include <iostream>
using namespace std;

struct node
{
    int seatNo;
    int booked;
    node *next;
    node *prev;
};

node *head[10];
int m, n;

void createRow(int r)
{
    head[r] = NULL;

    for (int i = 1; i <= n; i++)
    {
        node *temp = new node;
        temp->seatNo = i;
        temp->booked = ((r + i) % 3 == 0);

        if (head[r] == NULL)
        {
            head[r] = temp;
            temp->next = temp;
            temp->prev = temp;
        }
        else
        {
            node *last = head[r]->prev;

            last->next = temp;
            temp->prev = last;
            temp->next = head[r];
            head[r]->prev = temp;
        }
    }
}

void display()
{
    for (int r = 0; r < m; r++)
    {
        cout << "Row " << r + 1 << ": ";

        node *temp = head[r];

        if (temp == NULL)
        {
            cout << "No seats\n";
            continue;
        }

        do
        {
            if (temp->booked == 0)
                cout << temp->seatNo << " ";

            temp = temp->next;
        } while (temp != head[r]);

        cout << endl;
    }
}

void bookSeat(int r, int s)
{
    if (r < 1 || r > m || s < 1 || s > n)
    {
        cout << "Invalid seat!\n";
        return;
    }

    node *temp = head[r - 1];

    do
    {
        if (temp->seatNo == s)
        {
            if (temp->booked == 1)
                cout << "Seat already booked!\n";
            else
            {
                temp->booked = 1;
                cout << "Seat booked successfully!\n";
            }
            return;
        }

        temp = temp->next;
    } while (temp != head[r - 1]);
}

void cancelSeat(int r, int s)
{
    if (r < 1 || r > m || s < 1 || s > n)
    {
        cout << "Invalid seat!\n";
        return;
    }

    node *temp = head[r - 1];

    do
    {
        if (temp->seatNo == s)
        {
            if (temp->booked == 0)
                cout << "Seat is not booked!\n";
            else
            {
                temp->booked = 0;
                cout << "Booking cancelled!\n";
            }
            return;
        }

        temp = temp->next;
    } while (temp != head[r - 1]);
}

int main()
{
    cout << "Enter number of rows: ";
    cin >> m;

    cout << "Enter seats per row: ";
    cin >> n;

    if (m < 1 || m > 10 || n < 1)
    {
        cout << "Invalid dimensions!\n";
        return 0;
    }

    for (int i = 0; i < m; i++)
        createRow(i);

    int choice, r, s;

    do
    {
        cout << "\n1. Display Available Seats\n";
        cout << "2. Book Seat\n";
        cout << "3. Cancel Booking\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            display();
            break;

        case 2:
            cout << "Enter row and seat number: ";
            cin >> r >> s;
            bookSeat(r, s);
            break;

        case 3:
            cout << "Enter row and seat number: ";
            cin >> r >> s;
            cancelSeat(r, s);
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}