#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    string simplifyPath(string path)
    {
        int len = path.length();
        stack<string> stk;
        string s = "";

        for(int i=0; i<len; i++)
        {
            if(path[i] == '/')
            {
                if(!s.length() or s == ".");
                else if(s == "..")
                {
                    if(!stk.empty())
                        stk.pop();
                }
                else
                    stk.push(s);
                s = "";
            }
            else
                s += path[i];
        }
        if(s.length())
        {
            if(s == ".");
            else if(s == "..")
            {
                if(!stk.empty())
                    stk.pop();
            }
            else
                stk.push(s);
        }

        s = "";
        while(!stk.empty())
        {
            string top = stk.top();
            stk.pop();
            s = "/" + top + s;
        }
        if(!s.length())
            s = "/";

        return s;
    }
};


int main()
{
    Solution obj;

//    string in = "/a/../../b/../c//.//";
    string in = "/a//b////c/d//././/..";

    string ans = obj.simplifyPath(in);

    cout<<"Ans: "<<ans<<endl;

    return 0;
}

