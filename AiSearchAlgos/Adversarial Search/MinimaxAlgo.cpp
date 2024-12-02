/*
Minimax algorithm
The Minimax algorithm is claimed to be a recursive or backtracking algorithm that is responsible for choosing the best optimal move in the conflicting environment. The Minimax algorithm operates on a tree structure known as the game tree, which is the collection of all the possible moves in the corresponding game states in a given game. The game tree’s leaf node accommodates all the possible moves. The game state denotes the current board condition. With every single move, the game state changes and the game tree gets updated height-wise. When visualized, this game tree often resembles an inverted tree, with the root representing the current game state and the branches representing possible moves.

This algorithm simply works by proceeding down to the tree until it reaches the leaf node and then it backs up the minimax values through the tree as the recursion unwinds. The prime motive of the Minimax algorithm is to maximize the chance of winning for the maximizer. In the game tree, every node is assigned weights that influence the chances of winning, the higher the weights, the higher the chances of winning.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

// Function to calculate the minimax value of the game state
int minimax(int depth, int nodeIndex, bool maximizingPlayer, vector<int>& scores, int height)
{
    // Base case: if the depth of the tree is reached
    if (depth == height)
        return scores[nodeIndex];

    // If the player is maximizing, find the maximum possible value
    if (maximizingPlayer)
        return max(minimax(depth + 1, nodeIndex * 2, false, scores, height),
                   minimax(depth + 1, nodeIndex * 2 + 1, false, scores, height));

    // If the player is minimizing, find the minimum possible value
    else
        return min(minimax(depth + 1, nodeIndex * 2, true, scores, height),
                   minimax(depth + 1, nodeIndex * 2 + 1, true, scores, height));
}

// Driver code

int main()
{
    vector<int> scores = {3, 5, 2, 9, 12, 5, 23, 23};
    int height = log2(scores.size());
    int result = minimax(0, 0, true, scores, height);
    cout << "The optimal value is: " << result << endl;
    return 0;
}
