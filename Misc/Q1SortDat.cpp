#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// Define the person struct
struct person
{
    int id;
    string name;
    int age;
    int height;
    int weight;
};

// Function to read data from a CSV file and store it in a vector of struct person
vector<person> readCSV(const string &filename)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }

    vector<person> people;
    string line;

    while (getline(file, line))
    {
        person p;
        stringstream ss(line);
        char comma;

        ss >> p.id >> comma;
        getline(ss, p.name, ',');
        ss >> p.age >> comma >> p.height >> comma >> p.weight;

        people.push_back(p);
    }

    file.close();
    return people;
}

// Function to perform heapify operation during heap sort
void heapify(vector<person> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].height > arr[largest].height)
        largest = left;

    if (right < n && arr[right].height > arr[largest].height)
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort
void heapSort(vector<person> &arr)
{
    int n = arr.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from the heap one by one
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    // Initialize the input sizes
    int input_sizes[] = {10, 1000,100000, 1000000}; // You can add more sizes if needed

    ofstream timeFile("execution_times.csv"); // Create a file to record execution times

    for (int i = 0; i < sizeof(input_sizes) / sizeof(input_sizes[0]); i++)
    {
        int input_size = input_sizes[i];
        string filename = "dat" + to_string(input_size) + ".csv";

        // Measure execution time
        clock_t start = clock();
        vector<person> people = readCSV(filename);
        heapSort(people);
        clock_t end = clock();
        double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;

        // Record execution time in the file
        timeFile << input_size << "," << elapsed_time << "\n";

        // Output the sorted data or save it to a file as needed
        // ...

        cout << "Input size: " << input_size << ", Time taken: " << elapsed_time << " seconds" << endl;
    }

    timeFile.close(); // Close the execution time file
    return 0;
}
