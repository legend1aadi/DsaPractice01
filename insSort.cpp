#include<iostream>
#include<vector>
using namespace std;

int insSort(vector<int> &arr){
    int n=arr.size();
    int comparison=0;
    for(int i = 1; i<n;i++){
        int curr= arr[i];
        int prev= i-1;

        while( prev>=0 && arr[prev]>curr){
            comparison++;
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=curr;
    }
    return comparison;
}

int main(){
    cout<<"original array: \n";
    vector <int> arr={10,2,3,1,0};
    int n = arr.size();
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"sorted array : \n ";
    int comp= insSort(arr);
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"number of comparisons: "<<comp<<endl;

}