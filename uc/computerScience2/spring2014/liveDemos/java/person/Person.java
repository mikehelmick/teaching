
public class Person {
  private String name;
  private String studentId;

  Person(String name, String studentId) {
    this.name = name;
    this.studentId = studentId;
  }

  String getName() {
    return name;
  }

  String getStudentId() {
    return studentId;
  }

  @Override
  public boolean equals(Object other) {
    if (!(other instanceof Person)) {
      return false;
    }
    Person that = (Person) other;
    return name.equals(that.name)
        && studentId.equals(that.studentId);
  }

  @Override
  public String toString() {
    StringBuilder b = new StringBuilder();
    b.append("Student: Name: ");
    b.append(name);
    b.append(" id: ");
    b.append(studentId);
    return b.toString();
  }
}
