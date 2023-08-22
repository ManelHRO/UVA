#include <bits/stdc++.h>
#define pb push_back
using namespace std;
map<string,vector<string>> dist;
map<string,string> pai;
map<string,bool> vis;

void bfs(string c){
	queue<string> q;
	q.push(c);
	pai[c]=" "; 
	vis[c]=true;
	
	while(!q.empty()){
		string aux=q.front();q.pop();
	
		for(auto it : dist[aux]){
			if(!vis[it]){
				pai[it]=aux;
				vis[it]=true;
				q.push(it);
			}
		}
	}
}
void imp(string c2){
	if(pai[c2]==" ") return;
	imp(pai[c2]);
	cout<<pai[c2][0];
}
	

int main(){
	
	int t,m,n;
	string c1,c2;
	bool flag=false;
	
	cin>>t;
	getline(cin.ignore(),c1);
	
	while(t--){
		if(flag) cout<<endl;
		cin>>m>>n;
		for(int i=0;i<m;i++){
			cin>>c1>>c2;
			dist[c1].pb(c2);
			dist[c2].pb(c1);
		}
		for(int i=0;i<n;i++){
			cin>>c1>>c2;
			bfs(c1);
			imp(c2);
			cout<<c2[0]<<endl;
			vis.clear();
		    pai.clear();
		}
		dist.clear();
		flag=true;
	} 
}
