#include<bits/stdc++.h>
using namespace std;

#define MAXNODES 150010
#define D(x) cout<< #x " = "<<(x)<<endl

struct edge{
    int to,w;
    edge(){}
    edge(int T, int W): to(T), w(W){}
};

vector<edge> g[MAXNODES];
int T[MAXNODES];
int P[MAXNODES];
int L[MAXNODES];
long long dist_to_root[MAXNODES];
int n, nr;

void fill_l(){
    L[0] = 0;
    dist_to_root[0] = 0LL;

    vector<int> visited(n,0);
    queue<int> Q;
    Q.push(0);
    while(!Q.empty()){
        int act = Q.front();Q.pop();
        visited[act] = true;
        for(int i = 0; i< g[act].size(); ++i){
            if(visited[g[act][i].to])continue;
            T[g[act][i].to] = act;
            L[g[act][i].to] = L[act] + 1;
            dist_to_root[g[act][i].to] = dist_to_root[act] + g[act][i].w;
            Q.push(g[act][i].to);
        }
    }
}


void bfs(){

    vector<int> visited(n,0);
    queue<int> Q;
    Q.push(0);
    while(!Q.empty()){
        int node =  Q.front();Q.pop();
        if(visited[node])continue;
        visited[node] = true;

        if (L[node] < nr)
            P[node] = 1;
        else
            if(!(L[node] % nr))
                P[node] = T[node];
            else
                P[node] = P[T[node]];

        for(int i = 0; i< g[node].size(); ++i)
            Q.push(g[node][i].to);
    }
}

int LCA(int x, int y){

    while (P[x] != P[y])
      if (L[x] > L[y])
         x = P[x];
      else
         y = P[y];
    while (x != y)
      if (L[x] > L[y])
         x = T[x];
      else
         y = T[y];

    return x;
}


int main(){

    cin>>n;
    memset(T,-1,sizeof T);
    nr = sqrt(n);
    for(int i = 0; i< n; ++i)
        g[i].clear();

    int u,v,w;
    for(int i = 0; i< n-1; ++i){
        cin>>u>>v>>w;
        g[v].push_back(edge(u,w));
        g[u].push_back(edge(v,w));
    }

    fill_l();
    bfs();
    int queries;cin>>queries;

    for(int i = 0; i< queries; ++i){
        cin>>u>>v;
        cout<<(dist_to_root[u] + dist_to_root[v] - 2LL*dist_to_root[LCA(u,v)])<<endl;
    }


    return 0;
}
