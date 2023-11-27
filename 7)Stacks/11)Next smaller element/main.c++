#include<bits/stdc++.h>
using namespace std;
void nextSmallerElement(vector<int>&v,vector<int> &ans1)
{
    stack<int> st;

    st.push(-1); //coz rightmost element ka ans hamesha -1 hoga

    
    for(int i = v.size() - 1; i >= 0; i--)
    {
     //jb tk chota element na mile tb tk stack se pop kro
     while(st.top() > v[i])
     {
        st.pop();
     }
     
     //chota element mil gya
     ans1[i] = st.top();
     
     //current element stack me push kro taki vo bhi check ho paye for next elements
     st.push(v[i]);
    }
}
void previousSmallerElement(vector<int>& v, vector<int>& ans2)
{
    stack<int> st;

    st.push(-1); //coz leftmost element ka ans hamesha -1 hoga

    
    for(int i = 0; i < v.size(); i++)
    {
     //jb tk chota element na mile tb tk stack se pop kro
     while(st.top() > v[i])
     {
        st.pop();
     }
     
     //chota element mil gya
     ans2[i] = st.top();
     
     //current element stack me push kro taki vo bhi check ho paye for next elements
     st.push(v[i]);
    }
}
int main()
{
    
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);

    vector<int> ans1(v.size());
    vector<int> ans2(v.size());

    cout<<"ans of every element in order is : ";
    nextSmallerElement(v, ans1);
    for(int i = 0; i < ans1.size(); i++)
    {
        cout<<ans1[i] <<" ";
    }

    cout<<endl;
    previousSmallerElement(v, ans2);
    cout<<"ans of previous smaller element in order is : ";
    for(int i=0; i < ans2.size(); i++)
    {
        cout<<ans2[i]<<" ";
    }
    return 0;
}