#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int> container;
        generateSunsets(ans, nums, container, 0);
        return ans;
    }

    void generateSunsets(vector<vector<int>>& ans, vector<int>& nums, vector<int>& container, int src)
    {
        ans.push_back(container);
        for(int i=src; i<nums.size(); i++)
        {
            vector<int> v = container;
            v.push_back(nums[i]);
            generateSunsets(ans, nums, v, i+1);
        }
    }
};


int main()
{
    Solution obj;

    vector<int> v = {1, 2, 3, 4};
    vector<vector<int>> ans;

    ans = obj.subsets(v);

    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}

