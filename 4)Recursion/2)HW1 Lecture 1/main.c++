// NOTE : IN THIS PROBLEM WE HAVE TO FIND A KEY IN ARRAY USING RECURSION
#include <bits/stdc++.h>
using namespace std;
// int FindElement(int arr[], int h, int key)
// {
//     if (arr[h] == key)
//     {
//         return h + 1;
//     }
//     if (h >= sizeof(arr) / sizeof(arr[0]))
//         return -1;

//     int ans = FindElement(arr, h + 1, key);
//     return ans;
// }
// int main()
// {
//     cout << "Enter the size of array : ";
//     int n;
//     cin >> n;
//     int arr[n] = {0};
//     for (int i = 0; i < n; i++)
//     {
//         cout << "enter element : ";
//         cin >> arr[i];
//     }
//     cout << "enter key to search : ";
//     int key;
//     cin >> key;
//     int h = 0;
//     int index = FindElement(arr, h, key);
//     if (index == -1)
//         cout << "element not found ";
//     else
//         cout << "element foud at index " << index;
//     return 0;
// }

// NOTE : IN THIS PROBLEM WE HAVE TO FIND THE NUMBER OF OCCURENCES OF KEY IN AN ARRAY

int FindElement(int arr[], int h, int n, int key)
{
    if (h >= n)
    {
        return 0; // Base case: If index goes out of bounds, return 0 occurrences
    }

    int count = FindElement(arr, h + 1, n, key); // Recur on the rest of the array
    if (arr[h] == key)
    {
        return count + 1; // Increment count if key is found at this index
    }
    else
    {
        return count;
    }
}

int main()
{
    cout << "Enter the size of array : ";
    int n;
    cin >> n;
    int arr[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element : ";
        cin >> arr[i];
    }
    cout << "Enter key to search : ";
    int key;
    cin >> key;

    int count = FindElement(arr, 0, n, key);
    cout << "Number of occurrences of element is: " << count;
    return 0;
}
