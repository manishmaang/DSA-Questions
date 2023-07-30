// Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.

// Example 1:
// Input: timePoints = ["23:59","00:00"]
// Output: 1

// Example 2:
// Input: timePoints = ["00:00","23:59","00:00"]
// Output: 0
#include <bits/stdc++.h>
using namespace std;
int findMinDifference(vector<string> &timePoints)
{
    vector<int> minutes;
    for (int i = 0; i < timePoints.size(); i++)
    {
        string current = timePoints[i];

        // if(current[0] == '0' && current[1]=='0')
        // {
        //     int min = stoi(current.substr(3,2));
        //     int k = 1440+min;
        //     minutes.push_back(k);
        //     continue;
        // }  NOTE : check this logic

        int hours = stoi(current.substr(0, 2));
        int min = stoi(current.substr(3, 2));
        int totaltime = (hours * 60) + min;
        minutes.push_back(totaltime);
    }

    sort(minutes.begin(), minutes.end());
    int mini = INT_MAX;
    int n = minutes.size();
    for (int i = 0; i < n - 1; i++)
    {
        int diff = minutes[i + 1] - minutes[i];
        mini = min(mini, diff);
    }
    int lastdiff = (minutes[0] + 1440) - minutes[n - 1];
    mini = min(mini, lastdiff);
    return mini;
}

int main()
{
    int n;
    vector<string> timePoints;
    cout << "How many inputs : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string time;
        cout << "Enter time in HH:MM format with : in between time = ";
        cin >> time;
        timePoints.push_back(time);
    }
    int j = findMinDifference(timePoints);
    cout << j;
    return 0;
}