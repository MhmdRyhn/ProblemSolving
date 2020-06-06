#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        map<pair<pair<int, int>, pair<int, int>>, bool> numMap;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int>> ans;

        for(int i=0; i<(len-3); i++)
        {
            for(int j=i+1; j<(len-2); j++)
            {
                int left = j+1, right = len-1;
                while(left < right)
                {
                    int total = nums[i] + nums[j] + nums[left] + nums[right];
                    if(total == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[left], nums[right]};
                        if(numMap.find({{nums[i], nums[j]}, {nums[left], nums[right]}}) == numMap.end())
                        {
                            ans.push_back(temp);
                            numMap.insert({{{nums[i], nums[j]}, {nums[left], nums[right]}}, true});
                        }
                        left++, right--;
                    }
                    else if(total > target)
                        right--;
                    else
                        left++;
                }
            }

        }
        return ans;
    }
};


int main()
{
    Solution obj;

    vector<int> v= {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> ans = obj.fourSum(v, target);

    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}




