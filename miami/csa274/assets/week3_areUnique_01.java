public static boolean areUnique( int[] x ) {
	for( int i = 0; i < x.length; i++ ) {
		for( int j = 0; j < x.length; j++ ) {
			if ( i != j && x[i] == x[j] ) {
				return false;
			}
		}
	}
	return true;
}

