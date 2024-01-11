
int FindMin( int LowCost[ ],  int n )
{   /* 求V－VT中到VT最小距离的点 */
	int j, k, MinCost= INFINITY;
 
	for ( k = 0, j = 0; j < n; j++ )
		if ( LowCost[j] && LowCost[j]< MinCost ) {
			MinCost = LowCost[j];
			k = j;
		}

	return k;
}
