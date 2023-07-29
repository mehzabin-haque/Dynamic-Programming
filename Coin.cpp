#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

const int N = 100, val= 1e5;
int dp[N] = {0};

int main(){
	
	int n, a[N], total;
    cout << "Number of coins : " << endl;
    cin >> n;
    
    cout << "Enter the value of the coins : " << endl;
    
    for(int i=0; i<n; i++){
    	cin >> a[i] ;
	}
	
	cout << "Enter the total value : " << endl;
	cin >> total;
	
	for(int j=0; j<=total; j++){
		dp[j] = val;
	}
	
	dp[0] = 0;
	
	for(int i=1; i<=total; i++){
		for(int j=0; j<n; j++){
			if(a[j] <= i){
				dp[i] = min(dp[i], 1+ dp[i - a[j]]);
			}
		}
	}
	
	cout << "Minimum number of coins : " << dp[total];
	
}
