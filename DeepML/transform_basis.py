# Example:
#         B = [[1, 0, 0], 
#              [0, 1, 0], 
#              [0, 0, 1]]
#         C = [[1, 2.3, 3], 
#              [4.4, 25, 6], 
#              [7.4, 8, 9]]
#         output: [[-0.6772, -0.0126, 0.2342],
#                 [-0.0184, 0.0505, -0.0275],
#                 [0.5732, -0.0345, -0.0569]]

#         reasoning: The transformation matrix P from basis B to C can be found using matrix operations involving the inverse of matrix C.

import numpy as np

def transform_basis(B: list[list[int]], C: list[list[int]]) -> list[list[float]]:
	C_inv = np.linalg.inv(C)
	P = np.dot(C_inv, B)
	return P

# Test the function
B = [[1, 0, 0],
     [0, 1, 0],
     [0, 0, 1]]

C = [[1, 2.3, 3],
    [4.4, 25, 6],
    [7.4, 8, 9]]

print(transform_basis(B, C))