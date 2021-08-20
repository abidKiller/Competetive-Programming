#include<bits/stdc++.h>

using namespace std;
using pii=pair<int,int> ;
vector<int> dijkstra(vector<vector<pair<int ,int> > >& adj,int start){
    int n=adj.size();
    vector<int> p(n+1);
    vector<int> dis(n+1,INT_MAX);
    vector<int > d_min(n+1,INT_MAX); 
    d_min[start]=0;
    dis[start]=0;
    priority_queue<pii,vector<pii>,greater<pii> >  pq;
    pq.push({0,start});
    while(pq.empty()==false){
		int d_=pq.top().first;
        int u=pq.top().second;
        //cout<<d_<<" "<<u<<endl;
        pq.pop();
        
        
        for(auto edge:adj[u]){
           	int v=edge.first;
            int w=edge.second;
            if(d_min[v]>max(d_,w)){
             d_min[v]=min(max(w,d_),d_min[v]);
             pq.push({d_min[v],v});
    
            }
           // cout<<v<<" "<<w<<endl;
         
    		
        }
         
    }
    
    return d_min ;
}
int prev_u=0,prev_v=0,prev_w=0;
void addEdge(vector<vector<pair<int ,int > > >& adj,int u,int v,int w){
        bool milse=false;
    	for(int i=0;i<adj[u].size();i++){
            
			if(adj[u][i].first==v){
                milse=true;
               if(adj[u][i].second>w){
                	adj[u][i].second=w;
            	}
            }
        }
    	for(int i=0;i<adj[v].size();i++){
			if(adj[v][i].first==u && adj[v][i].second>w){
                adj[v][i].second=w;
            }
        }
    	if(!milse){
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
         
         
}
int main(){
    
    /*
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    */
    int t;
    cin>>t;
    int l=t;
    
    while(t--){
        int n,m,mycity;
        cin>>n>>m;

        vector<vector<pair<int ,int > > > adj(n+1);
       
		while(m--){
            
            int u,v,w;
            cin>>u>>v>>w;
            
            addEdge(adj,u,v,w);
            
        }     
		cin>>mycity;
        /*
        for(int i=0;i<adj.size();i++)
        for(int j=0;j<adj[i].size();j++)
     		cout<<i<<" "<<adj[i][j].first<<" "<<adj[i][j].second<<endl;               */
      
            
     vector<int > ans = dijkstra(adj,mycity);
     cout<<"Case "<<l-t<<":"<<endl;
     for(int i=0;i<n;i++){
         if(ans[i]==INT_MAX)
         	cout<<"Impossible"<<endl;
         else 
             cout<<ans[i]<<endl;
     }
        
        adj.clear();
    }
}