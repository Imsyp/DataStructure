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

    printf("루트 노드: %d \n", GetData(AVLRoot));

    clNode = GetLeftSubTree(AVLRoot);
    crNode = GetRightSubTree(AVLRoot);
    printf("왼쪽1: %d, 오른쪽1: %d \n", GetData(clNode), GetData(crNode));

    clNode = GetLeftSubTree(clNode);
    crNode = GetRightSubTree(crNode);
    printf("왼쪽2: %d, 오른쪽2: %d \n", GetData(clNode), GetData(crNode));

    clNode = GetLeftSubTree(clNode);
    crNode = GetRightSubTree(crNode);
    printf("왼쪽3: %d, 오른쪽3: %d \n", GetData(clNode), GetData(crNode));

    clNode = GetLeftSubTree(clNode);
    crNode = GetRightSubTree(crNode);
    printf("왼쪽4: %d, 오른쪽4: %d \n", GetData(clNode), GetData(crNode));

    return 0;
}