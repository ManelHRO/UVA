#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj[105];
int cont;

bool djistra(int start,int finish,int time){
	priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> q;
	vector<int> dist(105,INT_MAX);
	vector<int> tt(105,0);
	q.push({0,start});
	dist[start]=0;
	
	while(!q.empty()){
		int custo=q.top().first;
		int no=q.top().second;
		q.pop();
		
		if(custo>dist[no]) continue;
		
		for(auto x: adj[no]){
			if(custo+x.second<dist[x.first] and custo+x.second<=time){
				//cout<<"TIME: "<<custo+x.second<<endl;
				dist[x.first]=custo+x.second;
				q.push({dist[x.first],x.first});
				if(x.first==finish){
					cont++;
					return true;
				}
			}
		}
	}
	return false;
}

int main(){
	
	int t,n,sd,tm,qt,a,b,c;
	bool flag=false;
	
	cin>>t;
	while(t--){
		if(flag)cout<<endl;
		cin>>n>>sd>>tm>>qt;
		while(qt--){
			cin>>a>>b>>c;
			adj[a].push_back({b,c});
		}
		cont=1;
		for(int i=1;i<=n;i++){
			if(i!=sd) djistra(i,sd,tm);
		}
		cout<<cont<<endl;
		flag=true;
		for(int i = 0; i <= n; i++)adj[i].clear();
	}
}
