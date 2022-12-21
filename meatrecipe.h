#ifndef MEATRECIPE_H
#define MEATRECIPE_H
#include <QString>

#include "recipe.h"

class meatrecipe : public Recipe
{
private:
    Ingredient meat;
public:
    meatrecipe();
    meatrecipe(Ingredient, QString, Ingredient, Ingredient);
    double calculatePrice();
    double calculateDiscount();
};

#endif // MEATRECIPE_H
