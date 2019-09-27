#include<bits/stdc++.h>

using namespace std;

#define ll long long


bool is_balanced(string s)
{
    map<char, char> paren =
    {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };
    stack<char> stk;
    bool flag = true;

    int len = s.length();
    if(len == 1)
        return false;

    for(int i=0; i<len; i++)
    {
        if(s[i] == '(' or s[i] == '{' or s[i] == '[')
            stk.push(s[i]);
        else
        {
            if(stk.empty() or paren[s[i]] != stk.top())
            {
                flag = false;
                break;
            }
            else
                stk.pop();
        }
    }

    if(!stk.empty())
        flag = false;

    return flag;
}


int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    string s;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>s;
        if(is_balanced(s))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}
