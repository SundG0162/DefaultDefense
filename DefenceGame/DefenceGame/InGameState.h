#pragma once
class InGameState
{
public:
	virtual ~InGameState() {}
	virtual void update() abstract;
	virtual void render() abstract;
};