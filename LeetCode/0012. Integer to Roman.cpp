#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    string intToRoman(int num)
    {
        // Here, the ORDER of the symbols[] is important
        pair<int, string> symbols[] =
        {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"},
            {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
        string result = "";

        for(int i=0; i<13 and num; i++)
        {
            int q = num/symbols[i].first;
            if(q)
            {
                for(int j=0; j<q; j++)
                    result += symbols[i].second;
                num %= symbols[i].first;
            }
        }
        return result;
    }
};


int main()
{
    Solution obj;

    int num = 1499;
    string correct = "MCDXCIX";

    string ans = obj.intToRoman(num);
    cout<<ans<<endl;
    if(ans == correct)
        cout<<"Correct";

    return 0;
}


