#include<iostream>
#include<vector>
using namespace std;

void mergeSort(vector<int> &arr, int st, int end);
void merge(vector<int> &arr, int st, int mid, int end);

void mergeSort(vector<int> &arr, int st, int end){
    if(st < end){
        int mid = st + (end - st) / 2;
        mergeSort(arr, st, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, st, mid, end);
    }
}

void merge(vector<int> &arr, int st, int mid, int end){
   int l=mid-st+1;
   int r=end-mid;

   vector <int> arrL,arrR;
   for(int i=st;i<=mid;i++){
        arrL.push_back(arr[i]);
   }
   for(int j= mid+1;j<=end;j++){
        arrR.push_back(arr[j]);
   }
   //both right and left array created next doing sort 
   int i=0,j=0;
   for(int k=st;k<=end;k++){
    if(i>=l){
        arr[k]=arrR[j];
        j++;
    }
    else if(j>=r){
        arr[k]=arrL[i];
        i++;
    }
    //now comes main part 
    else if(arrL[i]<arrR[j]){
        arr[k]=arrL[i];
        i++;    
    }
    else{
        arr[k]=arrR[j];
        j++;
    }
   }
   
}

int main(){
    cout << "hello" << endl;
    vector<int> arr = {10, 2, 3, 1, 0};
    
    cout << "Original array: ";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    mergeSort(arr, 0, arr.size() - 1);
    
    cout << "Sorted array (ascending): ";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}