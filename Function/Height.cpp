// height of binary tree
#include<iostream>
#include<algorithm>
using namespace std;


/*

        1
          \
            2
          /    \
         3       4
          \
           5
  
  */

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){};
    TreeNode(int x):val(x),left(nullptr),right(nullptr){};
};

void height(TreeNode* root,int &max_depth,int level){
    if(root==NULL) return;
    max_depth = max(max_depth,level);
    if(root->left)  height(root->left,max_depth,level+1);
    if(root->right) height(root->right,max_depth,level+1);
}

int main(){

TreeNode* root = new TreeNode(5);
TreeNode* r3 = new TreeNode(3);
TreeNode* r1= new TreeNode(1);
TreeNode* r4 = new TreeNode(4);
TreeNode* r0 = new TreeNode(0);
TreeNode* r2 = new TreeNode(2);
TreeNode* r10 = new TreeNode(10);
TreeNode* r6 = new TreeNode(6);
TreeNode* r12 = new TreeNode(12);
TreeNode* r11 = new TreeNode(11);

root->left = r3;
root->right = r10;
r3->left = r1;
r3->right = r4;
r1->left = r0;
r1->right = r2;
r10->left = r6;
r10->right = r12;
r12->left = r11;


    int depth = 0;
    height(root,depth,0);
    cout<<depth<<endl;

}