
if __name__=='__main__':
    while True:
        try:
            s=input().split(' ')
            a=[]
            for itm in s:
                a.append(itm[::-1])
            print(*a)
        except:
            break

