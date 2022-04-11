#include "Ship.h"

Ship::Ship(ShipType shipType, std::string fullName, std::string shortName, unsigned int shipLength)
	: m_shipType(shipType), m_fullName(fullName), m_shortName(shortName), m_shipLength(shipLength), m_hit(false) {

}

Ship::Ship() : Ship(ShipType::Ocean, "Ocean", " . ", 0) {

}

std::string Ship::getFullName() {
	return m_fullName;
}

std::string Ship::getShortName() {
	return m_shortName;
}

unsigned int Ship::getLength() {
	return m_shipLength;
}

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