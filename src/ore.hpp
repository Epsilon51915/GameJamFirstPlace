enum class OreType {
	Iron,
	Aluminum,
	Carbon,
	Platinum,
	Etherium,
	SpaceTime,
	Titanium,
	Tungsten,
	Oconnium
};

struct Ore {
	int xPos;
	int yPos;
	OreType type;
	int health;
	int mineLevel;
};