#ifndef __TABLE_H__
#define __TABLE_H__

#include "Slot.h"

#define MAX_TBL     100

typedef int HashFunc(Key k);        //책에 잘못 써있음, 아래에서 HashFunc을 받을 때 *를 이용하기 때문에 여기선 그냥 함수의 형태로 와야 함
/***
typedef int HashFunc(Key k);

위와 같은 선언에 대해서는 이후에 아래와 같이 이용할 수 있음

MyHashFunc이라는 함수가 선언되었다고 가정

HashFunc * f = MyHashFunc
혹은 MyFunc(HashFunc * f); 형태로 매개변수로도 받을 수 있음
 ***/

typedef struct _table
{
    Slot tbl[MAX_TBL];
    HashFunc * hf;
} Table;

void TBLInit(Table * pt, HashFunc * f);

void TBLInsert(Table * pt, Key k, Value v);

Value TBLDelete(Table * pt, Key k);

Value TBLSearch(Table * pt, Key k);

#endif