#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

const int N = 100;

void print_LIS(int prev[], int n, int a[]){
	
	if(n == 0){
		return;
	}
    
    print_LIS(prev, prev[n], a);
    cout << a[n] << "\t";
}

int main()
{
    int n, a[N];
	cout << "Number of elements: " << endl ;
    cin >> n;
    
    cout << "Enter the elements : " << endl;
    
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    					
    int l[N], prev[N], maxLength=0, maxIndex=0;
    l[0] = 1;
    prev[0]=0, prev[1]=0;
    
    for(int i=1; i<n; i++){
    	
        l[i]=1;
        
        for(int j=0; j<i; j++){
        	
            if(a[j]<a[i] && (l[j]+1)>l[i]){
            	
                l[i] = l[j]+1;
                prev[i] = j;
                
                if(prev[i] > maxLength){
                	
                    maxLength = prev[i];
                    maxIndex = i;
                }
            }
        }
    }
    
    cout << "Length of LIS : " << *max_element(l, l+n) << endl;
    
    cout << "Sequence : ";
    print_LIS(prev, maxIndex, a);
}
