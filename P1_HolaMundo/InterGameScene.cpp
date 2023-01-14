#include "InterGameScene.h"

InterGameScene::InterGameScene(SceneManager* scMgr, Player* player, int level) :TextScene(scMgr)
{
	setText("PENDIENTE DE HACER");
}


void InterGameScene::Finalizar() 
{
	sceneManager->SetNextScene();
}

