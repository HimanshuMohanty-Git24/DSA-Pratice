/*
Alpha-beta pruning is an optimization technique for a minimax algorithm. It reduces computation time by a huge factor,
allowing the user to traverse faster and deeper into the tree. It stops evaluating when at least one possibility has been
found that typically proves the move to be worse than the previously examined move. The minimax search is based on depth-first
search which considers the nodes along a single path in a tree. But Alph-Beta pruning bonds with two major parameters in
MAX-VALUE(state, alpha, beta), representing Alpha plays a maximizer role, whereas Beta plays a minimizer role.
*/

#include <bits/stdc++.h>
using namespace std;


// Function to find the optimal value of a node
int alphabeta(int depth, int nodeIndex, bool maximizingPlayer, int values[], int alpha, int beta)
{
    // Terminating condition. i.e leaf node is reached
    if (depth == 3)
        return values[nodeIndex];

    if (maximizingPlayer)
    {
        int best = INT_MIN;

        // Recur for left and right children
        for (int i = 0; i < 2; i++)
        {
            int val = alphabeta(depth + 1, nodeIndex * 2 + i, false, values, alpha, beta);
            best = max(best, val);
            alpha = max(alpha, best);

            // Alpha Beta Pruning
            if (beta <= alpha)
                break;
        }
        return best;
    }
    else
    {
        int best = INT_MAX;

        // Recur for left and right children
        for (int i = 0; i < 2; i++)
        {
            int val = alphabeta(depth + 1, nodeIndex * 2 + i, true, values, alpha, beta);
            best = min(best, val);
            beta = min(beta, best);

            // Alpha Beta Pruning
            if (beta <= alpha)
                break;
        }
        return best;
    }
}

// Driver Code
int main()
{
    int values[] = {3, 5, 6, 9, 1, 2, 0, -1};
    cout << "The optimal value is : " << alphabeta(0, 0, true, values, INT_MIN, INT_MAX) << endl;
    return 0;
}