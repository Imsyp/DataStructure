#include <stdio.h>
#include "BinaryTree2.h"
#include "BinarySearchTree.h"

//BST 생성 및 초기화
void BSTMakeAndInit(BTreeNode ** pRoot)
{
    *pRoot = NULL;
}

//노드에 저장된 데이터 반환
BSTData BSTGetNodeData(BTreeNode * bst)
{
    return bst->data;
}

//BST를 대상으로 데이터 저장(노드의 생성과정 포함)
void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
    BTreeNode * pNode = NULL;
    BTreeNode * cNode = *pRoot;
    BTreeNode * nNode = NULL;

    //저장 위치를 찾는 while문
    while(cNode != NULL)
    {
        if(data == GetData(cNode))
            return;

        pNode = cNode;

        if(GetData(cNode) > data)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }

    nNode = MakeBTreeNode();
    SetData(nNode, data);

    //생성된 nNode를 저장 위치에 지정
    if(pNode != NULL)
    {
        if(data < GetData(pNode))
            MakeLeftSubTree(pNode, nNode);
        else 
            MakeRightSubTree(pNode, nNode);
    }
    else
    {
        *pRoot = nNode;
    }
}

//BST를 대상으로 데이터 탐색
BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
    BTreeNode * cNode = bst;
    BSTData cd;

    while(cNode != NULL)
    {
        cd = GetData(bst);

        if(target == cd)
            return cNode;
        else if(target < cd)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }

    return NULL;
}