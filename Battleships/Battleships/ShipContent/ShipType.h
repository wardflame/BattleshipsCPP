#pragma once

// The different ship types that can be present on the board
enum class ShipType {
	Null,
	Destroyer,
	Submarine,
	Cruiser,
	Battleship,
	Carrier,
	TargetOcean,
	Target,
	Shot
};

// Quick access to ship type strings.
static const char* ship_type_str[] =
{ "Null", "Destroyer", "Submarine", "Cruiser", "Battleship", "Carrier", "Target" , "Target", "Shot" };