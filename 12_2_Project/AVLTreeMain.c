#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree3.h"

int main(void)
{
    BTreeNode * AVLRoot;
    BTreeNode * clNode;     //current left node
    BTreeNode * crNode;     //current right node
    BSTMakeAndInit(&AVLRoot);

    BSTInsert(&AVLRoot, 1); 
    BSTInsert(&AVLRoot, 2); 
    BSTInsert(&AVLRoot, 3); 
    BSTInsert(&AVLRoot, 4); 
    BSTInsert(&AVLRoot, 5); 
    BSTInsert(&AVLRoot, 6); 
    BSTInsert(&AVLRoot, 7); 
    BSTInsert(&AVLRoot, 8); 
    BSTInsert(&AVLRoot, 9); 

    printf("��Ʈ ���: %d \n", GetData(AVLRoot));

    clNode = GetLeftSubTree(AVLRoot);
    crNode = GetRightSubTree(AVLRoot);
    printf("����1: %d, ������1: %d \n", GetData(clNode), GetData(crNode));

    clNode = GetLeftSubTree(clNode);
    crNode = GetRightSubTree(crNode);
    printf("����2: %d, ������2: %d \n", GetData(clNode), GetData(crNode));

    clNode = GetLeftSubTree(clNode);
    crNode = GetRightSubTree(crNode);
    printf("����3: %d, ������3: %d \n", GetData(clNode), GetData(crNode));

    clNode = GetLeftSubTree(clNode);
    crNode = GetRightSubTree(crNode);
    printf("����4: %d, ������4: %d \n", GetData(clNode), GetData(crNode));

    return 0;
}