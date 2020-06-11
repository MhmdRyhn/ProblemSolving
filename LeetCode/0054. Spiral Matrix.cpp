#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        int m, n, total;
        m = matrix.size();
        if(!m)
            return vector<int> {};

        n = m? matrix[0].size():0;
        if(!n)
            return matrix[0];

        total = m*n;
        bool isVisited[m][n];

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                isVisited[i][j] = false;

        map<string, string> noWayGoTo;
        noWayGoTo["Right"] = "Down";
        noWayGoTo["Down"] = "Left";
        noWayGoTo["Left"] = "Up";
        noWayGoTo["Up"] = "Right";

        string direction = "Right";
        int row = 0, column = 0, visCnt = 0;
        vector<int> ans;

        while(true)
        {
            if(!isVisited[row][column])
            {
                ans.push_back(matrix[row][column]);
                isVisited[row][column] = true;
                visCnt++;
            }
            if(total == visCnt)
                break;

            if(direction == "Right")
            {
                if((column + 1) < n)
                {
                    if(isVisited[row][column+1])
                        direction = noWayGoTo[direction];
                    else
                        column++;
                }
                else
                    direction = noWayGoTo[direction];
            }
            else if(direction == "Down")
            {
                if((row + 1) < m)
                {
                    if(isVisited[row+1][column])
                        direction = noWayGoTo[direction];
                    else
                        row++;
                }
                else
                    direction = noWayGoTo[direction];
            }
            else if(direction == "Left")
            {
                if((column - 1) > -1)
                {
                    if(isVisited[row][column-1])
                        direction = noWayGoTo[direction];
                    else
                        column--;
                }
                else
                    direction = noWayGoTo[direction];
            }
            else if(direction == "Up")
            {
                if((row - 1) > -1)
                {
                    if(isVisited[row-1][column])
                        direction = noWayGoTo[direction];
                    else
                        row--;
                }
                else
                    direction = noWayGoTo[direction];
            }
        }
        return ans;
    }
};


int main()
{
    Solution obj;

    vector<vector<int>> v;
    int m = 4, n = 4, x = 1;
    for(int i=1; i<=m; i++)
    {
        vector<int> a;
        for(int j=1; j<=n; j++)
        {
            a.push_back(x);
            x++;
        }
        v.push_back(a);
    }

    vector<int> ans = obj.spiralOrder(v);

    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
    cout<<endl;

    return 0;
}

