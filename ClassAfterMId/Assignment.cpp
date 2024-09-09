#include<stdio.h>
#include<string.h>

#define n 100  
char stk[n];   
int top = -1;  

void push(char x)
{
    if (top >= n - 1)
    {
        printf("\nStack Overflow\n");
    }
    else
    {
        top++;
        stk[top] = x;
    }
}

char pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow\n");
        return -1;  
    }
    else
    {
        return stk[top--];
    }
}

char pair(char c)
{
    if (c == ')')
        return '(';
    else if (c == '}')
        return '{';
    else
        return '[';
}

int main()
{
    int i;
    char x;
    char exp[50];

    printf("Enter Bracket: ");
    scanf("%s", exp);

    for (i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') //check opening 
        {
            push(exp[i]); //string a push korbe
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') //check closing
        {
            if (top == -1) // top jodi faka hoy
            {
                printf("Empty\n");
               
            }
            else {
                x = pair(exp[i]);  //corrosponding opening bracket
                if (pop() != x) //jodi na pay 
                 {
                    printf("Not Balanced\n");
                   
                }
            }
        }
    }

    if (top != -1) / sorboses ekhon string jodi empty na hoy
    {  
        printf("Not Balanced");
    }
    else //jodi hoy tahole ballance
     {
        printf("Balanced!\n");
    }

    return 0;
}
