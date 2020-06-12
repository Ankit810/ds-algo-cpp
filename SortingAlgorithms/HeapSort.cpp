// Heap sort in descending order (using min heap)
#include <iostream>
using namespace std;

int size;

int parent(int i) { return ((i - 1) / 2); }
int leftChild(int i) { return (2 * i + 1); }
int rightChild(int i) { return (2 * i + 2); }

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void minHeapify(int arr[], int i, int n)
{
    int left = leftChild(i);
    int right = rightChild(i);

    int smallest = i;
    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);
        minHeapify(arr, smallest, n);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << "\t";
    cout << endl;
}

void heapSort(int *arr, int n)
{
    // build the heap from given array
    int start = (n / 2) - 1; // first non-leaf node
    for (int i = start; i >= 0; i--)
    {
        minHeapify(arr, i, n);
    }

    for(int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        minHeapify(arr, 0, i); // pass i here because the size keeps decreasing
    }
}

int main()
{
    int arr[] = {13, 3, 17, 5, 9, 4, 6, 1, 10, 8, 15};
    size = sizeof(arr)/sizeof(arr[0]);
    cout << "Before sorting\n";
    printArray(arr, size);

    heapSort(arr, size);

    cout << "After sorting\n";
    printArray(arr, size);
}