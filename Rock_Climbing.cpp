#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

const int N = 100 , val = 1e5;
int n, m;
int a[N][N], c[N][N], dp[N];

void printBest(int i, int j){
	
    if(i==0 || j==0 || j==m+1){
    	return;
	}
	
    if((a[i-1][j-1] <= a[i-1][j]) && (a[i-1][j-1] <=a [i-1][j+1])){
    	printBest(i-1, j-1);
	}
	
    else if((a[i-1][j] <= a[i-1][j-1]) && (a[i-1][j] <= a[i-1][j+1])){
    	printBest(i-1, j);
	}
    
    else if((a[i-1][j+1]<=a[i-1][j-1]) && (a[i-1][j+1]<=a[i-1][j])){
    	printBest(i-1, j+1);
	}
        
    cout << i << " " << j << endl;
}   

int main(){ 
	
	cout << "Enter the row and col of the array : " << endl;
    cin >> n >> m;
    
    cout << "Enter the array : " << endl;
    for(int i=1; i<=n; i++){
    	for(int j=1; j<=m; j++){
    		cin >> c[i][j];
		}
	}
    
    for(int i=1; i<m; i++){
    	a[0][i] = 0;
	}
        
    for(int i=0; i<=n+1; i++){
    	 a[i][0] = val;
    	 a[i][m+1] = val ;
	}
       
    for(int i=1; i<=n; i++){
    	for(int j=1; j<=m; j++){
        	
            if(i==1){
            	a[i][j] = c[i][j];
			}
                
            else{
            	a[i][j] = c[i][j] + min(min(a[i-1][j-1], a[i-1][j]), a[i-1][j+1]);
			}      
        }
	}
    
    for(int i=1; i<=m; i++){
    	dp[i-1] = a[n][i];
	}
        
    cout << "Least Total Danger : " << *min_element(dp, dp+m) << endl;
    printBest(n, min_element(dp, dp+m)-dp+1);
}
