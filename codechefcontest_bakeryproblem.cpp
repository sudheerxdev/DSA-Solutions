#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int n , k ;
    cin >> n >> k;
    int c1 = 100*n ; 
    int c2 = k + 60*n ;
    cout << min(c1 , c2) << endl;
}
