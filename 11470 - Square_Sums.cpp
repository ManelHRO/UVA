#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n,soma,i,j,saida=0;
	cin>>n;
	while(n){
		int mt[n][n];
		bool vis[n+10][n+10];
		memset(vis,false,sizeof vis);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>mt[i][j];
			}
		}
		cout<<"Case "<<++saida<<":";
		for(int k=0;k<=n/2 and !vis[k][k];k++){
			soma=0;
			for(j=k;j<n-k and !vis[k][j];j++){
				vis[k][j]=true;
				soma+=mt[k][j];
			}
			for(i=k+1;i+1<n-k and !vis[i][j-1];i++){
				soma+=mt[i][j-1];
				vis[i][j-1]=true;
			}
			for(j=j-1;j>=k and i>=0 and i<n and !vis[i][j];j--){

				soma+=mt[i][j];
				vis[i][j]=true;
			}
			for(i=i-1,j+=1;i>k and !vis[i][j];i--){
				soma+=mt[i][j];
				vis[i][j]=true;
			}
			cout<<" "<<soma;
			vis[k][k]=true;
		}
		cout<<endl;
		cin>>n;
	}
}
