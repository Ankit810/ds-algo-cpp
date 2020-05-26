// quick sort
#include<iostream>
using namespace std;

void swap(int &, int &);

/* ------- Quick sort code begins here ------- */
int partition(int array[], int start, int end)
{
    int pivot = array[end]; // assuming pivot element to always be rightmost element
    int pIndex = start;

    for (int i = start; i < end; i++) {
        if (array[i] <= pivot)
        {
            swap(array[i], array[pIndex]);
            pIndex++;
        }
    }

    swap(array[pIndex], array[end]);
    return pIndex;
}

void quickSort(int arr[], int start, int end)
{
    // base case
    if (start >= end) return;

    int pIndex = partition(arr, start, end);
    quickSort(arr, start, pIndex - 1);
    quickSort(arr, pIndex + 1, end);
}

/* ------- Quick sort code ends here ------- */

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

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

    quickSort(a, 0, len-1);

    cout << "After sorting\n";
    printArray(a, len);

    return 0;
}
