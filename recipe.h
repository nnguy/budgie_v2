#include "ingredient.h"
#include <QString>

#ifndef RECIPE_H_
#define RECIPE_H_

class Recipe{
protected:
QString name;
Ingredient list_of_ingredients[2];
public:
Recipe();
Recipe(QString, Ingredient, Ingredient);
virtual double calculatePrice() = 0;
virtual double calculateDiscount() = 0;
};


#endif
