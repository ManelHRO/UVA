#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10000];
int cont;

bool vis[10000];
void dfs(int u){
	cont++;
	vis[u]=true;
	for(auto v : adj[u]){
		if(!vis[v]){
			dfs(v);
		}
	}
	
}
int main(){
	
	int c,x,y,k,j,m,n;
	cin>>c;
	while(c--){
		
		cin>>x>>y>>k;
		for(int i=0;i<y;i++){
			cin>>m>>n;
			adj[m].push_back(n);
		}
		
		cont=0;
		for(int i=0;i<k;i++){
			cin>>j;
			if(!vis[j]) dfs(j);
		}
		cout<<cont<<endl;
		memset(vis,false,sizeof(vis));
		for(int i=0;i<=x;i++) adj[i].clear();
	}
}
