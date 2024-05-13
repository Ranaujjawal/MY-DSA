#include <bits/stdc++.h>
using namespace std;

//selection sort find min swap it from the front 
// again find min from i=1 to i=n-1, swap(arr[i],arr[min]); and .... till i=n-2; O(n^2)
void selectionSort(int arr[], int n)
    {
        for(int i=0;i<n-1;i++){
      int minidx=i;
      for(int j=i;j<n;j++){
          if(arr[j]<arr[minidx]){
              minidx=j;
          }
      }
      swap(arr[i],arr[minidx]);
    }}

//bubble sort push maxmimum element to the last by adjacent swaps 
//if(arr[i]>arr[i+1]) swap (arr[i],arr[i+1]) O(n^2)
// time comp can be decreased to the O(n) if no swaps in the first interation
void bubbleSort(int arr[], int n)
    {
        for(int i=0;i<n;i++){
            int swaps=0;
            for(int j=0;j<n-1;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                    swaps=1;
                }
            }
            if(swaps==0) break; // optimization for if sorted already 
        }
    }

//insertion sort select an element and insert it into its right position
// like swap from that element from backward to forward till the front ele is smaller
// O(n^2) worst and average Best O(N) when no swaps happen
void insertionSort(int arr[], int n)
    {
      for(int i=0;i<n;i++){
          int j=i;
          while(j>0 and arr[j]<arr[j-1]){
              int temp=arr[j];
              arr[j]=arr[j-1];
              arr[j-1]=temp;
              j--;
          }
      }
    }

// merge sort divide array into two array at each recurssion call using mid=(low+high)/2
// call for first half and then call for second half 
// afterwards call the merge function using two pointer to store compared elements in a new temporary array
//in merge function push the remenning elements by making a two seprate while loop
// replace the elements into original array using temporary array
//Time complexity O(Nlog(N)) space O(N)
void mergesort(vector<int>arr,int low,int high){
    if(low>=high) return;
    int mid=(low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
void merge(vector<int>arr,int low,int mid,int high){
    vector<int>temp;
    int l=low;
    int r=mid+1;
    while(l<=mid && r<=high){
        if(arr[l]<arr[r]) {
            temp.push_back(arr[l]);
            l++;
    }
    else{
        temp.push_back(arr[r]);
            r++;
    }
    }
    while(l<=mid){
         temp.push_back(arr[l]);
            l++;
    }
    while(r<=high){
         temp.push_back(arr[r]);
            r++;
    }
    int i=0;
    for(auto it:temp){
        arr[i]=*it;
        i++;
    }
}

// quick sort divide and conquere alogo 
// select a pivot element can be first,last or any element of the array
// fix the pivot at its correct position by using a high low two pointer concept
// select the first element from left greater or equal to  pivot
// select the first element from right smaller then pivot
// if(low < high) swap them 
// outside loop make a swap of low and r to fix the pivot at correct position
// finally return the correct position of pivot 
// call the sorting quick func again for the unsorted left and right half of the array
//time complexity O(N*log(N)); space complexity O(1);
void quicksort(vector<int>arr,int low,int high){
if(low>=high) return;
int partidx=partition(arr,low,high);
quicksort(arr,low,partidx-1);
quicksort(arr,partidx+1,high);
} 
int partition(vector<int>arr,int low,int high){
int pivot=arr[low];
int l=low;
int r=high;
while(l<r){
    while(arr[l]<=pivot and l<=high-1)l++;
    while(arr[r]>pivot and r>=low+1) r--;
    if(l<r) swap(arr[l],arr[r]);
}
swap(arr[low],arr[r]);//sending pivot to correct position
return r;
}
signed main(){
        std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
 #endif
   
    return 0;
    
	
}
//pogo