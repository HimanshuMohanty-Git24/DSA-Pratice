#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'countMaximumCustomers' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. 2D_INTEGER_ARRAY customer
#  2. 2D_INTEGER_ARRAY shop
#

def countMaximumCustomers(customers, shops):
    print("Customers:", customers)
    print("Shops:", shops)
    max_customers_served = 0

    shop_items = [set(shop) for shop in shops]

    for customer in customers:
        for shop_items_set in shop_items:
            if set(customer).issubset(shop_items_set):
                max_customers_served += 1
                break

    return max_customers_served
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    customer_rows = int(input().strip())
    customer_columns = int(input().strip())

    customer = []

    for _ in range(customer_rows):
        customer.append(list(map(int, input().rstrip().split())))

    shop_rows = int(input().strip())
    shop_columns = int(input().strip())

    shop = []

    for _ in range(shop_rows):
        shop.append(list(map(int, input().rstrip().split())))

    result = countMaximumCustomers(customer, shop)

    fptr.write(str(result) + '\n')

    fptr.close()
