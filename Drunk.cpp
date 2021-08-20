#include<bits/stdc++.h>
using namespace std;
bool drunk=true;
bool dfsrec(vector<vector<int> >& adj,vector<bool>& vis,vector<bool>& rec,int s){	
    vis[s]=true;
    rec[s]=true;
    
    for(int i=0;i<adj[s].size();i++){
		if(vis[adj[s][i]]==false &&dfsrec(adj,vis,rec,adj[s][i]) )
            return true;
        else if(rec[adj[s][i]]==true) return true;
    }
	rec[s]=false;
    return false;
}


bool dfs(vector<vector<int> >& adj){
    vector<bool> visited(adj.size()+1,false);
    vector<bool> recursion(adj.size()+1,false);
    for(int i=0;i<adj.size();i++)
        if(visited[i]!=true &&dfsrec(adj,recursion,visited,i))
        	return   true ;
        
    return false;
}
void addedge(vector<vector<int >>& adj,int u,int v){
    adj[u].push_back(v);
}
void solve(int l,int t){
    map<string, int> store;
    
    
    int m;
    cin>>m;
    vector<vector<int> > adj(2*m+1);
    int it=0;
    bool edge=false;
    for(int i=0;i<m;i++){
    	string u,v;
        
        cin>>u>>v;
        if (u==v) {
             edge=true;
        }
        if(store.find(u)==store.end())
            store[u]=it++;
        if(store.find(v)==store.end())
            store[v]=it++;
       
        addedge(adj,store[u],store[v]);
    }
    
    /*for(auto itr:store)
            cout<<itr.first<<" "<<itr.second<<endl;
    
    */
    string ans="NO";
    
    if(!dfs(adj)) ans="Yes";
    else ans ="No";
    if(edge) ans="No";
    cout<<"Case "<<l-t<<": "<<ans<<endl;
    store.clear();
    adj.clear();
   
}

int main(){
    int t;
     cin>>t;
    int l=t;
   
    
    while(t--){
		solve(l,t);
    }
	return 0;
    
}