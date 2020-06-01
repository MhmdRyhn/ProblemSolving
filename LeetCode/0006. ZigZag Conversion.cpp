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


class Solution2
{
public:
    string convert(string s, int numRows)
    {
        string toReturn = "";
        int strLen = s.length();
        int maxDiff = (numRows-1)*2;

        if(numRows == 1 or numRows >= strLen)
            return s;

        for(int row=0; row<numRows; row++)
        {
            if(row == 0 or row == (numRows-1))
            {
                for(int i=row; i<strLen; i+=maxDiff)
                    toReturn += s[i];
            }
            else
            {
                int i = row;
                toReturn += s[i];
                while(true)
                {
                    int second = 2*row;
                    int first = maxDiff - second;

                    i += first;
                    if(i >= strLen)
                        break;
                    toReturn += s[i];
                    i += second;
                    if(i >= strLen)
                        break;
                    toReturn += s[i];
                }
            }
        }
        return toReturn;
    }
};


int main()
{
    Solution2 obj;
    string ans = obj.convert("PAYPALISHIRING", 3);
    cout<<"\""<<ans<<"\""<<endl;
    string correct = "PAHNAPLSIIGYIR";
    if(ans == correct)
        cout<<"Correct";

    return 0;
}
