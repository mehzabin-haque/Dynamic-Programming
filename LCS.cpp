#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

const int N = 100;
int d[N][N];

//int LCS_Length(string &s, string &s1, int n, int m){
//	
//	if(n == 0 || m == 0){
//	//	d[n][m] = 1;
//		return 0;
//	}
//	
//	// already did this part
////	if(d[n][m] != -1){
////		return d[n][m];
////	}
//	
//	if(s[n-1] == s1[m-1]){
//		
//		d[n][m] = 1;
//		return 1 + LCS_Length(s, s1, n-1, m-1);
//	}
//	
//	else{
//	
//		//d[n][m] = 2;
//		return max(LCS_Length(s, s1, n, m-1), LCS_Length(s, s1, n-1, m));
//	}
//	
//	//return d[n][m];
//}

int LCS_Length(string s, string s1, int n, int m){
	
	int c[n+1][m+1];
	
	for(int i=1; i<=n; i++){
		c[i][0] = 0;
	}
	
	for(int j=1; j<=m; j++){
		c[0][j] = 0 ;
	}
	
	for(int i=1; i<=n; i++){
		
		for(int j=1; j<=m; j++){
			
			if(s[i-1] == s1[j-1]){
				
				c[i][j] = 1 + c[i-1][j-1] ;
				//d[i][j] = " " ;
				d[i][j] = 1 ;
			}
			
			else if(c[i-1][j] >= c[i][j-1]){
				
                c[i][j] = c[i-1][j];
                //d[i][j]="->";
                d[i][j] = 2 ;
            }
            
            else
			{
                c[i][j] = c[i][j-1];
                //d[i][j]="<-";
                d[i][j] = 3 ;
            }
		}
	}
	
	return c[n][m];
}

void print_LCS(string s,int n,int m){
	
	if(n == 0 || m == 0){
		return;
	}
        
    if(d[n][m] == 1){
    	
        print_LCS(s, n-1, m-1);
        
        cout << "\t" << s[n-1];
    }
    
    else if(d[n][m] == 2){
    	print_LCS(s, n-1, m);
	}
	
    else{
    	print_LCS(s, n, m-1);
	}
	
}

int main(){
	
	string s,s1; 
	cout << "Enter two strings : " << endl;
	
	cin >> s >> s1;
	
	int n = s.length();
	//cout << n;
	
	int m = s1.length();
	//cout << m;
	
//	for(int i=0;i<N;i++){
//		
//		for(int j=0;i<N;j++){
//			
//			d[i][j] = -1 ;
//			
//		}
//	}
	
	cout << "Longest Common Subsequence is : " << LCS_Length(s, s1, n, m) << endl;
	
	cout << "Subsequence is : " << endl ;
	print_LCS(s, n, m);
	
}
