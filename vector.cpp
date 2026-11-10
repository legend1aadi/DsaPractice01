#include<iostream>
#include<vector>
using namespace std;

int main(){
    cout<<"hello"<<endl;
    vector<int> v1={1,2,30};
    cout<<v1[2]<<endl;
//vector functions 
//1. for each iterator in vectors 

    for(int i: v1){
        cout<<i<<" ";//here the i is the actual value not the index 
    }
    //size of the vector
    cout<<endl; 
    cout<<"sixe of the vector is : "<<v1.size()<<endl;
    //push back function 
    v1.push_back(56);
    v1.push_back(23);
    cout<<"new vector is : ";
    for(int i: v1){
        cout<<i<<" ";//here the i is the actual value not the index 
    }
    cout<<endl;
    //pop back:delete the last element in the vector 

    v1.pop_back();
   
    cout<<"new vector is : ";
    for(int i: v1){
        cout<<i<<" ";//here the i is the actual value not the index 
    }
    cout<<endl;
    //front : prints the value at front 

    cout<<"value in the front of the vector : "<<v1.front()<<endl;
    //back :similarly prints the value at the back
    cout<<"value in the back of the vector : "<<v1.back()<<endl;
    //at:gives the value at(index)
    cout<<"value at the index 3 of the vector is  : "<<v1.at(3)<<endl;
}
