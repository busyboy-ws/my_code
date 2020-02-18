/*
@File    :   leetcode938.c
@Time    :   2020/02/18 09:30:27
@Author  :   xiaosongsong
@Desc    :   None

给定二叉搜索树的根结点 root，返回 L 和 R（含）之间的所有结点的值的和。

二叉搜索树保证具有唯一的值。

 

示例 1：

输入：root = [10,5,15,3,7,null,18], L = 7, R = 15
输出：32
示例 2：

输入：root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
输出：23
 

提示：

树中的结点数量最多为 10000 个。
最终的答案保证小于 2^31。

*/

#include <stdio.h>
#include <malloc.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
void insertNode(struct TreeNode **t, int x)
{
    if ((*t) == NULL)
    {
        (*t) = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        (*t)->val = x;
        (*t)->left = NULL;
        (*t)->right = NULL;
    }
    else if ((*t)->val > x)
    {
        insertNode(&(*t)->left, x);
    }
    else if ((*t)->val < x)
    {
        insertNode(&(*t)->right, x);
    }
}
int rangeSumBST(struct TreeNode *root, int L, int R)
{
    int sum = 0;
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        if (root->val >= L && root->val <= R)
        {
            sum += root->val;
        }
        sum += rangeSumBST(root->left, L, R);
        sum += rangeSumBST(root->right, L, R);
        return sum;
    }
}
int main()
{
    struct TreeNode *root = NULL;
    int node[] = {10, 5, 15, 3, 7, 13, 18, 1, 6};
    for (int i = 0; i < 9; i++)
        insertNode(&root, node[i]);
    printf("%d", rangeSumBST(root, 6, 10));
    return 0;
}
