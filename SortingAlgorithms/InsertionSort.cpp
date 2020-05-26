// Insertion sort
#include<iostream>
using namespace std;

/* ------- Insertion sort code begins here ------- */
void insertionSort(int arr[], int len)
{
    for (int i = 1; i < len; i++)
    {
        int value = arr[i]; // value to be inserted
        int pos = i;
        while (pos > 0 && arr[pos - 1] > value)
        {
            arr[pos] = arr[pos-1];
            pos--;
        }
        arr[pos] = value;
    }
}
/* ------- Insertion sort code ends here ------- */

void printArray(int a[], int len)
{
    for (int i = 0; i < len; i++)
        cout << a[i] << "\t";
    cout << endl;
}

int main()
{
    int a[] = {20, 1, 4, 2, 10, 8};
    int len = sizeof(a) / sizeof(a[0]);
    cout << "Before sorting\n";
    printArray(a, len);

    insertionSort(a, len);

    cout << "After sorting\n";
    printArray(a, len);

    return 0;
}
