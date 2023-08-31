#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'getMaxTime' function below.
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

def getMaxTime(g_nodes, g_from, g_to):
    adj_list = [[] for _ in range(g_nodes + 1)]
    for i in range(len(g_from)):
        adj_list[g_from[i]].append(g_to[i])
        adj_list[g_to[i]].append(g_from[i])

    max_distance = [-1] * (g_nodes + 1)

    stack = [(1, 0, 0)]

    while stack:
        node, parent, distance = stack.pop()
        max_distance[node] = distance
        for neighbor in adj_list[node]:
            if neighbor != parent:
                stack.append((neighbor, node, distance + 1))

    max_distance_node = max(range(1, g_nodes + 1), key=lambda x: max_distance[x])

    stack = [(max_distance_node, 0, 0)]

    while stack:
        node, parent, distance = stack.pop()
        max_distance[node] = distance
        for neighbor in adj_list[node]:
            if neighbor != parent:
                stack.append((neighbor, node, distance + 1))

    return max(max_distance)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    g_nodes, g_edges = map(int, input().rstrip().split())

    g_from = [0] * g_edges
    g_to = [0] * g_edges

    for i in range(g_edges):
        g_from[i], g_to[i] = map(int, input().rstrip().split())

    result = getMaxTime(g_nodes, g_from, g_to)

    fptr.write(str(result) + '\n')

    fptr.close()
