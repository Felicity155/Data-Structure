
/* 分离链接法散列表.h文件 */

#define KEYLENGTH 15            /* 关键词字符串的长度不超过 15 */
typedef char ElementType[KEYLENGTH+1]; /* 关键词类型用字符串 */

typedef unsigned int Index;
#ifndef _HashSep_H
#define _HashSep_H

struct ListNode;
typedef struct ListNode *Position, *List;
struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable( int TableSize );
void DestroyTable( HashTable H );
Position Find( ElementType Key, HashTable H );
void Insert( ElementType Key, HashTable H );
/* 省略Delete 和 MakeEmpty 等函数 */

#endif  /* _HashSep_H */

/* 以下定义放入源程序中 */
#define Error( Str )        fprintf( stderr, "%s\n", Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )

#define MinTableSize (10)
struct ListNode{
	ElementType Element;
	unsigned short Times;  /* 词频统计应用实例中用于出现次数 */
	Position Next;
};
/*  为了简单起见，单链表的头结点就是散列表数组元素 */
struct HashTbl{
	int TableSize;
	List TheLists;
};
