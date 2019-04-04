#pragma once
#include "PlayScene.h"
#include <unordered_map>

class SceneManager
{
private:
	PlayScene * _curScene;							
	static SceneManager * _instance;
	std::unordered_map<int, PlayScene> scenes;
public:
	SceneManager();
	~SceneManager(); 
	void StartUp();
	void ShutDown();

	void ReplaceScene(PlayScene* scene);			// Thay thế Scene hiện có bằng Scene khác (dùng cho chuyển cảnh)
	PlayScene* GetCurScene();						// Get Scene hiện tại
	static SceneManager* GetInstance();
};