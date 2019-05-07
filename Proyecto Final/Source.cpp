//Computaci�n Gr�fica
//Proyecto Final
//Semestre 2019 - 2
//Fecha: 08/05/2019
//Alumnos: Garc�a Callejas Ricardo
//		   Ram�rez Verduzco Lizet
//Grupo Teoria: 01 Grupo Laboratorio: 02

#include "texture.h"
#include "figuras.h"
#include "Camera.h"

//Definicion de colores
GLfloat blanco[] = { 1.0,1.0,1.0 };
GLfloat morado[] = { 1.0,0.0,1.0 };
GLfloat negro[] = { 0.0,0.0,0.0 };
GLfloat amarillo[] = { 0.7,0.7,0.0 };
GLfloat gris[] = { 0.2,0.2,0.2 };
GLfloat azul[] = { 0.0,0.0,1.0 };
GLfloat rojo[] = { 1.0,0.0,0.0 };
GLfloat verde[] = { 0.0,1.0,0.0 };



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

	objCamera.Position_Camera(10, 10.5f, 0, 0, 2.5f, 0, 0, 1, 0);

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
	sky.skybox(400.0, 400.0, 400.0, text1.GLindex);

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

	glPushMatrix();//Faro1 
	glTranslatef(-180.0, 0.0, 90.0);
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

	glPushMatrix();//Faro2 
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
	glDisable(GL_LIGHTING);

	glPushMatrix();//Faro3
	glTranslatef(-180.0, 0.0, -40.0);
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
	asiento.prisma(1, 15, 3, madera.GLindex);

	glTranslatef(6,-0.5, 0);
	patas_asiento.prisma(1, 1, 3, madera.GLindex);

	glTranslatef(-12,-0.5, 0);
	patas_asiento.prisma(1, 1, 3, madera.GLindex);
	glPopMatrix();

	//banquita pegada al puesto amarillo lado izquierdo
	glPushMatrix();
	glTranslatef(-180, 2, -50);
	glRotatef(90, 0, 1, 0);
	asiento.prisma(1, 15, 3, madera.GLindex);

	glTranslatef(6, -0.5, 0);
	patas_asiento.prisma(1, 1, 3, madera.GLindex);

	glTranslatef(-12, -0.5, 0);
	patas_asiento.prisma(1, 1, 3, madera.GLindex);
	glPopMatrix();

	//puestos

	//puesto 1 
	glPushMatrix();
	glTranslatef(-180,0, 0);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(10, 10, 5, puesto_azul.GLindex);
	glPopMatrix();

	//puesto 2 
	glPushMatrix();
	glTranslatef(-180, 0, -15);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(10, 10, 5, puesto_rojo.GLindex);
	glPopMatrix();


	//puesto 3 
	glPushMatrix();
	glTranslatef(-180, 0, -30);
	glRotatef(90, 0, 1, 0);
	puesto.prisma(10, 10, 5, puesto_azul.GLindex);
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

	//Banquitas

	//banquita pegada a la jardinera izquierda
	glPushMatrix();
	glTranslatef(180, 2, 20);
	glRotatef(90, 0, 1, 0);
	asiento.prisma(1, 15, 3, madera.GLindex);

	glTranslatef(6, -0.5, 0);
	patas_asiento.prisma(1, 1, 3, madera.GLindex);

	glTranslatef(-12, -0.5, 0);
	patas_asiento.prisma(1, 1, 3, madera.GLindex);
	glPopMatrix();



	//Castillo
	glPushMatrix();
	glTranslatef(180, 0, -45);
	glRotatef(90, 0, 1, 0);
	castillo.prisma(130, 100 , 40, castillo_negro.GLindex);
	//torre 1 centro
	glTranslatef(0,65,0);
	castillo.poste(8.0, 45.0, 120.0,castillo_negro.GLindex);
	//torre 2 izquierda
	glTranslatef(40,0,0);
	castillo.poste(8.0, 30.0, 120.0, castillo_negro.GLindex);
	//torre 3 derecha
	glTranslatef(-80,0, 0);
	castillo.poste(8.0, 30.0, 120.0, castillo_negro.GLindex);
	glPopMatrix();

	//picos de las torres
	glPushMatrix();
	//torre 2 izquierda
	glTranslatef(180, 95, -5);
	glColor3f(0,0,0);
	castillo.cono(30,8, 120, castillo_negro.GLindex);
	//torre 3 derecha
	glTranslatef(0,0, -80);
	glColor3f(0, 0, 0);
	castillo.cono(30, 8, 120, castillo_negro.GLindex);
	//torre 1 centro
	glTranslatef(0, 15,40);
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
	glTranslatef(180.0, 0.0, 10.0);
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
	glTranslatef(180.0, 0.0, -120.0);
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

	//Jardinera pegada al lado izquierdo
	glPushMatrix();
	glTranslatef(-170, 0.0, -190);
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
	glEnable(GL_LIGHTING);

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
	glEnable(GL_LIGHTING);


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

	




	glPushMatrix();//Post
	glTranslatef(45.0, 0.0, 67.0);
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



	

	glPushMatrix();
	glTranslatef(-17.0, 0.0, 65.0);
	glDisable(GL_LIGHTING);
	jardinera1_1.maceta(10.0, 10.0, 7.5, pasto.GLindex, ladrillo.GLindex);//maceta2
	glTranslatef(-5.0, 0.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, ladrillo.GLindex);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0, 0.0, 3.75);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.5, 0.0, 3.75);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.5, 5, 3.75);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0, 5, 3.75);
	glEnd();
	glBegin(GL_POLYGON);  //Left
		//glColor3f(1.0,1.0,1.0);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.5, 5, 3.75);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.5, 0.0, 3.75);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0, 0.0, -3.75);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0, 5, -3.75);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, pasto.GLindex);
	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0, 5, 3.75);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.5, 5, 3.75);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0, 5, -3.75);
	glEnd();
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glDisable(GL_LIGHTING);


	glPushMatrix();//Post
	glTranslatef(-45.0, 0.0, 67.0);
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




	

	glPushMatrix();
	glTranslatef(57, 0.0, 30);
	glDisable(GL_LIGHTING);
	jardinera1_1.maceta(10.0, 15.0, 41.0, pasto.GLindex, ladrillo.GLindex);//maceta4
	glTranslatef(-7.5, 0.0, 20.5);
	glBindTexture(GL_TEXTURE_2D, ladrillo.GLindex);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0, 0.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-5, 0.0, -14.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-5, 5.0, -14.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0, 5.0, 0.0);
	glEnd();
	glBegin(GL_POLYGON);  //Left
		//glColor3f(1.0,1.0,1.0);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.0, 5.0, -14.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.0, 0.0, -14.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0, 0.0, -41.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0, 5.0, -41.0);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, pasto.GLindex);
	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0, 5.0, -41.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.0, 5.0, -14.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0, 5.0, 0.0);
	glEnd();
	glEnable(GL_LIGHTING);
	glTranslatef(7.5, 0.0, -20.5);
	arbol2.arbol(tree.GLindex);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-57, 0.0, -20);
	glDisable(GL_LIGHTING);
	jardinera1_1.maceta(10.0, 15.0, 30.0, pasto.GLindex, ladrillo.GLindex);//maceta5
	glTranslatef(7.5, 0.0, -15);
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
	glPopMatrix();



	





	glEnable(GL_LIGHTING);
	glPopMatrix();


	
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPopMatrix();
	glutSwapBuffers();

}

void animacion()
{

	glutPostRedisplay();
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
	glutInitWindowSize(2000, 2000);	// Tama�o de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Proyecto_Final"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut funci�n de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut funci�n en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut funci�n de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 
	return 0;
}
