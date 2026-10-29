#include <iostream>
using namespace std;

void input(int s[][3])
{
    cout << "Enter rows, columns and non-zero elements: ";
    cin >> s[0][0] >> s[0][1] >> s[0][2];

    for (int i = 1; i <= s[0][2]; i++)
    {
        cout << "Enter row, column and value: ";
        cin >> s[i][0] >> s[i][1] >> s[i][2];
    }
}

void display(int s[][3])
{
    cout << "Row Col Value\n";

    for (int i = 0; i <= s[0][2]; i++)
    {
        cout << s[i][0] << "   "
             << s[i][1] << "   "
             << s[i][2] << endl;
    }
}

void add(int a[][3], int b[][3], int c[][3])
{
    if (a[0][0] != b[0][0] ||
        a[0][1] != b[0][1])
    {
        cout << "Addition not possible!";
        return;
    }

    int i = 1, j = 1, k = 1;

    c[0][0] = a[0][0];
    c[0][1] = a[0][1];

    while (i <= a[0][2] && j <= b[0][2])
    {
        if (a[i][0] == b[j][0] &&
            a[i][1] == b[j][1])
        {

            int sum = a[i][2] + b[j][2];

            if (sum != 0)
            {
                c[k][0] = a[i][0];
                c[k][1] = a[i][1];
                c[k][2] = sum;
                k++;
            }

            i++;
            j++;
        }
        else if (a[i][0] < b[j][0] ||
                 (a[i][0] == b[j][0] &&
                  a[i][1] < b[j][1]))
        {

            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            i++;
            k++;
        }
        else
        {
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];
            j++;
            k++;
        }
    }
    while (i <= a[0][2])
    {
        c[k][0] = a[i][0];
        c[k][1] = a[i][1];
        c[k][2] = a[i][2];
        i++;
        k++;
    }
    while (j <= b[0][2])
    {
        c[k][0] = b[j][0];
        c[k][1] = b[j][1];
        c[k][2] = b[j][2];
        j++;
        k++;
    }
    c[0][2] = k - 1;
    cout << "\nAddition result:\n";
    display(c);
}
void transpose(int a[][3], int t[][3])
{
    int k = 1;

    t[0][0] = a[0][1]; // Rows become columns
    t[0][1] = a[0][0]; // Columns become rows
    t[0][2] = a[0][2]; // Same non-zero count

    for (int col = 0; col < a[0][1]; col++)
    {
        for (int i = 1; i <= a[0][2]; i++)
        {
            if (a[i][1] == col)
            {
                t[k][0] = a[i][1];
                t[k][1] = a[i][0];
                t[k][2] = a[i][2];
                k++;
            }
        }
    }
}
void fastTranspose(int a[][3], int t[][3])
{
    int total[100] = {0};
    int pos[100];

    int rows = a[0][0];
    int cols = a[0][1];
    int n = a[0][2];

    t[0][0] = cols;
    t[0][1] = rows;
    t[0][2] = n;

    // Count elements in each column
    for (int i = 1; i <= n; i++)
    {
        total[a[i][1]]++;
    }

    // Find starting position of each column
    pos[0] = 1;

    for (int i = 1; i < cols; i++)
    {
        pos[i] = pos[i - 1] + total[i - 1];
    }

    // Place each element directly
    for (int i = 1; i <= n; i++)
    {
        int col = a[i][1];
        int k = pos[col];

        t[k][0] = a[i][1];
        t[k][1] = a[i][0];
        t[k][2] = a[i][2];

        pos[col]++;
    }
}
int main()
{
    int a[100][3], b[100][3], c[200][3];
    int t[100][3], ft[100][3];
    cout << "First matrix:\n";
    input(a);
    cout << "\nSecond matrix:\n";
    input(b);
    cout << "\nFirst matrix:\n";
    display(a);
    cout << "\nSecond matrix:\n";
    display(b);
    cout << "\n";
    add(a, b, c);
    // Normal transpose of first matrix
    transpose(a, t);
    cout << "\nNormal transpose:\n";
    display(t);

    // Fast transpose of first matrix
    fastTranspose(a, ft);
    cout << "\nFast transpose:\n";
    display(ft);

    return 0;
}
