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

void insert(int arr[], int value)
{
    size++;
    int i = size - 1;
    while (i != 0 && arr[parent(i)] > arr[i])
    {
        arr[parent(i)] = arr[i];
        i = parent(i);
    }
    arr[i] = value;
}

void minHeapify(int arr[], int i)
{
    int left = leftChild(i);
    int right = rightChild(i);

    int smallest = i;
    if (left < size && arr[left] < arr[smallest])
        smallest = left;
    if (right < size && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);
        minHeapify(arr, smallest);
    }
}

void deleteNode(int arr[], int idx)
{
    arr[idx] = arr[size - 1];
    size--;
    minHeapify(arr, idx);
}

void buildHeap(int arr[])
{
    int start = (size / 2) - 1;
    for (int i = start; i >= 0; i--)
    {
        minHeapify(arr, i);
    }
}

void printHeap(int arr[])
{
    for (int i = 0; i < size; ++i)
        cout << arr[i] << "\t";
    cout << endl;
}

int main()
{
    int arr[] = {13, 3, 17, 5, 9, 4, 6, 1, 10, 8, 15};
    size = sizeof(arr) / sizeof(arr[0]);
    buildHeap(arr);

    cout << "Heap\n";
    printHeap(arr);

    deleteNode(arr, 4);

    cout << "Heap after deleting\n";
    printHeap(arr);
}
