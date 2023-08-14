#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

int EvalRPNExp(char exp[])
{
    Stack stack;
    int expLen = strlen(exp);

    int i;
    char tok, op1, op2;

    StackInit(&stack);

    for(i=0; i<expLen; i++)
    {
        tok = exp[i];

        if(isdigit(tok))
            SPush(&stack, tok - '0'); // '0'ÀÇ ¾Æ½ºÅ° ÄÚµå¸¦ »¬¼À
        else
        {
            op1 = SPop(&stack);
            op2 = SPop(&stack);
            switch (tok)
            {
            case '+':
                SPush(&stack, op2 + op1);
                break;
            case '-':
                SPush(&stack, op2 - op1);
                break;
            case '*':
                SPush(&stack, op2 * op1);
                break;
            case '/':
                SPush(&stack, op2 / op1);
                break;
            default:
                break;
            }
        }
    }

    int result = SPop(&stack);

    return result;
}