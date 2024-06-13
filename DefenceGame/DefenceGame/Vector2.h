#pragma once
#include<iostream>
struct Vector2
{
	Vector2(int x, int y) : x{ x }, y{ y } {};
	int x;
	int y;

    // 덧셈 연산자 오버로딩
    Vector2 operator+(const Vector2& other) const {
        return Vector2(x + other.x, y + other.y);
    }

    // 뺄셈 연산자 오버로딩
    Vector2 operator-(const Vector2& other) const {
        return Vector2(x - other.x, y - other.y);
    }

    // 곱셈 연산자 오버로딩 (스칼라 곱)
    Vector2 operator*(int scalar) const {
        return Vector2(x * scalar, y * scalar);
    }

    // 출력 연산자 오버로딩
    friend std::ostream& operator<<(std::ostream& os, const Vector2& vec) {
        os << "(" << vec.x << ", " << vec.y << ")";
        return os;
    }
};

