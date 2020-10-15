#include "character.h"

#include <cmath>
#include <iostream>
#include <limits>

Character::Character(
	std::pair<int, int> xy, 
	int health_points, 
	int attack, 
	int defence, 
	const std::string& name) :
		xy_(xy),
		health_points_(health_points),
		attack_(attack),
		defence_(defence),
		name_(name) {}

void Character::Attack(Character& enemy) const
{
	if(Distance(enemy) == 1)
	{
		enemy.SetHealthPoints(std::min(enemy.GetHealthPoints(), enemy.GetHealthPoints() - (attack_ - enemy.GetDefence())));
	}
}

bool Character::IsDead() const
{
	return(health_points_ <= 0 ? true : false);
}

float Character::Distance(const Character& character) const
{
	return (float)abs((xy_.first - character.xy_.first)+(xy_.second - character.xy_.second));
}
