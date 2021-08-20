#include<bits/stdc++.h>
using namespace std;
int V;
long long travllingSalesmanProblem(vector<vector<long long> >& graph, int s=1)
{
    vector<long long> vertex;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);
 
   
    long long min_path = INT_MAX;
    do {
        long long  current_pathweight = 0;
        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
 
   
        min_path = min(min_path, current_pathweight);
 
    } while (
        next_permutation(vertex.begin(), vertex.end()));
 
    return min_path;
}
 
// Driver Code
int main()
{
    
    int n;
    cin>>n;
    V=n;
    vector<vector<long long > > graph(n+10,vector<long long >(n+10));
    vector<pair<long long ,long long > > store(n);
    for(int i=0;i<n;i++)
    {
        long long a,c;
        cin>>a>>c;
        store[i]=make_pair(a,c);
    }

   // for(int i=0;i<store.size();i++)
    //cout<< store[i].first<<" "<<store[i].second<<endl;
    for(int i=0;i<n;i++){
        graph[i][i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;i<n;j++){
            if(i==j) continue;
            graph[i][j]=max(store[i].second,store[j].first-store[i].first);
            cout<<graph[i][j]<<" ";
        }

    }
    cout<<""<<endl;
 
    int s = 1;
  //  cout << travllingSalesmanProblem(graph, s) << endl;
    return 0;
}

