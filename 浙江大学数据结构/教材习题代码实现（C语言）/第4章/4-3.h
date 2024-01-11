
int SequentialSearch (StaticTable *Tbl, ElementType K)
{ /*在表Tbl中查找关键字为K的数据元素*/
	int i;

    Tbl->Element[0] = K; /*建立哨兵*/
    for( i = Tbl->Length; Tbl->Element[i] != K; i--);
    return i; /*查找成功返回数据元素所在单元下标；查找不成功返回0*/
}
