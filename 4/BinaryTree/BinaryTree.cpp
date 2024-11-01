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
    /* ���� ���� Ʈ�� �Ҹ� */
    SBT_DestroyTree(Root->Left);

    /* ������ ���� Ʈ�� �Ҹ� */
    SBT_DestroyTree(Root->Right);

    /* ��Ʈ ��� �Ҹ� */
    SBT_DestroyNode(Root);
}

void SBT_PreorderPrintTree(SBTNode* Node)
{
    if (Node == NULL)
        return;

    /* ��Ʈ ��� ��� */
    printf(" %c", Node->Data);

    /* ���� ���� Ʈ�� ��� */
    SBT_PreorderPrintTree(Node->Left);

    /* ������ ���� Ʈ�� ��� */
    SBT_PostorderPrintTree(Node->Right);
}

void SBT_InorderPrintTree(SBTNode* Node)
{
    if (Node == NULL)
        return;

    /* ���� ���� Ʈ�� ��� */
    SBT_InorderPrintTree(Node->Left);

    /* ��Ʈ ��� ��� */
    printf(" %c", Node->Data);

    /* ������ ���� Ʈ�� ��� */
    SBT_InorderPrintTree(Node->Right);
}

void SBT_PostorderPrintTree(SBTNode* Node)
{
    if (Node == NULL)
        return;

    /* ���� ���� Ʈ�� ��� */
    SBT_PostorderPrintTree(Node->Left);

    /* ������ ���� Ʈ�� ��� */
    SBT_PostorderPrintTree(Node->Right);

    /* ��Ʈ ��� ��� */
    printf(" %c", Node->Data);
}
