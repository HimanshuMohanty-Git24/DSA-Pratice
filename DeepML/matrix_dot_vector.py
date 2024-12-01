'''
    Example:
            input: a = [[1,2],[2,4]], b = [1,2]
            output:[5, 10] 
            reasoning: 1*1 + 2*2 = 5;
                    1*2+ 2*4 = 10
'''
def matrix_dot_vector(a:list[list[int|float]],b:list[int|float])-> list[int|float]:
    if len(a[0]) != len(b):
        return -1
    result = []
    for i in range(len(a)):
        sum = 0
        for j in range(len(a[0])):
            sum += a[i][j]*b[j]
        result.append(sum)
    return result

# Test the function
a = [[1,2],[2,4]]
b = [1,2]
print(matrix_dot_vector(a,b)) # Output: [5, 10]

# -1 test
a = [[1,2],[2,4]]
b = [1,2,3]
print(matrix_dot_vector(a,b)) # Output: -1
