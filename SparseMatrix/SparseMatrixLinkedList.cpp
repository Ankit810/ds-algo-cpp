// Sparse Matrix representation using Linked List
#include<iostream>
using namespace std;


class Node
{
    public:
        int value, row, col;
        Node *next;
    Node()
    {
        next = NULL;
    }
    Node(int row, int col, int value)
    {
        this->row = row;
        this->col = col;
        this->value = value;
    }
};

void printNode(Node* node)
{
    cout << "Row: " << node->row << "  " << "Col: " << node->col << "  " << "Value: " << node->value << "\t";
    cout << endl;
}

void printList(Node *root)
{
    Node *temp = root;
    while(temp != NULL)
    {
        printNode(temp);
        temp = temp -> next;
    }
}

void createNewNode(Node *& root, int i, int j, int value)
{
    Node* temp = root;

    if (temp == NULL)
    {
        root = new Node(i, j, value);
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        if(temp) temp->next = new Node(i, j, value);
    }
}

int main()
{
    Node *root = NULL;

    int m = 5;
    int n = 4;
    int arr[][5] = { { 0, 1, 0, 0 }, 
                    { 0, 0, 2, 0 }, 
                    { 0, 3, 0, 0 }, 
                    { 0, 0, 5, 0 }, 
                    { 0, 0, 0, 4 } }; 
    Node *temp;
    for (int i = 0; i < m; i++)
    {
        for(int j=0; j < n; j++)
        {
            if (arr[i][j])
            {
                createNewNode(root, i, j, arr[i][j]);
            }
        }
    }

    printList(root);
}