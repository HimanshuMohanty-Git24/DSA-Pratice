#include <stdio.h>

#include <conio.h>

#include <string.h>

int steck[10];

int top = -1;

void push(int value)

{

    steck[top++] = value;
}

int pop()

{

    return (steck[top--]);
}

int ope(char c)

{

    if (c == '+' || c == '-' || c == '*' || c == '/')

        return 1;

    else

        return 0;
}

void main()

{

    char prefix[10];

    int len, val, i, opr1, opr2, res;

    printf("Enter the prefix Expression: ");

    scanf("%s", prefix);

    len = strlen(prefix);

    for (i = len - 1; i >= 0; i--)

    {

        switch (ope(prefix[i]))

        {

        case 0:

            val = prefix[i];

            push(val);

            break;

        case 1:
            opr1 = pop();

            opr2 = pop();

            switch (prefix[i])

            {

            case '+':
                res = opr1 + opr2;

                break;

            case '-':
                res = opr1 - opr2;

                break;

            case '*':
                res = opr1 * opr2;

                break;

            case '/':
                res = opr1 / opr2;

                break;
            }

            push(res);
        }
    }

    printf("Result is %d", steck[top]);
}
