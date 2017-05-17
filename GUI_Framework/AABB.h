#pragma once

class AABB {
public:
	AABB(float x, float y, float halfDimension);
	AABB(float x, float y, float halfWidth, float halfHeight);
	~AABB();

	float getX();
	float getY();
	float getHalfWidth();
	float getHalfHeight();

	void setCenter(float x, float y);

	bool containsPoint(float x, float y);
	bool intersectsAABB(AABB rhs);
protected:
	float centerX, centerY, halfWidth, halfHeight;
};

