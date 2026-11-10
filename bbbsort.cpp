#include<iostream>
#include<vector>
using namespace std;

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
void bubbleSort(vector<int> &arr){
    int size=arr.size();

    for(int i = 0; i<size;i++){
        for(int j = i+1;j<size;j++){
            if(arr[j]<arr[i]){
                swap(arr[i],arr[j]);
            }
        }
    }
}

int main(){
    vector<int> arr={4,6,10,0,3,};
    int n=arr.size();
    cout<<"BEFORE sorting :";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    bubbleSort(arr);
    cout<<"after sorting :";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}


