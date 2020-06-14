#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int len = nums.size();
        if(len < 3)
            return len;
        int cnt = 1;
        for(int i=1; i<len; i++)
        {
            if(nums[i] == nums[i-1])
            {
                if(cnt == 2)
                {
                    nums.erase(nums.begin()+i);
                    i--;
                    len--;
                }
                else
                    cnt++;
            }
            else
                cnt = 1;
        }
        return len;
    }
};


int main()
{
    Solution obj;

//    vector<int> v = {1,1,1,2,2,3};
    vector<int> v = {0,0,1,1,1,1,2,3,3};

    int ans = obj.removeDuplicates(v);

    cout<<ans<<endl;

    return 0;
}

