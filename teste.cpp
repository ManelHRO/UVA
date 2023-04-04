#include <bits/stdc++.h>
using namespace std;
bool vis[105][105];
char mt[105][105];
int dx[] = {1, 0, -1, 0, -1, 1, -1, 1},dy[] = {0, 1, 0, -1, 1, 1, -1, -1},x,y,cont=0;

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
    string frase,frase1,frase2;
    vector<pair<int,int> > vc;
    stringstream ss;
    freopen("12","w",stdout);
	cin>>c;
    cin.ignore();
    getline(cin,frase);
    
	while(c--){
        k=0;
        while(getline(cin,frase)&&frase.size()>0){
            if(frase[0]>57){
                for(l=0;l<frase.size();l++){
                    mt[k][l]=frase[l];
                }
                k++;
            }
            else{
				ss<<frase;
				cout<<frase<<endl;
				cout<<'f'<<frase2<<" "<<frase1<<endl;
				ss>>frase2>>frase1;
                a=stoi(frase2);
                b=stoi(frase1);
                vc.push_back({a,b});
            }
		}
		/*for(int i=0;i<(int)vc.size();i++){
			cout<<vc[i].first<<" "<<vc[i].second<<endl;
		}*/
        /*for(int i=0;i<(int)vc.size();i++){
			if(!vis[vc[i].first][vc[i].second]) florida(l,k,vc[i].first,vc[i].second),cout<<cont<<endl;
			cont=0;
		}
		vc.clear();
		memset(vis,false,sizeof(vis));
		
		getline(cin,frase);*/
		
		
	}
}
