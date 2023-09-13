#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree3.h"

int main(void)
{
    BTreeNode * AVLRoot;
    BTreeNode * clNode;     //current left node
    BTreeNode * crNode;     //current right node
    BSTMakeAndInit(&AVLRoot);

    BSTInsert(&AVLRoot, 5); 
    BSTInsert(&AVLRoot, 2); 
    BSTInsert(&AVLRoot, 3); 


    printf("루트 노드: %d \n", GetData(AVLRoot));

    clNode = GetLeftSubTree(AVLRoot);
    crNode = GetRightSubTree(AVLRoot);
    printf("왼쪽1: %d, 오른쪽1: %d \n", GetData(clNode), GetData(crNode));

    return 0;
}