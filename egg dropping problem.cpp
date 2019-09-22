#include<bits/stdc++.h>
using namespace std;
int main(){
	int egg,stairs;
	cin>>egg>>stairs;
	
	int dp[egg+1][stairs+1];
	
	for(int i=0;i<=egg;i++){			//base case 1 when no stairs
		dp[i][0]=0;
	}
	for(int i=0;i<=stairs;i++){			//base case 2  when no eggs
		dp[0][i]=0;
	}
	
	for(int i=1;i<=stairs;i++){			//base case 3   for 1 egg total attempts=total stairs
		dp[1][i]=i;
	}
	
	for(int i=2;i<=egg;i++){
		for(int j=1;j<=stairs;j++){
			int minn=INT_MAX;
			for(int k=1;k<=j;k++){
				minn=min(minn,max(dp[i-1][k-1],dp[i][j-k]));
			}
			dp[i][j]=minn+1;
		}
	}
	
/*	for(int i=0;i<=egg;i++){
		for(int j=0;j<=stairs;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	
	cout<<dp[egg][stairs]<<endl;
	
	
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~**************PEACE OUT******************~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
