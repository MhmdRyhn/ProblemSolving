#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        int len = intervals.size();
        if(len <= 1)
            return intervals;

        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b)
        {
            return a[0] < b[0];
        });
        vector<vector<int>> ans;
        int start = intervals[0][0], stop = intervals[0][1];

        for(int i=1; i<len; i++)
        {
            if(intervals[i][0] <= stop)
                stop = max(intervals[i][1], stop);
            else
            {
                ans.push_back(vector<int> {start, stop});
                start = intervals[i][0];
                stop = intervals[i][1];
            }
        }
        ans.push_back(vector<int> {start, stop});

        return ans;
    }
};


int main()
{
    Solution obj;

//    vector<vector<int>> v{{1, 3}, {2, 6}, {6, 8}, {8, 10}, {15, 18}};
    vector<vector<int>> v{{2, 3}, {4, 5}, {6, 7}, {8, 9}, {1, 10}};

    vector<vector<int>> ans = obj.merge(v);

    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }


    return 0;
}

