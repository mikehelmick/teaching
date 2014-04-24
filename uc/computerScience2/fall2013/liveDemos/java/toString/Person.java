
public class Person {
  private String name;
  
  public Person(String name) {
    this.name = name;
  }
  
  @Override
  public String toString() {
    return "Person, Name: " + name;
  }
  
  @Override
  public boolean equals(Object other) {
    if (other instanceof Person) {
      Person that = (Person) other;
      return name.equals(that.name);
    }
    return false;
  }
  
  public static void main(String args[]) {
    Person person1 = new Person("Michael");
    System.out.println(person1.toString());
  
    Person person2 = new Person("Scott");
    System.out.println(person2.toString());
    
    Person person3 = new Person("Michael");
    System.out.println(person3.toString());
    
    if (person1.equals(person2)) {
      System.out.println("person1 is equal to person2");
    } else {
      System.out.println("person1 is NOT equal to person2");
    }
    
    if (person1.equals(person1)) {
      System.out.println("person1 is equal to person1");
    } else {
      System.out.println("person1 is NOT equal to person1");
    }
    
    if (person1.equals(person3)) {
      System.out.println("person1 is equal to person3");
    } else {
      System.out.println("person1 is NOT equal to person3");
    }
  }
}