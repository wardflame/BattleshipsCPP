#pragma once
#include "ShipType.h"
#include <string>

class Ship {
public:
	Ship(ShipType shipType);
	Ship();

	// Get short string version of ships.
	std::string getStrShort();

	bool isHit();
	void setHit(bool value);

	ShipType getType();
	void setType(ShipType shipType);

private:
	ShipType m_shipType;
	int m_shipLength;
	bool m_hit;
};

bool Ship::isHit() {
	return m_hit;
}

void Ship::setHit(bool value) {
	m_hit = value;
}

ShipType Ship::getType()
{
	return m_shipType;
}

void Ship::setType(ShipType shipType) {
	m_shipType = shipType;
}