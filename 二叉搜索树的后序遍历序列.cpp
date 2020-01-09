class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty())		// 测试用例规定[]空树不为二叉搜索树
            return false;
        if(sequence.size() <= 2)
            return true;

        int root = *(sequence.end() - 1);
        vector<int>::iterator middle = sequence.begin();
        while(middle != sequence.end() - 1){
            if(*middle > root)					//找到中间点，区分左子树和右子树
                break;
            ++ middle;
        }

        vector<int> leftTree(sequence.begin(),middle);	//左子树
        vector<int> rightTree(middle,sequence.end() - 1);	//右子树

        while(middle != sequence.end() - 1){		//检查右子树有没有不符合二叉搜索树的元素
            if(*middle < root)
                return false;
            ++ middle;
        }
        bool result = false;
        if(leftTree.empty())
            result = VerifySquenceOfBST(rightTree);
        else if(rightTree.empty())
            result = VerifySquenceOfBST(leftTree);
        else
            result = VerifySquenceOfBST(leftTree) && VerifySquenceOfBST(rightTree);
        return result;
    }
};