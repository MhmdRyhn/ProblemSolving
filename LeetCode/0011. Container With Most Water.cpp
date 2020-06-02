#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int len = height.size();
        int left = 0, right = len-1, area = 0;

        while(left < right)
        {
            area = max(area, (right-left)*min(height[left], height[right]));
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return area;
    }
};


int main()
{
    Solution obj;
    int a[] = {1,8,6,2,5,4,8,3,7};
    vector<int> arr(begin(a), end(a));
    int ans = obj.maxArea(arr);
    int correct = 49;
    if(ans == correct)
        cout<<"Correct";

    return 0;
}

