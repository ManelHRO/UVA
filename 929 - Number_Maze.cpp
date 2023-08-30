#include <bits/stdc++.h>
#define min_priority_queue priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>>>
using namespace std;
const int INF=1000000000;
vector<vector<int>> g;
int dx[] = {-1,0,1,0},dy[] = {0,1,0,-1};

int dj(int m,int n){
    min_priority_queue q;
    q.push({g[0][0],{0,0}}); //q.push({0,{0,0}}) and peso and posicao(i/j)
    vector<vector<int>> d(m, vector<int>(n, INF)); //todas as posiçoes começando em infinito
    d[0][0] = g[0][0];
    while(!q.empty()){
        int carg=q.top().first; //posicao da linha que eu to
        int ax=q.top().second.first; //posicao da coluna que eu to
        int ay=q.top().second.second; //valor da aresta que eu to
        q.pop();

        if(d[ax][ay]<carg) continue;

        for(int k=0;k<4;k++){
            int x=dx[k]+ax; //posicao(linha) que eu vou
            int y=dy[k]+ay; //posicao(coluna) que eu vou
           
            if(x>=0 and x<m and y>=0 and y<n and d[x][y]>carg+g[x][y]){
                d[x][y]=carg+g[x][y];
                q.push({d[x][y],{x,y}});
            }
        }
    }   
    return d[m-1][n-1];
}

int main(){

    int t,m,n;

    cin>>t;
    while(t--){
        cin>>m>>n;
        g.assign(m, vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j = 0; j < n; j++) {
				cin >> g[i][j];
			}
        }
        cout<<dj(m,n)<<endl;
    }
}
