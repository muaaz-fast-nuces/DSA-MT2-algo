#include <iostream>
using namespace std;

void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}




void quickSort(int arr[],int left, int right){
    if(left >=right) return;
    if((right - left) < 2)
    {
        if (arr[left] > arr[right])
            swap(arr[left], arr[right]);
        return;
    }
    int center = left+ (right-left)/2;
    int pivot = arr[center]; 
    swap(arr[center],arr[right]);

    int i = left;
    int j = right-1;
    while (true)
    {
        while(arr[i] < pivot ){i++;}
        while(j>left && arr[j]>=pivot){j--;}

        if(i>=j) break;
        swap(arr[i++],arr[j--]);
    }
  
    swap(arr[i],arr[right]);
    quickSort(arr, left, i - 1);
    quickSort(arr, i+1, right);
}


int main(){
    int arr[] = {7,6,5,4,3,4,2,1};
    quickSort(arr,0,7);
    for(auto x:arr) cout << x << " ";
    return 0;

}