// Sparse Matrix representation using List of Linked Lists
#include <iostream>
using namespace std;

class Node
{
public:
    int value, col;
    Node *next;
    Node(int value)
    {
        this->col = -1;
        this->value = value;
        next = NULL;
    }

    Node(int col, int value)
    {
        this->col = col;
        this->value = value;
    }
};


void append(Node *& root, int col, int value)
{
    Node* temp = root;

    while(temp->next != NULL)
        temp = temp->next;
    
    temp->next = new Node(col, value);
}

void printLIL(Node *nodeArray[], int len)
{
     Node* temp;
     for(int i = 0; i < len; i++)
     {
         temp = nodeArray[i];
         while(temp != NULL)
         {
            cout << temp -> value << " -> ";
            temp = temp->next;

         }
         cout << " NULL";
         cout << endl;
     }
}

int main()
{
    Node **nodeArray = NULL;

    int m = 5;
    int n = 4;
    int arr[][5] = {{0, 1, 0, 3},
                    {0, 0, 2, 0},
                    {0, 3, 0, 0},
                    {0, 0, 5, 0},
                    {8, 0, 0, 4}};

    nodeArray = new Node*[m];

    for (int i = 0; i < m; i++)
    {
        nodeArray[i] = new Node(i);
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j])
            {
                
                append(nodeArray[i], j, arr[i][j]);
            }
        }
    }

    printLIL(nodeArray, m);
}