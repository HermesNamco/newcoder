/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(vin.empty())			//递归结束条件
            return NULL;
        TreeNode* head = new TreeNode(pre[0]);
        int headNum = pre[0];
        int count = 0;
        for(int i = 0;i < vin.size();++ i){		//找到中序数组中的根节点位置
            if(vin[i] == headNum){
                count = i;
                break;
            }
        }
        //TreeNode* leftNode = new TreeNode(pre[1]);
        //TreeNode* rightNode = new TreeNode(pre[1 + count]);
        //head -> left = leftNode;
        //head -> right = rightNode;
        vector<int> left_preTree;
        vector<int> left_vinTree;
        vector<int> right_preTree;
        vector<int> right_vinTree;
        
        //copy(pre.begin() + 1,pre.begin() + count,preTree.begin());
        //copy(vin.begin(),vin.begin() + count - 1,vinTree.begin());
        for(int i = 0;i < count;i++)		//该循环和copy作用等同
        {
 
            left_vinTree.push_back(vin[i]);
            left_preTree.push_back(pre[i+1]);//前序第一个为根节点
        }
        head -> left = reConstructBinaryTree(left_preTree,left_vinTree);	//递归实现
        
        for(int i = count+1;i < vin.size();i++)			
        {
            right_vinTree.push_back(vin[i]);
            right_preTree.push_back(pre[i]);
        }
        //copy(pre.begin() + 1 + count,pre.end() - 1,preTree.begin());
        //copy(vin.begin() + count + 1,vin.end() - 1,vinTree.begin());
        head -> right = reConstructBinaryTree(right_preTree,right_vinTree);
        
        return head;
    }
};