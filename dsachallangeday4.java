import java.util.PriorityQueue;
import java.util.Scanner;

public class KthLargestElement {

 
 public static int findKthLargest(int[] nums, int k) {
 
 PriorityQueue<Integer> minHeap = new PriorityQueue<>();
 
 for (int num : nums) {
 minHeap.add(num);
 
 if (minHeap.size() > k) {
 minHeap.poll();
 }
 }
 
 // The root of the min-heap is the Kth largest element
 return minHeap.peek();
 }

 public static void main(String[] args) {
 Scanner sc = new Scanner(System.in);
 
 System.out.print("Enter the number of elements in the array: ");
 int n = sc.nextInt();
 
 int[] nums = new int[n];
 System.out.println("Enter the elements (can be posetive or negative): ");
 for (int i = 0; i < n; i++) {
 nums[i] = scanner.nextInt();
 }
 
 System.out.print("Enter the valu of K: ");
 int k = scanner.nextInt();
 
 if (k > 0 && k <= n) {
 int result = findKthLargest(nums, k);
 System.out.println("The " + k + "th largest element is: " + result);
 } else {
 System.out.println("Invalid value of K.");
 }
 }
}
