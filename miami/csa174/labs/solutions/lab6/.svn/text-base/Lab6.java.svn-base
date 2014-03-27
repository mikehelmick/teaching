import java.util.Scanner;

/**
 * Mike Helmick
 * Lab 6 - FF benefits
 **/
public class Lab6 {
  
  public static void main( String[] args ) {
    Scanner kb = new Scanner( System.in );
    
    System.out.print("What is your frequent flyer class: " );
    char ffClass = kb.next().toUpperCase().charAt(0);
    
    System.out.println("For class '" + ffClass + "' your benefits are.");
    switch( ffClass ) {
      case 'A':
        System.out.println("Buy 3 first class tickets - get one free!");
      case 'B':
        System.out.println("Always double miles for all fares.");
      case 'C':
        System.out.println("Complimentary meal service on all flights.");
        System.out.println("Personal audio and video system with complimentary headphones and iPod hookups.");
        break;
      case 'D':
        System.out.println("Double miles for all economy class tickets purchased online.");
      case 'E':
        System.out.println("A $5 credit for the sky mall catalogue for each flight segment.");
      case 'F':
        System.out.println("Free headphones for in flight movies.");
      case 'G':
        System.out.println("Free beverages on all flights.");
        break;
      default:
        System.out.println("Unknokwn membership class.");
        break;
    }
    
  }
  
}