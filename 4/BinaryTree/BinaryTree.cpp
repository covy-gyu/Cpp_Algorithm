#include "BinaryTree.h"

SBTNode* SBT_CreateNode(ElementType NewData)
{
    SBTNode* NewNode = new SBTNode;
    NewNode->Left = NULL;
    NewNode->Right = NULL;
    NewNode->Data = NewData;

    return NewNode;
}

void SBT_DestroyNode(SBTNode* Node)
{
    delete Node;
}

void SBT_DestroyTree(SBTNode* Root)
{
    if (Root == NULL)
        return;
    /* 왼쪽 하위 트리 소멸 */
    SBT_DestroyTree(Root->Left);

    /* 오른쪽 하위 트리 소멸 */
    SBT_DestroyTree(Root->Right);

    /* 루트 노드 소멸 */
    SBT_DestroyNode(Root);
}

void SBT_PreorderPrintTree(SBTNode* Node)
{
    if (Node == NULL)
        return;

    /* 루트 노드 출력 */
    printf(" %c", Node->Data);

    /* 왼쪽 하위 트리 출력 */
    SBT_PreorderPrintTree(Node->Left);

    /* 오른쪽 하위 트리 출력 */
    SBT_PostorderPrintTree(Node->Right);
}

void SBT_InorderPrintTree(SBTNode* Node)
{
    if (Node == NULL)
        return;

    /* 왼쪽 하위 트리 출력 */
    SBT_InorderPrintTree(Node->Left);

    /* 루트 노드 출력 */
    printf(" %c", Node->Data);

    /* 오른쪽 하위 트리 출력 */
    SBT_InorderPrintTree(Node->Right);
}

void SBT_PostorderPrintTree(SBTNode* Node)
{
    if (Node == NULL)
        return;

    /* 왼쪽 하위 트리 출력 */
    SBT_PostorderPrintTree(Node->Left);

    /* 오른쪽 하위 트리 출력 */
    SBT_PostorderPrintTree(Node->Right);

    /* 루트 노드 출력 */
    printf(" %c", Node->Data);
}
