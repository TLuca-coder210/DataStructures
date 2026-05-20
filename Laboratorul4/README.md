# Lab 4: Hierarchical Structures – Binary Search Trees & Heaps
## Problem 1 - Vector backed BST
### Aproach: Implemented a custom BST using a `std::vector<Node>` with integer indices instead of raw pointers to optimize cache locality and memory management. To guarantee a perfectly balanced initial tree, the input is sorted, and a divide-and-conquer strategy recursively selects the median element as the root of each subtree. Updates (insert, erase) and queries (exists, successor, predecessor) are handled through standard iterative traversal based on the BST property.
### Complexity: 
#### Time: $O(nlogn)$ for initial construct (dominated by sorting). $O(logn)$ average time for all other operations, which can degrade to $O(n)$ in the worst case if subsequent updates unbalance the tree.
#### Space: $O(n)$ total storage to maintain the vector-backed nodes, using $O(1)$ auxiliary space for iterative operations and $O(logn)$ recursion stack during initial construction.
