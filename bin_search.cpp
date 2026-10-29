#include <iostream>
using namespace std;
int BinarySearch(int size, int arr[], int target)
{
    int start = 0, end = size - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == target)
            return mid;
        else if (target > arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}
int main()
{
    int n, arr[100], target;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter target: ";
    cin >> target;
    cout << "Index: " << BinarySearch(n, arr, target);
    return 0;
}