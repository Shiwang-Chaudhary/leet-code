# 📝 Row with Max 1s in Rowwise Sorted (GeeksforGeeks)

🔗 [Problem Link](https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1)

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange) ![Language](https://img.shields.io/badge/Language-C++-blue)

### 💡 Tags
GFG Problem

### 🚀 Performance
- **Runtime:** Successfully Evaluated
- **Memory:** N/A

---

### 📜 Problem Description

You are given a 2D binary array  `**arr[][]**`  consisting of only  `1` s and  `0` s. Each row of the array is sorted in non-decreasing order. Your task is to find and return the index of the first row that contains the maximum number of  `1` s. If no such row exists, return  `-1` .

**Note:**

- The array follows 0-based indexing.

- The number of rows and columns in the array are denoted by  `n` .

**Examples:**

```
Input: arr[][] = [[0,1,1,1],
               [0,0,1,1],
               [1,1,1,1],
               [0,0,0,0]]
Output: 2
Explanation: Row 2 contains the most number of 1s (4 1s). Hence, the output is 2.
```

```
Input: arr[][] = [[0,0],
               [1,1]]
Output: 1
Explanation: Row 1 contains the most number of 1s (2 1s). Hence, the output is 1.
```

```
Input: arr[][] = [[0,0], 
               [0,0]]
Output: -1
Explanation: No row contains any 1s, so the output is -1.
```

**Constraints:** 
1 ≤ arr.size(), arr[i].size() ≤ 103