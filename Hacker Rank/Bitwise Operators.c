#include<stdio.h>
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))


int main()
{
    int a, b, n, k, max_and =0, max_or = 0, max_xor = 0;
    scanf("%d%d", &n, &k);

    for(b=2; b<=n; b++)
        for(a=1; a<b; a++)
        {
            max_and = ((a&b)<k) ? MAX(a&b, max_and):max_and;
            max_or = ((a|b)<k) ? MAX(a|b, max_or):max_or;
            max_xor = ((a^b)<k) ? MAX(a^b, max_xor):max_xor;
        }

    printf("%d\n%d\n%d\n", max_and, max_or, max_xor);

    return 0;
}

