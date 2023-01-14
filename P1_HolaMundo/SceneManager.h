#pragma once
class SceneManager
{
public:
	virtual void SetTitleScene() = 0;
	virtual void SetGameOverScene() = 0;

	virtual void SetNextScene() = 0;

	virtual void SetPause() = 0;

	virtual void SetNoPause() = 0;
};


