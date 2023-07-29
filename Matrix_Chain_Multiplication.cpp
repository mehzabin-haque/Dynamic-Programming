#include<bits/stdc++.h>
using namespace std;

const int N = 100 , val = 1e5;
int a[N];
int dp[N][N],pri[N][N]={};

void print_MCM(int pri[][100], int i, int j){
	
    if(i == j){
    	cout << " A" << i;
	}
    else{
    	
        cout << "(";
        print_MCM(pri, i, pri[i][j]);
        print_MCM(pri, pri[i][j]+1, j);
        cout << ")";
    }
}

int MCM_Memorized(int i, int j){
	if(i==j){
		return 0;
	}
	
	if(dp[i][j] != -1){
		return dp[i][j];
	}
	
	dp[i][j] = val;
	
	for(int m=i; m<j ; m++){
		
		int p = MCM_Memorized(i, m) + MCM_Memorized(m+1, j) + a[i-1]*a[m]*a[j];
		if(p < dp[i][j]){
			pri[i][j] = m;
		}
		
		dp[i][j] = min(dp[i][j],p);
		
	}
	
	return dp[i][j];
}

int main(){
	int n;
	cout << "Enter the size of the array : " << endl;
	cin >> n;
	
	cout << "Enter the array : " << endl ;
	
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	
	memset(dp,-1,sizeof dp);
	 
	cout << "Minimum num of the MCM is : " << MCM_Memorized(1,n-1) << endl;
	cout << "Matrix num : " ;
	print_MCM(pri, 1, n-1);
	
	return 0;
}
