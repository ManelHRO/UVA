#include <bits/stdc++.h>
using namespace std;
bool vis[105][105];
char mt[105][105];
int dx[] = {-1,0,1,0,-1,-1,1,1},dy[] = {0,1,0,-1,1,-1,-1,1},x,y,cont;
    
void star(int m,int n,int i,int j){
    cont++;
    vis[i][j] = true;
    
    for(int k=0; k<8; k++){
		x = dx[k] + i;
		y = dy[k] + j;
		
        if(x >=0 && x < m && y >=0 && y < n && !vis[x][y] && mt[x][y]=='*') cont++,star(m,n,x,y);
    }
}
int main(){

    int m,n,soma;
    while(cin>>m>>n and m and n){

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                cin>>mt[i][j];
        soma=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] and mt[i][j]=='*'){
                    cont=0;
                    star(m,n,i,j);
                    if(cont==1) soma++;
                }
            }
        }
        cout<<soma<<endl;
        memset(vis,false,sizeof(vis));
    }
}
