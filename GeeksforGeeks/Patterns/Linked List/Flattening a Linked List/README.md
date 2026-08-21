# 📝 Flattening a Linked List (GeeksforGeeks)

🔗 [Problem Link](https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1)

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange) ![Language](https://img.shields.io/badge/Language-C++-blue)

### 💡 Tags
Linked List

### 🚀 Performance
- **Runtime:** Successfully Evaluated
- **Memory:** N/A

---

### 📜 Problem Description

In a linked list, every node has two pointers:  **next** and  **bottom** . The heads of  **n**  linked lists are connected using the next pointer, while the bottom pointer points to the next node in the current linked list.

Each linked list is sorted in non-decreasing order of data, and the head nodes are also sorted in non-decreasing order.

Given the  **head**  of the first linked list, flatten the linked lists into a single sorted linked list such that every node is connected using only the bottom pointers.

**Examples:**

```
Input:

Output: 5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22 -> 28 -> 40 -> 45.
Explanation: 
Bottom pointer of 5 is pointing to 7.
Bottom pointer of 7 is pointing to 8.
Bottom pointer of 10 is pointing to 20 and so on.
So, after flattening the linked list the sorted list will be 
5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22 -> 28 -> 40 -> 45.
```

```
Input:

Output: 5 -> 7 -> 8 -> 10 -> 19 -> 22 -> 28 -> 30 -> 50
Explanation:
Bottom pointer of 5 is pointing to 7.
Bottom pointer of 7 is pointing to 8.
Bottom pointer of 8 is pointing to 30 and so on.
So, after flattening the linked list the sorted list will be 
5 -> 7 -> 8 -> 10 -> 19 -> 22 -> 28 -> 30 -> 50.
```

**Constraints:** 
0 ≤ n ≤ 104
1 ≤ **** number of nodes in each list ≤ 50
1 ≤ node->data ≤ 5*105