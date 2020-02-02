class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)					//笨办法
    {
        TreeLinkNode* pHead = pNode;			
        while(pHead -> next != NULL)							//找到根节点
            pHead = pHead -> next;
        vector<TreeLinkNode*> result;							//将中序遍历顺序存下来
        inorder(pHead, result);
        for(int i = 0; i < result.size(); ++ i){
            if(result[i] == pNode && i != result.size() - 1)
                return result[i + 1];
        }
        return NULL;
    }
    void inorder(TreeLinkNode* p,vector<TreeLinkNode*>& result){
            if(p -> left)
                inorder(p -> left, result);
            result.push_back(p);
            if(p -> right)
                inorder(p -> right, result);
        }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)				//高效算法，分情况讨论
    {
       if(pNode == nullptr){
            return nullptr;
        }
        TreeLinkNode* next = nullptr;
        //先右子节点的左子节点遍历
        if(pNode->right != nullptr){						//如果该节点的右子树存在，则以其右孩子为根节点向其最左节点遍历
            TreeLinkNode* rightNode  = pNode->right;
            while(rightNode->left != nullptr){
                rightNode = rightNode->left;
            }
            next = rightNode;
        }
            //向父结点遍历
        else if(pNode->next != nullptr){					//如果右孩子不存在，则判断该节点是其父节点的右孩子还是左孩子
            TreeLinkNode* parentNode = pNode->next;
            TreeLinkNode* currentNode = pNode;
            while(parentNode != nullptr  && currentNode == parentNode->right){			//如果是右孩子则再向上搜索直到找到是左孩子的情况
                currentNode = parentNode;
                parentNode = parentNode->next;
            }
            next = parentNode;
        }
        return next;										
    }
};