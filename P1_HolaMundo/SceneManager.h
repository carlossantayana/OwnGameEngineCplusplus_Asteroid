#pragma once
class SceneManager
{
public:
//Interfaz que define una serie de m�todos virtuales que ser�n implementados por la clase game para gestionar los cambios de escena.
//Todas las escenas tendr�n un puntero a game a trav�s de esta interfaz.
	virtual void SetTitleScene() = 0;
	virtual void SetGameOverScene() = 0;
	virtual void SetNextScene() = 0;
	virtual void SetPause() = 0;
	virtual void SetNoPause() = 0;
};


