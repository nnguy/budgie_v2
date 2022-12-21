#include "ingredient.h"

Ingredient::Ingredient(FOOD_GROUP group, double x, double y){
  f = group;
  price = x;
  discount = y;
}

void Ingredient::setPrice(double x){
  price = x;
}

void Ingredient::calcDiscount(double currPrice, double prevPrice){
  discount = (currPrice-prevPrice)/prevPrice;
}


