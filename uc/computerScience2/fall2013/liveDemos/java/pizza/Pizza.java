
import java.util.List;
import java.util.ArrayList;

public class Pizza {
  private List<Topping> toppings = new ArrayList<Topping>();

  public Pizza() {
  }

  public void addTopping(Topping topping) {
    toppings.add(topping);
  }

  public List<Topping> getToppings() {
    return toppings;
  }

  public int getToppingsCount() {
    return toppings.size();
  }
  
  public double getPrice() {
    double price = 8.99; // base price
    for (Topping topping : toppings) {
      if (topping.isPremium()) {
        price += 1.25;
      } else {
        price += 0.75;
      }
    }
    return price;
  }
}