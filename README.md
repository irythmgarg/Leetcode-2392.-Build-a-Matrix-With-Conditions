# Leetcode-2392.-Build-a-Matrix-With-Conditions
# Build Matrix With Conditions

This repository solves the problem of building a `k x k` matrix where each number from `1` to `k` must appear exactly once, and both row and column precedence constraints are satisfied.

---

## Problem Statement
You are given:
- An integer `k` representing the size of the matrix.
- Two lists of conditions: `rowConditions` and `colConditions`.

Each condition `[u, v]` means `u` must come before `v` in the respective dimension (row or column).

**Goal:** Build a `k x k` matrix such that:
- Each number from 1 to `k` appears exactly once.
- All row and column conditions are satisfied.

---

## 🔍 Approach: Topological Sorting (Kahn's Algorithm)

### ✅ Steps:
1. Convert 1-based to 0-based indexing.
2. Create adjacency lists for both row and column conditions.
3. Perform topological sort (Kahn's Algorithm) separately for row and column conditions.
4. If any cycle is detected, return an empty matrix.
5. Map each number to its topological index (row and column).
6. Fill the matrix using these mapped indices.

### ✅ Time and Space Complexity:
- **Time:** O(k + R + C), where R and C are sizes of row and column conditions.
- **Space:** O(k^2) for the matrix and maps.

---

## ✅ Example
**Input:**
```cpp
k = 3
rowConditions = [[1,2],[2,3]]
colConditions = [[2,3],[3,1]]
```
**Output:**
```cpp
[
 [0, 0, 1],
 [0, 2, 0],
 [3, 0, 0]
]
```

---

## 🤝 Contributions
Feel free to fork this repo and enhance with other approaches (DFS, DP etc.)

---

## 📜 License
MIT License

---

Happy Coding! 🚀
