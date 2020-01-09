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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        vector<TreeNode*> ac;		//将遍历结果存到数组里，再对左右指针进行操作
        if(pRootOfTree == NULL)
            return NULL;
        inorder(pRootOfTree,ac);
        for(int i = 0;i < ac.size() - 1;++ i){
            ac[i] ->right = ac[i + 1];
            ac[i + 1] -> left = ac[i];
        }
        ac[0] ->left = NULL;
        ac[ac.size() - 1] -> right = NULL;
        return ac[0];
    }
    void inorder(TreeNode* root, vector<TreeNode*> &ac){	//中序遍历二叉树
        if(root == NULL)
            return;
        inorder(root -> left, ac);
        ac.push_back(root);
        inorder(root -> right,ac);
        return;
    }

};