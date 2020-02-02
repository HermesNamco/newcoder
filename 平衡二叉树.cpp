class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {		//平衡二叉树判断即判断左右子树高度差是否小于1
        bool flag = true;							//代码完全基于二叉树深度题目代码改动
        searchD(pRoot ,0 ,flag);
        return flag;
    }
    int searchD(TreeNode* pRoot, int depth ,bool &flag){
        if(pRoot == NULL)
            return depth;
        ++ depth;
        int rightD = searchD(pRoot->right,depth,flag);
        int leftD = searchD(pRoot->left,depth,flag);
        if(rightD - leftD >= 2 || rightD - leftD <= -2)
            flag = false;
        return rightD > leftD ? rightD : leftD;
    }
};