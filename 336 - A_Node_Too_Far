#include <bits/stdc++.h>

using namespace std;

unordered_map<long long int,vector<long long int>> mp;
unordered_map<int,int>dist;

int range;

void bfs(int v, int r){
	queue <int> q;
	q.push(v);
	dist[v]+=1;
	while(!q.empty()){
		int aux=q.front();
		q.pop();
		for(int k=0;k<(int)mp[aux].size();k++){
			if(dist[mp[aux][k]]==-1){
				
				q.push(mp[aux][k]);
				dist[mp[aux][k]]=dist[aux]+1;
				
				if(dist[mp[aux][k]] <= r) range++;
			}
		}
	}
}

signed main(){
	
	int n,a,b,saida=0;
	
	cin>>n;
	while(n){
		
		set<int>nodes;
		
		for(int i=0;i<n;i++){
			cin>>a>>b;
			nodes.insert(a);
			nodes.insert(b);
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
	
		cin>>a>>b;
		while(a||b){
			for(auto k: nodes){
				dist[k] = -1;
			}
			range=1;
			bfs(a,b);
			cout<<"Case "<<++saida<<": "<<(nodes.count(a) ? (int)nodes.size()-range : (int)nodes.size())<<" nodes not reachable from node "<<a<<" with TTL = "<<b<<'.'<<endl;
			cin>>a>>b;
		}
		mp.clear();
		nodes.clear();
		
		cin>>n;
	}
}
