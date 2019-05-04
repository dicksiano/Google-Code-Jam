def bipartition(m):
    if m == 0:
        return [0,0]
    if m == 1:
        return [0,1]
    if m == 5:
        return [2,3]
    return [1, m-1]

def process(m):
    a, b, p = 0, 0, 1

    while(m):
        x, y = bipartition(m % 10)
        a = x * p + a 
        b = y * p + b

        p = p * 10
        m = m // 10

    return (a,b)

def main():
    n = int(input())
    for i in range(0,n):
        m = int(input())
        a,b = process(m)
        print("Case #{0}: {1} {2}".format(i+1, a, b))

if __name__ == '__main__':
    main()