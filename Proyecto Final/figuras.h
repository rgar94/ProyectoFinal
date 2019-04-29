//#include <windows.h>  //Solo para Windows
//#include <GL/gl.h>     // The GL Header File
//#include <stdio.h>

//#include <math.h>
#include "Main.h"


class CFiguras
{
	public:

	float text_der;
	float text_izq;

	void esfera(GLfloat radio, int meridianos, int paralelos, GLuint text); //Funcíon creacion esfera
	void cilindro(float radio, float altura, int resolucion, GLuint text,GLuint text2);	//Funcíon creacion un mediocilindro
	void CFiguras::cuarto(float radio, float altura, int resolucion, GLuint text, GLuint text2);//Funcíon creacion un  cuearto cilindro
	void cono(float altura, float radio, int resolucion, GLuint text);		//Funcíon creacion cono
	void CFiguras::poste(float radio, float altura, int resolucion, GLuint text);//Funcion creacion de poste
	void CFiguras::mediaesfera(GLfloat radio, int meridianos, int paralelos, GLuint text);//funcion creacion media esfera
	void CFiguras::arbol(GLuint text);											//Funcion crecion arbol
	void CFiguras::mouse(GLuint text);											//Funcion crecion mouse
	void CFiguras::keyboard(GLuint text);											//Funcion crecion teclado
	void CFiguras::desk(GLuint text);											//Funcion crecion escritorio
	void CFiguras::proyector(GLuint text);											//Funcion crecion proyector
	void CFiguras::board(GLuint text);											//Funcion crecion pizarron
	void CFiguras::gab(GLuint text);											//Funcion crecion gabinete
	void CFiguras::airec(GLuint text);											//Funcion crecion aireacondicionado
	void prisma_anun (GLuint text, GLuint text2);							//Funcíon creacion movimiento
	void prisma (float altura, float largo, float profundidad, GLuint text);//Funcíon creacion prisma por 20
	void prisma3(float altura, float largo, float profundidad, GLuint text);//Funcíon creacion prisma
	void prisma4(float altura, float largo, float profundidad, GLuint text);//Funcíon creacion prisma sin caras laterales
	void prisma5(float altura, float largo, float profundidad, GLuint text);//Funcíon creacion prisma sin top side
	void maceta(float altura, float largo, float profundidad, GLuint text, GLuint text2);//Funcíon creacion maceta
	void prisma2 (GLuint text, GLuint text2);
	void skybox(float altura, float largo, float profundidad, GLuint text);	//Funcion creacion cielo
	void skybox2 (float altura, float largo, float profundidad, GLuint text);
	void torus(GLfloat radioM, GLfloat radiom, int meridianos, int paralelos);


};
