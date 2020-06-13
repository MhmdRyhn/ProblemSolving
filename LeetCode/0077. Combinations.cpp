#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        stack<vector<int>> stk;
        if(!k)
            return ans;

        for(int i=1; i<=n; i++)
            stk.push(vector<int> {i});
        while(!stk.empty())
        {
            vector<int> u = stk.top();
            stk.pop();
            if(u.size() == k)
            {
                ans.push_back(u);
                continue;
            }
            int from = u.back() + 1;
            for(int i=from; i<=n; i++)
            {
                if((u.size()+n-i+1) >= k)
                {
                    vector<int> v = u;
                    v.push_back(i);
                    stk.push(v);
                }
            }
        }
        return ans;
    }
};


int main()
{
    Solution obj;

    int n = 4, k = 2;
    vector<vector<int>> ans;

    ans = obj.combine(n, k);

    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}

