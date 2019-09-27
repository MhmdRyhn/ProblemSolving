from collections import defaultdict


if __name__ == '__main__':
    n = input()
    arr = input()
    arr = list(map(int, arr.split()))

    d = defaultdict(int)
    for item in arr:
            d[item] += 1
    
    print(sum([int(v//2) for v in d.values()]))


