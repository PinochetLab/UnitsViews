#pragma once
#include "Unit.h"
#include <math.h>

Unit::Unit(float pos_x, float pos_y, float dir_x, float dir_y) {
	this->pos_x = pos_x;
	this->pos_y = pos_y;
	this->dir_x = dir_x;
	this->dir_y = dir_y;
}

void Unit::SetView(float fov, float radius) {
	Unit::fov_cos = cos(fov * 3.1415f / 180 / 2);
	Unit::radius = radius;
}

bool Unit::DoesSee(Unit* other) {
	if (pos_x == other->pos_x && pos_y == other->pos_y && dir_x == other->dir_x && dir_y == other->dir_y) {
		return false;
	}
	float x = other->pos_x - pos_x;
	float y = other->pos_y - pos_y;
	float distance = sqrt(pow(x, 2) + pow(y, 2));
	if (distance > radius) {
		return false;
	}
	x /= distance;
	y /= distance;
	float dot = x * dir_x + y * dir_y;
	return dot >= fov_cos;
}

float Unit::GetPosX() {
	return pos_x;
}

float Unit::GetPosY() {
	return pos_y;
}

float Unit::GetRadius() {
	return radius;
}

float Unit::fov_cos = 0;
float Unit::radius = 0;