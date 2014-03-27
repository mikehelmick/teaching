import java.util.Calendar;
public class Person {

	private String name;
	private int age;
	private Calendar birthday;
	
	
	public Person( String name, int age, Calendar birthday ) {
		// ...
	}
	
	
	public String getName() {
		return name;
	}
	
	
	public void checkAge() {
		age = (Calendar.getInstance().get(Calendar.YEAR)) - 
			  birthday.get(Calendar.YEAR);
	}
	
	
	public int getAge() {
		return age;
	}
	
	
	public String getBirthday() {
		return birthday.toString();
	}
	
	
	public String toString() {
		return name + " " + getBirthday();
	}
}



