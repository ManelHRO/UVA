#include <bits/stdc++.h>
using namespace std;

bool vis[8][8];
int profund[8][8];
int dx[] = {-1,0,1,0,-1,-1,1,1},dy[] = {0,1,0,-1,1,-1,-1,1},cont;
    
void bfs(int r1,int c1){
	queue<pair<int,int>> q;
	q.push({r1,c1});
	profund[r1][c1]=0;
	vis[r1][c1]=true;
	
	while(!q.empty()){
		int i=q.front().first;
		int j=q.front().second;
		q.pop();
		
		for(int k=0;k<8;k++){
			int x=dx[k]+i;
			int y=dy[k]+j;
			
			if(x>=0 and x<8 and y>=0 and y<8 and !vis[x][y]){
				profund[x][y]=profund[i][j]+1;
				vis[x][y]=true;
				q.push({x,y});
				cont++;
			}
		}
	}
}
int main(){
	
	int r1,c1,r2,c2,r3,c3,c=0;
	
	while(cin>>r1>>c1>>r2>>c2>>r3>>c3){
		
		vis[r3-1][c3-1]=true; 
		cont=0;
		bfs(r1-1,c1-1);
	    cout<<"Case "<<++c<<": "<<profund[r2-1][c2-1]<<endl;
	    
	    memset(vis,false,sizeof(vis));
	    memset(vis,0,sizeof(profund));
	}
}
