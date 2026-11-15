#ifndef RECIPE_H
#define RECIPE_H

#include "player.hpp"
#include "tool.hpp"
#include <vector>

struct Recipe{
	std::string name;
	bool isTool;
	Item resultItem;
	Tool resultTool;
	std::vector<Item> requirements; //item quantity specifies amount needed
};

void initializeWoodPickaxeRecipe(std::vector<Recipe> &recipes){
	Recipe woodPickaxe;
	woodPickaxe.name = "Wood Pickaxe";
	woodPickaxe.isTool = true;
	Tool woodPickaxeTool;
	woodPickaxeTool.mineLevel = 1;
	woodPickaxeTool.remainingDurability = 50;
	woodPickaxe.resultTool = woodPickaxeTool;
	std::vector<Item> woodRequirements;
	Item wood;
	wood.type = WOOD;
	wood.quantity = 3;
	woodRequirements.push_back(wood);
	Item sap;
	sap.type = SAP;
	sap.quantity = 1;
	woodRequirements.push_back(sap);
	Item sticks;
	sticks.type = STICK;
	sticks.quantity = 2;
	woodRequirements.push_back(sticks);

	woodPickaxe.requirements = woodRequirements;

	recipes.push_back(woodPickaxe);
}

void initializeStarterRecipes(std::vector<Recipe> &recipes){
	initializeWoodPickaxeRecipe(recipes);
}

bool canCraft(Recipe recipe, Player& player){
	for(int i = 0; i < recipe.requirements.size(); i++){
		int index = getItemIndex(player, recipe.requirements[i].type);
		if(index == -1){
			return false;
		}

		if(player.inventory.items[index].quantity < recipe.requirements[i].quantity){
			return false;
		}
	}
	return true;
}

bool craft(Recipe recipe, Player& player){
	if(canCraft(recipe, player)){
		std::vector<int> removeIndices;
		for(int i = 0; i < recipe.requirements.size(); i++){
			int index = getItemIndex(player, recipe.requirements[i].type);

			player.inventory.items[index].quantity -= recipe.requirements[i].quantity;
			if(player.inventory.items[index].quantity == 0){
				removeIndices.push_back(index);
			}
		}

		//for(int i = 0; i < removeIndices.size(); i++){
		//	player.inventory.items.erase(player.inventory.items.begin() + removeIndices[i]);
		//}
		if(recipe.isTool){
			player.tool = recipe.resultTool;
		}

		return true;
	} else {
		return false;
	}
}

#endif