import java.util.*;
public class GenericTree<E> {

	private Node<E> root;
	
	private static class Node<E> {
		private E data;
		
		private List<Node<E>> children = (List<Node<E>>) new ArrayList();
		
	}
	
	public List<E> preOrderTraversal() {
		List<E> results = new ArrayList<E>();
		
		// has methods push(E) and pop() - ignore exceptions
		Stack<Node<E>> stack = new Stack<Node<E>>();
		stack.push( root );
		
		// BEGIN ANSWER
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		// END ANSWER
		
		return results;
	}

}