import java.util.Scanner;

import javax.swing.JFrame;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner kb = new Scanner( System.in );
		System.out.println("Enter A and B for A*x+B");
		int a = kb.nextInt();
		int b = kb.nextInt();
		
		JFrame frame = new JFrame("Application");
		frame.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
		
		frame.getContentPane().add( new Grapher( a, b ) );
		
		frame.pack();
		frame.setVisible(true);
		
	}

}
