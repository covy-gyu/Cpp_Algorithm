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
    int Index = strlen(PostfixExpression) - 1;  // 마지막 문자 위치에서 시작
    ET_BuildExpressionTreeHelper(PostfixExpression, Node, Index);
}

void ET_BuildExpressionTreeHelper(const char* PostfixExpression, ETNode** Node, int& Index)
{
    if (Index < 0) return;  // 문자열 끝에 도달하면 종료

    char Token = PostfixExpression[Index--];

    // 연산자인 경우
    if (Token == '+' || Token == '-' || Token == '*' || Token == '/') {
        *Node = ET_CreateNode(Token);

        // 재귀적으로 오른쪽과 왼쪽 자식을 설정
        ET_BuildExpressionTreeHelper(PostfixExpression, &(*Node)->Right, Index);
        ET_BuildExpressionTreeHelper(PostfixExpression, &(*Node)->Left, Index);
    }
    else {
        // 피연산자인 경우 노드를 생성하고 설정
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
        /* 연산자인 경우 */
        case '+': case '-': case '*': case '/':
            Left = ET_Evaluate(Tree->Left);
            Right = ET_Evaluate(Tree->Right);

            if (Tree->Data == '+') Result = Left + Right;
            else if (Tree->Data == '-') Result = Left - Right;
            else if (Tree->Data == '*') Result = Left * Right;
            else if (Tree->Data == '/') Result = Left / Right;

            break;

        /* 피연산자인 경우 */
        default:
            memset(Temp, 0, sizeof(Temp));
            Temp[0] = Tree->Data;
            Result = atof(Temp);
            break;
    }

    return Result;
}
