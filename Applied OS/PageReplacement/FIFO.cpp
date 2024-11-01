#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
#include <iomanip>  // For table formatting

using namespace std;

void printTable(const vector<vector<int>> &frames, int pageFaults, int hits, int n) {
    cout << "FIFO (First In First Out) Page Replacement\n";
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

void FIFOPageReplacement(int pages[], int n, int capacity) {
    unordered_set<int> pageSet;  // To store the current pages in memory
    queue<int> pageQueue;        // To maintain the order of pages (FIFO)
    int pageFaults = 0;          // To count page faults
    int hits = 0;                // To count hits

    vector<vector<int>> frames(n, vector<int>(capacity + 1, -1));  // To store page changes for the table

    // Traverse through all the pages
    for (int i = 0; i < n; i++) {
        frames[i][0] = pages[i];  // First column will store the accessed page

        // If the page is not present in memory (a fault)
        if (pageSet.find(pages[i]) == pageSet.end()) {
            // Check if memory is full
            if (pageSet.size() == capacity) {
                // Remove the first page (FIFO)
                int pageToRemove = pageQueue.front();
                pageQueue.pop();
                pageSet.erase(pageToRemove);
            }
            // Add the new page into memory and queue
            pageSet.insert(pages[i]);
            pageQueue.push(pages[i]);
            pageFaults++;  // Increment page fault count
        } else {
            hits++;  // Increment hit count if page is already in memory
        }

        // Copy the current state of memory (page frames)
        vector<int> tempFrame(capacity, -1);  // Temporary vector to store the frame state
        queue<int> tempQueue = pageQueue;  // Copy of the queue for iteration

        int index = 0;
        while (!tempQueue.empty()) {
            tempFrame[index++] = tempQueue.front();  // Get the page at the front of the queue
            tempQueue.pop();
        }

        // Copy tempFrame to the table
        for (int j = 0; j < capacity; j++) {
            frames[i][j + 1] = tempFrame[j];
        }
    }

    // Print the table with results
    printTable(frames, pageFaults, hits, n);
}

int main() {
    // Hardcoded page reference string
    int pages[] = {1, 3, 0, 3, 5, 6, 3, 2, 5, 1};
    int n = sizeof(pages) / sizeof(pages[0]);  // Number of pages
    int capacity = 3;  // Memory capacity (number of frames)

    // Call the FIFO page replacement function
    FIFOPageReplacement(pages, n, capacity);

    return 0;
}
