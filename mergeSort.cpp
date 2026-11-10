#include <iostream>
#include <vector>
using namespace std;


void mergeSort(vector<int>& arr,int st,int end);
void merge(vector<int> &arr,int st,int mid ,int end);
void mergeSort(vector<int> &arr,int st,int end){
    if(st<end){
        int mid= st+ ((end-st)/2);
        mergeSort(arr,st,mid);//right half
        mergeSort(arr,mid+1,end);//left half
        merge(arr,st,mid,end);
    }
}
void merge(vector<int> &arr,int st,int mid ,int end){
    vector<int> temp;
    int i=st,j=mid+1;

    // i and j concept of merging 
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;  
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    //copying the remaining elements if anyy
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }
    //final copying 
    for(int idx=0;idx<temp.size();idx++){
        arr[idx+st]=temp[idx];
    }
}

int main(){
    vector<int> arr={10,4,6,0,3};
    int n = arr.size();
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    mergeSort(arr,0,n-1);
    cout<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    
}