
/* 平方探测法散列表.h文件 */
typedef int ElementType;  /* 关键词类型用整型 */

#ifndef _HashQuad_H
#define _HashQuad_H

typedef unsigned int Index; /* 散列地址类型 */
typedef Index Position;     /* 数据所在位置与散列地址是同一类型 */

struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable( int TableSize );
void DestroyTable( HashTable H );
Position Find( ElementType Key, HashTable H );
void Insert( ElementType Key, HashTable H );
ElementType Retrieve( Position P, HashTable H );
HashTable Rehash( HashTable H );
/* 省略了Delete 和 MakeEmpty 等函数 */

#endif  /* _HashQuad_H */

/* 以下定义放入源程序中 */
#define Error( Str )      fprintf( stderr, "%s\n", Str )
#define FatalError( Str ) fprintf(stderr, "%s\n", Str ), exit( 1 )
#define MinTableSize (10)
enum EntryType { Legitimate, Empty, Deleted };

struct HashEntry{
	ElementType Element;
	enum EntryType Info;
};

typedef struct HashEntry Cell;
        
struct HashTbl{
	int TableSize;
	Cell *TheCells;
    /* 单元 *TheCells 是一个数组，每个元素是 HashEntry*/
    /* 随后分配存储 */
};
