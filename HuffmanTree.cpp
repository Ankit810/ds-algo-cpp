// Huffman coding in C++
#include <iostream>
using namespace std;

#define CAPACITY 100
#define MAX_TREE_HT 100

class Node
{
public:
    char data;
    int freq;
    Node *left, *right;

    Node(char data, int freq)
    {
        this->data = data;
        this->freq = freq;
        left = right = NULL;
    }
};

int size;
Node **nodeArray = new Node *[CAPACITY];

int parent(int i) { return ((i - 1) / 2); }
int leftChild(int i) { return (2 * i + 1); }
int rightChild(int i) { return (2 * i + 2); }

void swap(Node *&a, Node *&b)
{
    Node *temp = a;
    a = b;
    b = temp;
}

void insert(Node *nodeArray[], char data, int freq)
{
    nodeArray[size] = new Node(data, freq);
    size++;
    int i = size - 1;
    while (i && nodeArray[parent(i)]->freq > nodeArray[i]->freq)
    {
        swap(nodeArray[parent(i)], nodeArray[i]);
        i = parent(i);
    }
}

void insertNode(Node *nodeArray[], Node *node)
{
    nodeArray[size] = node;
    size++;
    int i = size - 1;
    while (i && nodeArray[parent(i)]->freq > nodeArray[i]->freq)
    {
        swap(nodeArray[parent(i)], nodeArray[i]);
        i = parent(i);
    }
}

void minHeapify(Node *nodeArray[], int i)
{
    int left = leftChild(i);
    int right = rightChild(i);

    int smallest = i;
    if (left < size && nodeArray[left]->freq < nodeArray[smallest]->freq)
        smallest = left;
    if (right < size && nodeArray[right]->freq < nodeArray[smallest]->freq)
        smallest = right;

    if (smallest != i)
    {
        swap(nodeArray[smallest], nodeArray[i]);
        minHeapify(nodeArray, smallest);
    }
}

Node *extractNode(Node *nodeArray[], int idx)
{
    Node *temp = nodeArray[idx];
    nodeArray[idx] = nodeArray[size - 1];
    size--;
    minHeapify(nodeArray, idx);
    return temp;
}

void buildHeap(Node *nodeArray[])
{
    int start = (size / 2) - 1;
    for (int i = start; i >= 0; i--)
    {
        minHeapify(nodeArray, i);
    }
}

void printHeap(Node *nodeArray[])
{
    for (int i = 0; i < size; ++i)
        cout << nodeArray[i]->data << "\t";
    cout << endl;
}

bool isLeaf(Node *node)
{
    return !(node->left) && !(node->right);
}

void createMinHeap(char data[], int freq[])
{
    for (int i = 0; i < size; i++)
    {
        nodeArray[i] = new Node(data[i], freq[i]);
    }

    buildHeap(nodeArray);
}

Node *buildHuffmanTree(char data[], int freq[], int s)
{
    size = s;
    createMinHeap(data, freq);
    Node *left, *right, *top;
    while (size != 1)
    {
        left = extractNode(nodeArray, 0);
        right = extractNode(nodeArray, 0);

        top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertNode(nodeArray, top);
    }

    return extractNode(nodeArray, 0);
}

void printCodes(Node *root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (isLeaf(root))
    {
        cout << root->data << ": ";

        // print arr
        for (int i = 0; i < top; i++)
        {
            cout << arr[i];
        }
        cout << endl;
    }
}

int main()
{

    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int size = sizeof(data) / sizeof(data[0]);

    Node *root = buildHuffmanTree(data, freq, size);

    int arr[MAX_TREE_HT];
    printCodes(root, arr, 0);

    /*

    Expected output:
    f: 0
    c: 100
    d: 101
    a: 1100
    b: 1101
    e: 111

    */
    return 0;
}