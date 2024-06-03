#pragma once
class Scene
{
public:
	Scene();
	~Scene();

public:
	virtual void init() abstract;
	virtual void update() abstract;
	virtual void render() abstract;
};