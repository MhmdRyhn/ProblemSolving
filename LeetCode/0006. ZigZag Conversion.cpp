#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    string convert(string s, int numRows)
    {
        if(numRows == 1)
            return s;
        int strLen = s.length();
        string strRows[numRows];
        for(int i=0; i<numRows; i++)
            strRows[i] = "";
        int row = 0;
        bool goDown = true;

        for(int i=0; i<strLen; i++)
        {
            strRows[row] += s[i];

            if(row == 0)
                goDown = true;
            if(row == (numRows-1))
                goDown = false;

            if(goDown)
                row++;
            else
                row--;
        }

        string toReturn = "";
        for(int i=0; i<numRows; i++)
            toReturn += strRows[i];
        return toReturn;
    }
};


int main()
{
    Solution obj;
    string ans = obj.convert("PAYPALISHIRING", 3);
    string correct = "PAHNAPLSIIGYIR";
    if(ans == correct)
        cout<<"Correct";

    return 0;
}
