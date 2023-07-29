#include<stdio.h>
#include<bits/stdc++.h>
#include<string>
#include<fstream>
using namespace std;

int main(){
	
	//freopen("Input1.txt","r",stdin);
	float w[100],pr[100],x[100],total_profit=0,cap;
    int n,i,j;
    float r[100];
 
    cout << "\nEnter the num of objects : " ;
    cin >> n;
 
    cout << "\nEnter the weights and profits : \n";
    
    for( i=0 ; i<n ; i++){
        cin >> w[i] >> pr[i];
    }
 
    cout << "\nEnter the capacity of knapsack : ";
    cin >> cap;
 
    for( i=0 ; i<n ; i++){
        r[i] = pr[i] / w[i];
   	}
 
    for( i=0 ; i<n ; i++){
    	
        for ( j=i+1 ; j<n ; j++) {
      	
           if (r[j] > r[i]) {
         	
         	swap(r[i],r[j]);

            swap(w[i],w[j]);
     
            swap(pr[i],pr[j]);
         }
      }
   }
 
    for( i=0 ; i<n ; i++){
    	x[i] = 0.0;
	}
 
    for( i=0 ; i<n ; i++) {
    	
       	if(w[i] > cap){
       		break;
	   	}
	   	
       	else{
        	x[i] = 1.0;
         	total_profit = total_profit + pr[i];
         	cap = cap - w[i];
      }
   }
 
   	if (i < n){
   		x[i] = cap / w[i];
	}
 
   	total_profit = total_profit + (x[i] * pr[i]);
 
   	cout << "\nThe result is : ";
   
   	for( i=0 ; i<n ; i++){
   		cout << "\t" << x[i];
   	}

   	cout << "\nMaximum profit is : " << total_profit << endl;
   
   return 0;
}
