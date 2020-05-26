// Merge sort
#include <iostream>
using namespace std;

/* ------- Merge sort code begins here ------- */
void merge(int array[], int l, int m, int r)
{

    // size of left and right sub-arrays
    int nl = m - l + 1;
    int nr = r - m;

    // declare left and right sub-arrays
    int larr[nl], rarr[nr];

    // fill left and right sub-arrays
    for (int i = 0; i < nl; i++)
        larr[i] = array[l + i];
    for (int i = 0; i < nr; i++)
        rarr[i] = array[(m + 1) + i];

    int i = 0;
    int j = 0;
    int k = l; // fill array starting from l

    //merge temp arrays to real array
    while (i < nl && j < nr)
    {
        if (larr[i] <= rarr[j])
        {
            array[k] = larr[i];
            i++;
        }
        else
        {
            array[k] = rarr[j];
            j++;
        }
        k++;
    }

    // only one of these two while loops will be executed

    // extra elements in left array
    while (i < nl)
    {
        array[k] = larr[i];
        i++;
        k++;
    }

    // extra elements in right array
    while (j < nr)
    {
        array[k] = rarr[j];
        j++;
        k++;
    }
}
void mergeSort(int array[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merge(array, l, m, r);
    }
}
/* ------- Merge sort code ends here ------- */

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main()
{
    int a[] = {20, 1, 4, 2, 10, 8};
    int len = sizeof(a) / sizeof(a[0]);
    cout << "Before sorting\n";
    printArray(a, len);

    mergeSort(a, 0, len - 1);

    cout << "After sorting\n";
    printArray(a, len);

    return 0;
}