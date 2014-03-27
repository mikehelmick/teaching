public class MyArrayList<E> {

	private static final int CAPACITY = 10;
	
	/** number of elements in the list */
	private int size = 0;
	/** backing store for the array list */
	private E[] data; 
	
	public MyArrayList() {
	    // you canNOT create an array of E, but can create an array
	    // of object and downcast (always a valid downcast)
	    data = (E[]) new Object[CAPACITY];
	}
	
	/**
	 * Adds a new object to the end of the list
	 * post: the size of the arraylist is increased by one
	 * @param obj new object to insert into the list
	 */
	public void add( E obj ) {
	    checkSpace();
	    data[size++] = obj;
	}
	
	/**
	 * Adds a new object at the specified space
	 * post: the size of the arraylist is increased by one
	 *       
	 */
	public void add( int idx, E obj ) {
	    checkIndexStrict( idx );
	    checkSpace();
	    
	    // open up the appropriate gap
	    size++;
	    for( int i = size; i > idx; i-- ) {
	        data[i] = data[i-1];
	    }
	    data[idx] = obj;
	}
	
	/**
	 * Removes an element from a specific index of the array
	 *  and returns that element
	 * @param idx the index to remove the element from
	 * @throws IndexOutOfBoundsException if the index is invalid
	 */
	public E remove( int idx ) {
	    checkIndexStrict( idx );
	    
	    E rtn = data[idx];
	    
	    // copy elements down
	    for( int i = idx; i < size; i++ ) {
	        data[i] = data[i+1];
	    }
	    data[--size] = null;
	    
	    return rtn;
	}
	
	/**
	 * Removes a specific object from the list
	 *  (removed the first matching instance)
	 * post: if the object is found, the size is reduced
	 *       if the object is not found, the list is unchanged
	 * @param obj the objec to remove
	 * @return true if the obj was removed, otherwise false
	 */
	public boolean remove( Object obj ) {
	    int index = findObject( obj );
	    if ( index < 0 ) { 
	        return false;
	    } else {
	        return remove( index ) != null;
	    }
	}
	
	public int size() {
	    return size;
	}
	
	public E get( int index ) {
	    checkIndexStrict( index );
	    return data[index];
	}
	
	public E set( int index, E newVal ) {
	    checkIndexStrict( index );
	    E oldVal = data[index];
	    data[index] = newVal;
	    return oldVal;
	}

	private int findObject( Object obj ) {
	    boolean found = false;
	    int i = 0;
	    for( ; i < size; i++ ) {
	        found = (obj==null ? data[i]==null : obj.equals(data[i]) );
	        if ( found ) {
	            break;
	        }
        }
        
        if ( ! found ) {
            i = -1;
        }
        return i;
	}
	
	private void checkIndexStrict( int idx ) {
	    if ( idx < 0 || idx >= size ) {
	        throw new IndexOutOfBoundsException( "" + idx );
	    }
	}
	
	private void checkSpace() {
	    if ( size >= data.length ) {
	        // allocate a temporary array
	        E[] temp = (E[]) new Object[data.length * 2];
	        // copy everything over
	        System.arraycopy( data, 0, temp, 0, size );
	        // set the temp array to be the real one
	        data = temp;
	    }
	}
	
	private void dumpArray() {
	    System.out.println("------------------------");
	    for( int i = 0; i < size; i++ ) {
	        System.out.println( data[i].toString() );
	    }
	}
	
    public static void main( String[] args ) {
        MyArrayList<String> list = new MyArrayList<String>();
        
        list.add( "one" );
        list.add( "three" );
        list.add( 1, "two" );
        list.dumpArray();
        
        list.remove( 1 );
        list.dumpArray();
        
        list.remove( "three" );
        list.dumpArray();
    }
    
}