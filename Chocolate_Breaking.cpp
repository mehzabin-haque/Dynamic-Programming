#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

const int N = 500;
int d[N][N];

int Choco_Break(int r, int c){
	
	int temp=0;
	for(int i=0; i<=r; i++){
    	
    	for(int j=0; j<=c; j++) {
        	
        	if(i == 0){
        		d[i][j] = j ;
			}
			
			else if(j == 0){
        		d[i][j] = i ;
			}
        	
            else if(r == 1 && c == 1){
            	
            //	d[1][1] = price[1][1];
            	continue;
			}
            
            else{
            	
                temp = max( d[i][1] + d[i][j-1], d[1][j] + d[i-1][j]) ;
                //d[i][j] = max(price[i][j],temp) ;
            }
		}
    }
    
    return d[r][c];
}

int main(){
	
	//horizontal == row and vertical == col
    cout << "Enter the vertical and horizontal length of a chocolate : " << endl;
    int r, c, price[N][N], temp;
    cin >> r >> c;
    
    cout << "Enter the price of each block : " << endl;
    
    for(int i=1; i<=r; i++){
    	
        for(int j=1; j<=c; j++){
            cin >> price[i][j];
        }
    }
    
    d[1][1] = price[1][1];
    
    for(int i=1; i<=r; i++){
    	
        for(int j=1; j<=c; j++){
        	
            temp = max(price[i][j], Choco_Break(r,c));
        }
    }
    
    cout << temp << endl;
    
}
