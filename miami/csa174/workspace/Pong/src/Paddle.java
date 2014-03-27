import java.util.Random;


public class Paddle {
	
	private static final Random random = new Random();

	private int score;
	private int y;
	private int x;
	private int paddleWidth;
	
	private int last = 1;
	
	public Paddle( int x, int y, int width ) {
		score = 0;
		this.y = y;
		this.x = x;
		this.paddleWidth = width;
	}
	
	public int getPaddleWidth() {
		return paddleWidth;
	}
	
	public void setPaddleWidth( int width ) {
		this.paddleWidth = width;
	}
	
	public int getX() {
		return x;
	}
	
	public int getY() {
		return y;
	}
	
	public void addScore() {
		score++;
	}
	
	public int getScore() {
		return score;
	}
	
	public void movePaddle( int distance ) {
		y += distance;
	}
	
	public void autoMovePaddle( int ballY, int speed ) {
		speed--;
		if ( random.nextBoolean() ) {
			speed -= 1;
		}
		
		if ( ballY == y ) {
			y += speed;
			last = 0;
		} else if ( ballY > y ) {
			if ( last == 1 ) {
				y += speed;
			} 
			last = 1;
		} else {
			if ( last == -1 ) {
				y -= speed; 
			}
			last = -1;
		}
	}
	
}
