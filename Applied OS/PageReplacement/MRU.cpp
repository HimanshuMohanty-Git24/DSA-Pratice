#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>  // For table formatting

using namespace std;

// Function to print the table of frames after each step
void printTable(const vector<vector<int>>& frames, int pageFaults, int hits, int n) {
    cout << "MRU (Most Recently Used) Page Replacement\n";  // MRU Full form
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

void MRUPageReplacement(int pages[], int n, int capacity) {
    unordered_set<int> pageSet;              // To store the current pages in memory
    unordered_map<int, int> pageIndex;       // Map to store the most recently used pages
    vector<int> frames(capacity, -1);         // To store current pages in memory
    int pageFaults = 0;                       // To count page faults
    int hits = 0;                             // To count hits
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

            // If memory is full, we need to replace the most recently used page
            if (!added) {
                // Find the most recently used page
                int mruPage = -1;
                int mruIndex = -1;

                for (int j = 0; j < capacity; j++) {
                    if (pageIndex.find(frames[j]) != pageIndex.end()) {
                        if (mruIndex == -1 || pageIndex[frames[j]] > mruIndex) {
                            mruIndex = pageIndex[frames[j]];
                            mruPage = frames[j];
                        }
                    }
                }

                // Replace the most recently used page
                for (int j = 0; j < capacity; j++) {
                    if (frames[j] == mruPage) {
                        frames[j] = pages[i];
                        break;
                    }
                }
            }
        }

        // Update the most recently used index
        pageIndex[pages[i]] = i;

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

    // Call the MRU page replacement function
    MRUPageReplacement(pages, n, capacity);

    return 0;
}
