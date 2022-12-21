#include "vegrecipe.h"
#include <QString>

vegrecipe::vegrecipe()
{

}

vegrecipe::vegrecipe(Ingredient i, QString s, Ingredient a, Ingredient b) : Recipe(s, a, b){
    veg = i;
}

double vegrecipe::calculatePrice(){
    return veg.getPrice()+list_of_ingredients[0].getPrice()+list_of_ingredients[1].getPrice();
}

double vegrecipe::calculateDiscount(){
    return veg.getDiscount()+list_of_ingredients[0].getDiscount()+list_of_ingredients[1].getDiscount();
}
