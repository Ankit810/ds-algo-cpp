// Selection Sort
#include <iostream>
using namespace std;

/* ------- Selection sort code begins here ------- */
void selectionSort(int arr[], int len)
{
    int min;
    for (int i = 0; i < len - 1; i++) // only n - 2 passes needed
    {
        // find the minumum element and swap with current element if found
        min = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
/* ------- Selection sort code ends here ------- */

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

    selectionSort(a, len);

    cout << "After sorting\n";
    printArray(a, len);

    return 0;
}
