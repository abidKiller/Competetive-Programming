#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

struct Edge {
    int w = INF, to = -1;
    bool operator<(Edge const& other) const {
        return make_pair(w, to) < make_pair(other.w, other.to);  //this will help the set redblack tree to sort
    }
};

int n;
vector<vector<Edge>> adj;

void prim() {
    int total_weight = 0;
    vector<Edge> min_e(n);
    min_e[0].w = 0;
    set<Edge> q;           // keep next possible edges sorted by weight
    q.insert({0, 0});
    vector<bool> selected(n, false);
    for (int i = 0; i < n; ++i) {
        if (q.empty()) {
            cout << "No MST!" << endl;
            exit(0);
        }

        int v = q.begin()->to;
        selected[v] = true;
        total_weight += q.begin()->w;
        q.erase(q.begin());

        if (min_e[v].to != -1)
            cout << v << " " << min_e[v].to << endl;

        for (Edge e : adj[v]) {
            if (!selected[e.to] && e.w < min_e[e.to].w) {
                q.erase({min_e[e.to].w, e.to});
                min_e[e.to] = {e.w, v};
                q.insert({e.w, e.to});
            }
        }
    }
    cout<<total_weight<<endl;

}
int main()
{
  ifstream in("input.txt");
 
   int m;
  
   in>>n>>m; adj.resize(n+1);
   while(m--){
     int u,v,w;
     in>>u>>v>>w;
    
     adj[u].push_back((Edge){w,v});
     adj[v].push_back((Edge){w,u});
     

  }

 for(int i=0;i<n;i++){
   cout<<"vertex "<<i<<" :";
    for(Edge e: adj[i])
    {
      cout<<" "<<e.to;

    }
    cout<<endl;
 }
  prim();


}
