#include <iostream>
using namespace std;


void Heapify(int arr[],int n,int i){
  int largest =i;
  int left=2*i;
  int right = 2*i+1;
  if(left<=n&&arr[largest]<arr[left]){
    largest=left;
  }
  if(right<=n&&arr[largest]<arr[right]){
    largest=right;
  }
  if(largest!=i){
    swap(arr[i],arr[largest]);
    Heapify(arr,n,largest);
  }
}
void heapSort(int arr[],int n){
    int size=n;

    while(size>1){
        swap(arr[size],arr[1]);
        size--;
        Heapify(arr,size,1);
    }
}

int main() {
  int arr[6]={-1,70,60,50,45,50};
  heapSort(arr,5);
  cout<<"Printing the array"<<endl;
  for(int i=1;i<6;i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}
