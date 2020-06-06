#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int ans = 3000;

        for(int i=0; i<(len-2); i++)
        {
            int left = i+1, right = len-1;
            while(left < right)
            {
                int total = nums[i] + nums[left] + nums[right];
                if(!(total-target))
                    return total;
                if(abs(total-target) < abs(ans-target))
                    ans = total;
                else if(total > target)
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

    vector<int> v= {1,2,4,8,16,32,64,128};
    int target = 82;

    int ans = obj.threeSumClosest(v, target);
    int correct = 82;

    cout<<ans<<endl;

    if(ans == correct)
        cout<<"Correct"<<endl;

    return 0;
}




