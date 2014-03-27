import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.Random;

import javax.swing.JPanel;
import javax.swing.Timer;


public class PongPanel extends JPanel {
	private static final long serialVersionUID = 1L;

	private final Random random = new Random();
	
	private static final int PADDLE = 40;
	
	private Paddle player;
	private Paddle computer;
	private Ball ball;
	
	private int level;
	
	private Extra extra = new Extra(0,0,10,0);
	
	private Timer timer;
	
	private final int halfX;
	private final int halfY;
	
	private final int MIN_X;
	private final int MAX_X;
	private final int MIN_Y;
	private final int MAX_Y;
	
	private static final double UP_LEFT_ANGLE_X = Math.sin( Math.toRadians(315) );
	private static final double UP_LEFT_ANGLE_Y = Math.cos( Math.toRadians(315) );
	
	public PongPanel( int level ) {
		
		halfX = Pong.WIDTH / 2;
		halfY = Pong.HEIGHT / 2;
		
		MAX_X = halfX;
		MIN_X = -1 * halfX;
		MAX_Y = halfY;
		MIN_Y = -1 * halfY;
		
		player = new Paddle( MIN_X + 15, 0, PADDLE );
		computer = new Paddle( MAX_X - 15, 0, PADDLE );
		
		ball = new Ball( -1 * (halfX / 2), 0, 10, MAX_X, MAX_Y );
		//ball.setSpeed( level );
		
		this.level = level;
		
		addKeyListener( new KeyboardListener() );
		setFocusable(true);
		this.requestFocusInWindow();
		this.setPreferredSize( new Dimension(WIDTH,HEIGHT) );
		
		timer = new Timer( Pong.DELAY, new BallMover() );
		timer.start();
	}
	

	private int translateX( int x ) {
		return x + halfX;
	}
	
	private int translateY( int y ) {
		return halfY - y;
	}
	
	public void paintComponent( Graphics graphics ) {
		Graphics2D g2d = (Graphics2D) graphics;
		Font font = new Font("Courier", Font.PLAIN, 20);
	    g2d.setFont(font);
		
		
		// clear the screen
		g2d.setBackground( Color.BLACK );
		g2d.clearRect( 0, 0, Pong.WIDTH, Pong.HEIGHT );
		
		// draw the line down the middle
		g2d.setColor( Color.WHITE );
		for( int i = MIN_Y; i < MAX_Y; i = i + 20 ) {
			g2d.drawLine( translateX(0) , translateY(i), 
					      translateX(0) , translateY(i + 10) );
		}
		
		if ( extra.getTime() > 0 ) {
			g2d.setColor( Color.RED );
			g2d.drawLine( translateX(extra.getX()), translateY(extra.getY()), 0, 0 );
			boolean red = true;
			for( int i = 0; i < extra.getRadius(); i += 5 ) {
				g2d.fillOval( translateX(extra.getX() + (int)(UP_LEFT_ANGLE_X*extra.getRadius()))+i/2, 
						      translateY(extra.getY() + (int)(UP_LEFT_ANGLE_Y*extra.getRadius()))+i/2, 
						      extra.getRadius() - i, extra.getRadius() - i );
				
				if ( red ) {
					g2d.setColor( Color.RED );
					red = !red;
				} else {
					g2d.setColor( Color.WHITE );
					red = !red;
				}
			}
			g2d.setColor( Color.GREEN );
			g2d.drawString("" + extra.getTime(), 
					       translateX(extra.getX() + extra.getRadius() + 5), 
					       translateY(extra.getY()- extra.getRadius()/2) );
		}
		g2d.setColor( Color.WHITE );
		
		// draw player paddle
		g2d.fillRect( translateX( player.getX() - 5), translateY( player.getY() + player.getPaddleWidth() / 2 ),
				      15, player.getPaddleWidth() );
		
		g2d.fillRect(translateX(computer.getX() - 5), translateY(computer.getY() + computer.getPaddleWidth() / 2), 15, computer.getPaddleWidth() );
		
		
		// draw the ball
		g2d.fillOval( translateX(ball.getX()), translateY(ball.getY()), 
					  ball.getRadius(), ball.getRadius() );
		
		
		
		// score
		g2d.drawString( "" + player.getScore(), translateX(MIN_X + halfX/2), 25 );
		g2d.drawString( "" + computer.getScore(), translateX(MAX_X - halfX/2), 25 );
		
		if ( ball.getSpeed() == 0 ) {
			g2d.setColor( Color.GREEN );
			g2d.drawString("PRESS SPACE TO START", translateX(0-halfX/2), translateY(0) );
		}
		
		g2d.setColor( Color.GREEN );
		g2d.drawString( "ball=(" + ball.getX() + "," + ball.getY() + ")", 10, 15 );
	}
	
	private class KeyboardListener implements KeyListener {

		public void keyPressed(KeyEvent e) {
			if ( e.getKeyCode() == KeyEvent.VK_UP ) {
				player.movePaddle( 10 );
			} else if ( e.getKeyCode() == KeyEvent.VK_DOWN ) {
				player.movePaddle( -10 );
			} else if ( e.getKeyCode() == KeyEvent.VK_SPACE ) {
				if ( ball.getSpeed() == 0 ) {
					ball.setSpeed( level );
				} else { 
					ball.setSpeed( 0 );
				}
			}
			
			repaint();
		}

		public void keyReleased(KeyEvent e) {
		}

		public void keyTyped(KeyEvent e) {
		}
		
	}
	
	private class BallMover implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			// move the ball
			ball.move();
			ball.bounce();
			
			computer.autoMovePaddle( ball.getY(), level );
			
			// check for paddle bounce
			ball.bounce( player );
			ball.bounce( computer );
			
			// check for a score
			if ( ball.offTable() ) {
				if ( ball.getX() > 0 ) {
					player.addScore();
					player.setPaddleWidth( PADDLE );
				} else {
					computer.addScore();
					player.setPaddleWidth( PADDLE );
				}
				ball.resetBall();
			}
			
			
			// extra
			if ( extra.getTime() <= 0 && random.nextInt(100) == 42 ) {
				extra = new Extra( random.nextInt(halfX) - halfX/2, random.nextInt(halfY) - halfY/2, random.nextInt(45) + 30, random.nextInt(500) + 100 );
			} else if ( extra.getTime() > 0 ) {
				extra.tickTime();
				if ( extra.colission(ball) ) {
					player.setPaddleWidth( player.getPaddleWidth() * 2 );
					extra.setTime(0);
				}
			}
			
			
			// repaint
			repaint();
		}
	}
	
}
