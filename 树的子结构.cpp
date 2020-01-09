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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool result = false;
        bool result_left = false;
        bool result_right = false;
        
        if(pRoot2 == NULL)
            return false;
        if(pRoot1 == NULL)
            return false;
        
        if(pRoot1 -> val == pRoot2 -> val){		//根节点匹配，分别检查左右子树
            result_left = examTree(pRoot1 -> left,pRoot2 -> left);
            result_right = examTree(pRoot1 -> right,pRoot2 -> right);
            result = result_left && result_right;
        }
        if( result == false)		//根节点不匹配，检查pRoot1左子树
            result = HasSubtree(pRoot1 -> left,pRoot2);
        if( result == false)		//根节点不匹配，检查pRoot1右子树
            result = HasSubtree(pRoot1 -> right,pRoot2);
        return result;
    }
    
    bool examTree(TreeNode* p1,TreeNode* p2){
        if(p1 == NULL && p2 != NULL)
            return false;
        else if(p1 != NULL && p2 == NULL)
            return true;
        else if(p1 == NULL && p2 == NULL)
            return true;
        
        if(p1 -> val == p2 -> val){		//递归检查左右子树
            return examTree(p1 -> left,p2 -> left) && examTree(p1 -> right,p2 -> right);
        }else
            return false;
    }
};