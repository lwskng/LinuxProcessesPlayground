//думаю, так гораздо наглядней, для людей :) в т.ч. ответ на вопрос ниже (UPD!)
#include <cstdio>
#include <cstdlib>
#include <unistd.h>

int main(int argc, char **argv)
{
    char buf[128];
    int i,j=1;
    printf("%d\n", getpid());

    sprintf(buf, "pstree -p %d", getpid() );

    for(i=0; i!=3; i++)
        if(fork()==0){
            printf("%d\tI'm child [%d]\n", getpid(), i+1);
            break;
        }
        else  j=0;
    if(j==1){
        printf("%d\tHello! I'm parent!\n", getpid());
        system(buf);
    }
    scanf("%d", &i);
}