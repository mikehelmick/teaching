
public class VotingBooth {

	private int votesFor = 0;
	private int votesAgainst = 0;
	
	public VotingBooth() {
		// nothing to do
	}
	
	public void voteFor() {
		votesFor++;
	}
	
	public void voteAgainst() {
		votesAgainst++;
	}
	
	public int getVotesFor() {
		return votesFor;
	}
	
	public int getVotesAgainst() {
		return votesAgainst;
	}
	
	public int totalVotes() {
		return getVotesFor() + getVotesAgainst();
	}
	
	public double getForPercentage() {
		return votesFor / (double)(votesFor + votesAgainst) * 100;
	}
	
	public double getAgainstPercentage() {
		return votesAgainst / (double)(votesFor + votesAgainst) * 100;
	}
	
	public String toString() {
		return String.format("Yes=%4d (%6.2f%%) No=%4d (%6.2f%%)", 
		                     votesFor, getForPercentage(),
		                     votesAgainst, getAgainstPercentage() );
	}
	
}
