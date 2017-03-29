#pragma once
class Task
{
public:
	virtual ~Task(){};
	virtual void Initialize(){}
	virtual void Finalize(){}
	// XV
	virtual void Update() = 0;
	// •`‰æ
	virtual void Draw() = 0;
};
// End Of File