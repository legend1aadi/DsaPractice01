#include <iostream>
#include <vector>
using namespace std;

void Count_sort (vector <int>& A, vector <int>& B, int k){
    vector <int> C(k+1, 0);             //intialize count array with 0;
    

    //counting no of occurence of elements
    for (int j=0; j<A.size(); j++){
        C[A[j]] +=1;
    } 

    for (int i=1; i<k+1; i++){
        C[i]+= C[i-1];
    }

    for (int j=A.size()-1; j>=0; j--){
        B[C[A[j]]-1]=A[j];
        C[A[j]]--;
    }
}

int main(){
    int n;
    cout<< "enter the no of elements of array : ";
    cin>> n;
    vector <int> A(n), B(n);
    cout<< "enter elements of the array: ";
    for (int i=0; i<n; i++){
        cin>> A[i];
    }
    int maximum = A[0];
    for (int i=0; i<n; i++){
        if (A[i]>maximum){
            maximum=A[i];
        }
    }
    Count_sort(A,B, maximum);
    cout<< "Sorted array: "<< "[";
    for (int i=0; i<n; i++){
        cout<<B[i] << ",";
    }
    cout << "]";
    return 0;
}