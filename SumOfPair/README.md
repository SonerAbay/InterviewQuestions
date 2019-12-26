### Sum Of Pair Problem

Given an array, find if any pair adds up to number k  

**Example:**  

[10, 15, 3, 7] and k = 17, returns true because 10 + 7 = 17

**Solutions:**
1) Nested Loops, We don't want this because of the time complexity *O(n^2)*
2) First quick sort then loop towards middle from both ends. *O(nlogn)*
3) Hash set solution. *O(n)* on worst case scenario
