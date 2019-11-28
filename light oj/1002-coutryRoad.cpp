/*2
5 6
0 1 5
0 1 4
2 1 3
3 0 7
3 4 6
3 1 8

2
9 14
 0 1 4
 0 7 8
  1 2 8
 1 7 11
 2 3 7
 2 8 2
 2 5 4
 3 4 9
 3 5 14
 4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
*/
#include<bits/stdc++.h>
#define ll long long
#define fastIo ios_base::sync_with_stdio(0); cin.tie(0)

using namespace std;
#define max 10001
int dis[max];

void dijkstra(vector<pair<int,int> > g[],int s,int n)
{
   for(int i=0;i<=n;i++)dis[i]=INT_MAX;
	bool vis[n+1];
	for(int i=0;i<=n;i++) vis[i]=false;
	priority_queue<pair<int ,int> > disno;
	disno.push(make_pair(0,s)); // w,u
	dis[s]=0;
//	vis[s]=true;

	while(!disno.empty())
	{
	    pair<int,int> i=disno.top();

        // vis[i.second]=true;
        disno.pop();
	   if(dis[i.second]<i.first) continue;
            for(auto it : g[i.second])
        {
          //  if(vis[it.first]) continue;
               if(i.first+it.second<dis[it.first])
               {
                   dis[it.first]=i.first+it.second;
                   disno.push(make_pair(dis[it.first],it.first));

               }
        }


	}


}
int main()
{
	fastIo;

	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int nodes,edges,weight;
		int u,v,w;
		cin>>nodes>>edges;
		vector<pair<int,int> > g[nodes+1];
		while(edges--)
		{
			cin>>u>>v>>w;
			g[u].push_back(make_pair(v,w));
			g[v].push_back(make_pair(u,w));


		}
	/*	for(int i=0;i<nodes;i++)
        {
            for(auto it:g[i])
                cout<<"i :"<<i<<" "<<it.first<<" "<<it.second<<endl;
            cout<<" "<<endl;
        } */
        for(int i=0;i<n;i++)
        {
            for(auto it:x[i])
                cout<<"node "<<i<<" "<<it.first<<" "<<it.second<<endl;
        }

		int s;
		cin>>s;
		dijkstra(g,s,nodes+1);
		cout<<"case "<<i<<endl;
		for(int j=0;j<nodes;j++)
			if(dis[j]<INT_MAX)
             cout<<dis[j]<<endl;
         	else
                cout<<"Impossible"<<endl;;


	}
}
