#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <vector>
#include <iomanip>  // For table formatting

using namespace std;

// Function to print the table of frames after each step
void printTable(const vector<vector<int>>& frames, int pageFaults, int hits, int n) {
    cout << "LRU (Least Recently Used) Page Replacement\n";  // LRU Full form
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

void LRUPageReplacement(int pages[], int n, int capacity) {
    unordered_set<int> pageSet;  // To store the current pages in memory
    unordered_map<int, list<int>::iterator> pageMap;  // Map to store page references in the LRU cache
    list<int> lruCache;          // List to store the least recently used order
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
                // Remove the least recently used page (the back of the list)
                int lruPage = lruCache.back();
                lruCache.pop_back();
                pageSet.erase(lruPage);
                pageMap.erase(lruPage);
            }
            // Add the new page into memory and to the front of the list (most recently used)
            pageSet.insert(pages[i]);
            lruCache.push_front(pages[i]);
            pageMap[pages[i]] = lruCache.begin();
            pageFaults++;  // Increment page fault count
        } else {
            // Page is already present (a hit)
            hits++;  // Increment hit count
            // Move the page to the front of the list (most recently used)
            lruCache.erase(pageMap[pages[i]]);
            lruCache.push_front(pages[i]);
            pageMap[pages[i]] = lruCache.begin();
        }

        // Copy the current state of memory (page frames)
        vector<int> tempFrame(capacity, -1);  // Temporary vector to store the frame state
        int index = 0;
        for (auto it = lruCache.begin(); it != lruCache.end(); ++it) {
            tempFrame[index++] = *it;
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

    // Call the LRU page replacement function
    LRUPageReplacement(pages, n, capacity);

    return 0;
}
