#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int m = matrix.size();
        if(!m)
            return false;
        int n = matrix[0].size();
        if(!n)
            return false;

        int r;
        if(m > 1 and target < matrix[m-1][0])
            r = binary(matrix, 0, m-1, target, -1, 0);
        else
            r = m-1;
        int c = binary(matrix, 0, n-1, target, r, -1);
        if(c == -1)
            return false;
        if(matrix[r][c] == target)
            return true;
        return false;
    }

    // pass to this function either (row=-1, column=0) or (row=x, column=-1)
    int binary(vector<vector<int>>& matrix, int low, int high, int target, int row, int column)
    {
        if((high-low) == 1)
        {
            if(row == -1)
                return low;
            if(matrix[row][low] == target)
                return low;
            if(matrix[row][high] == target)
                return high;
            return -1;
        }

        if(low == high)
            return low;
        int mid = (low + high) / 2;
        int data;
        if(row == -1)
            data = matrix[mid][column];
        else
            data = matrix[row][mid];
        if(data == target)
            return mid;
        if(target > data)
            return binary(matrix, mid, high, target, row, column);
        else
            return binary(matrix, low, mid, target, row, column);
    }
};


int main()
{
    Solution obj;

    vector<vector<int>> v =
    {
        {1,   3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    int target = 12;

    bool ans = obj.searchMatrix(v, target);

    cout<<ans<<endl;

    return 0;
}

