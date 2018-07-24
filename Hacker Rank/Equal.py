# Warning: 
# In the problem, it is said that "Christy can give 1, 2 or 5 chocolates".
# Correct: Christy can give 1, 2 or 5 chocolates. 
# Otherwise you will get "Wrong Answer"

def oper_per_person(n):
    ans =0
    ans += int(n//5)
    n %= 5
    ans += int(n//2)
    n %= 2
    ans += n
    return ans


def total_oper(min, minus, arr, n):
    min_oper = 0
    for i in range(n):
        min_oper += oper_per_person(arr[i] - (min-minus))
    return min_oper


if __name__ == '__main__':
    t = int(input())
    for x in range(t):
        n = int(input())
        emp = list(map(int, input().split()))

        mn = min(emp)
        ans = total_oper(mn, 0, emp, n)

        for i in range(1, 5):
            temp = total_oper(mn, i, emp, n)
            ans = min(ans, temp)
        print(ans)

