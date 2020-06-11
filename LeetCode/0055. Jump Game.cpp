#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        int pos = nums.size() - 1;
        for(int i=nums.size()-1; i>-1; i--)
            if((i+nums[i]) >= pos)
                pos = i;
        return !pos;
    }
};


int main()
{
    Solution obj;

//    vector<int> v{2, 3, 1, 1, 4};
//    bool cor = true;

    vector<int> v{4,2,0,0,1,1,4,4,4,0,4,0};
    bool cor = true;

    bool ans = obj.canJump(v);

    if(ans == cor)
        cout<<"Correct"<<endl;

    return 0;
}

