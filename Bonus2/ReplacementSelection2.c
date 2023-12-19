#include<stdio.h>
#include<stdlib.h>
#define MaxN 100

//data structure
struct list{
    int list[MaxN];
    long long totalNum;
    long long readCount;
};
struct ram{
    int list[MaxN];
    long long maxRam;
};

void buildHeap(int list[], long long N);
void downHeap(int list[], long long index, long long N);
void insertHeap(int list[], long long index, int insertNumber);
int deleteMinandMaintainHeap(int list[], long long N);

int main()
{
    //read firstline
    struct list mainList;
    struct ram mainRam,tempRam,run;
    scanf("%lld%lld",&mainList.totalNum,&mainRam.maxRam);getchar();
    mainList.readCount = 0; tempRam.maxRam = 0; run.maxRam = 0;

    //read numbers
    long long i = 0;
    for(;i<mainList.totalNum;i++) scanf("%d",&mainList.list[i]);

    //start rank
    int lastnumber = -32766;
    for(i=1;i<=mainRam.maxRam;i++) mainRam.list[i] = mainList.list[mainList.readCount++];//read first list of numbers
    buildHeap(mainRam.list,mainRam.maxRam);

    while(mainRam.maxRam+tempRam.maxRam){
        int getmin;
        while(mainRam.maxRam){
            //get one number
            getmin = deleteMinandMaintainHeap(mainRam.list,mainRam.maxRam);
            if(getmin > lastnumber) break;
            else{//store the number into temp ram, and decrease maxRam
                mainRam.maxRam--;
                tempRam.maxRam++;
                insertHeap(tempRam.list,tempRam.maxRam,getmin);
            }
        }

        if(mainRam.maxRam == 0){//one run is over
            //print the run
            for(i = 0;i<run.maxRam-1;i++) printf("%d ",run.list[i]);
            printf("%d",run.list[run.maxRam-1]);
            printf("\n");
            //reset to origin: copy temp ram back, reset lastnumber, reset run
            for(i = 1;i<=tempRam.maxRam;i++) mainRam.list[i] = tempRam.list[i];
            mainRam.maxRam = tempRam.maxRam;
            tempRam.maxRam = 0;
            lastnumber = -32766;
            run.maxRam = 0;
            continue;
        }


        run.list[run.maxRam++] = getmin;
        lastnumber = getmin;
        if(mainList.readCount < mainList.totalNum){
            insertHeap(mainRam.list,mainRam.maxRam,mainList.list[mainList.readCount++]);
            continue;
        }else{
            mainRam.maxRam--;
            continue;
        }
    }

    for(i = 0;i<run.maxRam-1;i++) printf("%d ",run.list[i]);
    printf("%d",run.list[run.maxRam-1]);
}

void downHeap(int list[], long long index, long long N)
{
    long long child = index*2;
    if(index > N) return;
    int temp = list[index];

    while(child <= N){
        if(child+1 <= N && list[child+1] < list[child]) child++;
        if(list[index] > list[child]) list[index] = list[child];
        else break;
        index = child;
        child = index*2;
    }
    list[index] = temp;
}

void buildHeap(int list[], long long N)
{
    long long temp = N/2+1;
    for(;temp>=1;temp--) downHeap(list,temp,N);
}

int deleteMinandMaintainHeap(int list[], long long N)
{
    int temp = list[1];
    list[1] = list[N];
    downHeap(list,1,N-1);
    return temp;
}

void insertHeap(int list[], long long index, int insertNumber)
{
    long long temp = index;
    if(index == 1){
        list[1] = insertNumber;
        return;
    }
    for(;list[temp/2] > insertNumber; temp /= 2) list[temp] = list[temp/2];
    list[temp] = insertNumber;
}