class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > result;
        vector<int> temp;
        int sum = 0;
        if(root == NULL)
            return result;
        preOrder(root ,result ,temp ,sum ,expectNumber);	//前序遍历
        sort(result.begin(),result.end(),compare);			//按数组长度排序
        return result;
    }

    void preOrder(TreeNode* node, vector<vector<int>>& result, vector<int> temp,int sum,int expectNumber){
        temp.push_back(node -> val);
        sum = sum + node -> val;
        if(node -> left == NULL && node -> right == NULL){
            if(sum == expectNumber)
                result.push_back(temp);
            return;
        }else if(node -> left != NULL && node -> right == NULL)
            preOrder(node -> left,result,temp,sum,expectNumber);
        else if(node -> left == NULL && node -> right != NULL)
            preOrder(node -> right,result,temp,sum,expectNumber);
        else{
            preOrder(node -> left,result,temp,sum,expectNumber);
            preOrder(node -> right,result,temp,sum,expectNumber);
        }
        return;
    }

    bool static compare(vector<int> a,vector<int> b){
        return a.size() > b.size();
    }
};