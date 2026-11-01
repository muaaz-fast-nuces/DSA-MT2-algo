#include <iostream>
using namespace std;

void countingSort(int arr[], int temp[],int n,int power){
    int freq[10]= {0};
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]/power % 10]++;
    }
    for(int i=1;i<10;i++) freq[i] += freq[i-1];
    for(int i=n-1;i>=0;i--){
        temp[--freq[arr[i]/power % 10]] = arr[i];
    }
    for(int i=0;i<n;i++) arr[i] = temp[i];
}

int getMax(int arr[],int n){
    int maxi = 0;
    for (int i =1; i < n; i++)
    {
        if(arr[maxi] < arr[i]) maxi=i;
    }
    return arr[maxi];
}

void radixSort(int arr[],int temp[],int n){
    int maximumElem= getMax(arr,n);
    for(int power= 1;maximumElem/power >=1;power*=10)       
            countingSort(arr,temp,n,power);
}

int main(){
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int temp[20];
    int n = 8;
    radixSort(arr,temp,n);
    for(auto x:arr) cout << x << " ";
}
