#include <stdio.h>
#include "AVLRebalance.h"

int GetHeight(BTreeNode * bst)
{
    int leftH;
    int rightH;

    if(bst == NULL)
        return 0;

    leftH = GetHeight(GetLeftSubTree(bst));
    rightH = GetHeight(GetRightSubTree(bst));

    if(leftH > rightH)
        return leftH + 1;
    else
        return rightH + 1;
}

int GetHeightDiff(BTreeNode * bst)
{
    int lsh;    //left sub tree height
    int rsh;    //right sub tree height

    if(bst == NULL)
        return 0;
    
    lsh = GetHeight(GetLeftSubTree(bst));
    rsh = GetHeight(GetRightSubTree(bst));
    return lsh - rsh;
}

BTreeNode * RotateLL(BTreeNode * bst)
{
    BTreeNode * pNode;
    BTreeNode * cNode;

    pNode = bst;
    cNode = GetLeftSubTree(pNode);

    ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
    ChangeRightSubTree(cNode, pNode);

    return cNode;
}

BTreeNode * RotateRR(BTreeNode * bst)
{
    BTreeNode * pNode;
    BTreeNode * cNode;

    pNode = bst;
    cNode = GetRightSubTree(pNode);

    ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
    ChangeLeftSubTree(cNode, pNode);

    return cNode;
}

BTreeNode * RotateLR(BTreeNode * bst)
{
    BTreeNode * pNode;
    BTreeNode * cNode;

    pNode = bst;
    cNode = GetLeftSubTree(pNode);

    ChangeLeftSubTree(pNode, RotateRR(cNode));  //부분적 RR회전
    return RotateLL(pNode);
}

BTreeNode * RotateRL(BTreeNode * bst)
{
    BTreeNode * pNode;
    BTreeNode * cNode;

    pNode = bst;
    cNode = GetRightSubTree(pNode);

    ChangeRightSubTree(pNode, RotateLL(cNode));  //부분적 LL회전
    return RotateRR(pNode);
}

BTreeNode * Rebalance(BTreeNode ** pRoot)
{
    int hDiff = GetHeightDiff(*pRoot);

    //균형 인수가 +2 이상이면 LL상태 or LR상태
    if(hDiff > 1)
    {
        if(GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)
            *pRoot = RotateLL(*pRoot);
        else
            *pRoot = RotateLR(*pRoot);
    }

    if(hDiff < -1)
    {
        if(GetHeightDiff(GetRightSubTree(*pRoot)) < 0)
            *pRoot = RotateRR(*pRoot);
        else
            *pRoot = RotateRL(*pRoot);
    }

    return *pRoot;
}