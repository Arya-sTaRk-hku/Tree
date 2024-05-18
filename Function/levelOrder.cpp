#include <iostream>
#include <vector>

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

void levelOrder(TreeNode *root, vector<vector<int>> &v, int level)
{
    if (root == NULL)
        return;

    v[level].push_back(root->val);
    if (root->left)
        levelOrder(root->left, v, level + 1);
    if (root->right)
        levelOrder(root->right, v, level + 1);
}

int main()
{
    TreeNode* root;
    //insert tree here
    
    //end
    
    vector<vector<int>> v(6); // keep this vector long enough to store all level
    levelOrder(root, v, 0);

    for (auto x : v)
    {
        for (auto key : x)
            cout << key << " ";
        cout << endl;
    }
}