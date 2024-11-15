def solve(s):
    n = len(s)
    ct = 0
    flag = False

    for char in s:
        if char == '1':
            ct += 1
        else:
            ct -= 1

        if ct < 0:
            flag = True
            break

    if flag:
        return False
    return ct == 0

def f(s):
    n = len(s)

    for i in range(n):
        if s[i] == '0':
            return i
    return -1

# Read input
s = input()
ans = s
n = len(s)

for i in range(n):
    p = s[:i+1]
    q = s[i+1:]

    if solve(p) and solve(q):
        ko = q + p

        if f(ans) < f(ko):
            ans = ko

print(ans)
