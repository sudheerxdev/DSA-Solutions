class Solution {
    public java.util.ArrayList<java.util.ArrayList<Integer>> formCoils(int n) {

        int size = 4 * n;

        java.util.ArrayList<java.util.ArrayList<Integer>> ans =
            new java.util.ArrayList<>();

        java.util.ArrayList<Integer> coil1 = new java.util.ArrayList<>();
        java.util.ArrayList<Integer> coil2 = new java.util.ArrayList<>();

        // First coil
        int top = 0;
        int left = 0;
        int bottom = size - 1;
        int right = size - 2;

        while (top <= bottom && left <= right) {

            // Down
            for (int i = top; i <= bottom; i++) {
                coil1.add(i * size + left + 1);
            }

            // Right
            for (int j = left + 1; j <= right; j++) {
                coil1.add(bottom * size + j + 1);
            }

            // Up
            for (int i = bottom - 1; i > top; i--) {
                coil1.add(i * size + right + 1);
            }

            // Left
            for (int j = right - 1; j > left + 1; j--) {
                coil1.add((top + 1) * size + j + 1);
            }

            top += 2;
            left += 2;
            bottom -= 2;
            right -= 2;
        }

        // Second coil
        top = 0;
        left = 1;
        bottom = size - 1;
        right = size - 1;

        while (top <= bottom && left <= right) {

            // Up
            for (int i = bottom; i >= top; i--) {
                coil2.add(i * size + right + 1);
            }

            // Left
            for (int j = right - 1; j >= left; j--) {
                coil2.add(top * size + j + 1);
            }

            // Down
            for (int i = top + 1; i < bottom; i++) {
                coil2.add(i * size + left + 1);
            }

            // Right
            if (right - left > 2) {
                for (int j = left + 1; j < right - 1; j++) {
                    coil2.add((bottom - 1) * size + j + 1);
                }
            }

            top += 2;
            left += 2;
            bottom -= 2;
            right -= 2;
        }

        ans.add(coil1);
        ans.add(coil2);

        return ans;
    }
}


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna