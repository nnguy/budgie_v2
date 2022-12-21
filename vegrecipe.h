#ifndef VEGRECIPE_H
#define VEGRECIPE_H
#include <QString>
#include "recipe.h"

class vegrecipe : public Recipe
{
private:
    Ingredient veg;
public:
    vegrecipe();
    vegrecipe(Ingredient, QString, Ingredient, Ingredient);
    double calculatePrice();
    double calculateDiscount();
};

#endif // VEGRECIPE_H
