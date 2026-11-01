#include <iostream>
using namespace std;


void mergeSort(int arr[],int temp[],int left, int right){
    if(left >= right) return;
    int mid = left + (right-left)/2;

    mergeSort(arr, temp, left, mid);
    mergeSort(arr, temp, mid+1, right);

    int li = left;
    int ri = mid+1;
    int i=0;
    while(li <=mid && ri <=right){
        if(arr[li] > arr[ri]){
            temp[i++] = arr[ri++];
        }
        else temp[i++] = arr[li++];
    }
    while (li <= mid) temp[i++] = arr[li++];
    while(ri<=right) temp[i++] = arr[ri++];
    
    for(int j=0;j<i;j++) arr[left+j] = temp[j];
}

int main(){
    int arr[] = {5,6,7,1,2,3,4};
    int temp[7]= {0};
    mergeSort(arr,temp,0,6);
    for(auto x:arr) cout << x << " ";
}
