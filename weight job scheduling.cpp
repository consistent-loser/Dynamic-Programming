// weighted job scheduling using dynamic programming




#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	pair<int,int>a[n];   // first for the ending time and second for the starting time 
	map<pair<int,int>,int>m;    //map for storinfg the weights
	for(int i=0;i<n;i++){
		pair<int,int>p;
		cin>>p.second>>p.first;
		a[i]=p;
	}
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		m[a[i]]=temp;
	}
	
	sort(a,a+n);        // sort the jobs wrt increasing ending time
	
	int dp[n];
	
	for(int i=0;i<n;i++){
		dp[i]=m[a[i]];            //initially max job performed =1
	}
	int tot_max=INT_MIN;
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i].second>=a[j].first){          // if job i and job j doesnt overlap
				dp[i]=max(dp[i],m[a[i]]+dp[j]);	//do somethiing
				tot_max=max(dp[i],tot_max);
			}
		
		}
	}
	/*	for(int i=0;i<n;i++){
		cout<<dp[i]<<" ";
	}*/
	cout<<tot_max<<endl;
	return 0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~****************PEACE OUT***********************~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
