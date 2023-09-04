#!/bin/python3
#2/15 test cases passed
import math
import os
import random
import re
import sys



#
# Complete the 'getMinInversions' function below.
#
# The function is expected to return an INTEGER.
# The function accepts UNWEIGHTED_INTEGER_GRAPH g as parameter.
#

#
# For the unweighted graph, <name>:
#
# 1. The number of nodes is <name>_nodes.
# 2. The number of edges is <name>_edges.
# 3. An edge exists between <name>_from[i] and <name>_to[i].
#
#

def getMinInversions(g_nodes, g_from, g_to):
    print("g_nodes:", g_nodes)
    print("g_from:", g_from)
    print("g_to:", g_to)
    graph = [[] for _ in range(g_nodes + 1)]
    for i in range(len(g_from)):
        from_node = g_from[i]
        to_node = g_to[i]
        graph[from_node].append(to_node)

    def dfs(node, parent):
        inversions_count = 0
        for neighbor in graph[node]:
            if neighbor == parent:
                continue
            inversions_count += dfs(neighbor, node) + 1
        return inversions_count

    min_inversions = float('inf')

    for node in range(1, g_nodes + 1):
        inversions = dfs(node, 0)
        min_inversions = min(min_inversions, inversions)

    return min_inversions

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    g_nodes, g_edges = map(int, input().rstrip().split())

    g_from = [0] * g_edges
    g_to = [0] * g_edges

    for i in range(g_edges):
        g_from[i], g_to[i] = map(int, input().rstrip().split())

    result = getMinInversions(g_nodes, g_from, g_to)

    fptr.write(str(result) + '\n')

    fptr.close()
