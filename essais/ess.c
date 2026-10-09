#include<string.h>
#include <stdio.h>
void swap(void *a, void *b, size_t size){
    unsigned *p=(unsigned char *)a;
    unsigned *d=(unsigned char *)b;
    unsigned tmp;
    for(size_t i=0;i<size;i++){
        tmp=p[i];
        p[i]=d[i];
        d[i]=tmp;
    }
}
/*permet generalise la swap pour different type  */

