// THIS PROBLEM IS ALSO BASED ON INCLUDE AND EXCLUDE PATTERN
// PROBLEM :WE ARE GIVEN AN ARRAY OF INT & WE HAVE FIND THE MAX SUM IN THE WITHOUT INCLUDING THE ADJACENT ELEMENTS
// EXAMPLE : ARR = [1,2,3,4] ANS = 4+2  = 6

// logic : hum current element ko ya to sum me exclude karenege ya to include karenge

#include <bits/stdc++.h>
using namespace std;
void solve(int &maxi, int sum, vector<int> &v, int i)
{
    if (i >= v.size())
    {
        maxi = max(sum, maxi);
        return;
    }

    // include current element to i+2 krna hoga adjacent ke aage jane ke liye
    solve(maxi, sum + v[i], v, i + 2);

    // excluding current element to isme hum next element ko le skte hai to i+1 hoga
    solve(maxi, sum, v, i + 1);
}

int main()
{

    vector<int> v{3, 1};
    int maxi = 0;
    int sum = 0;
    int i = 0;
    solve(maxi, sum, v, i);
    cout << maxi;
    
    return 0;
}
