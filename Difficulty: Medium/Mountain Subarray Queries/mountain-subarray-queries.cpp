class Solution {
 public:
 vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries) {
  // code here
  int n = arr.size();
  int q = queries.size();
  vector<int>temp(n);
  vector<int>temp2(n);
   vector<int>temp3(n);
    vector<int>temp4(n);
  vector<bool>ans;
  
  for (int i = 1; i<n - 1; i++) {
   if (arr[i]>arr[i - 1] and arr[i]>arr[i + 1]) {
    temp[i] = 1;
   }
    if(arr[i]==arr[i - 1] and arr[i]<arr[i + 1]) {
    temp4[i] = 1;
   }
   
   if (arr[i]<arr[i - 1] and arr[i]<arr[i + 1]) {
    temp2[i] = 1;
   }
      if (arr[i]<arr[i - 1] and arr[i]==arr[i + 1]) {
    temp3[i] = 1;
   }
   
  }
  for (int i = 1; i<n; i++) {
   temp[i] += temp[i - 1];
   temp2[i] += temp2[i - 1];
   temp3[i] += temp3[i - 1];
   temp4[i] += temp4[i - 1];
  }
  
  
//   for(int i=0;i<n;i++) cout<<temp[i]<<" ";
  for (int i = 0; i<q; i++) {
   int l = queries[i][0];
   int r = queries[i][1];
   if (abs(r - l) <= 1) {
    ans.push_back(true);
    continue;
   }
   if (r - l == 2) {
    if (arr[l + 1]<arr[l] and arr[l + 1]<arr[l + 2]) {
     ans.push_back(false);
     continue;
    }
   }
   l++;
   r--;
   int val = temp[r];
   int val2 = temp2[r];
   int val3 = temp3[r];
   int val4 = temp4[r];
   if (l>0)
    val -= temp[l - 1];
   if (l>0)
    val2 -= temp2[l - 1];
   if (l>0)
    val3 -= temp3[l - 1];
   if (l>0)
    val4 -= temp4[l - 1];
    
    // cout<<val<<" "<<val2<<" "<<val3<<" "<<val4<<endl;
//    if((val2+val3)==0 and (val1+val))
    if ((val+val4 >=1 ) and (val2+val3) == 0)
    ans.push_back(true);
    // else if ((val+val4 >=1 ) and (val2==0   ))
    // ans.push_back(true);
   else if ((val+val4 == 0 ) and (val2) == 0)
    ans.push_back(true);
    else if(val==0 and val2==0 and (val3+val4)>=1) ans.push_back(false);
   else
    ans.push_back(false);
  }
  return ans ;
 }
};

//GFG POTD solution for 19 July
