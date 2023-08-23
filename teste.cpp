#include <bits/stdc++.h>
using namespace std;
int mov[9][9];
bool vis[9][9];

void bfs(int r1,int c1){
	
}

int main(){
	
	while(cin>>r1>>c1>>r2>>c2>>r3>>c3){
		
		vis[r3][c3]=true; //bloqueando a coordenada que o rei não pode pisar
		bfs(r1,c1);
	}
}
