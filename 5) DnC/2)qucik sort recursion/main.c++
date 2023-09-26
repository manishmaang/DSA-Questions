// QUICK SORT
#include <iostream>
using namespace std;
int partition(int arr[], int s, int e) // pivot ko correct jgh leke aana hai or pivot left side = smaller elements & pivot right side = bigger elements
{
    // STEP 1 : select pivot element (generally we prefer it to be the first element of the array)
    int pivotIndex = s;
    int pivotElement = arr[s];

    // STEP 2 : find correct position of pivotElement and place it there
    int count = 0;
    for (int i = s; i <= e; i++)
    {
        if (arr[i] < pivotElement)
        {
            count++;
        }
    }

    int correctIdex = s + count; // correct position of pivot element
    pivotIndex = correctIdex;

    swap(arr[s], arr[pivotIndex]); // placing pivot at correct position

    // STEP 3 : left side smaller and right side bigger elements
    int i = s;
    int j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivotElement) // <= will consider equal value (same element) also
        {
            i++;
        }
        while (arr[j] > pivotElement)
        {
            j--;
        }

        // 2 cases honge
        // A : either you got the elements to swap
        // B : or all elements in left are smaller and right are grtr
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i], arr[j]);
        }
    }

    return pivotIndex;
}

void quicksort(int arr[], int s, int e)
{
    // base case => invalid array and single element array
    if (s >= e)
    {
        return;
    }

    // partion logic
    int p = partition(arr, s, e); // p is the correct index(position) of pivot element

    // left side for smaller elements
    quicksort(arr, s, p - 1);

    // right side for bigger elements
    quicksort(arr, p + 1, e);
}

int main()
{
    int arr[] = {8, 2, 1, 3, 50, 20, 10, 10, 5, 5};
    int size = 10;
    int s = 0;
    int e = 9;
    quicksort(arr, s, e);
    for (auto val : arr)
    {
        cout << val << " ";
    }

    return 0;
}