#include "Recipe.h"

void print(string, vector<Recipe>&);
void print2(string, vector<Recipe>&);

void main()
{
	string response;
	Recipe temp;
	vector<Recipe> foodObjects;
	ifstream infile("Text.txt");
	if (!infile)
		cout << "Error opening file." << endl;

	while (infile >> temp)
	{
		foodObjects.push_back(temp);
	}

	cout << "Enter (C)ategory or (I)ngredient: ";
	cin >> response;

	if (response == "Category")
	{
		cout << "Enter (E)ntree, (D)esert, (S)andwich, or sou(p): ";
		cin >> response;
		print(response, foodObjects);
	}
	else if (response == "Ingredient")
	{
		cout << "Enter (C)hocolate, C(h)icken, (V)egetable, (B)eef, or (F)ish: ";
		cin >> response;
		print2(response, foodObjects);
	}

	system("pause");
}

void print(string c, vector<Recipe>& rVec)
{
	vector<Recipe> temp;
	Recipe r;

	for (size_t i = 0; i < rVec.size(); i++)
	{
		r = rVec.at(i);
		if (r.getCategory() == c)
			temp.push_back(rVec.at(i));
	}

	cout << "The List is: " << endl;

	for (size_t i = 0; i < temp.size(); i++)
		cout << temp.at(i);
}

void print2(string c, vector<Recipe>& rVec)
{
	vector<Recipe> temp;
	Recipe r;
	string str;
	size_t found = 0;

	for (size_t i = 0; i < rVec.size(); i++)
	{
		r = rVec.at(i);
		str = r.getIngredient();
		found = str.find(' ');
		str = str.substr(0, found);
		if (str == c)
				temp.push_back(rVec.at(i));
	}

	cout << "The List is: " << endl;

	for (size_t i = 0; i < temp.size(); i++)
		cout << temp.at(i);
}
