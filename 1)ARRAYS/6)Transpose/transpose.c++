// NOTE : IN THIS PROBLEM HUME ROWS KI VALUES KO COLUMN ME DAALNA HAI OR COUUMN KI VALUES KO ROWS ME DAALNA HAI

#include <iostream>

using namespace std;

int main()
{

    int arr[3][3] = {{1, 2, 3}, {2, 3, 4}, {5, 6, 1}};
    int r = 3;
    int c = 3;
    int brr[c][r];

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            brr[j][i] = arr[i][j];
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << brr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}