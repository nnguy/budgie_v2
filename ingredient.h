#ifndef INGREDIENT_H_
#define INGREDIENT_H_
enum FOOD_GROUP{meat, vegetable, starch};

class Ingredient{
private:
  FOOD_GROUP f;
  double price;
  double discount;

public:
  Ingredient(){
    f = meat;
    price = 0;
    discount = 0;
  }
  Ingredient(FOOD_GROUP, double, double);
  void setPrice(double);
  void calcDiscount(double, double);
  FOOD_GROUP getFoodGroup () {return f;}
  double getPrice() {return price;}
  double getDiscount() {return discount;}

};
#endif
