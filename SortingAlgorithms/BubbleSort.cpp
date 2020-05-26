// Bubble sort
#include<iostream>
using namespace std;

/* ------- Bubble sort code begins here ------- */
void bubbleSort(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len-i-1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
/* ------- Bubble sort code ends here ------- */

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

    bubbleSort(a, len);

    cout << "After sorting\n";
    printArray(a, len);

    return 0;
}
