// Sparse Matrix using array
#include <iostream>
using namespace std;

#define MAX 100

int main()
{
    int m = 5;
    int n = 4;
    int arr[][5] = {{0, 1, 0, 0},
                    {0, 0, 2, 0},
                    {0, 3, 0, 0},
                    {0, 0, 5, 0},
                    {0, 0, 0, 4}};
    int sparse[MAX][3];

    int k = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j])
            {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = arr[i][j];
                k++;
            }
        }
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << sparse[i][j] << " ";
        }
        cout << endl;
    }
}