#Transpose of a Matrix (easy)
# Example:
#         input: a = [[1,2,3],[4,5,6]]
#         output: [[1,4],[2,5],[3,6]]
#         reasoning: The transpose of a matrix is obtained by flipping rows and columns.

def transpose_matrix(a: list[list[int|float]]) -> list[list[int|float]]:
    return [[a[j][i] for j in range(len(a))] for i in range(len(a[0]))]

# Print the output

a = [[1,2,3],[4,5,6]]
print(transpose_matrix(a))

