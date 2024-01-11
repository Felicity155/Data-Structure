
static int NextPrime( int N )
{   /* ¼Ù¶¨ N >= 10 */
	int i;

	if( N % 2 == 0 )  N++;
	for( ; ; N += 2 ) {
		for( i = 3; i * i <= N; i += 2 )
			if( N % i == 0 )   break;
			if(i * i > N) return N;             
	}
}
