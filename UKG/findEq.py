MOD = int(1e9 + 7)

def dfs(node, adj, ans):
    for child, weight in adj[node]:
        ans[child] = (ans[node] * weight) % MOD
        dfs(child, adj, ans)

def find_equivalent_magnitude(unit_nodes, unit_from, unit_to, unit_weight, x):
    adj = [[] for _ in range(unit_nodes + 1)]
    n = len(unit_from)

    for i in range(n):
        adj[unit_from[i]].append((unit_to[i], unit_weight[i]))

    ans = [0] * (unit_nodes + 1)
    ans[1] = x

    dfs(1, adj, ans)
    return ans

# n = int(input())
# n -= 1

# arr = list(map(int, input().split()))
# brr = list(map(int, input().split()))
# crr = list(map(int, input().split()))

# x = int(input())

# result = find_equivalent_magnitude(n + 1, arr, brr, crr, x)
# print(" ".join(map(str, result[1:])))
