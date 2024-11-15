def minArea(x, y, k):
    def can_form_square(side_length):
        # Check if there exists a square of given side length that contains at least k points
        for i in range(len(x)):
            for j in range(len(y)):
                top_left_x, top_left_y = x[i] - side_length, y[j] - side_length
                count = 0
                for p in range(len(x)):
                    if top_left_x < x[p] < top_left_x + side_length and top_left_y < y[p] < top_left_y + side_length:
                        count += 1
                if count >= k:
                    return True
        return False

    low, high = 1, max(max(x) - min(x), max(y) - min(y))
    while low < high:
        mid = (low + high) // 2
        if can_form_square(mid):
            high = mid
        else:
            low = mid + 1
    return low * low

x = list(map(int,input().split()))
y = list(map(int,input().split()))

k = int(input())
print(minArea(x, y, k))  