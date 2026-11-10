#include <iostream>
#include <vector>
#include<string>
using namespace std;
//quick sort
void quickSort(vector<int> &arr,int st ,int end );
int  partition(vector<int> &arr,int st , int end );

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void quickSort(vector<int> &arr,int st ,int end ){
    if(st<end){
        int idx = partition(arr,st,end);
        quickSort(arr,st,idx-1);//must be idx-1
        quickSort(arr,idx+1,end);
    }
};
int partition(vector<int> &arr,int st , int end ){
    int idx=st-1;//must be st-1
    //we are taking ending element as the pivot element
      
    for(int  j=st;j<end;j++){
        if(arr[j]<=arr[end]){
            idx++;
            swap(arr[j],arr[idx]);
        }
    }
    idx++;
    swap(arr[idx],arr[end]);
    return idx;
};

void quickChar(vector<char> &arr,int st ,int end );
int  partitionchar(vector<char> &arr,int st , int end );

void quickChar(vector<char> &arr,int st ,int end ){
    if(st<end){
        int idx = partitionchar(arr,st,end);
        quickChar(arr,st,idx-1);//must be idx-1
        quickChar(arr,idx+1,end);
    }
};
int  partitionchar(vector<char> &arr,int st , int end ){
    int idx=st-1;
    for(int j=st;j<end;j++){
        if(arr[j]<arr[end]){
            idx++;
            swap(arr[j],arr[idx]);
        }
    }
    idx++;
    swap(arr[idx],arr[end]);
    return idx;
};


int main(){
    vector <int> arr={10,5,6,3,2,1};
    cout<<"original array:";
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    quickSort(arr,0,5);
    cout<<"after sorting: ";
    for(int i =0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    vector <char> arrC={'a','d','c','b','e'};
    cout<<"original array:";
    for(int i=0;i<6;i++){
        cout<<arrC[i]<<" ";
    }
    quickChar(arrC,0,5);
    cout<<endl;
    cout<<"original array:";
    for(int i=0;i<6;i++){
        cout<<arrC[i]<<" ";
    }
}