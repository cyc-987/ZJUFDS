#include<stdio.h>

int main()
{
    //read three number
    int m,n,k;
    scanf("%d%d%d",&m,&n,&k);
    int result[k];//store the result

    //circle k times
    int i = 0;//i counts for k
    for(i=0;i<k;i++)
    {
        //read a sequence
        int isPossible = 1;
        int j = 0;
        int num[1000];
        for(j=0;j<n;j++){
            scanf("%d",&num[j]);
        }

        //check
        int count = 0;//count the number passed
        int s = 0;//save the check point
        while(s<n)
        {
            //find the longest decend sequence
            count = 0;
            while(num[s]>=num[s+count]){
                count++;
                if(s+count==n){
                    //count--;
                    break;
                }
            }
            //check if overflow
            if(count>m){
                isPossible = 0;
                break;
            }
            //check if decend
            int temp = 1;
            for(temp=1;temp<count;temp++){
                if(num[s+temp-1]<num[s+temp]){
                    isPossible = 0;
                    break;
                }
            }
            //whether to continue
            if(isPossible){
                s = s+count;
                continue;
            }else break;
        }
        //store the result
        result[i] = isPossible;
    }
    for(i = 0;i<k;i++){
        if(result[i]){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}