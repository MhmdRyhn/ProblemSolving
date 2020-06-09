#include<bits/stdc++.h>
using namespace std;


// The following image describes the solution for distinct items.
// https://media.geeksforgeeks.org/wp-content/cdn-uploads/NewPermutation.gif
class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
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
            if(nums[start] != nums[i] or (nums[start] == nums[i] and i == start))
            {
                swap(nums[start], nums[i]);
                generatePermutation(ans, nums, start+1, len);
            }
        }
    }
};


int main()
{
    Solution obj;

    vector<int> v{1, 1, 2};
    vector<vector<int>> ans = obj.permuteUnique(v);

    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}

