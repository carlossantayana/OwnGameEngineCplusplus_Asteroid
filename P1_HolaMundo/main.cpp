// P1_HolaMundo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "Game.h"
#include <iostream>
using namespace std;
#include <string>
#include <GL/glut.h>

//////////////////    USANDO GAME      ////////////////////////

Game game = Game();

////////////////////////CONSTANTES///////////////////////////

const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1800;
const int WINDOW_POSITION_X = 0;
const int WINDOW_POSITION_Y = 0;
const char TITLE[] = "ASTEROID";

const GLclampf RED = 0.05;
const GLclampf GREEN = 0.05;
const GLclampf BLUE = 0.05;
const GLclampf ALPHA = 1.0;

bool fullScreenMode = true;

////////////////////FUNCIONES AUXILIARES////////////////////////

void writeLine(string text) {
    cout << text << endl;
}

////////////////////////FUNCIONES OPENGL/////////////////////////////////

void initGraphics() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glClearColor(RED, GREEN, BLUE, ALPHA);
    game.Init();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
   // glTranslatef(-4.0, -3.0, -12.0);

    game.Render();

    glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height) {
    if (height == 0) {
        height = 1;
    }
    GLfloat aspectRatio = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0f, aspectRatio, 1.0f, 200.0f);
    glMatrixMode(GL_MODELVIEW);
}

void idle() {
    game.Update();
    glutPostRedisplay();
}

void keyPressed(unsigned char key, int px, int py) {
    game.ProcessKeyPressed(key, px, py);
    glutPostRedisplay();
}

void keyUp(unsigned char key, int px, int py){
    game.ProcessKeyUp(key, px, py);
    glutPostRedisplay();
}

void mouseMoved(int x, int y) {
    game.ProcessMouseMovement(x, y);
    glutPostRedisplay();
}

void mouseClicked(int button, int state, int x, int y) {
    game.ProcessMouseClick(button, state, x, y);
    glutPostRedisplay();
}

void specialKey(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_F11:
            fullScreenMode = !fullScreenMode;
            if (fullScreenMode) {
                glutFullScreen();
            }
            else {
                glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
                glutPositionWindow(WINDOW_POSITION_X, WINDOW_POSITION_Y);
            }
            break;
    }
}

int main(int argc, char** argv)
{
    writeLine("Hello World con OpenGL");

    writeLine("Generando ventana...");
    glutInit(&argc, argv); //Inicializa GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); //Pantalla con un doble buffer, uso de colores RGB con canal alpha(A) - MODO RGBA, y un buffer de profundidad(DEPTH BUFFER/Z-BUFFER).
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT); //Tamaño inicial de la ventana
    glutInitWindowPosition(WINDOW_POSITION_X, WINDOW_POSITION_Y); //Posición inicial de la ventana
    glutCreateWindow(TITLE); //Crea una ventana con el título dado

    writeLine("Registrando funciones de tratamiento de eventos..."); 
    glutReshapeFunc(reshape); //Tratamiento del evento de redimensionado de la pantalla
    glutDisplayFunc(display); //Tratamiento del evento de repintado de la ventana
    glutKeyboardFunc(keyPressed); //Tratamiento del evento de tecla pulsada
    glutKeyboardUpFunc(keyUp); //Tratamiento del evento de tecla soltada
    glutSpecialFunc(specialKey); //Tratamiento del evento de tecla especial pulsada
    glutMotionFunc(mouseMoved); //Tratamiento del evento de movimiento del ratón
    glutMouseFunc(mouseClicked); //Tratamiento del evento de click del ratón
    glutIdleFunc(idle); //Para cuando no hay eventos que tratar

    writeLine("Iniciando gráficos...");
    initGraphics(); //Iniciamos OpenGL

    writeLine("Iniciando bucle infinito...");
    writeLine("Pulse F11 para activar/desactivar el modo de pantalla completa.");
    glutMainLoop();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
