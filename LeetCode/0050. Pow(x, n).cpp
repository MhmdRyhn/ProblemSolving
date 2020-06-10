#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    map<int, double> calc;
    double myPow(double x, int n)
    {
        return divideAndConquer(x, n);
    }

    double divideAndConquer(double x, int n)
    {
        if(abs(n) <= 1)
            return pow(x, n);
        if(calc.find(abs(n)) == calc.end())
            calc[abs(n)] = divideAndConquer(x, n/2) * divideAndConquer(x, n/2) * pow(x, n%2);
        return calc[abs(n)];
    }
};



int main()
{
    Solution obj;

//    double x = 2.0;
//    int n = 10;

    double x = 0.00001;
    int n = 2147483647;

    double ans = obj.myPow(x, n);

    cout<<ans<<endl;

    return 0;
}

