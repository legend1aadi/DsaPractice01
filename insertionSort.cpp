#include<iostream>
#include<vector>
using namespace std;

/*int insertionSort(vector <int> &arr){
    int n= arr.size();

    for(int i=1;i<n;i++){
        int cur=i;
        int prev=i-1;
        while(prev>=0 && arr[prev]>cur){
            arr[prev+1]=arr[prev];
            prev--;
        } 
        arr[prev+1]=cur;//increment after decrement like 0+1
    }

}*/

int insertionSort(vector<int> &arr){
    int n=arr.size();

    for(int i=1;i<n;i++){
        int curr=arr[i];
        int prev=i-1;
        
        while(prev>=0 && arr[prev]>curr){
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=curr;

    }
}





int main(){
    vector<int> arr={10,4,6,0,3};
    int n = arr.size();
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    insertionSort(arr);
    cout<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}