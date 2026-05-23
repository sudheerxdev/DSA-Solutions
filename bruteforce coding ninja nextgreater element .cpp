#include <bits/stdc++.h> 
vector<int> nextGreaterElement(vector<int>& arr, int n){
    // Write your code here.
    // aao brute force karte hai 
    vector<int > brr(n , -1) ; 
   
    for(int i = 0 ; i < n ; i++){
        for(int j = i ; j < n ; j++){
            if(arr[j]>arr[i]){
                brr[i]=arr[j];
                break;
            }
        }
        
    }
    return brr;
}
