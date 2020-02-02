class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)		//中序遍历递归做法，对于count的处理不尽人意
    {
        if(pRoot == nullptr)
            return nullptr;
        if(k <= 0)
            return nullptr;
        inOrder(pRoot, k);
        return result;
    }
    void inOrder(TreeNode* p, int k){
        if(p -> left)
            inOrder(p -> left, k);
        ++ count;
        if(count == k)
            result = p;
        if(p -> right)
            inOrder(p -> right, k);
    }
private:
    TreeNode* result = nullptr;
    int count = 0;
};