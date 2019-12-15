#include<stdio.h>
enum month {jan,feb,mart,apr,may,jun,july,aug,sep,oct,nov,dec};


int interval(enum month m1,enum month m2){
    int res = m2-m1;
    return res;
}


int main(){
    int res = interval(jan,feb);
    printf("%d ",res);

    return 0;
}

