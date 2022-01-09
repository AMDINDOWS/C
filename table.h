#ifndef TABLE_H
#define TABLE_H

#endif //TABLE_H

enum {TBLSIZE = 20};

void int_put_tbl(int *table, int idx, int val);
void int_get_tbl(int *table, int idx, int* pval);
void tbl_dump(int *table);
