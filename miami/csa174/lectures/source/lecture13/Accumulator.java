public class Accumulator {
	
	private int counter = 0;
	
	public int getCounter() {
		return counter;
	}
	
	public void increaseCounter() {
		counter++;
	}
	
	public String toString() {
		return "counter=" + counter;
	}
	
}