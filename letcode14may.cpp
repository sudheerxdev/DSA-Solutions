 sort(nums.begin() , nums.end());
        int n = nums.size();
        int maxi = nums[n - 1];
        if(maxi + 1 != n){
            return false;
        }
        // check kro n - 3 tak
        // if(n <= 3){
        //     if(nums[0]==nums[1]){
        //         return false;
        //     }
        // }
        for(int i = 1 ; i <= n - 2 ; i++){
            if(nums[i] == nums[i-1]){
                return false;
            }
        }
        int count = 0 ; 
        for(int i = n - 1 ; i >= 0 ; i--){
             if(nums[i]== maxi){
                count ++;
                if(count > 2){
                    return false;
                }
             }
        }
        return true;
