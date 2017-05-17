#include "AABB.h"

AABB::AABB(float x, float y, float halfDimension) : centerX(x), centerY(y), halfWidth(halfDimension), halfHeight(halfDimension) {
}

AABB::AABB(float x, float y, float halfWidth, float halfHeight) : centerX(x), centerY(y), halfWidth(halfWidth), halfHeight(halfHeight) {
}

AABB::~AABB() {
}

float AABB::getX() {
	return centerX;
}

float AABB::getY() {
	return centerY;
}

float AABB::getHalfWidth() {
	return halfWidth;
}

float AABB::getHalfHeight() {
	return halfHeight;
}

void AABB::setCenter(float x, float y) {
	centerX = x;
	centerY = y;
}

bool AABB::containsPoint(float x, float y) {
	return !(x > centerX + halfWidth ||
			 x < centerX - halfWidth ||
			 y < centerY - halfHeight ||
			 y > centerY + halfHeight);
}

bool AABB::intersectsAABB(AABB rhs) {
	return !(rhs.centerX - rhs.halfWidth > centerX + halfWidth ||
			 rhs.centerX + rhs.halfWidth < centerX - halfWidth ||
			 rhs.centerY - rhs.halfHeight > centerY + halfHeight ||
			 rhs.centerY + rhs.halfHeight < centerY - halfHeight);
}
