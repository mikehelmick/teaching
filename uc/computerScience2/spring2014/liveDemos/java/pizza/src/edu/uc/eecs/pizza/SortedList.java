package edu.uc.eecs.pizza;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

public class SortedList<E extends Comparable<E>> extends ArrayList<E> {

  private void sort() {
    Collections.sort(this);
  }
  
  @Override
  public boolean add(E e) {
    final boolean result = super.add(e);
    sort();
    return result;
  }

  @Override
  public void add(int index, E element) {
    super.add(index, element);
    sort();
  }

  @Override
  public boolean addAll(Collection<? extends E> c) {
    boolean result = super.addAll(c);
    sort();
    return result;
  }

  @Override
  public boolean addAll(int index, Collection<? extends E> c) {
    boolean result = super.addAll(index, c);
    sort();
    return result;
  }

}
