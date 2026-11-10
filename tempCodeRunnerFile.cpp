#include<iostream>
#include<vector>
using namespace std;

int main(){
    cout<<"hello"<<endl;
    vector<int> v1={1,2,30};
    cout<<v1[2];
//vector functions 
//1. for each iterator in vectors 

    for(int i: v1){
        cout<<i<<" ";//here the i is the actual value not the index 
    }

}
