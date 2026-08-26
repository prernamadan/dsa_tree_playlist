#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

// Define the structure for a tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to construct a complete binary tree
TreeNode* createTree(const vector<int>& values) {
    if (values.empty())
        return nullptr;

    TreeNode* root = new TreeNode(values[0]);

    queue<TreeNode*> q;
    q.push(root);

    size_t i = 1;

    while (i < values.size()) {
        TreeNode* current = q.front();
        q.pop();

        // Assign left child
        if (i < values.size()) {
            current->left = new TreeNode(values[i++]);
            q.push(current->left);
        }

        // Assign right child
        if (i < values.size()) {
            current->right = new TreeNode(values[i++]);
            q.push(current->right);
        }
    }

    return root;
}

// Print tree in level order
void printLevelOrder(TreeNode* root) {
    if (!root)
        return;

    queue<TreeNode*> q;
    q.push(root);

    cout << "Tree nodes in Level-Order traversal: ";

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        cout << current->val << " ";

        if (current->left)
            q.push(current->left);

        if (current->right)
            q.push(current->right);
    }

    cout << endl;
}

// Function to find Top View of Binary Tree
void topview(TreeNode* root) {
    if (!root)
        return;

    // Queue stores {node, horizontal distance}
    queue<pair<TreeNode*, int>> q;

    // map<horizontal distance, node value>
    map<int, int> m;

    q.push({root, 0});

    while (!q.empty()) {

        TreeNode* curr = q.front().first;
        int curr_hd = q.front().second;

        q.pop();

        // If this horizontal distance is seen for the first time
        if (m.find(curr_hd) == m.end()) {
            m[curr_hd] = curr->val;
        }

        // Left child -> horizontal distance -1
        if (curr->left != nullptr) {
            q.push({curr->left, curr_hd - 1});
        }

        // Right child -> horizontal distance +1
        if (curr->right != nullptr) {
            q.push({curr->right, curr_hd + 1});
        }
    }

    cout << "Top View: ";

    for (auto it : m) {
        cout << it.second << " ";
    }

    cout << endl;
}

// Free allocated memory
void freeTree(TreeNode* root) {
    if (!root)
        return;

    freeTree(root->left);
    freeTree(root->right);

    delete root;
}

int main() {

    vector<int> nodeValues = {
        1, 2, 3, 4, 5, 6, 7, 8, 9
    };

    // Create tree
    TreeNode* root = createTree(nodeValues);

    // Print level order
    printLevelOrder(root);

    // Print top view
    topview(root);

    // Free memory AFTER using the tree
    freeTree(root);

    return 0;
}
