#include <bits/stdc++.h>
using namespace std;
int cont;
map<int,vector<int>> mp;

void bfs(int v, int r){
	queue <int> q;
	q.push(v);
	while(r--){
		int aux=q.front();
		q.pop();
		
		for(int k=0;k<mp[aux].size();k++){
			cont++;
			q.push(mp[aux][k]);
		}
			 
	}
}
int main(){
	
	int n,a,b;
	
	while(cin>>n and n){
		
		for(int i=0;i<n;i++){
			cin>>a>>b;
			mp[a].push_back(b);
		}
		
		while(cin>>a>>b and a and b){
			cont=0;
			bfs(a,b);
			cout<<cont<<endl;
		}
	}
}
