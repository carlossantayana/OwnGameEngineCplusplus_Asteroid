#pragma once
class SceneManager
{
public:
//Interfaz que define una serie de métodos virtuales que serán implementados por la clase game para gestionar los cambios de escena.
//Todas las escenas tendrán un puntero a game a través de esta interfaz.
	virtual void SetTitleScene() = 0;
	virtual void SetGameOverScene() = 0;
	virtual void SetNextScene() = 0;
	virtual void SetPause() = 0;
	virtual void SetNoPause() = 0;
};


