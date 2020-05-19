#include <iostream>
using namespace std;

class BST
{
public:
    int data;
    BST *left, *right;
    void insert(BST *, int);
    void preorder(BST *);
    void del(BST *&, int);
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

void BST::del(BST *&root, int key)
{
    if (root == NULL)
    {
        cout << "Tree is empty";
        return;
    }
    // find the node to delete
    if (key < root->data)
        del(root->left, key);
    else if (key > root->data)
        del(root->right, key);
    else
    {
        // Case 1: No children, it is a leaf node
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        // Case 1: One contains one child
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
            {
                temp = temp->left;
            }
            root->data = temp->data;
            del(root->right, temp->data);
        }
    }
}

int main()
{
    int ch, ele;
    BST b;
    b.insert(root, 5);
    b.insert(root, 10);
    b.insert(root, 3);
    b.insert(root, 4);
    b.insert(root, 1);
    b.insert(root, 11);
    b.del(root, 5);
    b.preorder(root);
    cout << endl;
}