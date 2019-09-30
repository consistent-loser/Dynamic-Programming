#include<bits/stdc++.h>
using namespace std;

pair<pair<int,int>,int>kadane(int a[],int n){
	int maxx=0,current_start=0,max_start=-1,max_end=-1,max_so_far=0;
	
	for(int i=0;i<n;i++){
		max_so_far+=a[i];
		if(max_so_far<0){
			max_so_far=0;
			current_start=i+1;
		}
		
		if(maxx<max_so_far){
			maxx=max_so_far;
			max_start=current_start;
			max_end=i;
		}
	}
	pair<pair<int,int>,int>p=make_pair(make_pair(max_start,max_end),maxx);
	return p;
}
int main(){
	int row,col;
	cin>>row>>col;
	int a[row][col];
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cin>>a[i][j];
		}
	}

	int max_so_far=0;
	int max_top=-1,max_low=-1,max_right=-1,max_left=-1;
	int max_sum=0;
	for(int i=0;i<col;i++){
			int dp[row]={0};
		for(int j=i;j<col;j++){
			for(int k=0;k<row;k++){
				dp[k]+=a[k][j];
			}
			
			//time to call kadane for the rescue
			
			pair<pair<int,int>,int>p=kadane(dp,row);
			
			pair<int,int>tops=p.first;
			int max_so_far=p.second;
			//cout<<tops.first<<" "<<tops.second<<endl;
			//cout<<max_so_far<<endl;
			if(max_sum<max_so_far){
				max_sum=max_so_far;
				max_top=tops.first;
				max_low=tops.second;
				max_left=i;
				max_right=j;
				//do omething
			}
			
			
		}
	//	cout<<endl;
	}
	
	cout<<"sum= "<<max_sum<<endl;
	cout<<"left= "<<max_left<<endl;
	cout<<"right= "<<max_right<<endl;
	cout<<"top= "<<max_top<<endl;
	cout<<"low= "<<max_low<<endl;
}
