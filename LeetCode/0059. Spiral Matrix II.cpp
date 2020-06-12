#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        if(!n)
            return vector<vector<int>> {};

        int total = n*n;
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        map<string, string> noWayGoTo;
        noWayGoTo["Right"] = "Down";
        noWayGoTo["Down"] = "Left";
        noWayGoTo["Left"] = "Up";
        noWayGoTo["Up"] = "Right";

        string direction = "Right";
        int row = 0, column = 0, visCnt = 0, number = 1;

        while(true)
        {
            if(!matrix[row][column])
            {
                matrix[row][column] = number;
                number++;
                visCnt++;
            }
            if(total == visCnt)
                break;

            if(direction == "Right")
            {
                if((column + 1) < n)
                {
                    if(matrix[row][column+1])
                        direction = noWayGoTo[direction];
                    else
                        column++;
                }
                else
                    direction = noWayGoTo[direction];
            }
            else if(direction == "Down")
            {
                if((row + 1) < n)
                {
                    if(matrix[row+1][column])
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
                    if(matrix[row][column-1])
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
                    if(matrix[row-1][column])
                        direction = noWayGoTo[direction];
                    else
                        row--;
                }
                else
                    direction = noWayGoTo[direction];
            }
        }
        return matrix;
    }
};


int main()
{
    Solution obj;
    int n = 2;

    vector<vector<int>> ans = obj.generateMatrix(n);

    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}

