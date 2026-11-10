#include <iostream>
using namespace std;
/*
void BFS(int adj[20][20], int n, int s) {
    int queue[20]={0};
    int vis[20]={0};
    int f=-1,r=-1;

    vis[s]=1;
    queue[r++]=s;
    

    while(f<r){
        int u=queue[++f];
        for(int v=0;v<n;v++){
            if(adj[u][v]==1 && vis[v]==0){
                vis[v]=1;
                queue[r++]=v;
            }
        }
    }
}
*/


void BFS(int arr[20][20],int n , int s){
    int queue[20]={0};
    int vis[20]={0};
    int f=-1,r=-1;

    vis[s]=1;
    queue[++r]=s;

    while(f<r){
        int u=queue[++f];
        cout<<u<<" ";

        for(int v=0;v<n;v++){
            
            if(arr[u][v]==1  && vis[v]==0){
                vis[v]=1;
                queue[++r]=v;

            }
        }

    }
} 





int main() {
    int n, e, s;//n= no. of vertices ,e= no. of edges  , s= source node
    
    cout << "Total vertices (n) and edges (e) : ";
    if (!(cin >> n >> e)) return 0;

    int adj[20][20] = {0};

    cout << " Enter no. of Edges  (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; 
    }

    cout << "Enter Starting vertex (s) : ";
    cin >> s;

    BFS(adj, n, s);

    return 0;
}