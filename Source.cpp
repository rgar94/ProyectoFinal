//Computación Gráfica
//Proyecto Final
//Semestre 2019 - 2
//Fecha: 24/05/2019
//Alumnos: García Callejas Ricardo
//		   Ramírez Verduzco Lizet
//Grupo Teoria: 01 Grupo Laboratorio: 02


//para movimiento de tacitas
float tacitas = 0;

#include "texture.h"
#include "figuras.h"
#include "Camera.h"
//luces
float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = 0.0f;
float cont = 0.0f;
float gira = 0.0f;
float LightAngle = 30.0f;

bool	light = false;		// Luz ON/OFF
bool	positional = true;


int luna_neptuno2 = 0;

GLfloat LightAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; 			// Ambient Light Values
GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat LightSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat LightPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position
GLfloat LightPosition1[] = { 0.0f, 0.0f, 1.0f, 0.0f };			// Light Position
GLfloat LightDirection[] = { 0.0f, 0.0f, -2.0f };			// Light Position

GLfloat mat_ambient[] = { 0.0, 0.0, 0.0, 1.0 };					// Color background
GLfloat mat_diffuse[] = { 0.0, 1.0, 0.0, 1.0 };					// Object Color main
GLfloat mat_specular[] = { 0.0, 0.0, 1.0, 1.0 };				// Specular color
GLfloat mat_shininess[] = { 100.0 };							// 1 to greatest

GLfloat rota = 0.0;
//luces materiales
GLfloat lamparaDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat lamparaSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat lamparaPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position
GLfloat laparaShininess[] = { 100.0 };



GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 30.0 };

//neptuno
GLfloat LunaNeptuno2Diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat LunaNeptuno2Specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat LunaNeptuno2Shininess[] = { 100.0 };


//Definicion de colores
GLfloat blanco[] = { 1.0,1.0,1.0 };
GLfloat morado[] = { 1.0,0.0,1.0 };
GLfloat negro[] = { 0.0,0.0,0.0 };
GLfloat amarillo[] = { 0.7,0.7,0.0 };
GLfloat gris[] = { 0.2,0.2,0.2 };
GLfloat azul[] = { 0.0,0.0,1.0 };
GLfloat rojo[] = { 1.0,0.0,0.0 };
GLfloat verde[] = { 0.0,1.0,0.0 };


GLfloat alto_estructura = 0.0;
GLfloat i = 0.0;
GLfloat x = 0.0;
GLfloat y = 0.0;
GLfloat z = 0.0;
bool gira_der = false;
bool gira_der2 = false;
bool gira_der3 = false;
bool gira_der4 = false;
bool baja = false;
bool sube = false;
bool avanza = false;
bool izquierda = false;
bool derecha = false;
bool atras = false;
bool adelante = false;
//Animación del recorrido
float angRot = 0.0;
float movKitX = 0.0;
float movKitZ = 0.0;
float rotKit = 0.0;
float rotTires = 0.0;
bool g_fanimacion = false;
bool g_avanza = false;

bool circuito = false;
bool recorrido1 = true;
bool recorrido2 = false;
bool recorrido3 = false;
bool recorrido4 = false;
bool recorrido5 = false;
bool circuito2 = false;

//Creacion de la Camera
CCamera objCamera;	//Create objet Camera

//La posicion de la camara
GLfloat g_lookupdown = 0.0f;    // Mira la posicion en el eje z


//Definicion de texturas
CTexture text1;
CTexture suelo;
CTexture pasto;	
CTexture tree;
CTexture tree1;
CTexture ladrillo;
CTexture scale;
CTexture uspost;
CTexture pared;
CTexture pared2;
CTexture raton;
CTexture escritorio;
CTexture suelo_estacionamiento;
CTexture madera;
CTexture puesto_azul;
CTexture puesto_rojo;
CTexture puesto_amarillo;
CTexture castillo_negro;
CTexture carrito;
CTexture comida;
CTexture juegos;
CTexture globos;
CTexture patitos;
CTexture palomitas;
CTexture algodon;
CTexture hamburguesa;
CTexture puerta;
CTexture ventana1;
CTexture tuberia;
CTexture tacita;
CTexture vias;
CTexture vidrio;
CTexture letrero;
CTexture yoshi;
CTexture shy;
CTexture mario;
CTexture boo;
CTexture yoshi1;
CTexture huevo;
CTexture valla;

CTexture letrero_montañarusa;
CTexture letrero_rueda;
CTexture letrero_sillitas;
CTexture letrero_tacitas;




//Definicion de figuras
CFiguras sky;
CFiguras piso;
CFiguras jardinera1_1;
CFiguras jardinera1_2;
CFiguras jardinera2_1;
CFiguras jardinera2_2;
CFiguras medialuna;
CFiguras cuartode;
CFiguras arbol2;
CFiguras posteinf;
CFiguras postesup;
CFiguras lamp;
CFiguras correo1;
CFiguras correo2;
CFiguras correo3;
CFiguras correo4;
CFiguras correo5;
CFiguras correo6;
CFiguras escalon1;
CFiguras escalon2;
CFiguras escalon3;
CFiguras escalon4;
CFiguras escalon5;
CFiguras mouse;
CFiguras desk;
CFiguras entrada;
CFiguras puesto;
CFiguras patas_asiento;//para las bancas del parque
CFiguras asiento;
CFiguras castillo;
CFiguras montaña_rusa;
CFiguras adorno;



CFiguras fig7;





//Variables de dibujo y manipulacion
float posX = 0, posY = 2.5, posZ = -3.5, rotRodIzq = 0, rotRodDer = 0, rotBrazoIzq = 0, rotBrazoDer = 0, rotCabeza = 0;//paso 0
float giroMonito = 0;



typedef struct _frame
{
	//Variables para GUARDAR Key Frames
	float posX;		//Variable para PosicionX
	float posY;		//Variable para PosicionY
	float posZ;		//Variable para PosicionZ
	float incX;		//Variable para IncrementoX
	float incY;		//Variable para IncrementoY
	float incZ;		//Variable para IncrementoZ
	float rotRodIzq;
	float rotInc;
	float giroMonito;
	float giroMonitoInc;
	float movBrazoDer;
	float movBrazoDerInc;


}FRAME;

//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
static GLuint ciudad_display_list;	//Display List for the Monito

