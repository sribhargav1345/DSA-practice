import math

def find_number_sequence(s, n):
    low = 0
    high = 2 ** n
    ans = []
    ct = 0

    while ct < n and low <= high:
        mid = (low + high) // 2
        if s[ct] == 'L':
            high = mid
            ans.append(mid)
        else:
            low = mid
            ans.append(mid)
        ct += 1
    return ans

# Read input
n = int(input())
s = input()

# Find and print the number sequence
result = find_number_sequence(s, n)
print(" ".join(map(str, result)))
