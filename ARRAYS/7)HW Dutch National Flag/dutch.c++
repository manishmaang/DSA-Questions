// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the
// same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
// You must solve this problem without using the library's sort function.

// Example 1:
// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// Example 2:
// Input: nums = [2,0,1]
// Output: [0,1,2]
#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &nums)
{
    int start = 0;
    int end = nums.size() - 1;
    int i = 0;
    while (i <= end)
    {
        if (nums[i] == 0)
        {
            swap(nums[i], nums[start]);
            start++;
        }
        if (nums[i] == 2)
        {
            swap(nums[i], nums[end]);
            end--;
            continue; // jb isme end or i swap honge to i me kya aaya  vo dekhna padega isiliye continue kia
                      // taki i++ na ho paye
        }
        i++;
    }
    for (auto value : nums)
        cout << value << " ";
}

int main()
{
    vector<int> nums;
    int n;
    cout << "How many inputs do you wanna give : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        cout << "Enter no. ( only 0, 1 and 2 ) : ";
        cin >> m;
        nums.push_back(m);
    }
    sortColors(nums);
    return 0;
}