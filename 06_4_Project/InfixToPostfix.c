#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

int GetOpPrec(char op)
{
    switch (op)
    {
    case '*':
    case '/':
        return 5;
    case '+':
    case '-':
        return 3;
    case '(':
        return 1;
    }

    return -1;
}

int WhoPrecOp(char op1, char op2)
{
    int op1Prec = GetOpPrec(op1);
    int op2Prec = GetOpPrec(op2);

    if(op1Prec > op2Prec)
        return 1;
    else if(op1Prec < op2Prec)
        return -1;
    else
        return 0;
}

void ConvToRPNExp(char exp[])
{
    Stack stack;
    int expLen = strlen(exp);
    char * convExp = (char*)malloc(expLen+1);

    int i, idx=0;
    char tok, popOp;

    memset(convExp, 0, sizeof(char)*expLen+1);  //void memset(void * ptr, int value, size_t num) -> value가 저장된 ptr 반환, 저장 실패시 NULL 반환
    StackInit(&stack);

    for(i=0; i<expLen; i++)
    {
        tok = exp[i];

        if(isdigit(tok))
            convExp[idx++] = tok;
        else
        {
            switch(tok) //tok을 스택에 넣을지, 바로 옮길지 결정하는 구문
            {
            case '(':
                SPush(&stack, tok);
                break;
            case ')':
                while(1)
                {
                    popOp = SPop(&stack);
                    if(popOp == '(')
                        break;
                    convExp[idx++] = popOp;
                }
                break;
            case '+': case '-':
            case '*': case '/':
                while(!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)  //원래 있던 연산자가 우선순위 높거나 같으면
                    convExp[idx++] = SPop(&stack);  //stack을 비운다.
                SPush(&stack, tok);
                break;
            }
        }
    }

    while(!SIsEmpty(&stack))
        convExp[idx++] = SPop(&stack);

    strcpy(exp, convExp);
    free(convExp);
}
