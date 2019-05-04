alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

def GCD(a, b):
    if(b == 0):
        return a
    return GCD(b, a%b)

def findStart(v):
    s = 0
    while v[s] == v[s+1]:
        s = s + 1
    return s

def decript(v):
    vSorted = v.copy()

    s = findStart(v)

    gcd = GCD(v[s],v[s+1])
    vSorted[s] = v[s] // gcd
    vSorted[s+1] = gcd

    for i in range(s+2, len(v)):
        vSorted[i] = v[i-1] // vSorted[i-1]
    for i in range(s-1, -1, -1):
        vSorted[i] = v[i] // vSorted[i+1]
    
    vSorted.append(v[-1] // vSorted[-1])

    v = vSorted.copy()
    vSorted = list(set(vSorted))
    vSorted.sort()

    return v, vSorted

def mapPrimes(vSorted):
    dic = {}
    for i in range(0, min(len(alphabet), len(vSorted))):
        dic[ vSorted[i] ] = alphabet[i]
    return dic

def solve(v):
    a, vSorted = decript(v)
    dic = mapPrimes(vSorted)

    sol = ""
    for x in a:
        sol = sol + dic[ x ]    
    return sol

def main():
    t = int(input())
    for case in range(0,t):
        inp = input()
        inp = input()

        v = [int(x) for x in inp.split(' ')]        
        print("Case #{0}: {1}".format(case+1, solve(v) ))

if __name__ == '__main__':
    main()
