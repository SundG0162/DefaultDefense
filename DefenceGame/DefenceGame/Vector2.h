#pragma once
#include<iostream>
struct Vector2
{
	Vector2() : x{ 0 }, y{ 0 } {};
	Vector2(int x, int y) : x{ x }, y{ y } {};
	int x;
	int y;

	Vector2 operator+(const Vector2& other);
	Vector2 operator+=(const Vector2& other);
	Vector2 operator-(const Vector2& other);
	Vector2 operator-=(const Vector2& other);
	Vector2 operator*(const Vector2& other);
	Vector2 operator*=(const Vector2& other);
	Vector2 operator*(int scalar);
	Vector2 operator*=(int scalar);
};