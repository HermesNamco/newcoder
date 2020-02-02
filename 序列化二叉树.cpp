class Solution {
public:
    char* Serialize(TreeNode *root) {
        treeVal.clear();
        if(root == nullptr)				//如果不判空会发生段错误
            return "^_^";
        preOrder(root);
        return "^_^";
    }
    TreeNode* Deserialize(char *str) {
        if(treeVal.empty())
            return nullptr;
        TreeNode* pHead = dePreOrder();
        return pHead;

    }
    void preOrder(TreeNode* root){			//前序遍历序列化
        treeVal.push_back(root -> val);
        if(root -> left)
            preOrder(root -> left);		
        else
            treeVal.push_back(INT_MAX);		//用INT_MAX标识空节点
        if(root -> right)
            preOrder(root -> right);
        else
            treeVal.push_back(INT_MAX);
    }
    TreeNode* dePreOrder(){				//前序遍历反序列化
        if(count == treeVal.size())
            return nullptr;
        if(treeVal[count] != INT_MAX){
            TreeNode * p = new TreeNode(treeVal[count]);
            ++ count;
            p -> left = dePreOrder();
            p -> right = dePreOrder();
            return p;
        }
        else{
            ++ count;
            return nullptr;
        }
    }
private:
    vector<int> treeVal;
    int count = 0;
};
