#include<iostream>
#include<vector>
using namespace std;

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void selectionSort(vector<int> & arr){
    int size= arr.size();
    for(int i =0;  i<size;i++){
        int smallestIdx=i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[smallestIdx]){
                smallestIdx=j;
            }
        }
        swap(arr[smallestIdx],arr[i]);
    }
}
int main(){
    vector<int> arr={1,3,7,9,2,0,6};
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    selectionSort(arr);
    cout<<endl;

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

}
