#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Iterator
class TreeIterator {
    public:
    virtual bool first() = 0;
    virtual TreeNode* next() = 0;
    virtual bool isDone() = 0;
    virtual TreeNode* currentItem() = 0;
};

// ConcreteIterator
class DepthFirstIterator : public TreeIterator {
    private:
    TreeNode* root;
    stack<TreeNode*> stack;

    public:
    DepthFirstIterator(TreeNode* root) { this->root = root; }

    bool first() override {
        stack.push(root);
        return !stack.empty();
    }

    TreeNode* next() override {
        if (stack.empty()) { return nullptr; }
        TreeNode* current = stack.top();
        stack.pop();
        if (current->right != nullptr) { stack.push(current->right); }
        if (current->left != nullptr) { stack.push(current->left); }
        return current;
    }

    bool isDone() override { return stack.empty(); }

    TreeNode* currentItem() override { return stack.top(); }
};
class BreadthFirstIterator : public TreeIterator {
    private:
    TreeNode* root;
    queue<TreeNode*> queue;

    public:
    BreadthFirstIterator(TreeNode* root) { this->root = root; }

    bool first() override {
        queue.push(root);
        return !queue.empty();
    }

    TreeNode* next() override {
        if (queue.empty()) { return nullptr; }
        TreeNode* current = queue.front();
        queue.pop();
        if (current->left != nullptr) { queue.push(current->left); }
        if (current->right != nullptr) { queue.push(current->right); }
        return current;
    }

    bool isDone() override { return queue.empty(); }

    TreeNode* currentItem() override { return queue.front(); }
};

// Aggregate
class BinaryTree {
    private:
    TreeNode* root;

    public:
    BinaryTree(TreeNode* root) { this->root = root; }

    TreeIterator* createDepthFirstIterator() {
        return new DepthFirstIterator(root);
    }

    TreeIterator* createBreadthFirstIterator() {
        return new BreadthFirstIterator(root);
    }
};

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    BinaryTree tree(root);

    TreeIterator* depthFirstIterator = tree.createDepthFirstIterator();
    for (depthFirstIterator->first(); !depthFirstIterator->isDone(); depthFirstIterator->next()) {
        cout << depthFirstIterator->currentItem()->val << " ";
    }
    cout << endl;

    TreeIterator* breadthFirstIterator = tree.createBreadthFirstIterator();
    for (breadthFirstIterator->first(); !breadthFirstIterator->isDone(); breadthFirstIterator->next()) {
        cout << breadthFirstIterator->currentItem()->val << " ";
    }
    cout << endl;

    delete depthFirstIterator;
    delete breadthFirstIterator;
    return 0;
}

/* Output: */
/*
1 2 4 5 3 6 7
1 2 3 4 5 6 7
*/