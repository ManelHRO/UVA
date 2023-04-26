#include <bits/stdc++.h>
using namespace std;
bool vis[105][105];
char mt[105][105];
int dx[] = {-1,0,1,0,-1,-1,1,1},
    dy[] = {0,1,0,-1,1,-1,-1,1},
    x,y,cont;
    

void cell(int sizei,int sizej,int i,int j){
	cont++;
    vis[i][j] = true;
    
    for(int k=0; k<8; k++){
		x = dx[k] + i;
		y = dy[k] + j;
		
        if(x >=0 && x < sizei && y >=0 && y < sizej && !vis[x][y] && mt[x][y]=='1') cell(sizei,sizej,x,y);
    }
}

int main(){
	
	int l,k,c,aux;
    string frase;
    
	cin>>c;
    cin.ignore();
    getline(cin,frase);
    
	while(c--){
        k=0;
        
        while(getline(cin,frase)&&frase.size()>0){
			for(l=0;l<(int)frase.size();l++){
                mt[k][l]=frase[l];
            }  
            k++;
        }
        aux=0;
        for(int i=0;i<k;i++){
            for(int j=0;j<l;j++){
                cont=0;
                if(mt[i][j]=='1' and !vis[i][j]){
                    cell(k,l,i,j);
                    if(cont>aux) aux=cont;
                }
            }
        }
        cout<<aux<<endl;
        memset(vis,false,sizeof(vis));
		if(c) cout << "\n";
	}
}
