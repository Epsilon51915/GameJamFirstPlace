enum class OreType {
	Iron,
	Aluminum
};

struct Ore {
	int xPos;
	int yPos;
	OreType type;
	int health;
	int mineLevel;
};