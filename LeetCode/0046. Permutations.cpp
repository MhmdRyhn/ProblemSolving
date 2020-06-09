#include<bits/stdc++.h>
using namespace std;


// The following image describes the solution to this problem.
// https://media.geeksforgeeks.org/wp-content/cdn-uploads/NewPermutation.gif
class Solution
{
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> ans;
        generatePermutation(ans, nums, 0, nums.size());
        return ans;
    }

    void generatePermutation(vector<vector<int>>& ans, vector<int> nums, int start, int len)
    {
        if(start == (len-1))
        {
            ans.push_back(nums);
            return;
        }

        for(int i=start; i<len; i++)
        {
            swap(nums[start], nums[i]);
            generatePermutation(ans, nums, start+1, len);
        }
    }
};


int main()
{
    Solution obj;

    vector<int> v{1, 2, 3, 4};
    vector<vector<int>> ans = obj.permute(v);

    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}

