# Lab 4: Hierarchical Structures – Binary Search Trees & Heaps
## Problem 1 - Vector backed BST
### Aproach: 
#### Implemented a custom BST using a `std::vector<Node>` with integer indices instead of raw pointers to optimize cache locality and memory management. To guarantee a perfectly balanced initial tree, the input is sorted, and a divide-and-conquer strategy recursively selects the median element as the root of each subtree. Updates (insert, erase) and queries (exists, successor, predecessor) are handled through standard iterative traversal based on the BST property.
### Complexity: 
#### Time: $\mathcal{O}(n \ log \ n)$ for initial construct (dominated by sorting). $\mathcal{O}(\log \ n)$ average time for all other operations, which can degrade to $\mathcal{O}(n)$ in the worst case if subsequent updates unbalance the tree.
#### Space: $\mathcal{O}(n)$ total storage to maintain the vector-backed nodes, using $\mathcal{O}(1)$ auxiliary space for iterative operations and $\mathcal{O}(\log \ n)$ recursion stack during initial construction.
## Problem 2 - Validate a BST
### Aproach:
#### Utilized an in-order traversal strategy (Left → Root → Right) to validate the tree. Since an in-order traversal of a valid BST must yield strictly increasing values, I maintained a global tracker `mini` initialized to `LONG_MIN` to verify that each node's value is strictly greater than the previously visited one. If the condition is violated at any point, the recursion shorts-circuits and returns `false`.
### Complexity:
#### Time: $\mathcal{O}(n)$ because every node in the tree is visited exactly once.
#### Space: $\mathcal{O}(h)$ auxiliary space required by the recursive call stack, where h is the height of the tree (degrades to $\mathcal{O}(n)$ for a completely skewed tree).
## Problem 3 - Recover a BST
### Aproach:
#### Built upon the in-order traversal property where a valid BST must yield a strictly increasing sequence. By keeping a pointer to the `prev` visited node, I scanned for anomalies where `root->val <= prev->val`. If it is the first violation found, `prev` is marked as `firstNode` and `root` as `secondNode` (handles adjacent swaps). If a second violation occurs later, `secondNode` is updated to the new `root` (handles non-adjacent swaps). After the full traversal, the values of `firstNode` and `secondNode` are swapped to restore the tree.
### Complexity:
#### Time: $\mathcal{O}(n)$ as the algorithm performs a single, complete in-order traversal visiting each node exactly once.
#### Space: $\mathcal{O}(h)$ auxiliary space for the implicit recursion stack, where h is the height of the tree ($\mathcal{O}(n)$ in the worst case).
