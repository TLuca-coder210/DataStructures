# Lab 4: Hierarchical Structures – Binary Search Trees & Heaps
## Problem 1 - Vector backed BST
### Aproach: 
#### Implemented a custom BST using a `std::vector<Node>` with integer indices instead of raw pointers to optimize cache locality and memory management. To guarantee a perfectly balanced initial tree, the input is sorted, and a divide-and-conquer strategy recursively selects the median element as the root of each subtree. Updates (insert, erase) and queries (exists, successor, predecessor) are handled through standard iterative traversal based on the BST property.
### Complexity: 
#### Time: $\mathcal{O}(n \ log \ n)$ for initial construct (dominated by sorting). $\mathcal{O}(\log \ n)$ average time for all other operations, which can degrade to $\mathcal{O}(n)$ in the worst case if subsequent updates unbalance the tree.
#### Space: $\mathcal{O}(n)$ total storage to maintain the vector-backed nodes, using $\mathcal{O}(1)$ auxiliary space for iterative operations and $\mathcal{O}(\log \ n)$ recursion stack during initial construction.
## Problem 2 - Validate a BST
### Aproach:
#### Approach: Utilized an in-order traversal strategy (Left → Root → Right) to validate the tree. Since an in-order traversal of a valid BST must yield strictly increasing values, I maintained a global tracker `mini` initialized to `LONG_MIN` to verify that each node's value is strictly greater than the previously visited one. If the condition is violated at any point, the recursion shorts-circuits and returns `false`.
### Complexity:
#### Time: Time: $\mathcal{O}(n)$ because every node in the tree is visited exactly once.
#### Space: Space: $\mathcal{O}(h)$ auxiliary space required by the recursive call stack, where h is the height of the tree (degrades to $\mathcal{O}(n)$ for a completely skewed tree).
