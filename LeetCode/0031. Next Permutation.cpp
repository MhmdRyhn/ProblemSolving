#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    void nextPermutation(vector<int>& nums)
    {
        int len = nums.size();
        bool needOps = false;
        int i;
        for(i=len-1; i>0; i--)
        {
            if(nums[i] > nums[i-1])
            {
                needOps = true;
                break;
            }
        }

        if(needOps)
        {
            int pos = nearestGreaterPos(nums, i, len-1, nums[i-1]);
            swap(nums[i-1], nums[pos]);
        }

        sort(nums.begin()+i, nums.end());
    }

    int nearestGreaterPos(vector<int>& numbers, int from, int to, int n)
    {
        int minDif = (1<<30) - 1, pos;
        for(int i=from; i<=to; i++)
        {
            int diff = numbers[i]-n;
            if(diff > 0 and diff < minDif)
            {
                pos = i;
                minDif = diff;
            }
        }
        return pos;
    }
};


int main()
{
    Solution obj;

//    vector<int> v= {1, 2, 5, 4, 3};
//    vector<int> v= {2,3,1,3,3};
    vector<int> v= {5, 4, 3, 2, 1};
//    vector<int> v= {2, 3, 1};

    obj.nextPermutation(v);

    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<"  ";
    }

    return 0;
}



