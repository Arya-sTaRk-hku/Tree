// id:112. Path Sum
// Q:)Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
// A leaf is a node with no children.
// :::::::::::::::::::::::::::::::::::::
#include <iostream>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
};


void solve(TreeNode *&root, int preSum, int &target, bool &ans)
{
    if (root == NULL)
        return;
    else if (root->left == NULL && root->right == NULL)
    {
        if (preSum + root->val == target)
            ans = true;
    }
    else
    {
        preSum += root->val;
        solve(root->left, preSum, target, ans);
        solve(root->right, preSum, target, ans);
    }
}
bool hasPathSum(TreeNode *root, int targetSum)
{
    bool ans = false;

    int preSum = 0;
    solve(root, preSum, targetSum, ans);

    return ans;
}


int main()
{
    bool ans = false;

    // enter your tree
    TreeNode *root;
    root = new TreeNode(5);
    TreeNode *r3 = new TreeNode(3);
    TreeNode *r1 = new TreeNode(1);
    TreeNode *r4 = new TreeNode(4);
    TreeNode *r0 = new TreeNode(0);
    TreeNode *r2 = new TreeNode(2);
    TreeNode *r10 = new TreeNode(10);
    TreeNode *r6 = new TreeNode(6);
    TreeNode *r12 = new TreeNode(12);
    TreeNode *r11 = new TreeNode(11);

    root->left = r3;
    root->right = r10;
    r3->left = r1;
    r3->right = r4;
    r1->left = r0;
    r1->right = r2;
    r10->left = r6;
    r10->right = r12;
    r12->left = r11;
    // tree ends

    // call function
    ans = hasPathSum(root,10);

    // show ans
    cout << ans << endl;
}
