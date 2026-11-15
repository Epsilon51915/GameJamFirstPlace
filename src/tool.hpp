#ifndef TOOL_H
#define TOOL_H

enum ToolType
{
	PICKAXE = 0,
	AXE,
	TAPPER,
	CUTTER
};

struct Tool{
	ToolType type;
	int mineLevel;
	int remainingDurability;
};

#endif