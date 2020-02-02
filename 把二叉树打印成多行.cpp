/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {			//二叉树广度优先遍历的非递归实现
																//广度优先遍历的递归实现网上未找到，有博客说递归实现很拙劣，或无法实现
            vector<vector<int>> result;							//深度优先搜索的非递归实现用栈即可，递归实现即前序遍历
            queue<TreeNode*> btree;
            if(pRoot == nullptr)
                return result;
            btree.push(pRoot);
            
            while(!btree.empty()){
                vector<int> temp;
                int size = btree.size();
                for(int i = 0;i < size;++ i){
                    TreeNode* node = btree.front();
                    temp.push_back(node -> val);
                    if(node -> left)
                        btree.push(node -> left);
                    if(node -> right)
                        btree.push(node -> right);
                    btree.pop();
                }
                result.push_back(temp);
            }
            return result;
        }
    
};