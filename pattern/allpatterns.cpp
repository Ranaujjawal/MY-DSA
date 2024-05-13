#include <bits/stdc++.h>
using namespace std;

// 33333
// 32223
// 32123
// 32223
// 33333
void pattern1(int n){  // calculate minimum distance of a cell from boundary 
     for(int i=0;i<2*n-1;i++){// and subtract from n
       for(int j=0;j<2*n-1;j++){
           cout<<n-min(i,min(j,min(2*n-2-i,2*n-2-j)));
       }
       cout<<endl;
   }
}

// *****
//  ***
//   *
void nStarTriangle(int n) {
    for(int i=0;i<n;i++){
        for(int k=0;k<i;k++){
            cout<<" ";
        }
        for(int j=2*n-2-2*i;j>=0;j--){
            cout<<"*";
        }
         for(int k=0;k<i;k++){
            cout<<" ";
        }
        cout<<"\n";
    }
}
// *         *
// * *     * *
// * * * * * *
// * *     * *
// *         *
void symmetry(int n) {
    // Write your code here.
    int spaces=2*n-2;
    for(int i=1;i<=2*n-1;i++){
        int stars=i;
        if(i>n) stars=2*n-i;
        for(int j=1;j<=stars;j++){
            cout<<"* ";
        }
         for(int j=1;j<=spaces;j++){
            cout<<" ";
        }
         for(int j=1;j<=stars;j++){
            cout<<"* ";
        }
        cout<<"\n";
        if(i<n){
            spaces-=2;
        }
        else spaces+=2;
    }
}






signed main(){
        std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
 #endif
   pattern1(5);
   solve();
    return 0;
    
	
}
//pogo