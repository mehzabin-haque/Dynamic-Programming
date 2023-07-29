#include<stdio.h>
#include<bits/stdc++.h>
#include<string>
#include<fstream>
using namespace std;

int main(){
	//freopen("Input2.txt","r",stdin);
	int start[100],finish[100],act[100],i=0,j=0,k=0,n;
	
	cout << "Enter the num of activities : " ;
	cin >> n;
	cout << "\nEnter the start and finish time : " << endl;
	
	for( i=0 ; i<n ; i++){
		
		act[i] = i+1 ;
		cout << "Activity[" << act[i] << "]" << endl;
		cin >> start[i] >> finish[i];
	}
	
	for( i=0 ; i<n ; i++){
		for( j=0 ; j<n-i-1 ; j++){
			
			if( finish[j+1] < finish[j] ){
				
				swap(finish[j],finish[j+1]);
				swap(start[j],start[j+1]);
			}
		}
	}
	
	cout << "The activities are : " << endl ;
	cout << "Activity[" << act[0] << "]" << endl;
	
	for( i=0 ; i<n ; i++){
		
		if(start[i] >= finish[k]){
			cout << "Activity[" << act[i] << "]" << endl;
			k = i;
		}
	}
	
	return 0;
}
