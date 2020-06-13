#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    void sortColors(vector<int>& nums)
    {
        int zero = 0, one = 0, two = nums.size()-1;

        while(one <= two)
        {
            if(nums[one] == 0)
            {
                swap(nums[one], nums[zero]);
                zero++;
                one++;
            }
            else if(nums[one] == 1)
                one++;
            else
            {
                swap(nums[one], nums[two]);
                two--;
            }
        }
    }
};


int main()
{
    Solution obj;

    vector<int> v = {2,0,2,1,1,0};

    obj.sortColors(v);

    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";

    return 0;
}

