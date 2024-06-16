#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

void solveElection()
{
    int numCandidates, undecidedVoters;
    cin >> numCandidates >> undecidedVoters;

    vector<int> votes(numCandidates);
    for (auto &voteCount : votes)
    {
        cin >> voteCount;
    }

    // Add undecided voters to the first candidate
    votes[0] += undecidedVoters;
    int maxVotes = votes[0];
    int winnerIndex = 0;

    // Find the candidate with the maximum votes
    for (int i = 0; i < votes.size(); i++)
    {
        if (votes[i] > maxVotes)
        {
            maxVotes = votes[i];
            winnerIndex = i;
        }
    }

    int cumulativeVotes = 0;
    vector<int> minExclusions(numCandidates);

    // Calculate the minimum exclusions for each candidate to win
    for (int i = 0; i < votes.size(); i++)
    {
        cumulativeVotes += votes[i];
        if (i == winnerIndex)
        {
            minExclusions[i] = 0;
        }
        else
        {
            if (cumulativeVotes >= maxVotes)
            {
                minExclusions[i] = i;
            }
            else
            {
                minExclusions[i] = i + 1;
            }
        }
    }

    // Output the result for each candidate
    for (const auto &exclusion : minExclusions)
    {
        cout << exclusion << " ";
    }
    cout << endl;
}

signed main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        solveElection();
    }
    return 0;
}
