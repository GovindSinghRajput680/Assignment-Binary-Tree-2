#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class TreeNode{
public:    
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode (int val){
        this->val  = val;
        left = right = NULL;
    }

};
//Q-1 Diameter of Binary Tree O(n) approach using a user defined data type [LeetCode 543]
int level(TreeNode *root,int &ans){
        if(root == NULL) return 0;
        int l = level(root->left,ans);
        int r = level(root->right,ans);
        ans = max(ans,l+r);
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
       int ans = 0;
       level(root,ans);
       return ans;
    }
//Q-2 Level Order Traversal (Using Queue) [LeetCode 102]
 vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root == NULL) return v;
        queue<TreeNode*> q;
        q.push(root);
        //BFS
        while(q.size()){
            int n = q.size();
            vector<int> temp;
            for(int i =1;i<=n;i++){
                TreeNode *t = q.front();
                q.pop();
                temp.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            v.push_back(temp);
        }
        return v;
    }
//Q-3 *Level order traversal (Right to Left)
void Levelorder(TreeNode *root){
    queue<TreeNode*> q;
    q.push(root);
    while(q.size()){
        TreeNode *temp = q.front();
        cout<<temp->val<<" ";
        q.pop();
        if(temp->right) q.push(temp->right);
        if(temp->left) q.push(temp->left);
    }
}
//Q-4 Zigzag Level Order Traversal [LeetCode 103]
void Evenlevel(TreeNode *root,vector<vector<int>> &v,int i =0){
        //Base case
        if(!root) return;

        if(i%2 == 0) v[i].push_back(root->val);
        Evenlevel(root->left,v,i+1);
        Evenlevel(root->right,v,i+1);
    }
    void Oddlevel(TreeNode *root,vector<vector<int>> &v,int i =0){
        //Base case
        if(!root) return;

        if(i%2 != 0) v[i].push_back(root->val);
        Oddlevel(root->right,v,i+1);
        Oddlevel(root->left,v,i+1);
    }
    int levels(TreeNode *root){
        if(!root) return 0;
        return max(levels(root->left),levels(root->right))+1;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> v(levels(root),vector<int> {});
         Evenlevel(root,v);
         Oddlevel(root,v);
         return v;
    }
int main(){TreeNode * a= new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    TreeNode *e = new TreeNode(5);
    TreeNode *f = new TreeNode(6);
    TreeNode *g = new TreeNode(7);

    a->left = b;
    a->right =c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    Levelorder(a);


}