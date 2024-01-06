#include <iostream>

int minimumOperationsToMakeEqual(int x, int y)
{
    int operationCounter = 0;
    if (x == y)
        return 0;
    while (x != y)
    {
        if (x > y)
        {
            if (x % 5 == 0)
            {
                x /= 5;
                operationCounter++;
            }
            else if (x % 3 == 0)
            {
                x /= 3;
                operationCounter++;
            }
            else
            {
                x--;
                operationCounter++;
            }
        }
        else
        {
            if (y % 5 == 0)
            {
                y /= 5;
                operationCounter++;
            }
            else if (y % 3 == 0)
            {
                y /= 3;
                operationCounter++;
            }
            else
            {
                y--;
                operationCounter++;
            }
        }
    }
    return operationCounter;
}

int main()
{
    // Test cases
    std::cout << minimumOperationsToMakeEqual(5, 10) << std::endl;  // Expected output: 1
    std::cout << minimumOperationsToMakeEqual(10, 5) << std::endl;  // Expected output: 1
    std::cout << minimumOperationsToMakeEqual(3, 9) << std::endl;   // Expected output: 2
    std::cout << minimumOperationsToMakeEqual(7, 7) << std::endl;   // Expected output: 0
    std::cout << minimumOperationsToMakeEqual(1, 1) << std::endl;   // Expected output: 0

    return 0;
}