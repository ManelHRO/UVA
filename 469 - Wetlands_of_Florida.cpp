#include <bits/stdc++.h>
using namespace std;
bool vis[105][105];
char mt[105][105];
int dx[] = {-1,0,1,0,-1,-1,1,1},
    dy[] = {0,1,0,-1,1,-1,-1,1},
    x,y,cont;
    

void florida(int sizei,int sizej,int i,int j){
	cont++;
    vis[i][j] = true;
    
    for(int k=0; k<8; k++){
		x = dx[k] + i;
		y = dy[k] + j;
		
        if(x >=0 && x < sizei && y >=0 && y < sizej && !vis[x][y] && mt[x][y]=='W') florida(sizei,sizej,x,y);
    }
}

int main(){
	
	int l,k,c,a,b;
    string frase;
    vector<pair<int,int> > vc;
    freopen("in","r",stdin);
    freopen("12.txt","w",stdout);
   
	cin>>c;
    cin.ignore();
    getline(cin,frase);
    
	while(c--){
        k=0;
        while(getline(cin,frase)&&frase.size()>0){
            if(frase[0]>57){
                for(l=0;l<(int)frase.size();l++){
                    mt[k][l]=frase[l];
                }  
                k++;
            }
            else{
                stringstream ss;
                ss<<frase;
				ss>>frase;
				a=stoi(frase)-1;
				ss>>frase;
				b=stoi(frase)-1;
				vc.push_back({a,b});
            }
		}
		
        for(int i=0;i<(int)vc.size();i++){
			memset(vis,false,sizeof(vis));
            cont=0;
			florida(k,l,vc[i].first,vc[i].second);
			cout<<cont<<endl;
		}
		if(c) cout << "\n";
		vc.clear();
	}
}
