import java.util.Iterator;
import java.util.NoSuchElementException;

// Generic class - can only be used by things that are comparable against themselves
public class SortedList<E extends Comparable<E>> implements Iterable<E> {

  @SuppressWarnings("unchecked")
  public E data[] = (E[]) new Comparable[1];
  public int size = 0;

  public SortedList() {
    
  }

  static <T extends Comparable<T>> SortedList<T> of() {
    return new SortedList<T>();
  }
  
  public void add(E item) {
    if (size == data.length) {
      // resize
      @SuppressWarnings("unchecked")
      E newData[] = (E[]) new Comparable[data.length * 2];
      System.arraycopy(data, 0, newData, 0, size);
      data = newData;
    }

    // insertion sort from back
    for (int i = size; i > 0; i--) {
      if (item.compareTo(data[i - 1]) >= 0) {
        data[i] = item;
        size++;
        return;
      } else {
        data[i] = data[i - 1];
      }
    }
    size++;
    data[0] = item;
  }
  
  public Iterator<E> iterator() {
    return new SLIterator();
  }
  
  public int size() {
    return size;
  }

  public E get(int i) {
    if (i < 0 || i >= size) {
      throw new IndexOutOfBoundsException();
    }
    return data[i];
  }

  private class SLIterator implements Iterator<E> {
    private int pos;
    
    SLIterator() {
      pos = 0;
    }
    
    public boolean hasNext() {
      return pos < size;
    }
    
    public E next() {
      if (!hasNext()) {
        throw new NoSuchElementException();
      }
      E item = data[pos++];
      return item;
    }

    public void remove() {
      throw new UnsupportedOperationException();
    }
  }
}
