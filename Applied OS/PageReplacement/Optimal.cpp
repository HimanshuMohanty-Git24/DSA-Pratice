#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>  // For INT_MAX
#include <iomanip>  // For table formatting

using namespace std;

// Function to print the table of frames after each step
void printTable(const vector<vector<int>>& frames, int pageFaults, int hits, int n) {
    cout << "Optimal Page Replacement\n";  // Optimal Full form
    cout << "\nPage Replacement Table:\n\n";
    cout << "Step\tPage\tFrames\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << frames[i][0] << "\t";
        for (int j = 1; j < frames[i].size(); j++) {
            if (frames[i][j] == -1)
                cout << "- ";  // Empty frame
            else
                cout << frames[i][j] << " ";
        }
        cout << endl;
    }

    // Display summary
    cout << "\nTotal Page Faults: " << pageFaults << endl;
    cout << "Total Hits: " << hits << endl;
    double hitRate = (double)hits / n;
    cout << "Hit Rate: " << hitRate << endl;
}

void OptimalPageReplacement(int pages[], int n, int capacity) {
    vector<int> frames(capacity, -1);  // To store current pages in memory
    int pageFaults = 0;                 // To count page faults
    int hits = 0;                       // To count hits
    vector<vector<int>> frameHistory(n, vector<int>(capacity + 1, -1));  // To store page changes for the table

    // Traverse through all the pages
    for (int i = 0; i < n; i++) {
        frameHistory[i][0] = pages[i];  // Store the accessed page

        // Check if the page is already in memory
        bool found = false;
        for (int j = 0; j < capacity; j++) {
            if (frames[j] == pages[i]) {
                found = true;
                hits++;  // Increment hit count
                break;
            }
        }

        if (!found) {
            // If the page is not present, we have a page fault
            pageFaults++;

            // If there is space in memory, add the page
            bool added = false;
            for (int j = 0; j < capacity; j++) {
                if (frames[j] == -1) {
                    frames[j] = pages[i];
                    added = true;
                    break;
                }
            }

            // If memory is full, we need to replace a page
            if (!added) {
                int furthestIndex = -1;
                int pageToReplace = -1;

                // Find the page to replace
                for (int j = 0; j < capacity; j++) {
                    int index = -1;
                    // Find when this page will be used next
                    for (int k = i + 1; k < n; k++) {
                        if (frames[j] == pages[k]) {
                            index = k;
                            break;
                        }
                    }
                    // If the page is not found in future, replace it immediately
                    if (index == -1) {
                        pageToReplace = frames[j];
                        break;
                    }
                    // Find the furthest used page
                    if (index > furthestIndex) {
                        furthestIndex = index;
                        pageToReplace = frames[j];
                    }
                }

                // Replace the page
                for (int j = 0; j < capacity; j++) {
                    if (frames[j] == pageToReplace) {
                        frames[j] = pages[i];
                        break;
                    }
                }
            }
        }

        // Copy the current state of memory (page frames)
        for (int j = 0; j < capacity; j++) {
            frameHistory[i][j + 1] = frames[j];
        }
    }

    // Print the table with results
    printTable(frameHistory, pageFaults, hits, n);
}

int main() {
    // Hardcoded page reference string
    int pages[] = {1, 3, 0, 3, 5, 6, 3, 2, 5, 1};
    int n = sizeof(pages) / sizeof(pages[0]);  // Number of pages
    int capacity = 3;  // Memory capacity (number of frames)

    // Call the Optimal page replacement function
    OptimalPageReplacement(pages, n, capacity);

    return 0;
}
