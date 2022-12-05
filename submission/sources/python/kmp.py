import time


def KMPSearch(pat, txt):
    M = len(pat)
    file = open(txt, "r")
    data = file.read()
    N = len(data)

    # list_of_lists = []
    # with open(txt) as f:
    #     for line in f:
    #         inner_list = [int(elt.strip()) for elt in line]
    #     list_of_lists.append(inner_list)
 
    # create lps[] that will hold the longest prefix suffix
    # values for pattern
    lps = [0]*M
    j = 0 # index for pat[]
 
    # Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps)
 
    i = 0 # index for txt[]
    while (N - i) >= (M - j):
        if pat[j] == data[i]:
            i += 1
            j += 1
 
        if j == M:
            print ("Found pattern at index " + str(i-j))
            j = lps[j-1]
            break
 
        # mismatch after j matches
        elif i < N and pat[j] != data[i]:
            # Do not match lps[0..lps[j-1]] characters,
            # they will match anyway
            if j != 0:
                j = lps[j-1]
            else:
                i += 1
 
def computeLPSArray(pat, M, lps):
    len = 0 # length of the previous longest prefix suffix
 
    lps[0] # lps[0] is always 0
    i = 1
 
    # the loop calculates lps[i] for i = 1 to M-1
    while i < M:
        if pat[i]== pat[len]:
            len += 1
            lps[i] = len
            i += 1
        else:
            # This is tricky. Consider the example.
            # AAACAAAA and i = 7. The idea is similar
            # to search step.
            if len != 0:
                len = lps[len-1]
 
                # Also, note that we do not increment i here
            else:
                lps[i] = 0
                i += 1

# txt = "ABABDABACDABABCABAB"
pat = sys.argv[1]
st = time.time()
KMPSearch(pat, "./pi.txt")
et = time.time()
print("Time taken for searching the pattern in the pi expansion is : ",et-st," seconds")
