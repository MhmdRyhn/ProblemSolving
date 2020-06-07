#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        int len = nums.size();
        int low = 0, high = len - 1;
        return binary(nums, low, high, target);
    }

    int binary(vector<int>& nums, int low, int high, int target)
    {
        int mid = (low + high) / 2;
        if(low > high)
            return -1;
        if(nums[mid] == target)
            return mid;
        if((high-low) <= 1)
        {
            if(target == nums[low])
                return low;
            else if(target == nums[high])
                return high;
            else
                return -1;
        }
        if(nums[low] < nums[mid])
        {
            if(nums[low] <= target and target <= nums[mid])
                return binary(nums, low, mid, target);
            else
                return binary(nums, mid, high, target);
        }
        else
        {
            if(nums[mid] <= target and target <= nums[high])
                return binary(nums, mid, high, target);
            else
                return binary(nums, low, mid, target);
        }
    }
};


int main()
{
    Solution obj;

//    vector<int> v= {1, 3, 5};
//    int correct = 0, target = 1;

//    vector<int> v= {4,5,6,7,0,1,2};
//    int correct = -1, target = 0;

    vector<int> v= {};
    int correct = -1, target = 5;

    int ans = obj.search(v, target);
    cout<<ans<<endl;
    if(ans==correct)
        cout<<"Correct"<<endl;

    return 0;
}

