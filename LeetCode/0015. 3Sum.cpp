#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        map<pair<pair<int, int>, int>, bool> numMap;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int>> ans;

        for(int i=0; i<(len-2); i++)
        {
            int left = i+1, right = len-1;
            while(left < right)
            {
                int total = nums[i] + nums[left] + nums[right];
                if(total == 0)
                {
                    vector<int> temp = {nums[i], nums[left], nums[right]};
                    int n = ans.size();
                    if(numMap.find({{nums[i], nums[left]}, nums[right]}) == numMap.end())
                    {
                        ans.push_back(temp);
                        numMap.insert({{{nums[i], nums[left]}, nums[right]}, true});
                    }
                    left++, right--;
                }
                else if(total > 0)
                    right--;
                else
                    left++;
            }
        }
        return ans;
    }
};


int main()
{
    Solution obj;

    vector<int> v= {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};

    vector<vector<int>> ans = obj.threeSum(v);

    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}



