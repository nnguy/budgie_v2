#include "meatrecipe.h"
#include <QString>

meatrecipe::meatrecipe()
{

}

meatrecipe::meatrecipe(Ingredient i, QString s, Ingredient a, Ingredient b) : Recipe(s, a, b){
    meat = i;
}

double meatrecipe::calculatePrice(){
    return meat.getPrice()+list_of_ingredients[0].getPrice()+list_of_ingredients[1].getPrice();
}

double meatrecipe::calculateDiscount(){
    return meat.getDiscount()+list_of_ingredients[0].getDiscount()+list_of_ingredients[1].getDiscount();
}
