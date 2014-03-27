
public class Extra {

	private int x;
	private int y;
	
	private int radius;
	private int time;
	
	public Extra( int x, int y, int radius, int time ) {
		this.x = x;
		this.y = y;
		this.radius = radius;
		this.time = time;
	}

	public int getX() {
		return x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public int getY() {
		return y;
	}

	public void setY(int y) {
		this.y = y;
	}

	public int getRadius() {
		return radius;
	}

	public void setRadius(int radius) {
		this.radius = radius;
	}

	public int getTime() {
		return time;
	}

	public void setTime(int time) {
		this.time = time;
	}
	
	public void tickTime() {
		this.time--;
	}
	
	public boolean colission( Ball b ) {
		int x1 = b.getX() - x;
		int x2 = b.getY() - y;
		
		double dist = Math.sqrt( x1*x1 + x2*x2 );
		
		return dist <= radius;
	}
	
	
}
