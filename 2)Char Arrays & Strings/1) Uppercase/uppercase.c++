// NOTE : IN THIS PROBLEM WE ARE GIVEN A STRING WHOSE EVERY ELEMENT IS OF SMALLCASE AND WE HAVE TO CONVERT
// EVERY ELEMENT IN UPPER CASE

// SOLUTION : -a + A -> WE JUST SIMPLY SUBTRACT SMALL LETTER a AND THEN ADD UPPER LETTER A TO EVERY SINGLE ELEMENT
//  TO CONVERT THEM TO UPPERCASE

// FROM UPPERCASE TO LOWERCASE -> -A + a

// DOESNT WORK ON STRINGS WITH SPACES
#include <bits/stdc++.h>
using namespace std;
int main()
{
    char arr[100];
    cout << "Enter name (in smallcases) : ";
    cin.getline(arr, 100);
    int i = 0;
    while (arr[i] != '\0')
    {
        arr[i] = arr[i] - 'a' + 'A';
        i++;
    }
    for (int i = 0; arr[i] != '\0'; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}