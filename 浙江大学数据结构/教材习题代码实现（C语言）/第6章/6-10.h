
void Kruskal ( Graph G )
{   
	T = {空集};
    while  ( T 中收集的边不到n 1条 && 原图的边集E非空 ) {
        从E中选择最小代价边(v, w); /* 引入最小堆完成 */
        从E中删除此边(v, w);
        if  ( (v, w)的选取不在T中构成回路 ) /* 此判断由并查集的Find完成 */
	        将(v, w)加入T ; /* 此步由并查集的Union完成 */
        else     
	        彻底丢弃(v, w) ;
    } /* 结束while */
    if  ( T 中收集的边不到n 1条 )
       printf( "图不连通" ) ;
}
