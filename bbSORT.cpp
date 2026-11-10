#include <iostream>
#include<vector>
using namespace std;

void swap(int &a,int &b){
    int temp= a;
    a=b;
    b=temp;
}
int main(){
    vector<int> arr={0,3,4,6,10};
    int n=arr.size();
    bool isSwap= false;
    int iter=0;
    //for displaying purpose
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    //main algorithm start here
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                isSwap=true;
            }
            iter++;
        }
        if(isSwap==false){
            break ;
        }
    }
    cout<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

    cout<<"number of iterations are:- "<<iter<<endl;
    
    

}