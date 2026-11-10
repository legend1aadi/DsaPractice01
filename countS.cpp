#include <iostream>
#include <vector>
using namespace std;

int maximum(vector<int> arr){
    int maxi=0;
    for(int i=1;i<arr.size();i++){
        maxi=max(arr[i],maxi);
    }
    return maxi;
}


int count(int n, vector<int> arr){
    int c=0;
    for(int i =0;i<arr.size();i++){
        if(arr[i]==n){
            c++;
        }
    }
    return c;
};

void Count_sort(vector<int>& Arr){
    int size= Arr.size();
    int max= maximum(Arr);
    vector<int> arr(max+1,0);


    for(int i = 0; i<Arr.size();i++){
        arr[Arr[i]]++;
    }

    int idx=0;
    for(int j=0;j<arr.size();j++){
        while(arr[j]>0){
            Arr[idx++]=j;
            arr[j]--;
        }
    }
}


int main(){
    cout<<"hello"<<endl;
    vector<int> arr={0,3,8,6,6,3,78};
    cout<<"before sorting: "<<endl;
    for(int i =0 ; i<arr.size();i++){
        cout<<arr[i]<< " ";
    }
    cout<<endl;
    cout<<"after sorting: "<<endl;
    Count_sort(arr);
    for(int i =0 ; i<arr.size();i++){
        cout<<arr[i]<< " ";
    }
    


}