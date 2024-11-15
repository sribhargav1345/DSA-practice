def solve(arr, n):
    arr.sort()
    i = 0
    j = 1
    cnt = 0

    while j < n:
        if arr[i] == arr[j]:
            j += 1
        else:
            cnt += 1
            i += 1
            j += 1
    return cnt

n = int(input())
arr = list(map(int,input().split()))

print(solve(arr, n))
