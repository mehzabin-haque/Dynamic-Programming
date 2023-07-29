#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int Edit_Dist(string s, string s1, int n, int m)
{
    int c[n+1][m+1],temp;
	
//	for(int i=1; i<=n; i++){
//		c[i][0] = 0;
//	}
//	
//	for(int j=1; j<=m; j++){
//		c[0][j] = 0 ;
//	}
	
    for(int i=0; i<=n; i++){
    	
        for(int j=0; j<=m; j++) {
        	
        	if(i == 0){
        		c[i][j] = j ;
			}
			
			else if(j == 0){
        		c[i][j] = i ;
			}
        	
            if(s[i-1] == s1[j-1]){
            	
            	//c[i][j] = c[i-1][j-1] + 1;
				c[i][j] = c[i-1][j-1] ;
			}
            
            else{
                temp = min( c[i-1][j], c[i][j-1]) ;
                c[i][j] = min(c[i-1][j-1],temp) + 1 ;
            }
		}
    }
    
    return c[n][m];

}

int main()
{
    string s,s1; 
	cout << "Enter two strings : " << endl;
	
	cin >> s >> s1;
	
	int n = s.length();
	//cout << n;
	
	int m = s1.length();
	//cout << m;
    cout << "Edit distance is : " << Edit_Dist(s, s1, n, m) << endl;
}
