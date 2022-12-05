import sys
from kmp import KMPSearch
from chudnovskybinarysplitting import CalculatePi

if __name__ == '__main__':
    pat = sys.argv[1]
    CalculatePi()
    st = time.time()
    KMPSearch(pat, "./pi.txt")
    et = time.time()
    print("Time taken for searching the pattern in the pi expansion is : ",et-st," seconds")