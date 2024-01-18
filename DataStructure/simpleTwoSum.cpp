#include <iostream>

using namespace std;

int arraySummation(int arrNum, int arr[], int left, int right)
{
    int sum = 0;
    for (int i = left; i <= right; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}

int main()
{
    int arrNum;
    int arr[10000];
    int left, right;

    cout << "Enter the array number: " << endl;
    cin >> arrNum;
    cout << "Enter the array values" << endl;
    for (int i = 0; i < arrNum; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the left position: " << endl;
    cin >> left;

    cout << "Enter the right position: " << endl;
    cin >> right;

    int arraySum = arraySummation(arrNum, arr, left, right);
    cout << "The summation of the array from " << left << " to right " << right << " is: " << arraySum;

    return 0;
}
