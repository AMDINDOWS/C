#include "table.h"  // Provides TBLSIZE
#include <stdio.h>
#include <errno.h>


// insert val into table at index idx
void int_put_tbl(int* table, int idx, int val)
{
    if(!table || (idx >= TBLSIZE) || (idx<0)){ //it was also taking negative indexes to store values.
        errno = EINVAL;
        return;
    }
    
    *(table + idx) = val;
}

// get value present in table at index idx into
// the address pointed by pval
void int_get_tbl(int* table, int idx, int* pval)
{
    if(!table || !pval || (idx >= TBLSIZE) || (idx<0) ){ // giving output of 0 at negative indexes.
        errno = EINVAL;
        return;
    }
    
    *pval = *(table + idx);
}


// dump the contents of the table to stdout
void tbl_dump(int* table){
    printf("===========================================================================\n");
    printf("TABLE DUMP\n");
    for(int i=0;i<TBLSIZE;i++){
        printf("%d : %d\n",i,table[i]);
    }
    printf("===========================================================================\n");
}
