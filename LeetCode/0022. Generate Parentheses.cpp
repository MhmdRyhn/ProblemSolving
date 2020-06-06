#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        typedef struct node
        {
            string s;
            int len;
            int start;
            int close;
        } node;

        vector<string> result;
        int n2 = n * 2;

        queue<node> q;
        q.push({"(", 1, 1, 0});

        while(!q.empty())
        {
            node data = q.front();
            q.pop();
            if(data.len == n2)
                result.push_back(data.s);
            else
            {
                if(data.start < n)
                    q.push({data.s+"(", data.len+1, data.start+1, data.close});
                if(data.close < data.start)
                    q.push({data.s+")", data.len+1, data.start, data.close+1});
            }
        }

        return result;
    }
};


int main()
{
    Solution obj;

    int n = 4;
    vector<string> ans = obj.generateParenthesis(n);
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<endl;

    return 0;
}




