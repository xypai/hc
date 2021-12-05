#include <stdio.h>

int sum(int *aa, int nlen){
    int s = 0;
    for(int i = 0; i < nlen; i++){
        printf("%d ", aa[i]);
        s += aa[i];
    }
    return s;
}

int main(){
    int aa [] = {1,2,3,4,5,6,7,8,9};
    int nlen = sizeof(aa)/sizeof(aa[0]);
    printf( "sum = %d\n", sum(aa, nlen));
    return 0;
}
