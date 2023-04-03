#include <bits/stdc++.h>
using namespace std;
char mt[1000][1000];
bool vis[1000][1000];
int dx[] = {-1,0,1,0},dy[] = {0,1,0,-1},x,y;

void leng(int m,int n,int i,int j,char aux){
    vis[i][j]=true;

    for(int k=0;k<4;k++){
        x=dx[k]+i;
        y=dy[k]+j;
        if(x>=0 && x<m && y>=0 && y<n &&mt[x][y]==aux && !vis[x][y]) leng(m,n,x,y,aux);
    }
}

int main(){

    int m,n,c,p=0;
    char aux;
    cin>>c;
    while(c--){
		map<char,int> mp;
		vector<pair<char,int> > vc;
    
        cin>>m>>n;

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++) cin>>mt[i][j];


        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(!vis[i][j]){
                    aux=mt[i][j];
                    mp[aux]++;
                    leng(m,n,i,j,aux);
                }
        

        for(auto it : mp){
            vc.push_back({it.first,it.second});
        }
        sort(vc.begin(),vc.end(),[](auto g, auto f){
            if(g.second != f.second) return g.second>f.second;
            return g.first<f.first;
        });
        
		p++;
        cout<<"World #"<<p<<endl;
        for(int it=0;it<(int)vc.size();it++){
            cout<<vc[it].first<<": "<<vc[it].second<<endl;
        }
        
        memset(vis,false,sizeof(vis));
    }
}
