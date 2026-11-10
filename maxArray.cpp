#include <iostream>
using namespace std;

int maxArray(int arr[] ,int n){
    if(n==1){
        return arr[0];
    }

    int maxOfRemaining=maxArray(arr,n-1);
    return max(arr[n-1],maxOfRemaining);
}
int main(){
    int n;
    cout<<"enter size of array:";
    cin>>n;
    int * arr=new int[n];
    cout<<"enter the array";
    for(int i=0;i<n;i++){
        cout<<"enter at index "<<i<<" :";
        cin>>arr[i];
    }
    cout<<endl;
    cout<<"max element in the array is :";
    cout<<maxArray(arr,n)<<endl;
    return 0;
}