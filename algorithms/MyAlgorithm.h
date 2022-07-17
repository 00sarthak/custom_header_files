#ifndef MYALGORITHM_H
#define MYALGORITHM_H

#include <vector>
#include <climits>
#include <iostream>

using namespace std;

//----------------dijkstra's Algorithm---------------------------------------

int dijkstra(vector<vector<int>> &graph, int n, int src, int dst){
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    vector<bool> visited(n, false);
    for(int i = 0; i < n-1; i++){
        int min_dist = INT_MAX;
        int min_idx = -1;
        for(int j = 0; j < n; j++){
            if(!visited[j] && ( min_idx==-1 || dist[j] < min_dist) ){
                min_dist = dist[j];
                min_idx = j;
            }
        }
        visited[min_idx] = true;
        for(int j = 0; j < n; j++){
            if(!visited[j] && graph[min_idx][j] != 0 && dist[min_idx] + graph[min_idx][j] < dist[j]){
                dist[j] = dist[min_idx] + graph[min_idx][j];
            }
        }
    }
    return dist[dst];
}
//----------------------------------------------------------------------------


//-----------------Bellman-Ford algorithm-------------------------------------

int BellmanFord(vector<vector<int>> &graph, int n, int src, int dst){
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(graph[j][k] != 0 && dist[j] + graph[j][k] < dist[k]){
                    dist[k] = dist[j] + graph[j][k];
                }
            }
        }
    }
    return dist[dst];

}
//---------------------------------------------------------------------------


//-----------------Kadane's algorithm----------------------------------------

int kadane(vector<int> &arr){
    int max_sum = INT_MIN;
    int cur_sum = 0;
    for(int i = 0; i < arr.size(); i++){
        cur_sum += arr[i];
        if(cur_sum < 0){
            cur_sum = 0;
        }
        if(cur_sum > max_sum){
            max_sum = cur_sum;
        }
    }
    return max_sum;
}
//---------------------------------------------------------------------------


//-----------------Cycle detection in undirected graphs------------------------
bool cycle_undirected(vector<vector<int>> &graph, int n);
bool cycle_undirected_dfs(vector<vector<int>> &graph, int s, bool visited[],int parent);

bool cycle_undirected(vector<vector<int>> &graph, int n){
    bool visited[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            if(cycle_undirected_dfs(graph, i, visited, -1)) return true;
        }
    }
    return false;
}

bool cycle_undirected_dfs(vector<vector<int>> &graph, int s, bool visited[],int parent){
    visited[s]=true;
    for(int i=0;i<graph[s].size();i++){
        if(!visited[graph[s][i]]){
            if(cycle_undirected_dfs(graph, graph[s][i], visited, s)) return true;
        }
        else if(graph[s][i]!=parent){
            return true;
        }
    }
    return false;
}

//---------------------------------------------------------------------------


//-----------------Cycle detection in directed graphs----------------------

bool cycle_directed(vector<vector<int>> &graph, int n);
bool cycle_directed_dfs(vector<vector<int>> &graph, int s, bool visited[],bool recst[]);

bool cycle_directed(vector<vector<int>> &graph, int n){
    bool visited[n];
    bool recst[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
        recst[i]=false;
    }
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            if(cycle_directed_dfs(graph,i,visited,recst)) return true;
        }
    }
    return false;
}

bool cycle_directed_dfs(vector<vector<int>> &graph, int s, bool visited[],bool recst[]){
    visited[s]=true;
    recst[s]=true;

    for(auto i= graph[s].begin(); i!= graph[s].end(); i++){
        if( visited[ *i]== false && cycle_directed_dfs(graph, *i, visited, recst)){
            return true;
        }else if(recst[*i]) return true;
    }
    recst[s]=false;
    return false;
}
//---------------------------------------------------------------------------


#endif
