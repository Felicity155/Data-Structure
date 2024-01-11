
int GetAWord( FILE *fp, ElementType word )
{
	int len = 0;
	char tempword[81];/* 临时字符串，假定所有单词长度不会超过80 */
	char c;

	c = fgetc(fp);
	while( !feof( fp ) ){
		if( IsWordChar(c) )  /* 如果是合法的单词字符 */
			tempword[len++] = c;
		    c = fgetc(fp);
		    if(len && !IsWordChar(c))/* 非法的单词字符结束一个单词*/
				break;  /* 一个单词结束 */
	    }
	    tempword[len] = '\0';   /* 设定字符串结束符 */
	    if(len > KEYLENGTH){    /* 太长的单词被截断 */
		    tempword[KEYLENGTH] = '\0';
		    len = KEYLENGTH;
	    }
	    strcpy(word, tempword); /* 太长的单词被截断 */
	    return len;		
}
