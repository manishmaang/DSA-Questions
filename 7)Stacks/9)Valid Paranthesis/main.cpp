// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
// determine if the input string is valid.
// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.

// Example 1:
// Input: s = "()"
// Output: true

// Example 2:
// Input: s = "()[]{}"
// Output: true

// Example 3:
// Input: s = "(]"
// Output: false
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];

            switch (ch)
            {
            case '(':
            case '{':
            case '[':
                st.push(ch);
                break;
            case ')':
                if (st.empty() || st.top() != '(')
                    return false;
                st.pop();
                break;
            case '}':
                if (st.empty() || st.top() != '{')
                    return false;
                st.pop();
                break;
            case ']':
                if (st.empty() || st.top() != '[')
                    return false;
                st.pop();
                break;
            default:
                // Invalid character in the input string
                return false;
            }
        }

        // If the stack is empty at the end, it means all brackets were matched
        return st.empty();
    }
};

int main()
{
    Solution obj;
    string g;
    cout << "enter a string of paranthesis : ";
    cin >> g;
    bool ff = obj.isValid(g);
    cout << ff;
    return 0;
}
/* 
niche pura explain kiya bss if else ki jgh switch use kiya hai for saving time in above code
 class Solution {
 public:
     bool isValid(string s) {
         stack <char> st;
         for (int i = 0; i < s.length(); i++)
         {
             char ch = s[i];
  // agr opening bracket hai to push krdo
             if( ch == '[' || ch == '(' || ch == '{')
             {
                 st.push(ch);
             }
 // ch me closing bracket aaya hai
             else
             {
                 if( !s.empty())
                 {
                   if(ch == ')' && st.top() == '(')
                   {
                     st.pop();
                   }
                  else if(ch == ']' && st.top() == '[')
                   {
                     st.pop();
                   }
                  else if(ch == '}' && st.top() == '{')
                   {
                     st.pop();
                   }

                  else
                  {
                    return false;
                   // brackets not matching
                  }
                }
// stack empty hai or closing bracket mila hai to valid string nhi hai
// kyuki uska opening bracket nhi hai
                else
                {
                  return false;
                }
            }
        }
        if(st.empty())
        {
// sare opening bracket ne closing bracket ko cancel krdia to pop hone se stack empty ho gya
            return true;
        }
        else
        {
// agr stack empty nhi hai to koi opening bracket hai jiska closing bracket nhi hai string me
            return false;
        }
    }
}; 
*/