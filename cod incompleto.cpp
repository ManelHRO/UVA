#include <bits/stdc++.h>
using namespace std;

queue<pair<int,int>> fire;
char dist[1005][1005];
int profund[1005][1005];
int dx[] = {-1,0,1,0},dy[] = {0,1,0,-1};

void ff(int m,int n){
    
    while(!fire.empty()){
        int ax=fire.front().first;
        int ay=fire.front().second;
        fire.pop();
        
        for(int k=0;k<4;k++){
            int x= dx[k]+ax;
            int y= dy[k]+ay;
            if(x>=0 and x<m and y>=0 and y<n and dist[x][y]=='.') dist[x][y]='F';
        }

    }
}

void bfs(int p1,int p2,int m,int n){

    queue<pair<int,int>> q;
    q.push({p1,p2});
    profund[p1][p2]=0;

    while(!q.empty()){

        int ax=q.front().first;
        int ay=q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int x=dx[k]+ax;
            int y=dy[k]+ay;

            if(x>=0 and x<m and y>=0 and y<n and profund[x][y]==-1 and dist[x][y]=='.'){
                profund[x][y]=profund[ax][ay]+1;
                q.push({x,y});
            }
        }
    }
}

int main(){
    
    int t,m,n,p1,p2;

    cin>>t;
    while(t--){

        cin>>m>>n;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>dist[i][j];
                if(dist[i][j]=='F') fire.push({i,j});
                else if(dist[i][j]=='J') p1=i,p2=j;
            }
        }
        ff(m,n);
        memset(profund,-1,sizeof(profund));
        bfs(p1,p2,m,n);

    }
}
