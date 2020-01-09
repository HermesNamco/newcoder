/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> list;		//树的广度优先遍历，循环方法采用队列实现
        if(root == NULL)
            return result;

        list.push(root);
        while(!list.empty()){
            TreeNode* node = list.front();
            result.push_back(node -> val);
            list.pop();
            if(node -> left != NULL)
                list.push(node -> left);
            if(node -> right != NULL)
                list.push(node -> right);
        }
        return result;
    }
};