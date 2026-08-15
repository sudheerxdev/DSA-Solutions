/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
// #include<iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;
// int main(){
//     int n ; 
//     cin >> n ; 
//     vector<int>arr(n);
//     int k ; 
//     cin >> k ;
//     for(int i = 0 ; i < n ; i++){
//         cin >> arr[i];
//     }
//     k = k % n ;
//     reverse(arr.begin() , arr.end());
//     reverse(arr.begin() , arr.begin() + k );
//     reverse(arr.begin() + k , arr.end());
    
//     for(int i = 0 ; i < n ; i++){
//         cout << arr[i] << " ";
//     }
//     return 0;
    
// }
// #include<bits/stdc++.h>
// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     int n ; 
//     cin >> n ; 
//     vector<int>arr(n);
//     for(int i = 0 ; i < n ; i++){
//         cin >> arr[i];
//     }
//     int sum1 = n * (n + 1)/2;
//     int sum2 = 0 ; 
//     for(int i = 0 ; i < n ; i++){
//         sum2 += arr[i];
//     }
//     cout << sum1 - sum2;
//     return 0;
// }

// #include<iostream>
// #include<string>
// #include<algorithm>
// using namespace std;
// int main(){
//     string str1 , str2;
//     getline(cin , str1);
//     getline(cin , str2);
//     sort(str1.begin() , str1.end());
//     sort(str2.begin() , str2.end());
//     if(str1 == str2){
//         cout << "Anagram";
//     }
//     else{
//         cout << "Not Anagram";
//     }
// }


// #include<iostream>
// using namespace std;
// int main(){
//     string str ; 
//     getline(cin , str);
//     int n = str.length();
//     int len = 0 , count = 0 ,l = 0 , r = 0;
//     for(int i = 0 ; i < n ; i++){
//         if(str[i]==' '){
//             len = max(len , count);
//             count = 0;
//         }
//         else{
//             count ++;
//         }
//     }
//     cout << 
// }

// Given a sorted array and a target value, find whether there exists a pair whose sum is equal to the target.

// Print the pair if it exists; otherwise print -1.


// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     int n ; 
//     cin >> n ; 
//     vector<int>arr(n);
//     for(int i = 0 ; i < n ; i++){
//         cin >> arr[i];
//     }
//     int target ;
//     cin >> target;
//     int i = 0 , j = n - 1;
//     while(i < j){
//         if(arr[i]+arr[j]==target){
//             cout << i << " " << j;
//             return 0;
//         }
//         else if(arr[i]+arr[j] < target){
//             i++;
//         }
//         else {
//             j --;
//         }
//     }
//     cout << "Not Found";
//     return 0;
    
// }



// Q6. Minimum Number of Platforms
// Given arrival and departure times of N trains at a railway station, determine the minimum number of platforms required so that no train has to wait.
// Input:
// Arrival   = [900, 940, 950, 1100, 1500, 1800]
// Departure = [910, 1200, 1120, 1130, 1900, 2000]
// Output:
// 3
// Explanation:
// Around 11:00, three trains are present simultaneously, so at least 3 platforms are required.

// #include<iostream>

// #include<iostream>
// #include<vector>
// #include<unordered_map>
// using namespace std;

// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i = 0; i < n; i++){
//         cin >> arr[i];
//     }
//     int target;
//     cin >> target;

//     unordered_map<int, int> seen; // value -> index

//     for(int i = 0; i < n; i++){
//         int complement = target - arr[i];
//         if(seen.find(complement) != seen.end()){
//             cout << seen[complement] << " " << i;
//             return 0;
//         }
//         seen[arr[i]] = i;
//     }

//     cout << "Not Found";
//     return 0;
// }

// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n), dep(n);
//     for(int i = 0; i < n; i++) cin >> arr[i];
//     for(int i = 0; i < n; i++) cin >> dep[i];

//     sort(arr.begin(), arr.end());
//     sort(dep.begin(), dep.end());

//     int i = 0, j = 0;
//     int platforms = 0, maxPlatforms = 0;

//     while(i < n && j < n){
//         if(arr[i] <= dep[j]){
//             platforms++;              // new train arrives, needs a platform
//             maxPlatforms = max(maxPlatforms, platforms);
//             i++;
//         }
//         else{
//             platforms--;              // a train departs, platform freed
//             j++;
//         }
//     }

//     cout << maxPlatforms;
//     return 0;
// }

// find first non repeating character 
// #include<iostream>
// #include<string>
// #include<unordered_map>
// using namespace std;
// int main(){
//     string str; 
//     cin >> str;
//     unordered_map<char , int>mp;
//     for(int i = 0 ; i < str.length() ; i++){
//         mp[str[i]]++;
//     }
//     for(char ch : str){
//         if(mp[ch]==1){
//             cout << ch ; 
//             return 0;
//         }
//     }
//     return -1;
// }


























