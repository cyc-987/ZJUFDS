#include<stdio.h>

//some functions for stack
void push(long stack[], int *top, long value)
{
    stack[*top] = value;
    (*top)++;
}

long pop(long stack[], int *top)
{
    (*top)--;
    return stack[*top];
}

int main()
{
    //scan N
    int N;
    scanf("%d", &N);

    //initialize two stacks
    long stack1[1000];
    long stack2[1000];
    int top1 = 0;
    int top2 = 0;

    //start read every line
    int i;
    for(i=0;i<N;i++)
    {
        //scan operation code
        char op;
        scanf(" %c", &op);
        if(op == 'I')
        {
            //read one value
            long value;
            scanf("%ld", &value);
            //push to s1
            push(stack1, &top1, value);
        }else{
            //set count
            int count = 0;
            //check s2
            if(top2 == 0){
                //check s1
                if(top1 == 0){
                    //no value
                    printf("ERROR\n");
                }else{
                    //pop all value from s1 to s2
                    long temp;
                    while(top1 > 0){
                        temp = pop(stack1, &top1);
                        count++;
                        push(stack2, &top2, temp);
                        count++;
                    }
                    //pop one value from s2
                    temp = pop(stack2, &top2);
                    count++;
                    printf("%ld %d\n", temp,count);
                }
            }else{
                //pop one value from s2
                long temp = pop(stack2, &top2);
                count++;
                printf("%ld %d\n", temp,count);
            }
        }
    }
}