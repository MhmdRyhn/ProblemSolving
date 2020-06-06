#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        string data[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        int len = digits.length();
        if(!len)
            return result;

        stack<string> stk;
        int index = 0;
        stk.push("");

        while(!stk.empty())
        {
            string s = stk.top();
            stk.pop();

            if(s.length() == len)
                result.push_back(s);
            else
            {
                string num2Chars = data[(int) (digits[s.length()]-'0')];
                index++;
                for(int i=0; i<num2Chars.length(); i++)
                    stk.push(s+num2Chars[i]);
            }

        }
        return result;
    }
};


int main()
{
    Solution obj;

    string digits = "23";

    vector<string> ans = obj.letterCombinations(digits);

    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<endl;

    return 0;
}




