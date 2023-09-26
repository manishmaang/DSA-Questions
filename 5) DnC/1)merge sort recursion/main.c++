#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int s, int e)
{
    int mid = s + (e - s) / 2;

    int len1 = s + mid + 1;
    int len2 = e - mid;

    int *left = new int[len1];
    int *right = new int[len2];

    // copy values in left and right array
    int k = s; // humara arr s se start hoga jo function me pass hua hoga na ki 0 se

    // left array
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[k];
        k++;
    }
    // right array
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[k];
        k++;
    }

    // merge logic
    int leftindex = 0;
    int rightindex = 0;
    int mainarrayindex = s;
    while (leftindex < len1 && rightindex < len2)
    {
        if (left[leftindex] < right[rightindex])
        {
            arr[mainarrayindex++] = left[leftindex++];
        }
        else
        {
            arr[mainarrayindex++] = right[rightindex++];
        }
    }

    while (leftindex < len1)
    {
        arr[mainarrayindex++] = left[leftindex++];
    }

    while (rightindex < len2)
    {
        arr[mainarrayindex++] = right[rightindex++];
    }
}

void mergesort(int arr[], int s, int e)
{
    if (s >= e) // agr arr me single element hai to vo sorted hi hoga
    {
        //  cout << arr[s]<< " ";
        return;
    }

    // calculate mid for left part
    int mid = s + (e - s) / 2;

    // left part sort kro recursion
    mergesort(arr, s, mid);

    // right part sort kro recursion
    mergesort(arr, mid + 1, e);

    merge(arr, s, e);
}

int main()
{
    int arr[6] = {4, 2, 3, 1, 5};
    int s = 0;
    int e = 5;
    mergesort(arr, s, e);
    cout << endl;

    for (int i = 0; i < e; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}