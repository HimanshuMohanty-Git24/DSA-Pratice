#!/bin/python
#8/15 test cases passed
import math
import os
import random
import re
import sys

from collections import deque
from heapq import heappop, heappush

def mazeGame(t, endpoint1, endpoint2, edgeLength):
    n = len(t)
    m = len(endpoint1)
    graph = [[] for _ in range(n+1)]
    for i in range(m):
        u = endpoint1[i]
        v = endpoint2[i]
        w = edgeLength[i]
        graph[u].append((v, w))
        graph[v].append((u, w))
    distances = [-1] * (n+1)
    pq = [(0, 1)]
    while pq:
        time, u = heappop(pq)
        if distances[u] != -1:
            continue

        distances[u] = time

        for v, w in graph[u]:

            new_time = time + w

            if t[v-1] <= new_time:
                continue
            heappush(pq, (new_time, v))
    result = []
    for i in range(1, n+1):
        if distances[i] == -1:
            result.append(-1)
        else:
            result.append(distances[i])
    return result

