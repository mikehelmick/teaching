
public class BananaStand {
	
	private int storeNumber;
	private int bananasSoldToday;
	
	// SHARED BY ALL INSTANCES
	private static int totalSoldToday = 0;

	public BananaStand( int storeNumber ) {
		this.storeNumber = storeNumber;
		this.bananasSoldToday = 0;
	}

	public void justSold() {
		bananasSoldToday++;
		// all store total
		totalSoldToday++;
	}
	
	public int getBananasSoldToday() {
		return bananasSoldToday;
	}
	
	public int getStoreNumber() {
		return storeNumber;
	}
	
	public void resetBananaCount() {
		bananasSoldToday = 0;
	}
	
	public String toString() {
		return "Store Number " + storeNumber + " bananas sold today = " + bananasSoldToday;
	}
	
	public static int getTotalSold() {
		return totalSoldToday;
	}
	
	public static void resetTotalSold() {
		totalSoldToday = 0;
	}
	
}
