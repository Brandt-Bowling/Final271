#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

class Recipe
{
	friend istream& operator>>(istream&, Recipe&);
	friend ostream& operator<<(ostream&, Recipe&);
public:
	Recipe(string c = "", string i = "") : category(c), ingredient(i) {}
	string getCategory() { return category; }
	string getIngredient() { return ingredient; }
private:
	string category, ingredient;
};

inline istream& operator>>(istream& is, Recipe& rObj)
{
	is >> rObj.category;
	is.ignore(2, '\t');
	getline(is, rObj.ingredient);
	return is;
}

inline ostream& operator<<(ostream& os, Recipe& rObj)
{
	os << rObj.category << '\t' << rObj.ingredient << endl;
	return os;
}
