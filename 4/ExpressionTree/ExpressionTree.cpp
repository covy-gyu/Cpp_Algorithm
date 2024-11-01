#include "ExpressionTree.h"

ETNode* ET_CreateNode(ElementType NewData)
{
    ETNode* NewNode = new ETNode;
    NewNode->Left = NULL;
    NewNode->Right = NULL;
    NewNode->Data = NewData;

    return NewNode;
}

void ET_DestroyNode(ETNode* Node)
{
    delete Node;
}

void ET_DestroyTree(ETNode* Root)
{
    if (Root == NULL)
        return;

    ET_DestroyTree(Root->Left);
    ET_DestroyTree(Root->Right);
    ET_DestroyNode(Root);
}

void ET_PreorderPrintTree(ETNode* Node)
{
    if (Node == NULL)
        return;

    printf(" %c", Node->Data);
    ET_PreorderPrintTree(Node->Left);
    ET_PreorderPrintTree(Node->Right);
}

void ET_InorderPrintTree(ETNode* Node)
{
    if (Node == NULL)
        return;

    printf("(");
    ET_InorderPrintTree(Node->Left);

    printf("%c", Node->Data);

    ET_InorderPrintTree(Node->Right);
    printf(")");
}

void ET_PostorderPrintTree(ETNode* Node)
{
    if (Node == NULL)
        return;

    ET_PostorderPrintTree(Node->Left);
    ET_PostorderPrintTree(Node->Right);
    printf(" %c", Node->Data);
}

void ET_BuildExpressionTree(const char* PostfixExpression, ETNode** Node)
{
    int Index = strlen(PostfixExpression) - 1;  // ������ ���� ��ġ���� ����
    ET_BuildExpressionTreeHelper(PostfixExpression, Node, Index);
}

void ET_BuildExpressionTreeHelper(const char* PostfixExpression, ETNode** Node, int& Index)
{
    if (Index < 0) return;  // ���ڿ� ���� �����ϸ� ����

    char Token = PostfixExpression[Index--];

    // �������� ���
    if (Token == '+' || Token == '-' || Token == '*' || Token == '/') {
        *Node = ET_CreateNode(Token);

        // ��������� �����ʰ� ���� �ڽ��� ����
        ET_BuildExpressionTreeHelper(PostfixExpression, &(*Node)->Right, Index);
        ET_BuildExpressionTreeHelper(PostfixExpression, &(*Node)->Left, Index);
    }
    else {
        // �ǿ������� ��� ��带 �����ϰ� ����
        *Node = ET_CreateNode(Token);
    }
}

double ET_Evaluate(ETNode* Tree)
{
    char Temp[2];

    double Left = 0;
    double Right = 0;
    double Result = 0;

    if (Tree == NULL)
        return 0;

    switch (Tree->Data)
    {
        /* �������� ��� */
        case '+': case '-': case '*': case '/':
            Left = ET_Evaluate(Tree->Left);
            Right = ET_Evaluate(Tree->Right);

            if (Tree->Data == '+') Result = Left + Right;
            else if (Tree->Data == '-') Result = Left - Right;
            else if (Tree->Data == '*') Result = Left * Right;
            else if (Tree->Data == '/') Result = Left / Right;

            break;

        /* �ǿ������� ��� */
        default:
            memset(Temp, 0, sizeof(Temp));
            Temp[0] = Tree->Data;
            Result = atof(Temp);
            break;
    }

    return Result;
}
