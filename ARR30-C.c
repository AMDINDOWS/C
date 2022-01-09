#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "table.h"


enum {
    OP_INS=1,
    OP_GET,
    OP_DUMP,
    OP_EXIT
};

int main()
{
    int table[20] = {0};
    printf("===========================================================================\n");
    printf("USAGE\n");
    printf("1, index, value: put value at index\n");
    printf("2, index: get value from index\n");
    printf("3: dump the table\n");
    printf("4: exit\n");
    printf("===========================================================================\n");
    char input[30] = {0};
    int op = 0, idx = 0, val = 0;
    
    while(1){
        printf(">>> ");
        if(!fgets(input,30,stdin)){
            if(ferror(stdin)){
                printf("Error reading input\n");
                continue;
            }
        }
        
        op = 0;
        if(sscanf(input,"%d",&op)!=1){
            printf("Error parsing input\n");
        }
        
        errno = 0;
        switch(op){
            case(OP_INS):{
                printf("OP 1\n");
                idx = 0;
                val = 0;
                if(sscanf(input,"%d, %d, %d",&op,&idx,&val)!=3){
                    printf("Error parsing input\n");
                }
                errno = 0;
                int_put_tbl(table, idx, val);
                if(errno){
                    printf("Error while inserting %d into table at index %d\n",val,idx);
                }
                break;
            }
            case(OP_GET):{
                printf("OP 2\n");
                idx = 0;
                if(sscanf(input,"%d, %d",&op,&idx)!=2){
                    printf("Error parsing input\n");
                }
                int_get_tbl(table, idx, &val);
                if(errno){
                    printf("Error while retrieving data from the table at index %d\n",idx);
                    break;
                }
                printf(">>> table[%d] = %d\n",idx,val);
                break;
            }
            case(OP_DUMP):{
                tbl_dump(table);
                break;
            }
            case(OP_EXIT):{
                exit(0);
            }
            default:{
                printf("Unsupported operation %d\n",op);
            }
        }
    }
}
