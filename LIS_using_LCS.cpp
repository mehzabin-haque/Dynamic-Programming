#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

const int N = 100;
int a[N],b[N];
int dp[N][N];

int LCS(int a[], int b[], int n){
	
	int c[100][100];
	
	for(int i=1; i<=n; i++){
		c[i][0] = 0;
	}
	
	for(int j=1; j<=n; j++){
		c[0][j] = 0 ;
	}
	
	for(int i=1; i<=n; i++){
		
		for(int j=1; j<=n; j++){
			
			if(a[i-1] == b[j-1]){
				
				c[i][j] = 1 + c[i-1][j-1] ;
				//d[i][j] = " " ;
				dp[i][j] = 1 ;
			}
			
			else if(c[i-1][j] >= c[i][j-1]){
				
                c[i][j] = c[i-1][j];
                //dp[i][j]="->";
                dp[i][j] = 2 ;
            }
            
            else
			{
                c[i][j] = c[i][j-1];
                //dp[i][j]="<-";
                dp[i][j] = 3 ;
            }
		}
	}
	
	return c[n][n];
}

void print_LIS(int a[], int n,int m){
	
	if(n == 0 || m == 0){
		return;
	}
        
    if(dp[n][m] == 1){
    	
        print_LIS(a, n-1, m-1);
        
        cout << "\t" << a[n-1];
    }
    
    else if(dp[n][m] == 2){
    	print_LIS(a, n-1, m);
	}
	
    else{
    	print_LIS(a, n, m-1);
	}
	
}

int main(){
	
	int n;
	cout << "Number of elements: " << endl ;
    cin >> n;
    
    cout << "Enter the elements : " << endl;
    
    for(int i=0; i<n; i++){
    	
        cin >> a[i];
        b[i] = a[i];
    }
    
    sort(b, b+n);
	
	cout << "Longest Increasing Subsequence : " << LCS(a, b, n) <<endl;
	
    cout << "Sequence : ";
    print_LIS(a,n,n);
    
	return 0;
}
