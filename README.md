# Binary Search Tree (BST) in C++

A clean implementation of a Binary Search Tree data structure in C++, supporting core operations and multiple tree traversals.

## Features

- **Insert** — Add a new node to the tree
- **Search** — Find whether a value exists in the tree
- **Delete** — Remove a node while maintaining BST properties
- **Traversals:**
  - Inorder (Left → Root → Right)
  - Preorder (Root → Left → Right)
  - Postorder (Left → Right → Root)

## Getting Started

## How It Works

In a BST, each node follows one rule:
- **Left child** holds a value smaller than the parent
- **Right child** holds a value greater than the parent

This makes search, insert, and delete operations run in **O(log n)** time on average.

## Example

```cpp
BST tree;
tree.insert(50);
tree.insert(30);
tree.insert(70);
tree.insert(20);

tree.inorder();   // Output: 20 30 50 70
tree.search(30);  // Found
tree.remove(30);
tree.inorder();   // Output: 20 50 70
```
