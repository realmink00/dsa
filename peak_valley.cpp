#include<bits/stdc++.h>
using namespace std;
//helper fucntion to swap int same can be used for char also
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
void peakvalley(int arr[],int size){
    for(int i=1;i<size;i=i+2){
        if(arr[i]<arr[i-1])               swap(arr[i],arr[i-1]);      //mid smaler then left
        if((i+1)<size && arr[i]<arr[i+1]) swap(arr[i],arr[i+1]);
    }
}
int main(){
    int arr[]={4,5,6,3,1,7};
    int size=sizeof(arr)/sizeof(arr[0]);
    peakvalley(arr,size);
    //display array
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}