void monitozen()
{
	//glNewList(1, GL_COMPILE);
	glPushMatrix();//Pecho
	glScalef(0.5, 0.5, 0.5);
	fig7.prisma(2.0, 2.0, 1, madera.GLindex);

	glPushMatrix();//Cuello
	glTranslatef(0, 1.0, 0.0);
	fig7.poste(0.25, 0.25, 15, 0);
	glPushMatrix();//Cabeza
	glTranslatef(0, 1.0, 0);
	fig7.esfera(0.75, 15, 15, 0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Brazo derecho-->
	glTranslatef(1.25, 0.65, 0);
	fig7.esfera(0.5, 12, 12, 0);
	glPushMatrix();
	glTranslatef(0.25, 0, 0);
	//	glRotatef(movBrazoDer, 0.0, 0.0, 1.0);
	glRotatef(-45, 0, 1, 0);
	glTranslatef(0.75, 0, 0);
	fig7.prisma(0.7, 1.5, 0.7, 0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Brazo izquierdo <--
	glTranslatef(-1.25, 0.65, 0);
	fig7.esfera(0.5, 12, 12, 0);
	glPushMatrix();
	glTranslatef(-0.25, 0, 0);
	glRotatef(45, 0, 1, 0);
	glRotatef(25, 0, 0, 1);
	glRotatef(25, 1, 0, 0);
	glTranslatef(-0.75, 0, 0);
	fig7.prisma(0.7, 1.5, 0.7, 0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//Cintura
	glColor3f(0, 0, 1);
	glTranslatef(0, -1.5, 0);
	fig7.prisma(1, 2, 1, 0);

	glPushMatrix(); //Pie Derecho -->
	glTranslatef(0.75, -0.5, 0);
	glRotatef(-90, 1, 0, 0);
	glTranslatef(0, -0.5, 0);
	fig7.prisma(1.0, 0.5, 1, 0);

	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, -0.75, 0);
	fig7.prisma(1.5, 0.5, 1, 0);

	glPushMatrix();
	glTranslatef(0, -0.75, 0.3);
	fig7.prisma(0.2, 1.2, 1.5, 0);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPushMatrix(); //Pie Izquierdo -->
	glTranslatef(-0.75, -0.5, 0);
	glRotatef(-90, 1, 0, 0);
	glTranslatef(0, -0.5, 0);
	fig7.prisma(1.0, 0.5, 1, 0);

	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, -0.75, 0);
	fig7.prisma(1.5, 0.5, 1, 0);

	glPushMatrix();
	glTranslatef(0, -0.75, 0.3);
	fig7.prisma(0.2, 1.2, 1.5, 0);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPopMatrix();


	glColor3f(1, 1, 1);
	//glEndList();
}
void monito()
{
	//glNewList(1, GL_COMPILE);
	glPushMatrix();//Pecho
	glScalef(0.5, 0.5, 0.5);
	fig7.prisma(2.0, 2.0, 1, madera.GLindex);

	glPushMatrix();//Cuello
	glTranslatef(0, 1.0, 0.0);
	fig7.poste(0.25, 0.25, 15, 0);
	glPushMatrix();//Cabeza
	glTranslatef(0, 1.0, 0);
	fig7.esfera(0.75, 15, 15, 0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Brazo derecho-->
	glTranslatef(1.25, 0.65, 0);
	fig7.esfera(0.5, 12, 12, 0);
	glPushMatrix();
	glTranslatef(0.25, 0, 0);
//	glRotatef(movBrazoDer, 0.0, 0.0, 1.0);
	glRotatef(-45, 0, 1, 0);
	glTranslatef(0.75, 0, 0);
	fig7.prisma(0.7, 1.5, 0.7, 0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Brazo izquierdo <--
	glTranslatef(-1.25, 0.65, 0);
	fig7.esfera(0.5, 12, 12, 0);
	glPushMatrix();
	glTranslatef(-0.25, 0, 0);
	glRotatef(45, 0, 1, 0);
	glRotatef(25, 0, 0, 1);
	glRotatef(25, 1, 0, 0);
	glTranslatef(-0.75, 0, 0);
	fig7.prisma(0.7, 1.5, 0.7, 0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//Cintura
	glColor3f(0, 0, 1);
	glTranslatef(0, -1.5, 0);
	fig7.prisma(1, 2, 1, 0);

	glPushMatrix(); //Pie Derecho -->
	glTranslatef(0.75, -0.5, 0);
	glRotatef(-15, 1, 0, 0);
	glTranslatef(0, -0.5, 0);
	fig7.prisma(1.0, 0.5, 1, 0);

	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	glRotatef(15, 1, 0, 0);
	glTranslatef(0, -0.75, 0);
	fig7.prisma(1.5, 0.5, 1, 0);

	glPushMatrix();
	glTranslatef(0, -0.75, 0.3);
	fig7.prisma(0.2, 1.2, 1.5, 0);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPushMatrix(); //Pie Izquierdo -->
	glTranslatef(-0.75, -0.5, 0);
	glRotatef(-5, 1, 0, 0);
	glTranslatef(0, -0.5, 0);
	fig7.prisma(1.0, 0.5, 1, 0);

	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	glRotatef(15 + rotRodIzq, 1, 0, 0);
	glTranslatef(0, -0.75, 0);
	fig7.prisma(1.5, 0.5, 1, 0);

	glPushMatrix();
	glTranslatef(0, -0.75, 0.3);
	fig7.prisma(0.2, 1.2, 1.5, 0);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPopMatrix();


	glColor3f(1, 1, 1);
	//glEndList();
}







void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				//Fondo Negro

	glEnable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);

	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glLightfv(GL_LIGHT1, GL_DIFFUSE, SunDiffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, SunSpecular);
	glLightfv(GL_LIGHT1, GL_POSITION, SunPosition);

	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHTING);
	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);



	text1.LoadBMP("text/01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	tree.LoadTGA("text/tree.tga");
	tree.BuildGLTexture();
	tree.ReleaseImage();

	tree1.LoadTGA("text/tree01.tga");
	tree1.BuildGLTexture();
	tree1.ReleaseImage();

	suelo.LoadTGA("text/concreto.tga");
	suelo.BuildGLTexture();
	suelo.ReleaseImage();

	suelo_estacionamiento.LoadTGA("text/estacionamiento.tga");
	suelo_estacionamiento.BuildGLTexture();
	suelo_estacionamiento.ReleaseImage();

	pasto.LoadTGA("text/pasto01.tga");
	pasto.BuildGLTexture();
	pasto.ReleaseImage();

	ladrillo.LoadTGA("text/brickm.tga");
	ladrillo.BuildGLTexture();
	ladrillo.ReleaseImage();

	uspost.LoadTGA("text/uspost.tga");
	uspost.BuildGLTexture();
	uspost.ReleaseImage();

	scale.LoadTGA("text/floor.tga");
	scale.BuildGLTexture();
	scale.ReleaseImage();

	pared.LoadTGA("text/wall.tga");
	pared.BuildGLTexture();
	pared.ReleaseImage();

	pared2.LoadTGA("text/wall2.tga");
	pared2.BuildGLTexture();
	pared2.ReleaseImage();

	raton.LoadTGA("text/mouse.tga");
	raton.BuildGLTexture();
	raton.ReleaseImage();

	escritorio.LoadTGA("text/desk.tga");
	escritorio.BuildGLTexture();
	escritorio.ReleaseImage();

	madera.LoadTGA("text/madera.tga");
	madera.BuildGLTexture();
	madera.ReleaseImage();

	puesto_azul.LoadTGA("text/puesto_azul.tga");
	puesto_azul.BuildGLTexture();
	puesto_azul.ReleaseImage();

	puesto_rojo.LoadTGA("text/puesto_rojo.tga");
	puesto_rojo.BuildGLTexture();
	puesto_rojo.ReleaseImage();

	puesto_amarillo.LoadTGA("text/puesto_amarillo.tga");
	puesto_amarillo.BuildGLTexture();
	puesto_amarillo.ReleaseImage();

	castillo_negro.LoadTGA("text/castillo_negro.tga");
	castillo_negro.BuildGLTexture();
	castillo_negro.ReleaseImage();

	carrito.LoadTGA("text/carrito.tga");
	carrito.BuildGLTexture();
	carrito.ReleaseImage();

	comida.LoadTGA("text/comida.tga");
	comida.BuildGLTexture();
	comida.ReleaseImage();

	juegos.LoadTGA("text/juegos.tga");
	juegos.BuildGLTexture();
	juegos.ReleaseImage();

	globos.LoadTGA("text/globos.tga");
	globos.BuildGLTexture();
	globos.ReleaseImage();

	patitos.LoadTGA("text/patitos.tga");
	patitos.BuildGLTexture();
	patitos.ReleaseImage();

	palomitas.LoadTGA("text/palomitas.tga");
	palomitas.BuildGLTexture();
	palomitas.ReleaseImage();

	algodon.LoadTGA("text/algodon.tga");
	algodon.BuildGLTexture();
	algodon.ReleaseImage();


	hamburguesa.LoadTGA("text/hamburguesa.tga");
	hamburguesa.BuildGLTexture();
	hamburguesa.ReleaseImage();

	puerta.LoadTGA("text/puerta.tga");
	puerta.BuildGLTexture();
	puerta.ReleaseImage();

	ventana1.LoadTGA("text/ventana1.tga");
	ventana1.BuildGLTexture();
	ventana1.ReleaseImage();

	tacita.LoadTGA("text/tacita.tga");
	tacita.BuildGLTexture();
	tacita.ReleaseImage();

	tuberia.LoadTGA("text/tuberia.tga");
	tuberia.BuildGLTexture();
	tuberia.ReleaseImage();

	vias.LoadTGA("text/vias.tga");
	vias.BuildGLTexture();
	vias.ReleaseImage();


	tuberia.LoadTGA("text/tuberia.tga");
	tuberia.BuildGLTexture();
	tuberia.ReleaseImage();

	vidrio.LoadTGA("text/vidrio.tga");
	vidrio.BuildGLTexture();
	vidrio.ReleaseImage();

	letrero.LoadTGA("text/letrero.tga");
	letrero.BuildGLTexture();
	letrero.ReleaseImage();

	mario.LoadTGA("text/mario.tga");
	mario.BuildGLTexture();
	mario.ReleaseImage();

	shy.LoadTGA("text/shy.tga");
	shy.BuildGLTexture();
	shy.ReleaseImage();

	yoshi1.LoadTGA("text/yoshi1.tga");
	yoshi1.BuildGLTexture();
	yoshi1.ReleaseImage();

	yoshi.LoadTGA("text/yoshi.tga");
	yoshi.BuildGLTexture();
	yoshi.ReleaseImage();

	huevo.LoadTGA("text/huevo.tga");
	huevo.BuildGLTexture();
	huevo.ReleaseImage();

	valla.LoadTGA("text/valla.tga");
	valla.BuildGLTexture();
	valla.ReleaseImage();

	letrero_montañarusa.LoadTGA("text/letrero_montañarusa.tga");
	letrero_montañarusa.BuildGLTexture();
	letrero_montañarusa.ReleaseImage();

	letrero_rueda.LoadTGA("text/letrero_rueda.tga");
	letrero_rueda.BuildGLTexture();
	letrero_rueda.ReleaseImage();

	letrero_sillitas.LoadTGA("text/letrero_sillitas.tga");
	letrero_sillitas.BuildGLTexture();
	letrero_sillitas.ReleaseImage();

	letrero_tacitas.LoadTGA("text/letrero_tacitas.tga");
	letrero_tacitas.BuildGLTexture();
	letrero_tacitas.ReleaseImage();



	objCamera.Position_Camera(10, 10.5f, 0, 0, 2.5f, 0, 0, 1, 0);


}


void malla(void)
{
	glPushMatrix();

	glEnable(GL_LIGHTING);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
	montaña_rusa.poste(0.5, 6, 30, tuberia.GLindex);
	glTranslatef(0, 0, -6);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
	montaña_rusa.poste(0.5, 6, 30, tuberia.GLindex);
	glTranslatef(0, 6, -0.5);
	glRotatef(90, 1, 0, 0);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
	montaña_rusa.poste(0.5, 7, 30, tuberia.GLindex);
	glRotatef(-90, 1, 0, 0);
	glTranslatef(0, -6, 0);
	glRotatef(90, 1, 0, 0);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
	montaña_rusa.poste(0.5, 7, 30, tuberia.GLindex);
	glRotatef(-45, 1, 0, 0);
	glTranslatef(0, 0.5, 0);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
	montaña_rusa.poste(0.5, 8, 30, tuberia.GLindex);
	glPopMatrix();
}


void medmalla(void)
{
	glPushMatrix();

	glEnable(GL_LIGHTING);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
	montaña_rusa.poste(0.5, 2, 30, tuberia.GLindex);
	glTranslatef(0, 0, -6);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
	montaña_rusa.poste(0.5, 2, 30, tuberia.GLindex);
	glTranslatef(0, 2, -0.5);
	glRotatef(90, 1, 0, 0);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
	montaña_rusa.poste(0.5, 7, 30, tuberia.GLindex);
	glRotatef(-90, 1, 0, 0);
	glTranslatef(0, -6, 0);
	glRotatef(90, 1, 0, 0);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
	montaña_rusa.poste(0.5, 7, 30, tuberia.GLindex);
	glPopMatrix();
}
void via(float largo)
{
	glEnable(GL_LIGHTING);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glRotatef(-90, 0, 0, 1);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
	montaña_rusa.poste(0.2, largo, 30, vias.GLindex);
	glPopMatrix();

	glTranslatef(0, 0, -6);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glRotatef(-90, 0, 0, 1);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
	montaña_rusa.poste(0.2, largo, 30, vias.GLindex);
	glPopMatrix();

}
void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();


	glPushMatrix();
	glRotatef(g_lookupdown, 1.0f, 0, 0);

	gluLookAt(objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z,
		objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
		objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);


	glPushMatrix();
	glPushMatrix(); //Creamos cielo
	glDisable(GL_LIGHTING);

	glPushMatrix();
	glTranslatef(0, 200, 0);
	sky.skybox(500.0, 500, 500.0, text1.GLindex);

	if (positional)
	{
		glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);

		glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, LightDirection);
	}
	else
		glLightfv(GL_LIGHT1, GL_POSITION, LightPosition1);

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glColor3f(1.0, 1.0, 0.0);

	if (!light)
	{
		glDisable(GL_LIGHTING);

	}
	else
	{
		glEnable(GL_LIGHTING);
	}

	glPushMatrix();
	glTranslatef(transX, transY, transZ);
	glRotatef(angleX, 1.0f, 0.0f, 0.0f);
	glRotatef(angleZ, 0.0f, 0.0f, 1.0f);
	glRotatef(angleY, 0.0f, 1.0f, 0.0f);
	glColor3f(1.0, 1.0, 1.0);
	glutSolidCube(400);
	//prisma();

	glPopMatrix();



	glPopMatrix();
	glEnable(GL_LIGHTING);
	glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();
	glPushMatrix();
	glDisable(GL_LIGHTING);

	//suelo del parque en general
	glPushMatrix();
	glEnable(GL_LIGHTING);
	glTranslatef(0, 0, -50);
	glColor3f(0,0.8,1.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
	piso.prisma(0.5, 400.0, 300.0, suelo.GLindex);
	glPopMatrix();

	//suelo estacionamiento
	glPushMatrix();
	glTranslatef(0, 0, 150);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
	piso.prisma(0.5, 400.0, 100.0, suelo_estacionamiento.GLindex);
	glPopMatrix();

	//Entrada al parque
	glPushMatrix();
	glTranslatef(0, 90, 107.5);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);	
	entrada.prisma(20, 150, 15, scale.GLindex);
	//letrero
	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(0, 0,8);
	glRotatef(90, 0, 1, 0);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
	adorno.prisma(60, 0.1, 60,letrero.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();


	//columna 1
	glTranslatef(90, -40, 0);
	entrada.prisma(100, 30, 15, scale.GLindex);

	//columna 2
	glTranslatef(-180, 0, 0);
	entrada.prisma(100, 30, 15, scale.GLindex);

	//Barda 1
	glTranslatef(-62.5, -25, 0);
	entrada.prisma(50, 95, 15, scale.GLindex);

	//Barda 
	glTranslatef(305, 0, 0);
	entrada.prisma(50, 95, 15, scale.GLindex);
	glPopMatrix();
	glPopMatrix();

	///////////////////////////////////////
	//////////////////////////////////////
	/////////MONTAÑA RUSA////////////////
	/////////////////////////////////////
	///////////////////////////////////

	//letrero
	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(-30, 0,65);
	glScalef(0.5, 0.5, 0.5);
	puesto.cartel(letrero_montañarusa.GLindex);

	glTranslatef(20, 0, 0);
	glScalef(1, 1, 1);
	puesto.cartel(yoshi1.GLindex);
	

	glPopMatrix();


	
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glColor3f(1,1,1);
	//carritos montaña rusa (4)
	glPushMatrix();
	glTranslatef(15, 0, 3.5);
	glTranslatef(x, y, z);
	glRotatef(180, 0, 1, 0);
	//carrito 1
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(0, 2.5, 0);
	glRotatef(gira,0,1,0);
	montaña_rusa.prisma5(4, 6, 7, carrito.GLindex);

	//asientos
	//asiento de atras
	glPushMatrix();
	glTranslatef(-1.5, 0, 0);
	montaña_rusa.prisma(2, 1, 3.8, castillo_negro.GLindex);
	//respaldo asiento de atras
	glPushMatrix();
	glTranslatef(-0.5, 0, 0);
	montaña_rusa.prisma(4.2, 0.1, 3.8, madera.GLindex);
	glPopMatrix();

	//asiento de adelante
	glTranslatef(3, 0, 0);
	montaña_rusa.prisma(2, 1, 3.8, castillo_negro.GLindex);
	glPushMatrix();
	glTranslatef(0, 2, 0);
	glRotatef(90, 0, 1, 0);
	monitozen();
	glPopMatrix();
	//respaldo asiento de atras
	glPushMatrix();
	glTranslatef(-0.5, 0, 0);
	montaña_rusa.prisma(4.2, 0.1, 3.8, madera.GLindex);
	glPopMatrix();

	glPopMatrix();
	//parte de enfrente del carrito
	glTranslatef(4.5, -1, 0);
	montaña_rusa.prisma(2, 3, 7, carrito.GLindex);
	glTranslatef(0, 2, 0);
	glRotatef(180, 0, 1, 0);
	montaña_rusa.triangulo(2, 3, 7, carrito.GLindex);
	glPopMatrix();
	glPopMatrix();//fin de los carritos
		//soportes
		//malla 1

	malla();
	glTranslatef(0, 0, 12);
	malla();
	//malla 2

	glTranslatef(-10, 0, 0);
	malla();
	glPushMatrix();
	glTranslatef(0, 0, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 6, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 6, 0);
	malla();
	glPopMatrix();
	//malla 3
	glTranslatef(-10, 0, 0);
	malla();
	glPushMatrix();
	glTranslatef(0, 0, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 6, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 6, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, -12);
	malla();
	glPopMatrix();
	//malla 4
	glTranslatef(-10, 0, 0);
	malla();
	glPushMatrix();
	glTranslatef(0, 0, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 6, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 6, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 18, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 18, -12);
	malla();
	glPopMatrix();
	//malla 5
	glTranslatef(-10, 0, 0);
	malla();
	glPushMatrix();
	glTranslatef(0, 0, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 6, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 6, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 18, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 18, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 24, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 24, -12);
	malla();
	glPopMatrix();

	//malla 6
	glTranslatef(0, 0, -30);
	glRotatef(90, 0, 1, 0);
	malla();
	glPushMatrix();
	glTranslatef(0, 0, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 6, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 6, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 18, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 18, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 24, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 24, -12);
	malla();
	glPopMatrix();

	//malla 7
	glRotatef(-90, 0, 1, 0);
	glTranslatef(0, 0, -15);
	glRotatef(90, 0, 1, 0);
	malla();
	glPushMatrix();
	glTranslatef(0, 0, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 6, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 6, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 18, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 18, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 24, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 24, -12);
	malla();
	glPopMatrix();

	//malla 8
	glRotatef(-90, 0, 1, 0);
	glTranslatef(0, 0, -15);
	glRotatef(90, 0, 1, 0);
	malla();
	glPushMatrix();
	glTranslatef(0, 0, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 6, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 6, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 18, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 18, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 24, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 24, -12);
	malla();
	glPopMatrix();

	//malla 10
	glRotatef(-90, 0, 1, 0);
	glTranslatef(20, 0, 0);
	glRotatef(90, 0, 1, 0);
	malla();
	glPushMatrix();
	glTranslatef(0, 0, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 6, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 6, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 18, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 18, -12);
	malla();
	glPopMatrix();

	//malla 11
	glRotatef(-90, 0, 1, 0);
	glTranslatef(0, 0, 15);
	glRotatef(90, 0, 1, 0);
	malla();
	glPushMatrix();
	glTranslatef(0, 0, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 6, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 6, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 18, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 18, -12);
	malla();
	glPopMatrix();


	//malla 12
	glRotatef(-90, 0, 1, 0);
	glTranslatef(0, 0, 15);
	glRotatef(90, 0, 1, 0);
	malla();
	glPushMatrix();
	glTranslatef(0, 0, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 6, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 6, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 18, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 18, -12);
	malla();
	glPopMatrix();


	//malla 13
	glRotatef(-90, 0, 1, 0);
	glTranslatef(20, 0, 0);
	glRotatef(90, 0, 1, 0);
	malla();
	glPushMatrix();
	glTranslatef(0, 0, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 6, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 6, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, -12);
	malla();
	glPopMatrix();


	//malla 14
	glRotatef(-90, 0, 1, 0);
	glTranslatef(0, 0, -15);
	glRotatef(90, 0, 1, 0);
	malla();
	glPushMatrix();
	glTranslatef(0, 0, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 6, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 6, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, -12);
	malla();
	glPopMatrix();

	//malla 15
	glRotatef(-90, 0, 1, 0);
	glTranslatef(0, 0, -15);
	glRotatef(90, 0, 1, 0);
	malla();
	glPushMatrix();
	glTranslatef(0, 0, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 6, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 6, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, 0);
	medmalla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, -12);
	medmalla();
	glPopMatrix();

	//malla 16
	glRotatef(-90, 0, 1, 0);
	glTranslatef(20, 0, 0);
	glRotatef(90, 0, 1, 0);
	malla();
	glPushMatrix();
	glTranslatef(0, 0, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 6, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 6, 0);
	malla();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 12, 0);
	medmalla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, -12);
	medmalla();
	glPopMatrix();


	//malla 17
	glRotatef(-90, 0, 1, 0);
	glTranslatef(0, 0, 15);
	glRotatef(90, 0, 1, 0);
	malla();
	glPushMatrix();
	glTranslatef(0, 0, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 6, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 6, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, 0);
	medmalla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, -12);
	medmalla();
	glPopMatrix();
	//malla 18
	glRotatef(-90, 0, 1, 0);
	glTranslatef(0, 0, 15);
	glRotatef(90, 0, 1, 0);
	malla();
	glPushMatrix();
	glTranslatef(0, 0, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 6, -12);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 6, 0);
	malla();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 12, 0);
	medmalla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, -12);
	medmalla();
	glPopMatrix();


	//malla 19
	glRotatef(-90, 0, 1, 0);
	glTranslatef(-20, 0, 10);
	malla();
	glPushMatrix();
	glTranslatef(0, 6, 0);
	malla();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 12, 0);
	medmalla();
	glPopMatrix();
	//malla 20
	glTranslatef(-10, 0, 0);
	malla();
	glPushMatrix();
	glTranslatef(0, 6, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, 0);
	medmalla();
	glPopMatrix();

	//malla 21
	glTranslatef(-10, 0, 0);
	malla();
	glPushMatrix();
	glTranslatef(0, 6, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, 0);
	medmalla();
	glPopMatrix();

	//malla 22
	glTranslatef(-10, 0, 0);
	malla();
	glPushMatrix();
	glTranslatef(0, 6, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, 0);
	medmalla();
	glPopMatrix();

	//malla 23
	glTranslatef(-10, 0, 0);
	malla();
	glPushMatrix();
	glTranslatef(0, 6, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, 0);
	medmalla();
	glPopMatrix();

	//malla 24
	glTranslatef(-10, 0, 0);
	malla();
	glPushMatrix();
	glTranslatef(0, 6, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, 0);
	medmalla();
	glPopMatrix();

	//malla 25
	glTranslatef(-10, 0, 0);
	malla();
	glPushMatrix();
	glTranslatef(0, 6, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, 0);
	medmalla();
	glPopMatrix();

	//malla 26
	glTranslatef(-10, 0, -10);
	glRotatef(90, 0, 1, 0);
	malla();
	glPushMatrix();
	glTranslatef(0, 6, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, 0);
	medmalla();
	glPopMatrix();


	//malla 27
	glRotatef(-90, 0, 1, 0);
	glTranslatef(0, 0, -15);
	glRotatef(90, 0, 1, 0);
	malla();
	glPushMatrix();
	glTranslatef(0, 6, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, 0);
	medmalla();
	glPopMatrix();

	//malla 28
	glRotatef(-90, 0, 1, 0);
	glTranslatef(0, 0, -15);
	glRotatef(90, 0, 1, 0);
	malla();
	glPushMatrix();
	glTranslatef(0, 6, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, 0);
	medmalla();
	glPopMatrix();

	//malla 29
	glRotatef(-90, 0, 1, 0);
	glTranslatef(10, 0, -10);
	malla();
	glPushMatrix();
	glTranslatef(0, 6, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, 0);
	medmalla();
	glPopMatrix();

	//malla 30
	glTranslatef(10, 0, 0);
	malla();
	glPushMatrix();
	glTranslatef(0, 6, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, 0);
	medmalla();
	glPopMatrix();


	//malla 31
	glTranslatef(10, 0, 0);
	malla();
	glPushMatrix();
	glTranslatef(0, 6, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, 0);
	medmalla();
	glPopMatrix();


	//malla 32
	glTranslatef(10, 0, 0);
	malla();
	glPushMatrix();
	glTranslatef(0, 6, 0);
	malla();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 12, 0);
	medmalla();
	glPopMatrix();

	//malla 33
	glTranslatef(10, 0, 0);
	malla();
	glPushMatrix();
	glTranslatef(0, 4, 0);
	malla();
	glPopMatrix();

	//malla 34
	glTranslatef(10, 0, 0);
	malla();

	//via
	glTranslatef(10, 1, 0);
	via(30);
	glRotatef(180, 1, 0, 0);
	glTranslatef(30, 0, 0);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glRotatef(-90, 0, 0, 1);
	montaña_rusa.poste(0.2, 6, 30, scale.GLindex);// vuelta1
	glPopMatrix();
	glTranslatef(6, 0, -1.5);
	glPushMatrix();
	glTranslatef(2, 0, 0);
	glRotatef(90, 1, 0, 0);
	glRotatef(180, 0, 0, 1);
	montaña_rusa.poste(0.2, 6, 30, scale.GLindex);// vuelta1
	glPopMatrix();
	montaña_rusa.vuelta4(1, 2, 100, 10);
	glTranslatef(-6, 0, -6);
	montaña_rusa.vuelta4(1, 2, 100, 10);
	glTranslatef(8, 0, 0);
	glRotatef(90, 0, 1, 0);



	via(55);
	glTranslatef(55, 0, 6);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glRotatef(-90, 0, 0, 1);
	montaña_rusa.poste(0.2, 6, 30, scale.GLindex);// vuelta2
	glPopMatrix();
	glTranslatef(6, 0, -1.5);
	glPushMatrix();
	glTranslatef(2, 0, 0);
	glRotatef(90, 1, 0, 0);
	glRotatef(180, 0, 0, 1);
	montaña_rusa.poste(0.2, 6, 30, scale.GLindex);// vuelta2
	glPopMatrix();
	montaña_rusa.vuelta4(1, 2, 100, 10);
	glTranslatef(-6, 0, -6);
	montaña_rusa.vuelta4(1, 2, 100, 10);
	glTranslatef(8, 0, 0);

	glRotatef(90, 0, 1, 0);
	via(20);
	glTranslatef(20, 0, 5.5);
	glRotatef(-30.3, 0, 0, 1);
	via(58);//subida
	glRotatef(30.3, 0, 0, 1);
	glRotatef(180, 1, 0, 0);
	glTranslatef(50, 29.5, 0);
	via(6);
	glTranslatef(5, 0, 0);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glRotatef(-90, 0, 0, 1);
	montaña_rusa.poste(0.2, 6, 30, scale.GLindex);// vuelta3
	glPopMatrix();
	glTranslatef(6, 0, -1.5);
	glPushMatrix();
	glTranslatef(1.5, 0, 8);
	glRotatef(-90, 1, 0, 0);
	montaña_rusa.poste(0.2, 6, 30, scale.GLindex);// vuelta3
	glPopMatrix();
	glRotatef(180, 1, 0, 0);
	glTranslatef(0, 0, -3);
	montaña_rusa.vuelta4(1, 2, 100, 10);
	glTranslatef(-6, 0, -6);
	montaña_rusa.vuelta4(1, 2, 100, 10);
	glTranslatef(7.5, 0, 1);
	glRotatef(90, 0, 1, 0);


	via(50);
	glRotatef(180, 1, 0, 0);
	glTranslatef(50, 0, 0);
	via(6);
	glTranslatef(5, 0, 0);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glRotatef(-90, 0, 0, 1);
	montaña_rusa.poste(0.2, 6, 30, scale.GLindex);// vuelta4
	glPopMatrix();
	glTranslatef(6, 0, -1.5);
	glPushMatrix();
	glTranslatef(1.5, 0, 8);
	glRotatef(-90, 1, 0, 0);
	montaña_rusa.poste(0.2, 6, 30, scale.GLindex);// vuelta4
	glPopMatrix();
	glRotatef(180, 1, 0, 0);
	glTranslatef(0, 0, -3);
	montaña_rusa.vuelta4(1, 2, 100, 10);
	glTranslatef(-6, 0, -6);
	montaña_rusa.vuelta4(1, 2, 100, 10);
	glTranslatef(7.5, 0, 1);
	glRotatef(90, 0, 1, 0);

	via(6);
	glTranslatef(6, 0, 6);
	glRotatef(35, 0, 0, 1);
	via(9);

	glRotatef(180, 1, 0, 0);
	via(6);
	glTranslatef(6, 0, 0);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glRotatef(-90, 0, 0, 1);
	montaña_rusa.poste(0.2, 5.5, 30, scale.GLindex);// vuelta5
	glPopMatrix();
	glTranslatef(11, 1, -1.5);
	glPushMatrix();
	glTranslatef(-3, 1.5, 8);
	glRotatef(-90, 1, 0, 0);
	montaña_rusa.poste(0.2, 6, 30, scale.GLindex);// vuelta5
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-3, 1.5, 1.5);
	glRotatef(130, 0, 0, 1);
	montaña_rusa.poste(0.2, 4, 30, scale.GLindex);// vuelta5
	glPopMatrix();
	glRotatef(180, 1, 0, 0);
	glRotatef(-30.4, 0, 0, 1);
	glTranslatef(-3, -3, -3);
	montaña_rusa.vuelta4(1, 2, 100, 10);
	glTranslatef(-5.5, 0, -6);
	montaña_rusa.vuelta4(1, 2, 100, 10);
	glTranslatef(6.7, 0.1, 1);
	glRotatef(90, 0, 1, 0);


	via(34);
	glRotatef(180, 1, 0, 0);
	glTranslatef(34, 0, 0);
	via(6);
	glTranslatef(5, 0, 6);
	glRotatef(-180, 1, 0, 0);
	glPushMatrix();
	glRotatef(-90, 0, 0, 1);
	montaña_rusa.poste(0.2, 6, 30, scale.GLindex);// vuelta6
	glPopMatrix();
	glTranslatef(6, 0, -1.5);
	glPushMatrix();
	glTranslatef(1.5, 0, 8);
	glRotatef(-90, 1, 0, 0);
	montaña_rusa.poste(0.2, 6, 30, scale.GLindex);// vuelta6
	glPopMatrix();
	glRotatef(180, 1, 0, 0);
	glTranslatef(0, 0, -3);
	montaña_rusa.vuelta4(1, 2, 100, 10);
	glTranslatef(-6, 0, -6);
	montaña_rusa.vuelta4(1, 2, 100, 10);
	glTranslatef(7.5, 0, 1);
	glRotatef(90, 0, 1, 0);


	via(6);
	glTranslatef(6, 0, 6);
	glRotatef(-35, 0, 0, 1);
	via(9);

	glRotatef(180, 1, 0, 0);
	via(6);
	glTranslatef(9, 0, 0);
	glRotatef(-45, 0, 0, 1);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glRotatef(8, 0, 1, 0);
	glRotatef(-90, 0, 0, 1);
	montaña_rusa.poste(0.2, 7, 30, scale.GLindex);// vuelta7
	glPopMatrix();
	glTranslatef(11, 0, -1.5);
	glPushMatrix();
	glTranslatef(-3.5, 0.5, 8);
	glRotatef(-90, 1, 0, 0);
	montaña_rusa.poste(0.2, 6, 30, scale.GLindex);// vuelta7
	glPopMatrix();
	glRotatef(180, 1, 0, 0);
	glTranslatef(-5, -.5, -3);
	montaña_rusa.vuelta4(1, 2, 100, 10);
	glTranslatef(-6, 0.5, -6);
	montaña_rusa.vuelta4(1, 2, 100, 10);
	glTranslatef(7.5, -0.5, 1);
	glRotatef(90, 0, 1, 0);

	via(40);
	glRotatef(180, 1, 0, 0);
	glTranslatef(40, 0, 0);
	via(6);
	glTranslatef(0, 0, 6);
	glRotatef(180, 1, 0, 0);
	glTranslatef(5, 0, 0);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glRotatef(-90, 0, 0, 1);
	montaña_rusa.poste(0.2, 6, 30, scale.GLindex);// vuelta8
	glPopMatrix();
	glTranslatef(6, 0, -1.5);
	glPushMatrix();
	glTranslatef(1.5, 0, 8);
	glRotatef(-90, 1, 0, 0);
	montaña_rusa.poste(0.2, 6, 30, scale.GLindex);// vuelta8
	glPopMatrix();
	glRotatef(180, 1, 0, 0);
	glTranslatef(0, 0, -3);
	montaña_rusa.vuelta4(1, 2, 100, 10);
	glTranslatef(-6, 0, -6);
	montaña_rusa.vuelta4(1, 2, 100, 10);
	glTranslatef(7.5, 0, 1);
	glRotatef(90, 0, 1, 0);
	via(6);
	glTranslatef(6, 0, 6);
	glRotatef(35, 0, 0, 1);
	via(9);

	glRotatef(180, 1, 0, 0);
	via(6);
	glTranslatef(6, 0, 0);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glRotatef(-90, 0, 0, 1);
	montaña_rusa.poste(0.2, 5.5, 30, scale.GLindex);// vuelta9
	glPopMatrix();
	glTranslatef(11, 1, -1.5);
	glPushMatrix();
	glTranslatef(-3, 1.5, 8);
	glRotatef(-90, 1, 0, 0);
	montaña_rusa.poste(0.2, 6, 30, scale.GLindex);// vuelta9
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-3, 1.5, 1.5);
	glRotatef(130, 0, 0, 1);
	montaña_rusa.poste(0.2, 4, 30, scale.GLindex);// vuelta9
	glPopMatrix();
	glRotatef(180, 1, 0, 0);
	glRotatef(-30.4, 0, 0, 1);
	glTranslatef(-3, -3, -3);
	montaña_rusa.vuelta4(1, 2, 100, 10);
	glTranslatef(-5.5, 0, -6);
	montaña_rusa.vuelta4(1, 2, 100, 10);
	glTranslatef(6.7, 0.1, 1);
	glRotatef(90, 0, 1, 0);



	via(42);
	glRotatef(180, 1, 0, 0);
	glTranslatef(42, 0, 0);
	via(6);
	glTranslatef(5, 0, 0);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glRotatef(-90, 0, 0, 1);
	montaña_rusa.poste(0.2, 6, 30, scale.GLindex);// vuelta10
	glPopMatrix();
	glTranslatef(6, 0, -1.5);
	glPushMatrix();
	glTranslatef(1.5, 0, 8);
	glRotatef(-90, 1, 0, 0);
	montaña_rusa.poste(0.2, 6, 30, scale.GLindex);// vuelta10
	glPopMatrix();
	glRotatef(180, 1, 0, 0);
	glTranslatef(0, 0, -3);
	montaña_rusa.vuelta4(1, 2, 100, 10);
	glTranslatef(-6, 0, -6);
	montaña_rusa.vuelta4(1, 2, 100, 10);
	glTranslatef(7.5, 0, 1);
	glRotatef(90, 0, 1, 0);

	glRotatef(-1, 0, 0, 1);
	via(71);
	glRotatef(180, 1, 0, 0);
	glTranslatef(71, 0, 0);
	via(6);
	glTranslatef(5, 0, 0);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glRotatef(-90, 0, 0, 1);
	montaña_rusa.poste(0.2, 6, 30, scale.GLindex);// vuelta11
	glPopMatrix();
	glTranslatef(6, 0, -1.5);
	glPushMatrix();
	glTranslatef(1.5, 0, 8);
	glRotatef(-90, 1, 0, 0);
	montaña_rusa.poste(0.2, 6, 30, scale.GLindex);// vuelta11
	glPopMatrix();

	glRotatef(180, 1, 0, 0);
	glTranslatef(0, 0, -3);
	montaña_rusa.vuelta4(1, 2, 100, 10);
	glTranslatef(-6, 0, -6);
	montaña_rusa.vuelta4(1, 2, 100, 10);
	glTranslatef(7.5, 0, 1);
	glRotatef(90, 0, 1, 0);

	via(37);
	glRotatef(180, 1, 0, 0);
	glTranslatef(37, 0, 0);
	via(6);
	glTranslatef(5, 0, 0);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glRotatef(-90, 0, 0, 1);
	montaña_rusa.poste(0.2, 6, 30, scale.GLindex);// vuelta12
	glPopMatrix();
	glTranslatef(6, 0, -1.5);
	glPushMatrix();
	glTranslatef(1.5, 0, 8);
	glRotatef(-90, 1, 0, 0);
	montaña_rusa.poste(0.2, 6, 30, scale.GLindex);// vuelta12
	glPopMatrix();
	glRotatef(180, 1, 0, 0);
	glTranslatef(0, 0, -3);
	montaña_rusa.vuelta4(1, 2, 100, 10);
	glTranslatef(-6, 0, -6);
	montaña_rusa.vuelta4(1, 2, 100, 10);
	glTranslatef(7.5, 0, 1);
	glRotatef(90, 0, 1, 0);

	via(40);
	glTranslatef(40, 0, 6);
	glRotatef(22.5, 0, 0, 1);
	via(34);//bajada
	glRotatef(-30, 0, 0, 1);

	glPopMatrix();
	glColor3f(1, 1, 1);

	glEnable(GL_LIGHTING);


	//cerca montaña rusa


	glPushMatrix();

	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);

	glTranslatef(0, 0, -10);

	glRotatef(90, 0, 1, 0);

	puesto.prisma6(20, 140, 100, valla.GLindex);




	glTranslatef(-70, 0, 43);

	glScalef(0.7, 0.7, 0.7);

	glRotatef(90, 0, 1, 0);
	puesto.cartel(valla.GLindex);


	glTranslatef(20, 0, 0);
	puesto.cartel(valla.GLindex);

	glTranslatef(20, 0, 0);
	puesto.cartel(valla.GLindex);

	glTranslatef(20, 0, 0);
	puesto.cartel(valla.GLindex);

	glTranslatef(20, 0, 0);

	puesto.cartel(valla.GLindex);

	glTranslatef(20, 0, 0);

	puesto.cartel(valla.GLindex);


	glDisable(GL_ALPHA_TEST);

	glPopMatrix();



	/////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////
	//DIBUJO DE BANQUITAS, PUESTOS Y DEMAS, LADO IZQUIERDO//
	///////////////////////////////////////////////////////
	///////////////////////////////////////////////////////

	//adornos
	//mario
	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(-160, 0, -15);
	glScalef(0.5, 0.5, 0.5);
	glRotatef(90, 0, 1, 0);
	puesto.cartel(mario.GLindex);
	glPopMatrix();

	//yoshi
	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(-160, 0, 78);
	glScalef(0.5, 0.5, 0.5);
	glRotatef(90, 0, 1, 0);
	puesto.cartel(yoshi.GLindex);
	glPopMatrix();

	//////////
	// Tacitas
	//////////

	//letrero tacitas

	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(-160, 0, 68);
	glScalef(0.5, 0.5, 0.5);
	glRotatef(90, 0, 1, 0);
	puesto.cartel(letrero_tacitas.GLindex);
	glPopMatrix();


	//cerca sillitas

	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(-180, 0, 50);
	glRotatef(180, 0, 1, 0);
	puesto.prisma6(10, 30, 30, valla.GLindex);

	glTranslatef(-10, 0, 47);
	glScalef(0.3, 0.3, 0.3);
	glRotatef(90, 0, 1, 0);
	puesto.cartel(valla.GLindex);

	glTranslatef(20, 0, 0);
	puesto.cartel(valla.GLindex); 
	glTranslatef(20, 0, 0);
	puesto.cartel(valla.GLindex);

	glDisable(GL_ALPHA_TEST);
	glPopMatrix();


	
	//base de las tacitas circular
	glPushMatrix();
	glTranslatef(-180, 5, 50);

	glPushMatrix();
	glTranslatef(0, 5, 20);
	glPopMatrix();
	glRotatef(tacitas, 0.0, 1.0, 0.0);	// la estructura gira sobre su eje
	jardinera1_1.vuelta8(6, 8, 100, 12);
	//base pegada al piso
	glTranslatef(0, -5, 0);
	jardinera1_1.poste(0.5, 5, 120, tuberia.GLindex);
	//TUBOS QUE UNEN LA BASE DEL PISO CON LA BASE DE LAS TACITAS
	glPushMatrix();
	glTranslatef(6, 5, 0);
	glRotatef(90, 0, 0, 1);
	jardinera1_1.poste(0.3, 12, 120, tuberia.GLindex);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 5, -5);
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 1, 0, 0);
	jardinera1_1.poste(0.3, 12, 120, tuberia.GLindex);
	//cabinitas
	glPushMatrix();
	glTranslatef(2.8, -3, 0);
	glRotatef(90, 0, 0, 1);
	glRotatef(270, 1, 0, 0);
	jardinera1_1.mediaesfera(2, 12, 120, tacita.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.8, 12, 0);
	glRotatef(90, 0, 0, 1);
	glRotatef(270, 1, 0, 0);
	jardinera1_1.mediaesfera(2, 12, 120, tacita.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.8, 5, -6);
	glRotatef(90, 0, 0, 1);
	glRotatef(270, 1, 0, 0);
	jardinera1_1.mediaesfera(2, 12, 120, tacita.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.8, 5, 6);
	glRotatef(90, 0, 0, 1);
	glRotatef(270, 1, 0, 0);
	jardinera1_1.mediaesfera(2, 12, 120, tacita.GLindex);
	glPopMatrix();
	glPopMatrix();
	glEnable(GL_LIGHTING);
	glPopMatrix();
	//fin tacitas



	////////////////////////
	////SILLAS VOLADORAS///
	/////////////////////////

	//letrero letrero sillitas
	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(-160, 0, -5);
	glScalef(0.5, 0.5, 0.5);
	glRotatef(90, 0, 1, 0);
	puesto.cartel(letrero_sillitas.GLindex);
	glPopMatrix();



	//cerca sillitas

	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(-180, 0, 10);
	glRotatef(180, 0, 1, 0);
	puesto.prisma6(10, 20, 20, valla.GLindex);

	glTranslatef(-15, 0, -28);
	glScalef(0.3, 0.3, 0.3);
	glRotatef(90, 0, 1, 0);
	puesto.cartel(valla.GLindex);
	glTranslatef(20, 0, 0);
	puesto.cartel(valla.GLindex);
	glTranslatef(20, 0, 0);
	puesto.cartel(valla.GLindex);
	glTranslatef(20, 0, 0);
	puesto.cartel(valla.GLindex);
	
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();


	glDisable(GL_ALPHA_TEST);
	glPopMatrix();


	

	//base pegada al piso
	glPushMatrix();
	glTranslatef(-180, 5, 30);

	glPushMatrix();
	glTranslatef(0, -5, -20);
	jardinera1_1.poste(0.1, 15, 120, tuberia.GLindex);
	//TECHO
	glPopMatrix();
	glTranslatef(0, 10, -20);
	glRotatef(tacitas, 0.0, 1.0, 0.0);	// la estructura gira sobre su eje
	jardinera1_1.prisma(0.1, 10, 10, tuberia.GLindex);
	//CUERDAS

	glPushMatrix();
	glTranslatef(4, -5, 4);
	glRotatef(tacitas, 0.0, 1.0, 0.0);	// la estructura gira sobre su eje
	jardinera1_1.poste(0.1, 5, 120, tuberia.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4, -5, 4);
	glRotatef(tacitas, 0.0, 1.0, 0.0);	// la estructura gira sobre su eje
	jardinera1_1.poste(0.1, 5, 120, tuberia.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4, -5, -4);
	glRotatef(tacitas, 0.0, 1.0, 0.0);	// la estructura gira sobre su eje
	jardinera1_1.poste(0.1, 5, 120, tuberia.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4, -5, -4);
	glRotatef(tacitas, 0.0, 1.0, 0.0);	// la estructura gira sobre su eje
	jardinera1_1.poste(0.1, 5, 120, tuberia.GLindex);
	glPopMatrix();

	//sillitas
	glPushMatrix();
	glTranslatef(4, -5, 3.5);
	glRotatef(90, 0, 0, 1);
	glRotatef(270, 1, 0, 0);
	glRotatef(90, 0, 0, 1);
	glRotatef(270, 1, 0, 0);
	jardinera1_1.mediaesfera(0.5, 12, 120, tacita.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4, -5, 3.5);
	glRotatef(90, 0, 0, 1);
	glRotatef(270, 1, 0, 0);
	glRotatef(90, 0, 0, 1);
	glRotatef(270, 1, 0, 0);
	jardinera1_1.mediaesfera(0.5, 12, 120, tacita.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4, -5, -3.5);
	glRotatef(90, 0, 0, 1);
	glRotatef(270, 1, 0, 0);
	glRotatef(90, 0, 0, 1);
	glRotatef(270, 1, 0, 0);
	jardinera1_1.mediaesfera(0.5, 12, 120, tacita.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4, -5, -3.5);
	glRotatef(90, 0, 0, 1);
	glRotatef(270, 1, 0, 0);
	glRotatef(90, 0, 0, 1);
	glRotatef(270, 1, 0, 0);
	jardinera1_1.mediaesfera(0.5, 12, 120, tacita.GLindex);
	glPopMatrix();


	glEnable(GL_LIGHTING);
	glPopMatrix();
	//fin tacitas






	glPushMatrix();//Faro1 pegado a la jardinera
	glTranslatef(-180.0, 0.0, -25.0);
	glColor3fv(gris);
	posteinf.poste(0.1, 20, 40, 0);
	glTranslatef(0.0, 20.0, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	postesup.poste(0.07, 2.0, 40.0, 0);
	glTranslatef(0.0, 2.0, 0.0);
	glColor3fv(amarillo);

	lamp.mediaesfera(1.0, 30.0, 30.0, 0);
	glColor3f(1.0, 1.0, 1.0);

	glPopMatrix();

	glDisable(GL_LIGHTING);


	//glDisable(GL_LIGHTING);

	glPushMatrix();//Faro 2
	glTranslatef(-180.0, 0.0, -45.0);
	glColor3fv(gris);
	posteinf.poste(0.1, 20, 40, 0);
	glTranslatef(0.0, 20.0, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	postesup.poste(0.07, 2.0, 40.0, 0);
	glTranslatef(0.0, 2.0, 0.0);
	glColor3fv(amarillo);
	lamp.mediaesfera(1.0, 30.0, 30.0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();

	glPushMatrix();//Faro3
	glTranslatef(-180.0, 0.0, -110.0);
	glColor3fv(gris);
	posteinf.poste(0.1, 20, 40, 0);
	glTranslatef(0.0, 20.0, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	postesup.poste(0.07, 2.0, 40.0, 0);
	glTranslatef(0.0, 2.0, 0.0);
	glColor3fv(amarillo);
	lamp.mediaesfera(1.0, 30.0, 30.0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();
	glDisable(GL_LIGHTING);

	glPushMatrix();//Faro 4
	glTranslatef(-180.0, 0.0, -130.0);
	glColor3fv(gris);
	posteinf.poste(0.1, 20, 40, 0);
	glTranslatef(0.0, 20.0, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	postesup.poste(0.07, 2.0, 40.0, 0);
	glTranslatef(0.0, 2.0, 0.0);
	glColor3fv(amarillo);
	lamp.mediaesfera(1.0, 30.0, 30.0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();
	glDisable(GL_LIGHTING);

	//Banquitas

	//banquita pegada a la jardinera izquierda
	glPushMatrix();
	glTranslatef(-180, 2, -35);
	glRotatef(90, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, LunaNeptuno2Diffuse);//para aplicar los materiales y funciona como glcolor
	glMaterialfv(GL_FRONT, GL_SPECULAR, LunaNeptuno2Diffuse);
	glMaterialfv(GL_FRONT, GL_SHININESS, LunaNeptuno2Diffuse);

	glEnable(GL_LIGHTING); //Habilita el sombreado para los demás planetas
	asiento.prisma(1, 15, 3, madera.GLindex);

	glTranslatef(6, -0.5, 0);

	patas_asiento.prisma(1, 1, 3, madera.GLindex);

	glTranslatef(-12, -0.5, 0);
	patas_asiento.prisma(1, 1, 3, madera.GLindex);
	glPopMatrix();

	//banquita pegada al puesto lado izquierdo
	glPushMatrix();
	glTranslatef(-180, 2, -120);
	glRotatef(90, 0, 1, 0);
	asiento.prisma(1, 15, 3, madera.GLindex);

	glTranslatef(6, -0.5, 0);
	patas_asiento.prisma(1, 1, 3, madera.GLindex);

	glTranslatef(-12, -0.5, 0);
	patas_asiento.prisma(1, 1, 3, madera.GLindex);
	glPopMatrix();


	//////////////////////
	//PUESTOS DE COMIDA//
	/////////////////////

	//presentación área de comida

	//pilar 1
	glPushMatrix();
	glTranslatef(-190, 0, -50);
	entrada.prisma(40, 2, 2, madera.GLindex);

	//pilar 2
	glTranslatef(0, 0, -60);
	entrada.prisma(40, 2, 2, madera.GLindex);

	//anuncio
	glTranslatef(0, 22, 30);
	glRotatef(90, 0, 1, 0);
	glRotatef(90, 0, 1, 0);
	entrada.prisma(4, 2, 62, madera.GLindex);

	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(-1, 0, 0);
	entrada.prisma(15, 0.05, 30, comida.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	/////////////////
	glDisable(GL_LIGHTING);//el no necesita sombra ya que funciona como sol
	//puesto 1 
	glPushMatrix();

	//cajita
	glPushMatrix();
	glTranslatef(-180, 0, -55);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(10, 10, 5, puesto_azul.GLindex);

	//fondo de acuerdo a la comida (palomitas)
	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(0, 9, -2.5);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(8, 0.1, 10, palomitas.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();


	//
	glPushMatrix();
	glTranslatef(-5, 5, 0);
	puesto.poste(0.1, 5, 120, puesto_azul.GLindex);
	glTranslatef(0, 0, -2.2);
	puesto.poste(0.1, 5, 120, puesto_azul.GLindex);
	glPopMatrix();

	//
	glPushMatrix();
	glTranslatef(5, 5, 0);
	puesto.poste(0.1, 5, 120, puesto_azul.GLindex);
	glTranslatef(0, 0, -2.2);
	puesto.poste(0.1, 5, 120, puesto_azul.GLindex);
	glPopMatrix();

	// toldo
	glPushMatrix();

	glTranslatef(0, 10, 0);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(5, 0.1, 11, puesto_azul.GLindex);
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();



	glPopMatrix();

	//puesto 2 
	glPushMatrix();
	glTranslatef(-180, 0, -70);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(10, 10, 5, puesto_rojo.GLindex);

	//fondo de acuerdo al juego (globos)
	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(0, 9, -2.5);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(8, 0.1, 10, algodon.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();


	//
	glPushMatrix();
	glTranslatef(-5, 5, 0);
	puesto.poste(0.1, 5, 120, puesto_azul.GLindex);
	glTranslatef(0, 0, -2.2);
	puesto.poste(0.1, 5, 120, puesto_azul.GLindex);
	glPopMatrix();

	//
	glPushMatrix();
	glTranslatef(5, 5, 0);
	puesto.poste(0.1, 5, 120, puesto_azul.GLindex);
	glTranslatef(0, 0, -2.2);
	puesto.poste(0.1, 5, 120, puesto_azul.GLindex);
	glPopMatrix();

	// toldo
	glPushMatrix();

	glTranslatef(0, 10, 0);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(5, 0.1, 11, puesto_azul.GLindex);
	glPopMatrix();
	glPopMatrix();


	//puesto 3 
	glPushMatrix();
	glTranslatef(-180, 0, -85);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(10, 10, 5, puesto_azul.GLindex);

	//fondo de acuerdo al juego (globos)
	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(0, 9, -2.5);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(8, 0.1, 10, hamburguesa.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	//
	glPushMatrix();
	glTranslatef(-5, 5, 0);
	puesto.poste(0.1, 5, 120, puesto_azul.GLindex);
	glTranslatef(0, 0, -2.2);
	puesto.poste(0.1, 5, 120, puesto_azul.GLindex);
	glPopMatrix();

	//
	glPushMatrix();
	glTranslatef(5, 5, 0);
	puesto.poste(0.1, 5, 120, puesto_azul.GLindex);
	glTranslatef(0, 0, -2.2);
	puesto.poste(0.1, 5, 120, puesto_azul.GLindex);
	glPopMatrix();

	// toldo
	glPushMatrix();

	glTranslatef(0, 10, 0);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(5, 0.1, 11, puesto_azul.GLindex);
	glPopMatrix();
	glPopMatrix();

	//puesto 4
	glPushMatrix();
	glTranslatef(-180, 0, -100);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(10, 10, 5, puesto_azul.GLindex);

	//fondo de acuerdo al juego (globos)
	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(0, 9, -2.5);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(8, 0.1, 10, hamburguesa.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	//
	glPushMatrix();
	glTranslatef(-5, 5, 0);
	puesto.poste(0.1, 5, 120, puesto_azul.GLindex);
	glTranslatef(0, 0, -2.2);
	puesto.poste(0.1, 5, 120, puesto_azul.GLindex);
	glPopMatrix();

	//
	glPushMatrix();
	glTranslatef(5, 5, 0);
	puesto.poste(0.1, 5, 120, puesto_azul.GLindex);
	glTranslatef(0, 0, -2.2);
	puesto.poste(0.1, 5, 120, puesto_azul.GLindex);
	glPopMatrix();

	// toldo
	glPushMatrix();

	glTranslatef(0, 10, 0);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(5, 0.1, 11, puesto_azul.GLindex);
	glPopMatrix();
	glPopMatrix();

	
	//////////////////////
	//juegos de destreza//
	/////////////////////

	//presentación juegos de destreza

	//pilar 1
	glPushMatrix();
	glTranslatef(-190, 0, -140);
	entrada.prisma(40, 2, 2, madera.GLindex);

	//pilar 2
	glTranslatef(0, 0, -60);
	entrada.prisma(40, 2, 2, madera.GLindex);

	//anuncio
	glTranslatef(0, 22, 30);
	glRotatef(90, 0, 1, 0);
	glRotatef(90, 0, 1, 0);
	entrada.prisma(4, 2, 62, madera.GLindex);

	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(-1, 0, 0);
	entrada.prisma(15, 0.05, 30, juegos.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	/////////////////

	//puesto 5
	glPushMatrix();
	glTranslatef(-180, 0, -140);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(10, 10, 5, puesto_azul.GLindex);


	//fondo de acuerdo al juego (globos)
	glPushMatrix();
	glTranslatef(0, 9, -2.5);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(8, 0.1, 10, globos.GLindex);
	glPopMatrix();


	//
	glPushMatrix();
	glTranslatef(-5, 5, 0);
	puesto.poste(0.1, 8, 120, puesto_azul.GLindex);
	glTranslatef(0, 0, -2.2);
	puesto.poste(0.1, 8, 120, puesto_azul.GLindex);
	glPopMatrix();

	//
	glPushMatrix();
	glTranslatef(5, 5, 0);
	puesto.poste(0.1, 8, 120, puesto_azul.GLindex);
	glTranslatef(0, 0, -2.2);
	puesto.poste(0.1, 8, 120, puesto_azul.GLindex);
	glPopMatrix();

	//toldo
	glPushMatrix();
	glTranslatef(0, 13, 0);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(5, 0.1, 11, puesto_azul.GLindex);
	glPopMatrix();
	glPopMatrix();

	//puesto 6
	glPushMatrix();
	glTranslatef(-180, 0, -155);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(10, 10, 5, puesto_azul.GLindex);


	//fondo de acuerdo al juego (globos)
	glPushMatrix();
	glTranslatef(0, 9, -2.5);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(8, 0.1, 10, patitos.GLindex);
	glPopMatrix();


	//
	glPushMatrix();
	glTranslatef(-5, 5, 0);
	puesto.poste(0.1, 8, 120, puesto_azul.GLindex);
	glTranslatef(0, 0, -2.2);
	puesto.poste(0.1, 8, 120, puesto_azul.GLindex);
	glPopMatrix();

	//
	glPushMatrix();
	glTranslatef(5, 5, 0);
	puesto.poste(0.1, 8, 120, puesto_azul.GLindex);
	glTranslatef(0, 0, -2.2);
	puesto.poste(0.1, 8, 120, puesto_azul.GLindex);
	glPopMatrix();

	//toldo
	glPushMatrix();
	glTranslatef(0, 13, 0);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(5, 0.1, 11, puesto_azul.GLindex);
	glPopMatrix();
	glPopMatrix();



	//puesto 7
	glPushMatrix();
	glTranslatef(-180, 0, -170);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(10, 10, 5, puesto_azul.GLindex);


	//fondo de acuerdo al juego (globos)
	glPushMatrix();
	glTranslatef(0, 9, -2.5);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(8, 0.1, 10, globos.GLindex);
	glPopMatrix();


	//
	glPushMatrix();
	glTranslatef(-5, 5, 0);
	puesto.poste(0.1, 8, 120, puesto_azul.GLindex);
	glTranslatef(0, 0, -2.2);
	puesto.poste(0.1, 8, 120, puesto_azul.GLindex);
	glPopMatrix();

	//
	glPushMatrix();
	glTranslatef(5, 5, 0);
	puesto.poste(0.1, 8, 120, puesto_azul.GLindex);
	glTranslatef(0, 0, -2.2);
	puesto.poste(0.1, 8, 120, puesto_azul.GLindex);
	glPopMatrix();

	//toldo
	glPushMatrix();
	glTranslatef(0, 13, 0);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(5, 0.1, 11, puesto_azul.GLindex);
	glPopMatrix();
	glPopMatrix();

	//puesto 8
	glPushMatrix();
	glTranslatef(-180, 0, -185);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(10, 10, 5, puesto_azul.GLindex);

	//fondo de acuerdo al juego (globos)
	glPushMatrix();
	glTranslatef(0, 9, -2.5);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(8, 0.1, 10, patitos.GLindex);
	glPopMatrix();


	//
	glPushMatrix();
	glTranslatef(-5, 5, 0);
	puesto.poste(0.1, 8, 120, puesto_azul.GLindex);
	glTranslatef(0, 0, -2.2);
	puesto.poste(0.1, 8, 120, puesto_azul.GLindex);
	glPopMatrix();

	//
	glPushMatrix();
	glTranslatef(5, 5, 0);
	puesto.poste(0.1, 8, 120, puesto_azul.GLindex);
	glTranslatef(0, 0, -2.2);
	puesto.poste(0.1, 8, 120, puesto_azul.GLindex);
	glPopMatrix();

	//toldo
	glPushMatrix();
	glTranslatef(0, 13, 0);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(5, 0.1, 11, puesto_azul.GLindex);
	glPopMatrix();
	glPopMatrix();

	glEnable(GL_LIGHTING);

	
	///////////////////////////////////////////////////////
	///////////////////////////////////////////////////////
	//DIBUJO DE BANQUITAS, PUESTOS Y DEMAS, LADO DERECHO//
	//////////////////////////////////////////////////////
	//////////////////////////////////////////////////////}

	//////////////////////
	//juegos de destreza//
	/////////////////////


	//presentación juegos de destreza

	//pilar 1
	glPushMatrix();
	glTranslatef(190, 0, -180);
	glRotatef(180, 0, 1, 0);
	entrada.prisma(40, 2, 2, madera.GLindex);

	//pilar 2
	glTranslatef(0, 0, -60);
	entrada.prisma(40, 2, 2, madera.GLindex);

	//anuncio
	glTranslatef(0, 22, 30);
	glRotatef(90, 0, 1, 0);
	glRotatef(90, 0, 1, 0);
	entrada.prisma(4, 2, 62, madera.GLindex);

	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(-1, 0, 0);
	entrada.prisma(15, 0.05, 30, juegos.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	/////////////////

	//puesto 5
	glPushMatrix();
	glTranslatef(180, 0, -125);
	glRotatef(270, 0, 1, 0);
	puesto.prisma(10, 10, 5, puesto_azul.GLindex);


	//fondo de acuerdo al juego (globos)
	glPushMatrix();
	glTranslatef(0, 9, -2.5);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(8, 0.1, 10, globos.GLindex);
	glPopMatrix();


	//
	glPushMatrix();
	glTranslatef(-5, 5, 0);
	puesto.poste(0.1, 8, 120, puesto_azul.GLindex);
	glTranslatef(0, 0, -2.2);
	puesto.poste(0.1, 8, 120, puesto_azul.GLindex);
	glPopMatrix();

	//
	glPushMatrix();
	glTranslatef(5, 5, 0);
	puesto.poste(0.1, 8, 120, puesto_azul.GLindex);
	glTranslatef(0, 0, -2.2);
	puesto.poste(0.1, 8, 120, puesto_azul.GLindex);
	glPopMatrix();

	//toldo
	glPushMatrix();
	glTranslatef(0, 13, 0);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(5, 0.1, 11, puesto_azul.GLindex);
	glPopMatrix();
	glPopMatrix();

	//puesto 6
	glPushMatrix();
	glTranslatef(180, 0, -140);
	glRotatef(270, 0, 1, 0);
	puesto.prisma(10, 10, 5, puesto_azul.GLindex);


	//fondo de acuerdo al juego (globos)
	glPushMatrix();
	glTranslatef(0, 9, -2.5);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(8, 0.1, 10, patitos.GLindex);
	glPopMatrix();


	//
	glPushMatrix();
	glTranslatef(-5, 5, 0);
	puesto.poste(0.1, 8, 120, puesto_azul.GLindex);
	glTranslatef(0, 0, -2.2);
	puesto.poste(0.1, 8, 120, puesto_azul.GLindex);
	glPopMatrix();

	//
	glPushMatrix();
	glTranslatef(5, 5, 0);
	puesto.poste(0.1, 8, 120, puesto_azul.GLindex);
	glTranslatef(0, 0, -2.2);
	puesto.poste(0.1, 8, 120, puesto_azul.GLindex);
	glPopMatrix();

	//toldo
	glPushMatrix();
	glTranslatef(0, 13, 0);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(5, 0.1, 11, puesto_azul.GLindex);
	glPopMatrix();
	glPopMatrix();



	//puesto 7
	glPushMatrix();
	glTranslatef(180, 0, -155);
	glRotatef(270, 0, 1, 0);
	puesto.prisma(10, 10, 5, puesto_azul.GLindex);


	//fondo de acuerdo al juego (globos)
	glPushMatrix();
	glTranslatef(0, 9, -2.5);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(8, 0.1, 10, globos.GLindex);
	glPopMatrix();


	//
	glPushMatrix();
	glTranslatef(-5, 5, 0);
	puesto.poste(0.1, 8, 120, puesto_azul.GLindex);
	glTranslatef(0, 0, -2.2);
	puesto.poste(0.1, 8, 120, puesto_azul.GLindex);
	glPopMatrix();

	//
	glPushMatrix();
	glTranslatef(5, 5, 0);
	puesto.poste(0.1, 8, 120, puesto_azul.GLindex);
	glTranslatef(0, 0, -2.2);
	puesto.poste(0.1, 8, 120, puesto_azul.GLindex);
	glPopMatrix();

	//toldo
	glPushMatrix();
	glTranslatef(0, 13, 0);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(5, 0.1, 11, puesto_azul.GLindex);
	glPopMatrix();
	glPopMatrix();

	//puesto 8
	glPushMatrix();
	glTranslatef(180, 0, -170);
	glRotatef(270, 0, 1, 0);
	puesto.prisma(10, 10, 5, puesto_azul.GLindex);

	//fondo de acuerdo al juego (globos)
	glPushMatrix();
	glTranslatef(0, 9, -2.5);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(8, 0.1, 10, patitos.GLindex);
	glPopMatrix();


	//
	glPushMatrix();
	glTranslatef(-5, 5, 0);
	puesto.poste(0.1, 8, 120, puesto_azul.GLindex);
	glTranslatef(0, 0, -2.2);
	puesto.poste(0.1, 8, 120, puesto_azul.GLindex);
	glPopMatrix();

	//
	glPushMatrix();
	glTranslatef(5, 5, 0);
	puesto.poste(0.1, 8, 120, puesto_azul.GLindex);
	glTranslatef(0, 0, -2.2);
	puesto.poste(0.1, 8, 120, puesto_azul.GLindex);
	glPopMatrix();

	//toldo
	glPushMatrix();
	glTranslatef(0, 13, 0);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(5, 0.1, 11, puesto_azul.GLindex);
	glPopMatrix();
	glPopMatrix();




	//Jardinera 1 (Entrada derecha)
	glPushMatrix();
	glTranslatef(180.0, 0.0, 60.0);
	glDisable(GL_LIGHTING);
	jardinera1_1.maceta(10.0, 15.0, 41.0, pasto.GLindex, ladrillo.GLindex);
	glTranslatef(7.5, 0.0, 20.5);
	glBindTexture(GL_TEXTURE_2D, ladrillo.GLindex);   // choose the texture to use.

	glBegin(GL_POLYGON);	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0, 0.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(5, 0.0, -14.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(5, 5.0, -14.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0, 5.0, 0.0);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(5.0, 5.0, -14.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(5.0, 0.0, -14.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0, 0.0, -41.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0, 5.0, -41.0);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, pasto.GLindex);

	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0, 5.0, -41.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(5.0, 5.0, -14.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0, 5.0, 0.0);
	glEnd();
	glEnable(GL_LIGHTING);
	glTranslatef(-7.5, 0.0, -20.5);
	arbol2.arbol(tree.GLindex);
	glPopMatrix();



	/////////////
	//Castillo//
	////////////
	glPushMatrix();
	glTranslatef(180, 0, -30);
	glRotatef(90, 0, 1, 0);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
	castillo.prisma(130, 100, 40, castillo_negro.GLindex);

	//puerta
	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(0, 8, -20);
	glRotatef(90, 0, 1, 0);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
	castillo.prisma(15, 0.1, 15, puerta.GLindex);

	//ventanas
	//parte de abajo
	//izq a der
	glPushMatrix();

	glPushMatrix();
	glTranslatef(0, 22, 0);
	castillo.prisma(10, 0.1, 10, ventana1.GLindex);
	glTranslatef(0, 0, 35);
	castillo.prisma(10, 0.1, 10, ventana1.GLindex);
	glTranslatef(0, 0, -70);
	castillo.prisma(10, 0.1, 10, ventana1.GLindex);
	glPopMatrix();

	//parte de arriba der a izq
	glPushMatrix();
	glTranslatef(0, 42, 0);
	castillo.prisma(10, 0.1, 10, ventana1.GLindex);
	glTranslatef(0, 0, 35);
	castillo.prisma(10, 0.1, 10, ventana1.GLindex);
	glTranslatef(0, 0, -70);
	castillo.prisma(10, 0.1, 10, ventana1.GLindex);

	glPopMatrix();

	glDisable(GL_ALPHA_TEST);
	glPopMatrix();
	glPopMatrix();

	//torre 1 centro
	glTranslatef(0, 65, 0);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
	castillo.poste(8.0, 45.0, 120.0, castillo_negro.GLindex);
	//torre 2 izquierda
	glTranslatef(40, 0, 0);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
	castillo.poste(8.0, 30.0, 120.0, castillo_negro.GLindex);
	//torre 3 derecha
	glTranslatef(-80, 0, 0);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
	castillo.poste(8.0, 30.0, 120.0, castillo_negro.GLindex);
	glPopMatrix();

	//picos de las torres
	glPushMatrix();
	//torre 2 izquierda
	glTranslatef(180, 95, 10);
	glColor3f(0, 0, 0);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
	castillo.cono(30, 8, 120, castillo_negro.GLindex);
	//torre 3 derecha
	glTranslatef(0, 0, -80);
	glColor3f(0, 0, 0);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
	castillo.cono(30, 8, 120, castillo_negro.GLindex);
	//torre 1 centro
	glTranslatef(0, 15, 40);
	glColor3f(0, 0, 0);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
	castillo.cono(30, 8, 120, castillo_negro.GLindex);
	glPopMatrix();



	glPushMatrix();//Faro1 
	glTranslatef(180.0, 0.0, 90.0);
	glColor3fv(gris);
	posteinf.poste(0.1, 20, 40, 0);
	glTranslatef(0.0, 20.0, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	postesup.poste(0.07, 2.0, 40.0, 0);
	glTranslatef(0.0, 2.0, 0.0);
	glColor3fv(amarillo);
	lamp.mediaesfera(1.0, 30.0, 30.0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();


	glPushMatrix();//Faro2 pegado al castillo
	glTranslatef(180.0, 0.0, 30.0);
	glColor3fv(gris);
	posteinf.poste(0.1, 20, 40, 0);
	glTranslatef(0.0, 20.0, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	postesup.poste(0.07, 2.0, 40.0, 0);
	glTranslatef(0.0, 2.0, 0.0);
	glColor3fv(amarillo);
	lamp.mediaesfera(1.0, 30.0, 30.0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();
	glDisable(GL_LIGHTING);

	glPushMatrix();//Faro3
	glTranslatef(180.0, 0.0, -100.0);
	glColor3fv(gris);
	posteinf.poste(0.1, 20, 40, 0);
	glTranslatef(0.0, 20.0, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	postesup.poste(0.07, 2.0, 40.0, 0);
	glTranslatef(0.0, 2.0, 0.0);
	glColor3fv(amarillo);
	lamp.mediaesfera(1.0, 30.0, 30.0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();
	glDisable(GL_LIGHTING);
	

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
//////////////DIBUJO JARDINERAS DEL FONDO//////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////


	//mario
	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(180, 0, -185);
	glScalef(0.5, 0.5, 0.5);
	glRotatef(90, 0, 1, 0);
	puesto.cartel(mario.GLindex);
	glPopMatrix();

	//yoshi
	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(180, 0, -100);
	glScalef(0.5, 0.5, 0.5);
	glRotatef(90, 0, 1, 0);
	puesto.cartel(yoshi1.GLindex);
	glPopMatrix();



	//faros


	glDisable(GL_LIGHTING);
	glPushMatrix();//Faro 1
	glTranslatef(-170.0, 0.0, -190.0);
	glColor3fv(gris);
	posteinf.poste(0.1, 20, 40, 0);
	glTranslatef(0.0, 20.0, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	postesup.poste(0.07, 2.0, 40.0, 0);
	glTranslatef(0.0, 2.0, 0.0);
	glColor3fv(amarillo);
	lamp.mediaesfera(1.0, 30.0, 30.0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();
	glDisable(GL_LIGHTING);


	glPushMatrix();//Faro 2
	glTranslatef(-150.0, 0.0, -190.0);
	glColor3fv(gris);
	posteinf.poste(0.1, 20, 40, 0);
	glTranslatef(0.0, 20.0, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	postesup.poste(0.07, 2.0, 40.0, 0);
	glTranslatef(0.0, 2.0, 0.0);
	glColor3fv(amarillo);
	lamp.mediaesfera(1.0, 30.0, 30.0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();
	glDisable(GL_LIGHTING);

	
	//Jardinera pegada lado izquierdo
	glPushMatrix();
	glTranslatef(-115, 0.0, -190);
	glRotatef(-90, 0.0, 1.0, 0.0);
	glDisable(GL_LIGHTING);
	jardinera1_1.maceta(10.0, 15.0, 30.0, pasto.GLindex, ladrillo.GLindex);
	glTranslatef(0.0, 0.0, 15.0);
	medialuna.cilindro(7.5, 5.0, 30.0, pasto.GLindex, ladrillo.GLindex);
	glTranslatef(7.5, 0.0, -30);
	glBindTexture(GL_TEXTURE_2D, ladrillo.GLindex);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0, 0.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-15, 0.0, -15.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-15, 5.0, -15.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0, 5.0, 0.0);
	glEnd();
	glBegin(GL_POLYGON);  //Left
		//glColor3f(1.0,1.0,1.0);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-15.0, 5.0, -15.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-15.0, 0.0, -15.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-15.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-15.0, 5.0, 0.0);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, pasto.GLindex);
	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-15.0, 5.0, -15.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-15.0, 5.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0, 5.0, 0.0);
	glEnd();
	glEnable(GL_LIGHTING);
	glTranslatef(-7.5, 0.0, 30.0);
	arbol2.arbol(tree1.GLindex);
	glPopMatrix();


	//banquita pegada a la jardinera izquierda
	glPushMatrix();

	glTranslatef(-160, 2, -190);
	glRotatef(180, 0, 1, 0);
	asiento.prisma(1, 15, 3, madera.GLindex);

	glTranslatef(6, -0.5, 0);
	patas_asiento.prisma(1, 1, 3, madera.GLindex);

	glTranslatef(-12, -0.5, 0);
	patas_asiento.prisma(1, 1, 3, madera.GLindex);

	glPopMatrix();

	///fondo lado derecho

	glDisable(GL_LIGHTING);
	glPushMatrix();//Faro 1
	glTranslatef(170.0, 0.0, -190.0);
	glColor3fv(gris);
	posteinf.poste(0.1, 20, 40, 0);
	glTranslatef(0.0, 20.0, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	postesup.poste(0.07, 2.0, 40.0, 0);
	glTranslatef(0.0, 2.0, 0.0);
	glColor3fv(amarillo);
	lamp.mediaesfera(1.0, 30.0, 30.0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();
	glDisable(GL_LIGHTING);


	glPushMatrix();//Faro 2
	glTranslatef(150.0, 0.0, -190.0);
	glColor3fv(gris);
	posteinf.poste(0.1, 20, 40, 0);
	glTranslatef(0.0, 20.0, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	postesup.poste(0.07, 2.0, 40.0, 0);
	glTranslatef(0.0, 2.0, 0.0);
	glColor3fv(amarillo);
	lamp.mediaesfera(1.0, 30.0, 30.0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();
	glDisable(GL_LIGHTING);


	//Jardinera pegada lado derecho
	glPushMatrix();
	glTranslatef(115, 0.0, -190);
	glRotatef(-90, 0.0, 1.0, 0.0);
	glDisable(GL_LIGHTING);
	jardinera1_1.maceta(10.0, 15.0, 30.0, pasto.GLindex, ladrillo.GLindex);
	glTranslatef(0.0, 0.0, 15.0);
	medialuna.cilindro(7.5, 5.0, 30.0, pasto.GLindex, ladrillo.GLindex);
	glTranslatef(7.5, 0.0, -30);
	glBindTexture(GL_TEXTURE_2D, ladrillo.GLindex);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0, 0.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-15, 0.0, -15.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-15, 5.0, -15.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0, 5.0, 0.0);
	glEnd();
	glBegin(GL_POLYGON);  //Left
		//glColor3f(1.0,1.0,1.0);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-15.0, 5.0, -15.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-15.0, 0.0, -15.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-15.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-15.0, 5.0, 0.0);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, pasto.GLindex);
	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-15.0, 5.0, -15.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-15.0, 5.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0, 5.0, 0.0);
	glEnd();
	glEnable(GL_LIGHTING);
	glTranslatef(-7.5, 0.0, 30.0);
	arbol2.arbol(tree1.GLindex);
	glPopMatrix();


	//banquita pegada a la jardinera 
	glPushMatrix();

	glTranslatef(160, 2, -190);
	glRotatef(180, 0, 1, 0);
	asiento.prisma(1, 15, 3, madera.GLindex);

	glTranslatef(6, -0.5, 0);
	patas_asiento.prisma(1, 1, 3, madera.GLindex);

	glTranslatef(-12, -0.5, 0);
	patas_asiento.prisma(1, 1, 3, madera.GLindex);

	glPopMatrix();

	


	//bote 1
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(-70.0, 0.0, -190.0);
	glColor3fv(azul);
	correo1.poste(0.1, 1.0, 40, 0);
	glTranslatef(2.0, 0.0, 0.0);
	correo2.poste(0.1, 1.0, 40, 0);
	glTranslatef(0.0, 0.0, 2.0);
	correo3.poste(0.1, 1.0, 40, 0);
	glTranslatef(-2.0, 0.0, 0.0);
	correo4.poste(0.1, 1.0, 40, 0);
	glTranslatef(1.0, 4.0, -1.0);
	glColor3f(1.0, 1.0, 1.0);
	correo5.prisma(6.0, 3.0, 3.0, uspost.GLindex);
	glTranslatef(0.0, 3.0, 1.0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	glColor3fv(azul);
	correo6.cilindro(1.5, 2.5, 40, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();

	//bote 2
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(70.0, 0.0, -190.0);
	glColor3fv(azul);
	correo1.poste(0.1, 1.0, 40, 0);
	glTranslatef(2.0, 0.0, 0.0);
	correo2.poste(0.1, 1.0, 40, 0);
	glTranslatef(0.0, 0.0, 2.0);
	correo3.poste(0.1, 1.0, 40, 0);
	glTranslatef(-2.0, 0.0, 0.0);
	correo4.poste(0.1, 1.0, 40, 0);
	glTranslatef(1.0, 4.0, -1.0);
	glColor3f(1.0, 1.0, 1.0);
	correo5.prisma(6.0, 3.0, 3.0, uspost.GLindex);
	glTranslatef(0.0, 3.0, 1.0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	glColor3fv(azul);
	correo6.cilindro(1.5, 2.5, 40, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();
	



	



///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
/////////////////////rueda/////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////

	//letrero
	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(-40, 0,-115);
	glScalef(0.5, 0.5, 0.5);
	puesto.cartel(letrero_rueda.GLindex);

	glTranslatef(20, 0, 0);
	glScalef(1, 1, 1);
	puesto.cartel(huevo.GLindex);
	glPopMatrix();

	//Rueda de la fortuna
	glTranslatef(0, 0, -150);
	//soporte
//centro
	glPushMatrix();
	glEnable(GL_LIGHTING);
	glTranslatef(0, 120, 0);
	glRotatef(90, 1, 0, 0);
	jardinera2_1.poste(3, 10, 200, tuberia.GLindex);
	glPopMatrix();
	//soporte1
	glPushMatrix();
	glTranslatef(0, 0, 12);
	jardinera2_1.poste(3, 122, 200, tuberia.GLindex);
	glPushMatrix();
	glTranslatef(0, 122, 0);
	glRotatef(160, 0, 0, 1);
	jardinera2_1.poste(3, 130, 200, tuberia.GLindex);
	glRotatef(-320, 0, 0, 1);
	jardinera2_1.poste(3, 130, 200, tuberia.GLindex);
	glPopMatrix();
	//soporte2 
	glTranslatef(0, 0, -24);
	jardinera2_1.poste(3, 122, 200, tuberia.GLindex);
	glPushMatrix();
	glTranslatef(0, 122, 0);
	glRotatef(160, 0, 0, 1);
	jardinera2_1.poste(3, 130, 200, tuberia.GLindex);
	glRotatef(-320, 0, 0, 1);
	jardinera2_1.poste(3, 130, 200, tuberia.GLindex);
	glPopMatrix();
	glPopMatrix();

	//centro
	glPushMatrix();
	glTranslatef(0, 120, 0);
	glRotatef(-90, 1, 0, 0);
	jardinera2_1.poste(3, 10, 200, tuberia.GLindex);
	glPopMatrix();
	//rueda
	glPushMatrix();//rotacion
	glTranslatef(0, 120, 0);
	glRotatef(90, 1, 0, 0);
	glRotatef(rota, 0, 1, 0);

	glDisable(GL_LIGHTING);

	glColor3f(0.3, 0.3, 0.3);


	jardinera1_1.torus(90, 100, 200, 200);
	//aros
	glRotatef(90, 0, 0, 1);
	glEnable(GL_LIGHTING);
	jardinera2_1.poste(1, 90, 200, tuberia.GLindex);
	glRotatef(90, 1, 0, 0);
	jardinera2_1.poste(1, 90, 200, tuberia.GLindex);
	glPushMatrix();
	glTranslatef(0, 0, 105);
	glRotatef(rota, 1, 0, 0);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	jardinera2_1.esfera(5, 100, 100, vidrio.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();
	glRotatef(90, 1, 0, 0);
	jardinera2_1.poste(1, 90, 200, tuberia.GLindex);
	glPushMatrix();
	glTranslatef(0, 0, 105);
	glRotatef(rota, 1, 0, 0);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	jardinera2_1.esfera(5, 100, 100, vidrio.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();
	glRotatef(90, 1, 0, 0);
	jardinera2_1.poste(1, 90, 200, tuberia.GLindex);
	glPushMatrix();
	glTranslatef(0, 0, 105);
	glRotatef(rota, 1, 0, 0);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	jardinera2_1.esfera(5, 100, 100, vidrio.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();
	glRotatef(90, 1, 0, 0);
	jardinera2_1.poste(1, 90, 200, tuberia.GLindex);
	glPushMatrix();
	glTranslatef(0, 0, 105);
	glRotatef(rota, 1, 0, 0);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	jardinera2_1.esfera(5, 100, 100, vidrio.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();
	glRotatef(45, 1, 0, 0);
	jardinera2_1.poste(1, 90, 200, tuberia.GLindex);
	glPushMatrix();
	glTranslatef(0, 0, 105);
	glRotatef(rota, 1, 0, 0);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	jardinera2_1.esfera(5, 100, 100, vidrio.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();
	glRotatef(45, 1, 0, 0);
	jardinera2_1.poste(1, 90, 200, tuberia.GLindex);
	glPushMatrix();
	glTranslatef(0, 0, 105);
	glRotatef(rota, 1, 0, 0);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	jardinera2_1.esfera(5, 100, 100, vidrio.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();
	glRotatef(45, 1, 0, 0);
	jardinera2_1.poste(1, 90, 200, tuberia.GLindex);

	glRotatef(90, 1, 0, 0);
	jardinera2_1.poste(1, 90, 200, tuberia.GLindex);

	glRotatef(90, 1, 0, 0);
	jardinera2_1.poste(1, 90, 200, tuberia.GLindex);
	glPopMatrix();
	
	//vaya de la rueda

	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(0, 0, 0);
	glRotatef(90, 0, 1, 0);
	puesto.prisma6(20, 60, 125, valla.GLindex);
	glDisable(GL_ALPHA_TEST);




	glTranslatef(-30, 0, 55);
	glScalef(0.7, 0.7, 0.7);
	glRotatef(90, 0, 1, 0);
	puesto.cartel(valla.GLindex);
	glTranslatef(20, 0, 0);
	puesto.cartel(valla.GLindex);
	glTranslatef(20, 0, 0);
	puesto.cartel(valla.GLindex);
	glTranslatef(20, 0, 0);
	puesto.cartel(valla.GLindex);
	glTranslatef(20, 0, 0);
	puesto.cartel(valla.GLindex);
	glTranslatef(20, 0, 0);
	puesto.cartel(valla.GLindex);

	glTranslatef(20, 0, 0);
	puesto.cartel(valla.GLindex);

	glTranslatef(20, 0, 0);
	puesto.cartel(valla.GLindex);
	glDisable(GL_ALPHA_TEST);


	glPopMatrix();


	//////////////////////
	/////////////////////
	/////MONITOS//////////
	///////////////////
	/////////////////


	//MONITO QUE MANEJA LA montaña rusa
	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(1, 1, 1);
	//glScalef(0.5, 0.5, 0.5);
	//monito();
	glCallList(ciudad_display_list);
	glTranslatef(-35, posY, 60);
	glRotatef(giroMonito, 0, 1, 0);
	monito();
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();
	glEnable(GL_LIGHTING);
	glPopMatrix();




	glPopMatrix();
	glutSwapBuffers();

}



void animacion()
{

	if (avanza == true) {

		printf("\nx=%f,y=%f,z=%f", x, y, z);

		if (x == 0 && y == 0 && z == 0)
		{
			atras = false;
			sube = true;
		}
		if (y == 30 && sube == true)
		{
			gira_der = true;
			gira = -90;
			sube = false;
		}
		if (x == -60 && gira_der == true)
		{
			gira_der = false;
			derecha = true;
		}
		if (z == -61 && derecha == true && y != 19 && z != 65 && y != 13)
		{
			gira_der2 = true;
			gira = gira - 90;
			derecha = false;
		}
		if (x == -58 && gira_der2 == true)
		{
			gira_der2 = false;
			adelante = true;
		}

		if (x == -55 && adelante == true && y != 13)
		{
			adelante = false;
			baja = true;
		}
		if (x == -46 && baja == true && y != 12.5)
		{
			baja = false;
			gira = gira - 90;
			gira_der3 = true;
		}
		if (x == -44 && gira_der3 == true)
		{
			gira_der3 = false;
			izquierda = true;
		}
		if (z == -23 && izquierda == true && y != 13 && y != 0)
		{
			izquierda = false;
			gira_der3 = true;
			gira = gira + 90;
		}
		if (x == -38 && gira_der3 == true)
		{
			gira_der3 = false;
			baja = true;
		}
		if (x == -25 && baja == true && z != -65)
		{
			baja = false;
			gira_der2 = true;
			gira = gira + 90;
		}
		if (x == -21 && gira_der2 == true)
		{
			gira_der2 = false;
			derecha = true;
		}
		if (z == -67 && x == -21 && derecha == true)
		{
			derecha = false;
			gira_der2 = true;
			gira = gira - 90;
		}
		if (x == -18 && gira_der2 == true)
		{
			gira_der2 = false;
			baja = true;
		}
		if (x == -6 && baja == true)
		{
			baja = false;
			gira_der3 = true;
			gira = gira - 90;
		}
		if (x == -1 && gira_der3 == true)
		{
			gira_der3 = false;
			izquierda = true;
		}
		if (z == -18 && izquierda == true && y != 0)
		{
			izquierda = false;
			gira_der4 = true;
			gira = gira - 90;
		}
		if (x == -4 && gira_der4 == true && y != 0)
		{
			gira_der4 = false;
			atras = true;
		}
		if (x == -83 && atras == true)
		{
			atras = false;
			gira_der = true;
			gira = gira - 90;
		}
		if (x == -87 && gira_der == true)
		{
			gira_der = false;
			derecha = true;
		}

		if (z == -61 && derecha &&  y == 13)
		{
			gira_der2 = true;
			gira = gira - 90;
			derecha = false;
		}
		if (x == -83 && gira_der2 == true && y == 13)
		{
			gira_der2 = false;
			adelante = true;
		}


		if (x == -47 && adelante == true)
		{
			adelante = false;
			baja = true;
		}
		if (y == 0 && baja == true)
		{
			baja = false;
			adelante = true;
		}
		if (x == 13 && adelante == true)
		{
			izquierda = true;
			gira = gira - 90;
			adelante = false;
		}
		if (z == 0 && izquierda == true)
		{
			izquierda = false;
			gira = gira - 90;
			atras = true;
		}
		if (derecha == true)
		{
			z--;
		}
		if (izquierda == true)
		{
			z++;
		}
		if (atras == true)
		{
			x--;
		}
		if (adelante == true)
		{
			x++;
		}
		if (sube == true) {
			x = x - 1;
			y = y + 0.5;
		}
		if (baja == true) {
			x = x + 1;
			y = y - 0.5;
		}
		if (gira_der == true) {
			x = x - 0.5;
			z = z - 0.5;
		}
		if (gira_der2 == true) {
			x = x + 0.5;
			z = z - 0.5;
		}
		if (gira_der3 == true) {
			x = x + 0.5;
			z = z + 0.5;
		}
		if (gira_der4 == true) {
			x = x - 0.5;
			z = z + 0.5;
		}
	}


	rota--;
	{	glutPostRedisplay();

		tacitas--;
	}

	if (g_fanimacion)
	{
		if (cont == 1) {
			objCamera.mPos.x = 10;
			objCamera.mPos.y = 10;
			objCamera.mPos.z = 199;
		}
		else {
			if (objCamera.mPos.z >= 90 && objCamera.mPos.x <= 117) {

				objCamera.mPos.z = objCamera.mPos.z - 0.00005;
			}
			else {
				if (objCamera.mPos.x <= 117 && objCamera.mPos.z >= -80 && objCamera.mPos.y == 10) {

					objCamera.mPos.x = objCamera.mPos.x + 0.00005;
				}
				else {
					if (objCamera.mPos.z >= -80 && objCamera.mPos.x >= -110) {

						objCamera.mPos.z = objCamera.mPos.z - 0.00005;
					}
					else {
						if (objCamera.mPos.x >= -110) {

							objCamera.mPos.x = objCamera.mPos.x - 0.00005;
							objCamera.mPos.y = 12;

						}
						else
							if (objCamera.mPos.x <= 110) {

								objCamera.mPos.z = objCamera.mPos.z + 0.00005;

							}


					}
				}
			}
		}

	}
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 700.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Funcion de teclas del teclado
{
	switch (key) {

	case 'w':   //Movimientos de camara
	case 'W':
		objCamera.Move_Camera(CAMERASPEED + 0.5);
		break;

	case 's':
	case 'S':
		objCamera.Move_Camera(-(CAMERASPEED + 0.5));
		break;

	case 'a':
	case 'A':
		objCamera.Strafe_Camera(-(CAMERASPEED + 0.5));
		break;

	case 'd':
	case 'D':
		objCamera.Strafe_Camera(CAMERASPEED + 0.5);
		break;
	case 'm':
	case 'M':
		avanza ^= true;
		break;
	case 'l':   //Activamos/desactivamos luz
	case 'L':
		light = !light;
		glDisable(GL_LIGHT1);
		break;
	case 'k':   //Activamos/desactivamos luz
	case 'K':
		light = !light;
		glEnable(GL_LIGHT1);
		break;

	case 'o':		//  
	case 'O':
		g_fanimacion = true;
		cont++;
		break;


	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}

	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_PAGE_UP: // Presionamos Re Pag...
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN: // Presionamos Av Pag...
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 2.0f;
		break;

	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 2.0f;
		break;

	case GLUT_KEY_LEFT:  // Presionamos tecla IZQUIERDA...
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:  // Presionamos tecla DERECHA...
		objCamera.Rotate_View(CAMERASPEED);
		break;

	default:
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)   // Main Function
{

	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(2000, 2000);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Proyecto_Final"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 
	return 0;
}
