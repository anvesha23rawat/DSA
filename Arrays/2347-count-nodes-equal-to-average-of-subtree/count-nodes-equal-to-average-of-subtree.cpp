/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    // TC = O(n2)
    // int result = 0;
    // int sum = 0;
    // int findSum(TreeNode* root,int &count){
    //     if(root == NULL){
    //         return 0;
    //     }
    //     count++;
    //     int LSum = findSum(root->left,count);
    //     int RSum = findSum(root->right,count);
    //     return LSum + RSum + root->val;
    // }
    // void solve(TreeNode* root){
    //     if(root == NULL) {
    //         return;
    //     }
    //     int count = 0;
    //     sum = findSum(root,count);
    //     if(root->val == sum/count){
    //         result++;
    //     }
    //     solve(root->left);
    //     solve(root->right);
    // }
    // int averageOfSubtree(TreeNode* root) {
    //     solve(root);
    //     return result;
    // }

    // TC = O(n)
    int result = 0;
    pair<int,int> solve(TreeNode* root){
        if(root == NULL){
            return {0,0};
        }
        auto p1 = solve(root->left);
        auto p2 = solve(root->right);
        int total_sum = p1.first + p2.first + root->val;
        int total_count = p1.second + p2.second + 1;
        int avg = total_sum/total_count;
        if(avg == root->val){
            result++;
        }
        return {total_sum,total_count};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return result;
    }

};