import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;

import javax.swing.JPanel;


public class Grapher extends JPanel { 
	
	private int width = 700;
	private int height = 700;

	private int a;
	private int b;
	
	public Grapher( int a, int b ) {
		this.a = a;
		this.b = b;
	
		setPreferredSize( new Dimension(width,height) );
		setBackground( Color.BLACK );	
	}
	
	public void paintComponent( Graphics screen ) {
		
		Graphics2D g2d = (Graphics2D) screen;
		
		g2d.setBackground( Color.BLACK );
		g2d.clearRect(0, 0, width, height);
		
		// draw lines
		g2d.setColor( Color.WHITE );
		for( int i = 0; i < width; i+=20 ) {
			g2d.drawLine( i, height/2, i+10, height/2);
		}
		for( int i = 0; i < height; i+=20 ) {
			g2d.drawLine( width/2, i, width/2, i+10 );
		}
		
		g2d.setColor( Color.RED );
		// draw the line
		for( int i = 0; i < width; i++ ) {
			int eqnX = i - width/2;
			int eqnY = a * eqnX + b;
			
			int dispX = i;
			int dispY = height/2 - eqnY;
			
			g2d.drawOval(dispX, dispY, 1, 1);
		}
		
	}
	
	
	
}
