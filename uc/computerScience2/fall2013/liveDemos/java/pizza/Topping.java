
public class Topping {
  private final String name;
  private final boolean premium;

  public Topping(String name, boolean isPremium) {
    this.name = name;
    this.premium = isPremium;
  }

  public Topping(String name) {
    // Call the other constructor!
    this(name, false);
  }

  private Topping() {
    // private, no use
    name = null;
    premium = false;
  }

  public String getName() {
    return name;
  }

  public boolean isPremium() {
    return premium;
  }
}