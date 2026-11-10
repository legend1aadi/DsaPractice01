#include<iostream>
#include <vector>
using namespace std;

void dfsHelper(int u,vector<bool> &vis){
    cout<< U <<" ";
    vis[u]= true;

    for(int v : l[u]){
        if(!vis[v]){
            dfsHelper(v,vis);
        }
    }

}
void dfs(){
    int src=0;
    vector<bool> vis(V,false);
}
int main(){
    
}
