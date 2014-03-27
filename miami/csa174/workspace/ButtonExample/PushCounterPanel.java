import java.awt.Color;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;


public class PushCounterPanel extends JPanel {

	private int count;
	private JButton reset;
	private JButton push;
	private JLabel label;
	
	// constructor
	public PushCounterPanel() {
		count = 0;
		
		reset = new JButton("Reset Counter");
		reset.addActionListener( new ResetListener() );
		
		push = new JButton("Push Me!");
		push.addActionListener( new ButtonListener() );
		
		label = new JLabel("Pushes: " + count );
		
		add( reset );
		add( push );
		add( label );
		
		setBackground( Color.LIGHT_GRAY );
		setPreferredSize( new Dimension(300, 50) );
	}
	
	private class ResetListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			count = 0;
			label.setText( "Pushes: " + count );
		}		
	}
	
	private class ButtonListener implements ActionListener {

		public void actionPerformed(ActionEvent e) {
			if( e.getSource() == push ) {
				count++;
				label.setText( "Pushes: " + count );
			}
			
		}
		
	}
	
	
}
