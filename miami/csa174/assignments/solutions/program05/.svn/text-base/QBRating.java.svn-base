import java.util.Scanner;

/**
 * Mike Helmick
 * QB Rating calculation
 */
public class QBRating {
 
    public static void main( String[] args ) {
        Scanner kb = new Scanner(System.in);
        final double MAX_COMPONENT = 2.375;
        
        // read input
        System.out.println("Enter QB statistics: games, completions, attempts, yards, interceptions, TDs");
        int games = kb.nextInt();
        int completions = kb.nextInt();
        int attempts = kb.nextInt();
        int yards = kb.nextInt();
        int interceptions = kb.nextInt();
        int tds = kb.nextInt();
        
        // validate input
        if ( games < 0 || games > 16 ) {
            System.out.println("games played must be in the range [0, 16]");
            System.exit(0);
        }
        
        if ( attempts < 0 ) {
            System.out.println("attempts must be >= 0");
            System.exit(0);
        } 
           
        if ( completions < 0 || completions > attempts ) {
            System.out.println("completions must be in the range [0, attempts]");
            System.exit(0);
        }
        
        if ( yards < (-99*completions) || yards > (99*completions) ) {
            System.out.println("yards must be in the range [-99*completions, 99*completions]");
            System.exit(0);
        }
        
        if ( interceptions < 0 || interceptions > attempts - completions ) {
            System.out.println("interceptions must be in the range [0, attempts-completions]");
            System.exit(0);
        }
 
        if ( tds < 0 || tds > completions ) {
            System.out.println("TD passes must be in the range [0, completions]");
            System.exit(0);
        }
  
        // calculate rating
        double completionPCT = (((double)completions/attempts) - 0.3) * 5;
        double tdPCT = (double)tds / attempts * 20;
        double yardsPerAttempt = ((double)yards/attempts - 3) * 0.25;
        double interceptionPCT = MAX_COMPONENT - ((double)interceptions / (4*attempts)) * 100;
        
        // correct percentages
        if ( completionPCT < 0 ) {
            completionPCT = 0;
        }
        if ( completionPCT > MAX_COMPONENT ) {
            completionPCT = MAX_COMPONENT;
        }
        if ( tdPCT < 0 ) {
            tdPCT = 0;
        }
        if ( tdPCT > MAX_COMPONENT ) {
            tdPCT = MAX_COMPONENT;
        }
        if ( yardsPerAttempt < 0 ) {
            yardsPerAttempt = 0;
        }
        if ( yardsPerAttempt > MAX_COMPONENT ) {
            yardsPerAttempt = MAX_COMPONENT;
        }
        if ( interceptionPCT < 0 ) {
            interceptionPCT = 0;
        }
        if ( interceptionPCT > MAX_COMPONENT ) {
            interceptionPCT = MAX_COMPONENT;
        }
        
        // calculate rating
        double qbRating = (completionPCT + tdPCT + yardsPerAttempt + interceptionPCT) / 6 * 100;
        
        String status = "Dismal";
        if ( qbRating >= 110 && games >= 10 ) {
            status = "Hall of fame";
        }
        if ( qbRating > 110 && games < 10 ) {
            status = "Setllar";
        }
        if ( qbRating < 110 && qbRating >= 90 ) {
            status = "Impressive";   
        }
        if ( qbRating < 90 && qbRating >= 70 ) {
            status = "Decent";
        }
        
        System.out.printf("QB Rating: %.1f (%s)%n", qbRating, status );
        
    }
    
}