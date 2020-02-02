class Solution {
public:
    int TreeDepth(TreeNode* pRoot)		
    {
        int depth = 0;
        depth = searchD(pRoot , depth);
        return depth;
    }
    int searchD(TreeNode* pRoot, int depth){		//树结构的简单递归搜索
        if(pRoot == NULL)
            return depth;
        ++ depth;
        int rightD = searchD(pRoot->right,depth);
        int leftD = searchD(pRoot->left,depth);
        return rightD > leftD ? rightD : leftD;
    }
};