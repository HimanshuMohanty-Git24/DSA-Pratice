def solve(A, B):
    mod = 1000000007
    n = len(A)
    left = 0
    current_sum = 0
    min_len = float('inf')
    result = [-1]

    for right in range(n):
        current_sum += A[right]

        while current_sum >= B:
            if current_sum == B:
                if right - left + 1 < min_len:
                    min_len = right - left + 1
                    result = []

                    for i in range(left, right + 1):
                        diff = B - (current_sum - A[i])
                        result.append(diff % mod if diff != 0 else 1)

            current_sum -= A[left]
            left += 1

    if result == [-1]:
        return [-1]
    else:
        return result

print("input: [3,3,3,4], 9")

A = [3,3,3,4]
B = 9
print(solve(A, B))


print("input: [5,26,88,71,41,37,63,61,23], 57")

A = [5,26,88,71,41,37,63,61,23]
B = 57
print(solve(A, B))