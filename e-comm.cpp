#include <iostream>
using namespace std;

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low,j=high;
    while(i<j){
        while(i<=high-1 && arr[i]<=pivot) i++;
        while(j>=low+1 && arr[j]>pivot) j--;
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

void quickSort(int arr[],int low,int high){
    if(low<high){
        int p=partition(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
}

void merge(int arr[],int low,int mid,int high){
    int temp[100];
    int i=low,j=mid+1,k=0;

    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]) temp[k++]=arr[i++];
        else temp[k++]=arr[j++];
    }

    while(i<=mid) temp[k++]=arr[i++];
    while(j<=high) temp[k++]=arr[j++];

    for(int i=low;i<=high;i++)
        arr[i]=temp[i-low];
}

void mergeSort(int arr[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

void selectionSort(int arr[],int n){
    for(int i=0;i<=n-2;i++){
        int mini=i;
        for(int j=i+1;j<=n-1;j++){
            if(arr[j]<arr[mini]) mini=j;
        }
        swap(arr[i],arr[mini]);
    }
}

void insertionSort(int arr[],int n){
    for(int i=1;i<=n-1;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}

int main(){
    int arr[100],n;
    cout<<"Enter number of products: ";
    cin>>n;

    cout<<"Enter product prices: ";
    for(int i=0;i<n;i++) cin>>arr[i];

    int temp[100];
    for(int i=0;i<n;i++) temp[i]=arr[i];

    mergeSort(temp,0,n-1);
    cout<<"Products sorted by price: ";
    for(int i=0;i<n;i++) cout<<temp[i]<<" ";
    cout<<endl;

    cout<<"Enter product popularity values: ";
    for(int i=0;i<n;i++) cin>>arr[i];

    insertionSort(arr,n);
    cout<<"Products sorted by popularity: ";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}