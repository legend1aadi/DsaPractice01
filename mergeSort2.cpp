//this is the way taught according to the book'

#include<iostream>
#include<vector>
using namespace std;

void mergeSort(int * arr,int st,int end);
void merge(int *arr,int st,int mid , int end );
int comparisons=0;

void mergeSort(int * arr,int st,int end){
    if(st<end){
        int mid= st+ ((end-st)/2);
        mergeSort(arr,st,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,st,mid,end);
    }
};
/*
void merge(int *arr,int st,int mid , int end){
    int n1=mid-st+1;//size of n1
    int n2=end-mid+1;//size of n2

    //creating the arrays :
    int arrL[n1],arrR[n2];
    for(int i=0;i<n1;i++){
        arrL[i]=arr[st+i];//for sub parts of arrays here we do st+i
    }
    for(int j=0;j<n2;j++){
        arrR[j]=arr[mid+j+1];
    }
    //
    int i=0,j=0;
    for(int k=st;k<=end;k++){
        if(arrL[i]<=arrR[j]){
            arr[k]=arrL[i];
            i++;
        }else{
            arr[k]=arrR[j];
            j++;
        }
    }


}
*/
void merge(int*arr,int st, int mid , int end ){
    int n1=mid-st+1;//size of arr
    int n2=end-mid;
    //creating 2  arrays
    int arrL[n1],arrR[n2];
    for(int i=0;i<n1;i++){
        arrL[i]=arr[st+i];//for sub parts of arrays here we do st+i
    }
    for(int j=0;j<n2;j++){
        arrR[j]=arr[mid+j+1];
    }
    int i=0,j=0,k=st;
    while(i<n1 && j<n2){
        if(arrL[i]<arrR[j]){
            arr[k]=arrL[i];
            k++;
            i++;
        }
        else{
            arr[k]=arrR[j];
            k++;
            j++;
        }
    }
    while(i<n1){
        arr[k]=arrL[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=arrR[j];
        j++;
        k++;
    }

}













int main(){
    int arr[5]={10,4,6,0,3};
    int n = 5;
    cout<<"before sorting: ";
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\nafter sorting: ";
    mergeSort(arr,0,n-1);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}
