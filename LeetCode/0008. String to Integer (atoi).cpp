#include<bits/stdc++.h>
using namespace std;


typedef long long ll;


class Solution
{
public:
    int myAtoi(string str)
    {
        ll maxNum = (1ll << 31) - 1ll, minNum = -(1ll << 31);
        ll len = str.length(), i = 0, number = 0;
        bool neg = false, invalid = false, sign_found = false;

        for(i; i<len; i++)
        {
            if(str[i] == ' ')
                continue;
            if(str[i] == '+' or str[i] == '-')
            {
                neg = (str[i] == '-')? true: false;
                i++;
                break;
            }
            if(str[i] >= '0' and str[i] <= '9')
                break;
            return 0;
        }

        for(i; i<len; i++)
        {
            if(str[i] >= '0' and str[i] <= '9')
            {
                number = number*10 + (int) (str[i] - '0');
                ll toCheckNumber = number * (neg? -1: 1);

                if(toCheckNumber <= minNum)
                    return minNum;

                if(toCheckNumber >= maxNum)
                    return maxNum;
            }
            else
                break;
        }
        return (int) number * (neg? -1: 1);
    }
};



int main()
{
    Solution obj;
//    string str = "4193 with words";
//    int correct = 4193;

//    string str = "-42";
//    int correct = -42;

//    string str = "words and 987";
//    int correct = 0;

    string str = "-91283472332";
    int correct = -2147483648;

//    string str = "-2147483648";
//    int correct = -2147483648;

    int ans = obj.myAtoi(str);
    cout<<ans<<endl;
    if(ans == correct)
        cout<<"Correct";

    return 0;
}

