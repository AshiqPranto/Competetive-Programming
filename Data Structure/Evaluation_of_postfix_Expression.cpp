#include<iostream>
#include<climits>

using namespace std;

int stack[100000],point=0,maxSize;

void push(int x)
{
    if(point==maxSize)
    {
        printf("Stack Overflow, can't add more element element to stack.\n");
        return ;
    }
    point++;
    stack[point]=x;
    return ;
}

void pop()
{
    if(point<1)
    {
        printf("Stack is empty.\n");
        return;
    }
    point--;
    return;
}

long long int top()
{
    if(point<1)
    {
        printf("Stack is empty.\n");
        return INT_MIN;
    }
    return stack[point];
}

int main()
{
    printf("------------------------------------\n");
    printf("Enter a 'Postfix Expression' like this 5,6,2,+,*,12,4,/,-\n");
    printf("Put a separator(,) after every operator and operand \n");
    printf("------------------------------------\n");
    string s;
    cin>>s;
    
    maxSize = s.size();
    for(int i=0;i<maxSize;i++)
    {
        
        if(isdigit(s[i]))
        {
            int temp = 0;
            while (isdigit(s[i]))
            {
                temp = (temp*10)+int(s[i]-'0');
                i++;
                
            }
            i--;
            push(temp);
            
        }
        else if(s[i]!=',')
        {
            int val1 = top();
            pop();
            int val2 = top();
            pop();
            switch (s[i])
            {
            case '+':
                push(val2+val1);
                break;
            case '-':
                push(val2-val1);
                break;
            case '*':
                push(val2*val1);
                break;
            case '/':
                push(val2/val1);
                break;            
            default:
                break;
            }
        }
        
    }
    printf("%lld",top());
}