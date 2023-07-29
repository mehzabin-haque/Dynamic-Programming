#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
	
	//freopen("input1.txt", "r" , stdin);
	int n,value[1000]={},price[1000], opt[1000];
	int max1 = 0;
	value[0] = 0;
	
	cout << "Enter the length of the rod : " ;
	cin >> n ;
	
	cout << endl;
	cout << "Enter the price of the rod : " ;
	
	for(int i=1;i<=n;i++){
		cin >> price[i] ;
	}
	
	//value[0]=0;
	for(int i=1;i<=n;i++){
		
		for(int j=1;j<=i;j++){
		
			if(max1 < price[j] + value[i-j]){
				max1   = price[j] + value[i-j];
				opt[i] = j;
			}	
		}
		
		value[i] = max1;
	}
	
	cout << "Max value : " << max1 << endl;
	cout << "Cutting Lengths : " << endl ;
	
	while(n>0){
		
        cout << opt[n] << "\t";
        n = n - opt[n];
    }
	return 0;
}
