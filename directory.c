#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<stdlib.h>
#include<stdio.h>
int main(int argc, char *argv[]){
    
    DIR *dir;
    dir = opendir(argv[1]);
    struct dirent *d;
    if(dir){
        while(( d = readdir(dir)) != NULL){
            printf("%s\n",d->d_name);
        }
    }    
    closedir(dir);

    return 0;
}
