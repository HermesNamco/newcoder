class Solution {
public:
    int count = 0;
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot == NULL)
            return true;
        bool result = check(pRoot -> left, pRoot -> right);
        return result;
    }
    bool check(TreeNode* Lroot, TreeNode* Rroot){
        if(Lroot == nullptr && Rroot != nullptr)
            return false;
        if(Lroot != nullptr && Rroot == nullptr)
            return false;
        if(Lroot == nullptr && Rroot == nullptr)
            return true;
        bool flag = (Lroot -> val == Rroot -> val);
        return flag && check(Lroot -> left,Rroot -> right) && check(Lroot -> right,Rroot -> left);
    }
};