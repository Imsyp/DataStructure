#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree3.h"
#include "BinarySearchTree2.h"

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
        cd = GetData(cNode);

        if(target == cd)
            return cNode;
        else if(target < cd)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }

    return NULL;
}

BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target) 
{
    BTreeNode * pVRoot = MakeBTreeNode();
    BTreeNode * pNode = pVRoot;
    BTreeNode * cNode = *pRoot;
    BTreeNode * dNode;

    ChangeRightSubTree(pVRoot, *pRoot); //루트 노드가 삭제될 경우를 대비하여 루트 노드의 pNode를 지정

    while(cNode != NULL && GetData(cNode) != target)
    {
        pNode = cNode;
        if(target < GetData(cNode))
            cNode = GetLeftSubTree(cNode);
        else 
            cNode = GetRightSubTree(cNode);
    }

    if(cNode == NULL)
        return NULL;
    
    dNode = cNode;

    //Case 1.
    if(GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
    {
        if(GetLeftSubTree(pNode) == dNode)
            RemoveLeftSubTree(pNode);
        else
            RemoveRightSubTree(pNode);
    }
    //Case 2.
    else if(GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
    {
        BTreeNode * dcNode;

        if(GetLeftSubTree(dNode) != NULL)
            dcNode = GetLeftSubTree(dNode);
        else
            dcNode = GetRightSubTree(dNode);

        if(GetLeftSubTree(pNode) == dNode)
            ChangeLeftSubTree(pNode, dcNode);
        else
            ChangeRightSubTree(pNode, dcNode);
    }
    //Case 3.
    else
    {
        BTreeNode * mNode = GetRightSubTree(dNode);
        BTreeNode * mpNode = dNode;
        int delData;

        while(GetLeftSubTree(mNode) != NULL)
        {
            mpNode = mNode;
            mNode = GetLeftSubTree(mNode);
        }

        delData = GetData(dNode);
        SetData(dNode, GetData(mNode)); //루트 노드에 대체 노드 데이터 저장

        // 대체 노드의 부모 노드와 자식 노드 연결
        if(GetLeftSubTree(mpNode) == mNode) //while을 한 바퀴라도 돈 경우!!
            ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
        else                                //while을 한 바퀴도 돌지 않은 경우!!
            ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

        dNode = mNode;
        SetData(dNode, delData);
    }

    //삭제된 노드가 루트 노드일 때 추가적인 처리
    if(GetRightSubTree(pVRoot) != *pRoot)
        *pRoot = GetRightSubTree(pVRoot);

    free(pVRoot);
    
    return dNode;
}




void ShowIntData(int data)
{
    printf("%d ",data);
}

void BSTShowAll(BTreeNode * bst)
{
    InorderTraverse(bst, ShowIntData);
}