#include "recipe.h"


Recipe::Recipe(){

}
Recipe::Recipe(QString s, Ingredient a, Ingredient b){
  name = s;
  list_of_ingredients[0] = a;
  list_of_ingredients[1] = b;
}

