#include <bits/stdc++.h>
using namespace std;
int mt[1005][1005];
int dx[] = {-1,0,1,0},dy[] = {0,1,0,-1},x,y,m,n;

void bombs(int ic1,int ic2){
	queue<pair<int,int> > q;
	mt[ic1][ic2]=0;
	q.push({ic1,ic2}); //0
	while(!q.empty()){
		
		int ax = q.front().first;
		int ay = q.front().second;
		q.pop();
		
		for(int k=0;k<4;k++){
			x=dx[k]+ax;
			y=dy[k]+ay;
			if(x>=0 and x<m and y>=0 and y<n and mt[x][y]==-1){
				mt[x][y]=mt[ax][ay]+1;
				q.push({x,y});
			}
		}
	}
}
int main(){
	
	int c,linha,coluna,qtd,ic1,ic2,fi1,fi2;
	cin>>m>>n; 
	while(n || m){
		memset(mt,-1,sizeof(mt));
		
		cin>>c;
		while(c--){
			cin>>linha>>qtd;
			while(qtd--){
				cin>>coluna;
				mt[linha][coluna]=-2;
			}
		}
		cin>>ic1>>ic2>>fi1>>fi2;
		bombs(ic1,ic2);
		cout<<mt[fi1][fi2]<<endl;
		cin>>m>>n;
	}
}
