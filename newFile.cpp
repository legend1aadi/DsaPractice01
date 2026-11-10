#include <iostream>
using namespace std;

int main(){
    cout<<"helllo"<<endl;
    int *arr=new int[5];
    arr[2]=4;
    arr[3]=5;
    arr[4]=6;
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    arr=new int[10];
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}