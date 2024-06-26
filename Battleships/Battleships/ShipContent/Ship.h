#pragma once
#include "ShipType.h"
#include <string>

class Ship {
public:
	Ship(ShipType shipType, std::string fullName, std::string shortName, unsigned int shipLength);
	Ship();

	// Get/set full/short name of ship.
	std::string getFullName();
	std::string getShortName();
	void setShortName(std::string shortName);

	// Get ship length.
	unsigned int getLength();
	void setLength(unsigned int length);

	// See, or set, whether a ship is hit.
	bool isHit();
	void setHit(bool value);

	ShipType getType();
	void setType(ShipType shipType);

private:
	ShipType m_shipType;
	std::string m_fullName;
	std::string m_shortName;
	unsigned int m_shipLength;
	bool m_hit;
};