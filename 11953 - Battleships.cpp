#include <bits/stdc++.h>
using namespace std;
bool vis[105][105];
char mt[105][105];
int dx[] = {-1,0,1,0,-1,-1,1,1},dy[] = {0,1,0,-1,1,-1,-1,1},x,y,cont;
    

void batle(int n,int i,int j){
    vis[i][j]=true;

    for(int k=0;k<4;k++){
        x=dx[k]+i;
        y=dy[k]+j;
        if(x >=0 && x < n && y >=0 && y < n && !vis[x][y] && (mt[x][y]=='x' or mt[x][y]=='@')) batle(n,x,y);
    }
}

int main(){

    int c,k=0,n;
    
	cin>>c;
    
	while(c--){
        cin>>n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mt[i][j];
        cont=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mt[i][j]=='x' and !vis[i][j])cont++, batle(n,i,j);
            }
        }
        cout<<"Case "<<++k<<": "<<cont<<endl;
        memset(vis,false,sizeof(vis));
	}
}
