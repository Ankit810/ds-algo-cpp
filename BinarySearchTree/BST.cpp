#include <iostream>
using namespace std;

class BST
{
    int data;
public:
    BST *left, *right;
    void insert(BST *, int);
    void deleteNode(BST *&, int);
    void preorder(BST *);

    // define a constructor to initialize left and right to NULL
    BST()
    {
        left = NULL;
        right = NULL;
    }
};

BST *root; // define a global root pointer

void BST::insert(BST *tree, int val)
{
    if (root == NULL)
    {
        root = new BST;
        root->data = val;
        return;
    }

    // Check if value to be inserted already exists, if it does, do nothing
    // because BST cannot contain duplicate values
    if (val == tree->data)
        return;

    if (val < tree->data)
    {
        if (tree->left != NULL)
            insert(tree->left, val);
        else
        {
            BST *newnode = new BST;
            newnode->data = val;
            tree->left = newnode;
        }
    }
    else
    {
        if (tree->right != NULL)
            insert(tree->right, val);
        else
        {
            BST *newnode = new BST;
            newnode->data = val;
            tree->right = newnode;
        }
    }
}

void BST::preorder(BST *ptr)
{
    if (root == NULL)
        return;

    if (ptr != NULL)
    {
        cout << ptr->data << "\t";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void BST::deleteNode(BST *&root, int key)
{
    // Check if tree is empty
    if (root == NULL)
        return;

    // find the node to delete
    if (key < root->data)
        deleteNode(root->left, key);
    else if (key > root->data)
        deleteNode(root->right, key);
    else
    {
        // Case 1: No children, it is a leaf node
        if (root->left == NULL && root->right == NULL)
        {
            delete root; // free the memory referenced by this pointer
            root = NULL;
        }
        // Case 2: One contains one child
        else if (root->left == NULL)
        {
            BST *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            BST *temp = root;
            root = root->left;
            delete temp;
        }
        // Case 3: Contains 2 children (left and right subtree)
        else
        {
            // Find the least value in the right subtree
            BST *temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;

            root->data = temp->data;
            deleteNode(root->right, temp->data);
        }
    }
}

int main()
{
    int ch, ele;
    BST b;
    while (1)
    {
        cout << "\n1. Insert\n2. Display (preorder) \n3. Delete\n4. Exit\n";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter the element to be inserted: ";
            cin >> ele;
            b.insert(root, ele);
            break;
        case 2:
            cout << "\nPreorder traversal:\n";
            b.preorder(root);
            cout << "\n";
            break;
        case 3:
            cout << "Enter the element to be deleted: ";
            cin >> ele;
            b.deleteNode(root, ele);
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Please enter a valid choice\n";
        }
    }
}