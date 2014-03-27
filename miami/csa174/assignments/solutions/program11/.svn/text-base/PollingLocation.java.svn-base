
public class PollingLocation {
	
	private VotingBooth[] booths;
	
	public PollingLocation( int numBooths ) {
		booths = new VotingBooth[numBooths];
		
		for( int i = 0; i < booths.length; i++ ) {
			booths[i] = new VotingBooth();
		}
	}
	
	public void castVote( int booth, boolean voteFor ) {
		if ( voteFor ) {
			booths[booth].voteFor();
		} else {
			booths[booth].voteAgainst();
		}
	}
	
	public VotingBooth getBooth( int booth ) {
		return booths[booth];
	}
	
	public int numBooths() {
		return booths.length;
	}
	
	public int totalVotes() {
		int voteCount = 0;
		for( int i = 0; i < booths.length; i++ ) {
			voteCount += (booths[i].getVotesFor() + booths[i].getVotesAgainst());
		}
		return voteCount;
	}
	
	public int totalVotesFor() {
		int voteCount = 0;
		for( int i = 0; i < booths.length; i++ ) {
			voteCount += booths[i].getVotesFor();
		}
		return voteCount;
	}
	
	public int totalVotesAgainst() {
		int voteCount = 0;
		for( int i = 0; i < booths.length; i++ ) {
			voteCount += booths[i].getVotesAgainst();
		}
		return voteCount;		
	}
	
	public double getVoteForPercent() {
		return (double)totalVotesFor()/totalVotes()*100;
	}
	
	public double getVoteAgainstPercent() {
		return (double)totalVotesAgainst()/totalVotes()*100;
	}
	
	public String toString() {
		return String.format("Yes=%4d (%6.2f%%) No=%4d (%6.2f%%)", 
		                     totalVotesFor(), getVoteForPercent(),
		                     totalVotesAgainst(), getVoteAgainstPercent() );
	}

}
