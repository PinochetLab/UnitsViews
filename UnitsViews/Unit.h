#pragma once
class Unit
{
public:
	Unit(float pos_x, float pos_y, float dir_x, float dir_y);
	static void SetView(float fov, float radius);
	bool DoesSee(Unit* other);
	float GetPosX();
	float GetPosY();
	static float GetRadius();
private:
	float pos_x;
	float pos_y;
	float dir_x;
	float dir_y;
	static float fov_cos;
	static float radius;
};

