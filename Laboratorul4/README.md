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
## Problem 4 - Serialize and Deserialize BST
### Aproach:
#### Exploited the unique structural properties of a BST to optimize data storage. For serialization, the tree is flattened into a space-separated string using a pre-order traversal (Root → Left → Right), completely avoiding the need to store `null` markers for empty child slots. For deserialization, the string is parsed back into an array of integers. The tree is then reconstructed in a single pass by recursively enforcing strict valid value ranges `(mini, maxi)` for each subtree path, allowing the algorithm to correctly place nodes based solely on their keys.
### Complexity:
#### Time: $\mathcal{O}(n)$ for both operations. `serialize` visits every node once, and `deserialize` processes each number in the array exactly once due to the bounding range checks.
#### Space: $\mathcal{O}(n)$ memory to store the output string and intermediate parsed vector, alongside $\mathcal{O}(h)$ stack space for the recursive calls, where `h` is the tree height.
