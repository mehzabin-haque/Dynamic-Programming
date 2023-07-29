#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int dp[100];

void print_LIS(){
	
}

int main(){
	int n, a[100];
	cout << "Number of elements: " << endl ;
    cin >> n;
    
    cout << "Enter the elements : " << endl;
    
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    for(int i=0;i<n;i++){
    	dp[i] = 1;
	}
	
	int ans = 0;
	
	for(int i=1;i<n;i++){
		
		for(int j=0;j<i;j++){
			
			if(a[i] > a[j]){
				dp[i] = max(dp[i], 1+dp[j]);
			}
		}
		
		ans = max(ans,dp[i]);
		
	}
	
	cout << "Length of LIS : " << ans << endl;
    
    //cout << "Sequence : ";
    //print_LIS(dp, maxIndex, a);
	return 0;
}
