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

void initializeCampfireRecipe(std::vector<Recipe> &recipes)
{
	Recipe campfire;
	campfire.name = "Campfire";
	campfire.isTool = false;
	Item campfireItem;
	campfireItem.type = CAMPFIRE;
	campfireItem.quantity = 1;
	campfire.resultItem = campfireItem;

	std::vector<Item> woodRequirements;
	Item wood;
	wood.type = WOOD;
	wood.quantity = 5;
	woodRequirements.push_back(wood);
	Item leaf;
	leaf.type = LEAF;
	leaf.quantity = 10;
	woodRequirements.push_back(leaf);
	Item sticks;
	sticks.type = STICK;
	sticks.quantity = 10;
	woodRequirements.push_back(sticks);

	campfire.requirements = woodRequirements;

	recipes.push_back(campfire);
}

void initializeWoodAxeRecipe(std::vector<Recipe> &recipes)
{
	Recipe woodAxe;
	woodAxe.name = "Wood Axe";
	woodAxe.isTool = true;
	Tool woodAxeTool;
	woodAxeTool.type = AXE;
	woodAxeTool.mineLevel = 1;
	woodAxeTool.remainingDurability = 50;
	woodAxe.resultTool = woodAxeTool;

	std::vector<Item> woodRequirements;
	Item wood;
	wood.type = WOOD;
	wood.quantity = 15;
	woodRequirements.push_back(wood);
	Item sap;
	sap.type = SAP;
	sap.quantity = 2;
	woodRequirements.push_back(sap);
	Item sticks;
	sticks.type = STICK;
	sticks.quantity = 2;
	woodRequirements.push_back(sticks);

	woodAxe.requirements = woodRequirements;

	recipes.push_back(woodAxe);
}

void initializeWoodPickaxeRecipe(std::vector<Recipe> &recipes){
	Recipe woodPickaxe;
	woodPickaxe.name = "Wood Pickaxe";
	woodPickaxe.isTool = true;
	Tool woodPickaxeTool;
	woodPickaxeTool.mineLevel = 1;
	woodPickaxeTool.type = PICKAXE;
	woodPickaxeTool.remainingDurability = 50;
	woodPickaxe.resultTool = woodPickaxeTool;
	std::vector<Item> woodRequirements;
	Item wood;
	wood.type = WOOD;
	wood.quantity = 20;
	woodRequirements.push_back(wood);
	Item sap;
	sap.type = SAP;
	sap.quantity = 4;
	woodRequirements.push_back(sap);
	Item sticks;
	sticks.type = STICK;
	sticks.quantity = 4;
	woodRequirements.push_back(sticks);

	woodPickaxe.requirements = woodRequirements;

	recipes.push_back(woodPickaxe);
}

void initializeIronPickaxeRecipe(std::vector<Recipe> &recipes){
	Recipe ironPickaxe;

	ironPickaxe.name = "Iron Pickaxe";
	ironPickaxe.isTool = true;

	Tool ironPickaxeTool;
	ironPickaxeTool.mineLevel = 2;
	ironPickaxeTool.remainingDurability = 100;

	ironPickaxe.resultTool = ironPickaxeTool;

	std::vector<Item> ironRequirements;
	Item iron;
	iron.type = IRON;
	iron.quantity = 5;
	ironRequirements.push_back(iron);

	Item sap;
	sap.type = SAP;
	sap.quantity = 3;
	ironRequirements.push_back(sap);

	Item sticks;
	sticks.type = STICK;
	sticks.quantity = 3;
	ironRequirements.push_back(sticks);

	Item flint;
	flint.type = FLINT;
	flint.quantity = 3;
	ironRequirements.push_back(flint);

	ironPickaxe.requirements = ironRequirements;
	recipes.push_back(ironPickaxe);
}

void initializeStarterRecipes(std::vector<Recipe> &recipes){
	initializeWoodPickaxeRecipe(recipes);
	initializeWoodAxeRecipe(recipes);
	initializeIronPickaxeRecipe(recipes);
	initializeCampfireRecipe(recipes);
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
		if(recipe.isTool){
			if(recipe.resultTool.type == PICKAXE)
			{
				std::cout << "PCAKXE" << std::endl;
				player.pickaxeTool = recipe.resultTool;
			}
			else if(recipe.resultTool.type == AXE)
			{
				player.axeTool = recipe.resultTool;
			}
		}
		else
		{
			if(recipe.resultItem.type == CAMPFIRE)
			{
				if(lookForItem(player, recipe.resultItem))
				{
					editInventory(player, recipe.resultItem);
				}
				else
				{
					if(addItemToInventory(player, recipe.resultItem))
					{
						// Had space, good
					}
				}
			}
		}

		return true;
	} else {
		return false;
	}
}

#endif