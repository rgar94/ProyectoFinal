//Computación Gráfica
//Proyecto Final
//Semestre 2019 - 2
//Fecha: 08/05/2019
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


//luces materiales
GLfloat lamparaDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat lamparaSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat lamparaPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position
GLfloat laparaShininess[] = { 100.0 };




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

	glShadeModel(GL_FLAT);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);				// Setup The Ambient Light
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);				// Setup The Diffuse Light
	glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpecular);				// Setup The Diffuse Light

	glEnable(GL_LIGHT1);							// Enable Light One

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	//luz de la lampara
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);				// Setup The Ambient Light
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);				// Setup The Diffuse Light
	glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpecular);				// Setup The Diffuse Light

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);							// Enable Light One



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

	objCamera.Position_Camera(0, 10.5f, 150, 0, 2.5f, 0, 0, 1, 0);


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
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
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
	glTranslatef(0, 0, -50);
	piso.prisma(0.5, 400.0, 300.0, suelo.GLindex);
	glPopMatrix();

	//suelo estacionamiento
	glPushMatrix();
	glTranslatef(0, 0, 150);
	piso.prisma(0.5, 400.0, 100.0, suelo_estacionamiento.GLindex);
	glPopMatrix();

	//caminito del parque
	glPushMatrix();
	glTranslatef(0, 0, 40);
	piso.prisma(0.6, 100, 120, suelo_estacionamiento.GLindex);

	glTranslatef(0, 0, -70);
	piso.prisma(0.6, 350, 20, suelo_estacionamiento.GLindex);
	glPopMatrix();


	//Entrada al parque
	glPushMatrix();
	glTranslatef(0, 90, 107.5);
	entrada.prisma(20, 150, 15, scale.GLindex);

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







	/////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////
	//DIBUJO DE BANQUITAS, PUESTOS Y DEMAS, LADO IZQUIERDO//
	///////////////////////////////////////////////////////
	///////////////////////////////////////////////////////

	//botes de basura
	//bote 1
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(-190.0, 0.0, 35.0);
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
	glEnable(GL_LIGHTING);

	//bote 2
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(-190.0, 0.0, -170.0);
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





	glPushMatrix();//Faro1 pegado a la jardinera
	glTranslatef(-180.0, 0.0, 30.0);
	glColor3fv(gris);
	posteinf.poste(0.1, 20, 40, 0);
	glTranslatef(0.0, 20.0, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	postesup.poste(0.07, 2.0, 40.0, 0);
	glTranslatef(0.0, 2.0, 0.0);
	glColor3fv(amarillo);

	glDisable(GL_LIGHTING);//el no necesita sombra ya que funciona como sol

	lamp.mediaesfera(1.0, 30.0, 30.0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glEnable(GL_LIGHTING); //Habilita el sombreado para los demás planetas

	glPopMatrix();

	glDisable(GL_LIGHTING);


	//glDisable(GL_LIGHTING);

	glPushMatrix();//Faro 2
	glTranslatef(-180.0, 0.0, 10.0);
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
	glTranslatef(-180.0, 0.0, -55.0);
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
	glTranslatef(-180.0, 0.0, -75.0);
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

	glPushMatrix();//Faro 5
	glTranslatef(-180.0, 0.0, -140.0);
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

	glPushMatrix();//Faro 6
	glTranslatef(-180.0, 0.0, -160.0);
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

	//Jardinera 1 (Entrada izquierda)

	glPushMatrix();
	glTranslatef(-180.0, 0.0, 60.0);
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


	//Banquitas

	//banquita pegada a la jardinera izquierda
	glPushMatrix();
	glTranslatef(-180, 2, 20);
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
	glTranslatef(-180, 2, -65);
	glRotatef(90, 0, 1, 0);
	asiento.prisma(1, 15, 3, madera.GLindex);

	glTranslatef(6, -0.5, 0);
	patas_asiento.prisma(1, 1, 3, madera.GLindex);

	glTranslatef(-12, -0.5, 0);
	patas_asiento.prisma(1, 1, 3, madera.GLindex);
	glPopMatrix();

	//banquita ultima banquita
	glPushMatrix();
	glTranslatef(-180, 2, -150);
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
	glTranslatef(-190, 0, 10);
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
	glTranslatef(-180, 0, 0);
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
	glTranslatef(-180, 0, -15);
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
	glTranslatef(-180, 0, -30);
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
	glTranslatef(-180, 0, -45);
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
	glTranslatef(-190, 0, -80);
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
	glTranslatef(-180, 0, -85);
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
	glTranslatef(-180, 0, -100);
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
	glTranslatef(-180, 0, -115);
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
	glTranslatef(-180, 0, -130);
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
	//////////////////////////////////////////////////////

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
	castillo.prisma(130, 100, 40, castillo_negro.GLindex);

	//puerta
	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(0, 8, -20);
	glRotatef(90, 0, 1, 0);
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
	castillo.poste(8.0, 45.0, 120.0, castillo_negro.GLindex);
	//torre 2 izquierda
	glTranslatef(40, 0, 0);
	castillo.poste(8.0, 30.0, 120.0, castillo_negro.GLindex);
	//torre 3 derecha
	glTranslatef(-80, 0, 0);
	castillo.poste(8.0, 30.0, 120.0, castillo_negro.GLindex);
	glPopMatrix();

	//picos de las torres
	glPushMatrix();
	//torre 2 izquierda
	glTranslatef(180, 95, 10);
	glColor3f(0, 0, 0);
	castillo.cono(30, 8, 120, castillo_negro.GLindex);
	//torre 3 derecha
	glTranslatef(0, 0, -80);
	glColor3f(0, 0, 0);
	castillo.cono(30, 8, 120, castillo_negro.GLindex);
	//torre 1 centro
	glTranslatef(0, 15, 40);
	glColor3f(0, 0, 0);
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




	//////////
	// Tacitas
	//////////

	glPushMatrix();
	glTranslatef(180, 5, -115);
	//base de las tacitas circular
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
	jardinera1_1.mediaesfera(2, 12, 120,tacita.GLindex);
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

	glPushMatrix();
		glTranslatef(180, 5, -130);



		
		glPushMatrix();

		//base pegada al piso
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





///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
//////////////DIBUJO JARDINERAS DEL FONDO//////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////

	//faros


	glDisable(GL_LIGHTING);
	glPushMatrix();//Faro 1
	glTranslatef(-130.0, 0.0, -190.0);
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
	glTranslatef(-90.0, 0.0, -190.0);
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

	glPushMatrix();//Faro 3
	glTranslatef(-20.0, 0.0, -190.0);
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
	glTranslatef(20.0, 0.0, -190.0);
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

	glPushMatrix();//Faro 5
	glTranslatef(90.0, 0.0, -190.0);
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

	glPushMatrix();//Faro 6
	glTranslatef(130.0, 0.0, -190.0);
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

	//Jardinera pegada al lado izquierdo
	glPushMatrix();
	glTranslatef(170, 0.0, -190);
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

	glTranslatef(-120, 2, -190);
	glRotatef(180, 0, 1, 0);
	asiento.prisma(1, 15, 3, madera.GLindex);

	glTranslatef(6, -0.5, 0);
	patas_asiento.prisma(1, 1, 3, madera.GLindex);

	glTranslatef(-12, -0.5, 0);
	patas_asiento.prisma(1, 1, 3, madera.GLindex);

	glPopMatrix();

	//banquita 
	
	glPushMatrix();
	glTranslatef(-100, 2, -190);
	glRotatef(180, 0, 1, 0);
	asiento.prisma(1, 15, 3, madera.GLindex);

	glTranslatef(6, -0.5, 0);
	patas_asiento.prisma(1, 1, 3, madera.GLindex);

	glTranslatef(-12, -0.5, 0);
	patas_asiento.prisma(1, 1, 3, madera.GLindex);

	glPopMatrix();
	glDisable(GL_LIGHTING);

	//jardinera 2
	glPushMatrix();
	glTranslatef(-55, 0.0, -190);
	glRotatef(-270, 0.0, 1.0, 0.0);
	glDisable(GL_LIGHTING);
	jardinera1_1.maceta(10.0, 15.0, 30.0, pasto.GLindex, ladrillo.GLindex);//maceta8
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
	glEnable(GL_LIGHTING);


	//bote 1
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(-5.0, 0.0, -190.0);
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
	glTranslatef(5.0, 0.0, -190.0);
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


	//segundo bloque
	//Jardinera pegada al lado izquierdo
	glPushMatrix();
	glTranslatef(55, 0.0, -190);
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
	
	glTranslatef(120, 2, -190);
	glRotatef(180, 0, 1, 0);
	asiento.prisma(1, 15, 3, madera.GLindex);

	glTranslatef(6, -0.5, 0);
	patas_asiento.prisma(1, 1, 3, madera.GLindex);

	glTranslatef(-12, -0.5, 0);
	patas_asiento.prisma(1, 1, 3, madera.GLindex);

	glPopMatrix();


	//banquita 

	glPushMatrix();

	glTranslatef(100, 2, -190);
	glRotatef(180, 0, 1, 0);
	asiento.prisma(1, 15, 3, madera.GLindex);

	glTranslatef(6, -0.5, 0);
	patas_asiento.prisma(1, 1, 3, madera.GLindex);

	glTranslatef(-12, -0.5, 0);
	patas_asiento.prisma(1, 1, 3, madera.GLindex);

	glPopMatrix();
	glDisable(GL_LIGHTING);
	

	//jardinera 2
	glPushMatrix();
	glTranslatef(170, 0.0, -190);
	glRotatef(-270, 0.0, 1.0, 0.0);
	glDisable(GL_LIGHTING);
	jardinera1_1.maceta(10.0, 15.0, 30.0, pasto.GLindex, ladrillo.GLindex);//maceta8
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
	glEnable(GL_LIGHTING);

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
/////////////////////Montaña Rusa/////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////









		//carritos montaña rusa (4)
		glPushMatrix();
		//carrito 1
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(0,2.5, 0);		
		montaña_rusa.prisma5(4, 6, 4, carrito.GLindex);

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
		//respaldo asiento de atras
		glPushMatrix();
		glTranslatef(-0.5, 0, 0);
		montaña_rusa.prisma(4.2, 0.1, 3.8, madera.GLindex);
		glPopMatrix();

		glPopMatrix();
		//parte de enfrente del carrito 
		glTranslatef(4.5, -1, 0);
		montaña_rusa.prisma(2, 3, 4, carrito.GLindex);
		glTranslatef(0, 2, 0);
		glRotatef(180,0,1,0);
		montaña_rusa.triangulo(2,3, 4, carrito.GLindex);
		glPopMatrix();

		//tubito que une los carritos
		glPushMatrix();
		glTranslatef(-3,2,0);
		glRotatef(90, 1, 0, 0);
		glRotatef(90, 0, 0, 1);
		montaña_rusa.poste(0.1,1, 120, madera.GLindex);
		glPopMatrix();

		//carrito 2
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(-7, 2.65, 0);
		montaña_rusa.prisma5(4, 6, 4, carrito.GLindex);

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
		//respaldo asiento de atras
		glPushMatrix();
		glTranslatef(-0.5, 0, 0);
		montaña_rusa.prisma(4.2, 0.1, 3.8, madera.GLindex);
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();


		//tubito que une los carritos
		glPushMatrix();
		glTranslatef(-0.5, 2, 0);
		glRotatef(90, 1, 0, 0);
		glRotatef(90, 0, 0, 1);
		montaña_rusa.poste(0.1, 1, 120, madera.GLindex);
		glPopMatrix();


		//carrito 3
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(-14, 2.65, 0);
		montaña_rusa.prisma5(4, 6, 4, carrito.GLindex);

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
		//respaldo asiento de atras
		glPushMatrix();
		glTranslatef(-0.5, 0, 0);
		montaña_rusa.prisma(4.2, 0.1, 3.8, madera.GLindex);
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();

		glPopMatrix();//fin de los carritos
	glPopMatrix();




	//////////////////////
	/////////////////////
	/////MONITO//////////
	///////////////////
	/////////////////
	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(1, 1, 1);
	//glScalef(0.5, 0.5, 0.5);
	//monito();
	glCallList(ciudad_display_list);
	glTranslatef(posX, posY, posZ);
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

	{	glutPostRedisplay();

		tacitas--;
	}

	{
		////////////
		//recorrido guiado
		///////////
	
			//Movimiento de la cámara
			if (g_fanimacion)
			{
				if (circuito) // comienza maquina
				{
					if (recorrido1) // estado A
					{
						objCamera.mPos.z++;
						if (objCamera.mPos.z >= 200) // transicion a B
						{
							recorrido1 = false;
							recorrido2 = true;
						}
					}
					if (recorrido2) // estado B
					{
					
						objCamera.mPos.x++;
						if (objCamera.mPos.x > 125) // transicion a C
						{
							recorrido2 = false;
							recorrido3 = true;

						}
					}
				}
			}

			

			//modificar
					/*if (recorrido3) // estado C
					{
						rotKit = 205 + tanf(125.0 / 310);
						movKitZ--;
						movKitX = movKitX - 0.4;
						if (movKitZ < -155) // transicion a D
						{
							recorrido3 = false;
							recorrido5 = true;
						}
					}
					//fin
					if (recorrido4) // estado D
					{
						rotKit = 135;
						movKitX--;
						if (movKitX < 0) // transicion a E
						{
							recorrido4 = false;
							recorrido5 = true;
						}
					}

					if (recorrido5) // estado E
					{
						rotKit = 0;
						movKitZ++;
						if (movKitZ > 0) // transicion a A
						{
							recorrido5 = false;
							recorrido1 = true;
						}
					}*/
		
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

	case 'l':   //Activamos/desactivamos luz
	case 'L':
		light = !light;
		break;

	case 'i':		//  
	case 'I':
		circuito ^= true; //Activamos/desactivamos la animacíon
		g_fanimacion = false;
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
