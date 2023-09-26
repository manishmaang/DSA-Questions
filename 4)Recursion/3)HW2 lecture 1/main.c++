// NOTE : In this problem we have to print all the digits of a number using recursion
#include <iostream>
using namespace std;
void printDigit(int n)
{
    if (n == 0)
        return;
    printDigit(n / 10);
    int k = n % 10;
    cout << k << " ";
}
int main()
{
    int n;
    cout << "Enter a digit of your choice : ";
    cin >> n;
    if (n == 0)
        cout << n;
    printDigit(n);
    return 0;
}

