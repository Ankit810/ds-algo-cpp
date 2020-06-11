#include<iostream>
using namespace std;

int size;

int parent(int i) {return ((i-1)/2);}
int leftChild(int i) {return (2*i + 1);}
int rightChild(int i) {return (2*i + 2);}

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
    while(i != 0 && arr[parent(i)] < arr[i])
    {
        arr[parent(i)] = arr[i];
        i = parent(i);
    }
    arr[i] = value;
}

void maxHeapify(int arr[], int i)
{
    int left = leftChild(i);
    int right = rightChild(i);

    int largest = i;
    if (left < size && arr[left] > arr[largest]) largest = left;
    if (right < size && arr[right] > arr[largest]) largest = right;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        maxHeapify(arr, largest);
    }
}

void deleteNode(int arr[], int idx)
{
    arr[idx] = arr[size - 1];
    size--;
    maxHeapify(arr, idx);
}

void buildHeap(int arr[])
{
    int start = (size/2) - 1;
    for(int i = start; i>=0; i--)
    {
        maxHeapify(arr, i);
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
    int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
    size = sizeof(arr) / sizeof(arr[0]); 
    buildHeap(arr);
    
    cout << "Heap\n";
    printHeap(arr);

    deleteNode(arr, 4);
    
    cout << "Heap after deleting\n";
    printHeap(arr);
}
