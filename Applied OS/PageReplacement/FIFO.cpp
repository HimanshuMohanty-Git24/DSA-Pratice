//Implement FIFO page replacement algo using 3 frames and a custom hardcoded page series display the table,Hits,Pgaefaults*hit ratio make the code functionl
//Display the table
//Display the No.of Hits
//Display the no of Page faults
//Display the Hitratio

#include<bits/stdc++.h>

using namespace std;

// Function to find page faults using FIFO and display the frame table
int pageFaults(int pages[], int n, int capacity)
{
    // To represent set of current pages. We use an unordered_set so that we quickly check if a page is present in set or not
    unordered_set<int> s;
    // To store the pages in FIFO manner
    queue<int> indexes;
    // Start from initial page
    int page_faults = 0;
    int hits = 0;

    cout << "Frame Table:" << endl;

    for (int i = 0; i < n; i++)
    {
        // Check if the set can hold more pages
        if (s.size() < capacity)
        {
            // Insert it into set if not present already which represents page fault
            if (s.find(pages[i]) == s.end())
            {
                s.insert(pages[i]);
                // Increment page fault
                page_faults++;
                // Push the current page into the queue
                indexes.push(pages[i]);
            }
            else
            {
                hits++;
            }
        }
        // If the set is full then need to perform page replacement
        else
        {
            // Check if the current page is not already present in the set
            if (s.find(pages[i]) == s.end())
            {
                // Get the page at the front of the queue which is to be replaced
                int val = indexes.front();
                indexes.pop();
                // Remove the indexes page
                s.erase(val);
                // Insert the current page
                s.insert(pages[i]);
                // Push the current page into the queue
                indexes.push(pages[i]);
                // Increment page fault
                page_faults++;
            }
            else
            {
                hits++;
            }
        }

        // Display the current frame table
        queue<int> temp = indexes;
        while (!temp.empty())
        {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }

    cout << "No. of Hits: " << hits << endl;
    cout << "No. of Page Faults: " << page_faults << endl;
    cout << "Hit Ratio: " << (float)hits / n << endl;

    return page_faults;
}

// Function to display the table
void displayTable(int pages[], int n, int capacity)
{
    cout << "Page Series: ";
    for (int i=0; i<n; i++)
        cout << pages[i] << " ";
    cout << endl;
    cout << "Frame Table: ";
    int page_faults = pageFaults(pages, n, capacity);
    cout << endl;
    cout << "No. of Hits: " << n - page_faults << endl;
    cout << "No. of Page Faults: " << page_faults << endl;
    cout << "Hit Ratio: " << (float)(n - page_faults) / n << endl;
}

// Driver code
int main()
{
    int pages[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 6};
    int n = sizeof(pages)/sizeof(pages[0]);
    int capacity = 3;
    displayTable(pages, n, capacity);
    return 0;
}