class Solution {
	public:
	vector<int> getThreeLargest(vector<int>& arr) {
		// code here
		int num1 = INT_MIN ;
		int num2 = INT_MIN;
		int num3 = INT_MIN;
		for (int i = 0 ; i < arr.size() ; i++) {
			if (arr[i] > num1) {
				num1 = max(num1, arr[i]);
			}
			
		}
		for (int i = 0 ; i < arr.size() ; i++) {
			if (arr[i] > num2 && arr[i] < num1) {
				num2 = arr[i];
			}
			
		}
		for (int i = 0 ; i < arr.size() ; i++) {
			if (arr[i] > num3 && arr[i] < num2) {
				num3 = arr[i];
			}
			
		}
		if (num2 == INT_MIN) {
			return {num1};
		}
		if (num3 == INT_MIN) {
			return {num1, num2};
		}
		return {num1, num2, num3};
	}
};
