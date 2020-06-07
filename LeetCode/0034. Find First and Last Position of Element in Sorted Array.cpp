#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int len = nums.size();
        int low = 0, high = len - 1;
        int first = -1, last = -1;
        binary(nums, len, low, high, target, first, last);
        return vector<int> {first, last};
    }

    void binary(vector<int>& nums, int len, int low, int high, int target, int &first, int &last)
    {
        int mid = (low + high) / 2;
        if(first >= 0 and last >= 0)
            return;
        if(low > high)
            return;
        if(nums[mid] == target)
        {
            if(mid > 0)
            {
                if(first < 0)
                {
                    if(nums[mid] == nums[mid-1])
                        binary(nums, len, 0, mid-1, target, first, last);
                    else
                        first = mid;
                }
            }
            else
                first = mid;
            if(mid < (len-1))
            {
                if(last < 0)
                {
                    if(nums[mid] == nums[mid+1])
                        binary(nums, len, mid+1, len-1, target, first, last);
                    else
                        last = mid;
                }
            }
            else
                last = mid;
        }
        else if(target < nums[mid])
            binary(nums, len, low, mid-1, target, first, last);
        else
            binary(nums, len, mid+1, high, target, first, last);
    }
};


int main()
{
    Solution obj;

    vector<int> v= {5,7,7,8,8,10};
    int target = 8;
    vector<int> correct = {3, 4};

//    vector<int> v= {5,7,7,8,8,10};
//    int target = 2;
//    vector<int> correct = {-1, -1};

    vector<int> ans = obj.searchRange(v, target);
    cout<<ans[0]<<"  "<<ans[1]<<endl;

    if(ans[0]==correct[0] and ans[1]==correct[1])
        cout<<"Correct"<<endl;

    return 0;
}

