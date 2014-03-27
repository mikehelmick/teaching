import java.util.Scanner;

public class VoteCounter {
	
	public static void main( String[] args ) {
		Scanner kb = new Scanner( System.in );
		
		System.out.println("Vote Counter 2007");
		System.out.print("How many voting booths? ");
		int boothCount = kb.nextInt();
		PollingLocation location = new PollingLocation( boothCount );
		
		System.out.println("Enter all votes (machine yes or no), -1 to stop.");
		
		int machineNumber = kb.nextInt();
		while( machineNumber >= 0 ) {
			boolean vote = kb.next().equalsIgnoreCase("yes");
			location.castVote( machineNumber, vote );
			machineNumber = kb.nextInt();
		}
		
		System.out.println("** Voting stats by booth");
		for( int i = 0; i < location.numBooths(); i++ ) {
			System.out.println("Booth #" + i + 
			                   " " + location.getBooth(i) );
		}
		System.out.println("** Overall voting stats");
		System.out.println(location);
		
	}
	
}