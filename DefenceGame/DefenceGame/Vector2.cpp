#include "Vector2.h"

Vector2 Vector2::operator+(const Vector2& other)
{
	return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator+=(const Vector2& other)
{
	return Vector2(x + other.x, y + other.y);

}

Vector2 Vector2::operator-(const Vector2& other)
{
	return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator-=(const Vector2& other)
{
	return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator*(const Vector2& other)
{
	return Vector2(x * other.x, y * other.y);
}

Vector2 Vector2::operator*=(const Vector2& other)
{
	return Vector2(x * other.x, y * other.y);
}

Vector2 Vector2::operator*(int scalar)
{
	return Vector2(x * scalar, y * scalar);
}
Vector2 Vector2::operator*=(int scalar)
{
	return Vector2(x * scalar, y * scalar);
}
