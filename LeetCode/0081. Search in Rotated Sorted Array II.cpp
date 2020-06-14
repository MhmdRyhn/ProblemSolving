#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int pivot = -1;

    bool search(vector<int>& nums, int target)
    {
        int len = nums.size();
        if(!len)
            return false;
        if(len == 1)
            return (target == nums[0]);

        int low = 0, high = len - 1;
        findPivotPoint(nums, 0, len-1);
        if(pivot == -1)
            return binary_search(nums.begin(), nums.end(), target);
        return (binary_search(nums.begin(), nums.begin()+pivot+1, target) or binary_search(nums.begin()+pivot+1, nums.end(), target));
    }

    void findPivotPoint(vector<int>& nums, int low, int high)
    {
        if((high - low) == 1)
        {
            if(nums[low] > nums[high])
            {
                pivot = low;
                return;
            }
            return;
        }

        int mid = (low + high) / 2;
        if(nums[low] >= nums[mid] and pivot == -1)
            findPivotPoint(nums, low, mid);
        if(nums[mid] >= nums[high] and pivot == -1)
            findPivotPoint(nums, mid, high);
    }
};


int main()
{
    Solution obj;

//    vector<int> v= {1, 1, 1, 3};
//    int target = 3;
//    bool correct = true;

//    vector<int> v= {2, 3, 3, 4, 1, 1, 2};
//    int target = 4;
//    bool correct = true;

//    vector<int> v= {2, 2, 2, 2, 2, 1, 2};
//    int target = 3;
//    bool correct = false;

    vector<int> v= {2};
    int target = 1;
    bool correct = false;

//    vector<int> v= {1, 3, 1, 1, 1};
//    int target = 3;
//    bool correct = true;

    bool ans = obj.search(v, target);
//    cout<<ans<<endl;
    if(ans==correct)
        cout<<"Correct"<<endl;
    else
        cout<<"Wrong"<<endl;

    return 0;
}

