#include <iostream>
using namespace std;

class Heap {
public:
  int arr[100];
  int size = 0;

  Heap() {
    arr[0] = -1;
    size = 0;
  }

  void insert(int val) {
    size = size + 1;
    int index = size;
    arr[index] = val;

    while (index > 1) {
      int parent = index / 2;

      if (arr[parent] < arr[index]) {
        swap(arr[parent], arr[index]);
        index = parent;
      } else {
        return;
      }
    }
  }

  void print() {
    for (int i = 1; i <= size; i++) {
      cout << arr[i] << " ";
    }
  }

  void Delete() {
    if (size == 0) {
      cout << "Heap is empty" << endl;
      return;
    }

    arr[1] = arr[size];
    size--;

    int i = 1;
    while (i * 2 <= size) {
      int left = i * 2;
      int right = i * 2 + 1;
      int largest = i;

      if (arr[left] > arr[largest]) {
        largest = left;
      }

      if (right <= size && arr[right] > arr[largest]) {
        largest = right;
      }

      if (largest != i) {
        swap(arr[i], arr[largest]);
        i = largest;
      } else {
        break;
      }
    }
  }
};

int main() {
  Heap h;
  h.insert(50);
  h.insert(55);
  h.insert(54);
  h.insert(53);
  h.insert(52);

  cout << "Heap before deletion: ";
  h.print();
  cout << endl;

  h.Delete();

  cout << "Heap after deletion: ";
  h.print();
  cout << endl;

  return 0;
}
