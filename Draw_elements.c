#include <GL/glut.h>
#include "Draw_elements.h"

/*iscrtavanje polja na kome se kasnije crta mreza*/
void field(){
  
  glPushMatrix();
    glBegin(GL_POLYGON);
      glShadeModel(GL_SMOOTH);
      glColor3f(0.90, 0.8, 0);
      glVertex3f(-1,1,0);
      glVertex3f(-1,-1,0);
      glVertex3f(1,-1,0);
      glVertex3f(1,1,0);
    glEnd();
  glPopMatrix();
  
}
/*Iscrtavanje mreze polja po kojima se igraci krecu*/
void field_separated(){

  glShadeModel(GL_SMOOTH);
  glPushMatrix();
    glBegin(GL_LINES);
      int i;
      float j=-1;
      
      for(i=0;i<16;i++){
	if(i< 8){
	  glColor3f(0,0,0);
	    glVertex3f(j,-1,0);
	    glVertex3f(j,1,0);
	  j = j+0.25;   
	}
	else{
	  glColor3f(0,0,0);
	    glVertex3f(-1,j,0);
	    glVertex3f(1,j,0);
	  j = j-0.25;   	
	}
    }
    glEnd();
  glPopMatrix();
}

/* funkcija koja na ekran iscrtava nekoliko igraca koji su slicni ogracima 1 i 2 */
void Confuse_rand(float px, float py, int k){
  px = px+0.125;
  py = py+0.125;
  if(k == 0 || k == 4 || k == 8){
    glPushMatrix();
    GLfloat model_ambient[] = {0.9,0.2, 0.4, 0.2};  
    glMaterialfv(GL_FRONT,GL_AMBIENT,model_ambient);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
      glShadeModel(GL_SMOOTH);
      glTranslatef(-px,-py,0);
      glutSolidCone(0.12,0.4,10,1);
      glTranslatef(0,0,0.4);
      glShadeModel(GL_FLAT);
      glutSolidSphere(0.10,10,10);
      glTranslatef(0,0,-0.4);
      glTranslatef(px,py,0);
      glDisable(GL_LIGHT0);
      glDisable(GL_LIGHTING);
    glPopMatrix();    
  }else if(k == 2 || k == 6){
    glPushMatrix();
    GLfloat model_ambient[] = {0.2,0.9, 0.4, 0.2};  
    glMaterialfv(GL_FRONT,GL_AMBIENT,model_ambient);
  
      glEnable(GL_LIGHT0);
      glEnable(GL_LIGHTING);
      glShadeModel(GL_SMOOTH);
      glTranslatef(-px,-py,0);
      glutSolidCone(0.12,0.4,10,1);
      glTranslatef(0,0,0.4);
      glShadeModel(GL_FLAT);
      glutSolidSphere(0.10,10,10);
      glTranslatef(0,0,-0.4);
      glTranslatef(px,py,0);
      glDisable(GL_LIGHT0);
      glDisable(GL_LIGHTING);
    glPopMatrix();    
  }  
}

/* funkcija koja iscrtava kupu */
void Cone_rand(float px, float py){
  px = px+0.12;
  py= py+0.12;
  
  GLfloat model_ambient[] = {0.2,0.2, 0.9, 0.2};  
  glMaterialfv(GL_FRONT,GL_AMBIENT,model_ambient);
  
  glTranslatef(px, py, 0);	
    glRotatef(90,1,0,0);
    glPushMatrix();
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glutSolidCone(0.12,0.4,10,1);
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glRotatef(-90,1,0,0);
  glTranslatef(-px, -py, 0);
}

/*iscrtavanje kocke koja se random pojavljuje*/
void Cube_rand(float px, float py){
  px = px+0.125;
  
  GLfloat model_ambient[] = {0.25,0.25, 0, 0.2};  
  glMaterialfv(GL_FRONT,GL_AMBIENT,model_ambient);
  
  glTranslatef(px,py,0);  
    glPushMatrix();
      glEnable(GL_LIGHT0);
      glEnable(GL_LIGHTING);
      glutSolidCube(0.2);
      glDisable(GL_LIGHT0);
      glDisable(GL_LIGHTING);
    glPopMatrix();
  glTranslatef(-px,-py,0);
}

/*iscrtavanje strelice*/
void Arrow_rand(float px, float py){
  glTranslatef(px,py,0);
  GLfloat model_ambient[] = {0.25,0.2, 0.3, 0.2};  
  glMaterialfv(GL_FRONT,GL_AMBIENT,model_ambient);
	
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHTING);

    if(mod7 == 1){
      glPushMatrix();
    	glPushMatrix();
	  glBegin(GL_POLYGON);
	    glVertex3f(0.145, 0,0);
	    glVertex3f(0.145,0.150,0);
	    glVertex3f(0.105,0.150,0);
	    glVertex3f(0.105,0,0);
	  glEnd();
	glPopMatrix();
      
	glPushMatrix();
	  glBegin(GL_TRIANGLES);
	    glVertex3f(0.125,0.25,0);
	    glVertex3f(0.2,0.150,0);
	    glVertex3f(0.05,0.150,0);
	  glEnd();
	glPopMatrix();
      glPopMatrix();
    }
    else if(mod4 == 1){
      glPushMatrix();
	glPushMatrix();
	  glBegin(GL_POLYGON);
	    glColor3f(0.25,0.2,0.3);
	    glVertex3f(0,0.145,0);
	    glVertex3f(0.150,0.145,0);
	    glVertex3f(0.150,0.105,0);
	    glVertex3f(0,0.105,0);
	  glEnd();
	glPopMatrix();
      
	glPushMatrix();
	  glBegin(GL_TRIANGLES);
	    glColor3f(0.2,0.25,0.3);
	    glVertex3f(0.25,0.125,0);
	    glVertex3f(0.150,0.2,0);
	    glVertex3f(0.150,0.05,0);
	  glEnd();
	glPopMatrix();    
      glPopMatrix();
    }
  glDisable(GL_LIGHT0);
  glDisable(GL_LIGHTING);
      
  glTranslatef(-px,-py,0);
}

/*iscrtavanje X koje ce obojiti horizontalno i vertikalno sva neobojena polja*/
void X_rand(float px, float py){
  GLfloat model_ambient[] = {0,0, 0, 0.2};  
  glMaterialfv(GL_FRONT,GL_AMBIENT,model_ambient);
  
  
  glTranslatef(px,py,0);   
    glPushMatrix();
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glLineWidth(5);
    glBegin(GL_LINES);
      glVertex3f(0.25, 0.25,0);
      glVertex3f(0,0,0);
      glVertex3f(0.25,0,0);
      glVertex3f(0,0.25,0);
    glEnd();
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING);
    glPopMatrix();  
    glLineWidth(1);

  glTranslatef(-px,-py,0);
}
/*iscrtavanje loptica kojima igraci mogu da dobiju bonus poene*/
void take_Ball(float px, float py){
  GLfloat model_ambient[] = {0.2,0.2, 0.8, 0.2};  
  glMaterialfv(GL_FRONT,GL_AMBIENT,model_ambient);
  
  glTranslatef(px,py,0);   
    glPushMatrix();
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glutSolidSphere(0.8,15,15);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glPopMatrix();  
  glTranslatef(-px,-py,0);
}



/*crta se crveni kvadrat ispod igraca 1*/
void RedCube(float Gx1, float Gy1){
  red_num = 0;
  int pom = 0;
  i=0;
  while(niz_r[i+1]!='\0'){
    if(niz_r[i] == Gx1 && niz_r[i+1] == Gy1){
      pom=1;
    }
    i=i+2;
  }
  
  if(pom==0){
   niz_r[i] = Gx1;
   niz_r[i+1] = Gy1;
   j=0;
    while(niz_g[j+1]!= '\0'){
	if(niz_g[j] == Gx1 && niz_g[j+1] == Gy1){
	  niz_g[j] = niz_g[j+2];
	  niz_g[j+1] = niz_g[j+3];
	  j=j+2;
	  while(niz_g[j+3]!='\0'){
	    niz_g[j] = niz_g[j+2];
	    niz_g[j+1] = niz_g[j+3];
	    j=j+2;
	  }
	  niz_g[j] = '\0';
	  niz_g[j+1] = '\0';	
	} 

      j=j+2;
    }
  }
  
  for(j=0; niz_r[j+1]!='\0'; j=j+2){
  GLfloat model_ambient[] = {0.9,0.2, 0.4, 0.2};
  glMaterialfv(GL_FRONT,GL_AMBIENT,model_ambient);

    glPopMatrix();
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glBegin(GL_POLYGON);
	glVertex3f(niz_r[j]+0.123,niz_r[j+1]+0.123,0);
	glVertex3f(niz_r[j]-0.123,niz_r[j+1]+0.123,0);
	glVertex3f(niz_r[j]-0.123,niz_r[j+1]-0.123,0);
	glVertex3f(niz_r[j]+0.123,niz_r[j+1]-0.123,0);
      glEnd();
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING);
    glPopMatrix();  
    red_num++;
  }
}

/*igrac broj 1 -crveni napravljen u koorinatnom 
 *pocetku i zatim transliran na pocetnu poziciju*/
void Gamer1(){
  
  GLfloat model_ambient[] = {0.9,0.2, 0.4, 0.2};  
  glMaterialfv(GL_FRONT,GL_AMBIENT,model_ambient);  
  
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  float rot1 = rot * 360 / 24;
  
  glPushMatrix();
    glShadeModel(GL_SMOOTH);
    glTranslatef(-Gx1,-Gy1,0);
    
    
  GLfloat model_ambient1[] = {0.1,0.2, 0.9, 0.5};  
  glMaterialfv(GL_FRONT,GL_AMBIENT,model_ambient1);

    
   // TELO
    glPushMatrix();
      glTranslatef(0,0,0.2);
      glScalef(1,0.5,1);
      glutSolidCube(0.2);
      glScalef(1,-0.5,-1);
      glTranslatef(0,0,-0.2);
    glPopMatrix();

    //NOGE    
    glPushMatrix();
      glTranslatef(0.05,0,0);
      glScalef(0.3,0.3,0.8);
      glutSolidCube(0.2);
      glScalef(-0.3,-0.3,-0.8);
      glTranslatef(-0.05,0,0);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(-0.05,0,0);
      glScalef(0.3,0.3,0.8);
      glutSolidCube(0.2);
      glScalef(-0.3,-0.3,-0.8);
      glTranslatef(0.05,0,0);
    glPopMatrix();
    
    
    //RUKE
    glPushMatrix();
      glTranslatef(0.11,0,0.2);
      glScalef(0.3,0.3,0.8);
      glutSolidCube(0.2);
      glScalef(-0.3,-0.3,-0.8);
      glTranslatef(-0.11,0,-0.2);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(-0.11,0,0.2);
      glScalef(0.3,0.3,0.8);
      glutSolidCube(0.2);
      glScalef(-0.3,-0.3,-0.8);
      glTranslatef(0.11,0,-0.2);
    glPopMatrix();

    glTranslatef(0,0,0.4);
    glRotatef(rot1, 0, 1, 0);
    
  glMaterialfv(GL_FRONT,GL_AMBIENT,model_ambient);  

    glShadeModel(GL_SMOOTH);
    glutSolidSphere(0.10,10,10);
    glTranslatef(0,0,-0.4);
    glTranslatef(Gx1,Gy1,0);
  glPopMatrix();
  
  glDisable(GL_LIGHT0);
  glDisable(GL_LIGHTING);
}

/*crta se zeleni kvadrat ispod igraca 2*/
void GreenCube(float Gx2, float Gy2){
  green_num = 0;
  int pom = 0;
  i=0;
  while(niz_g[i+1]!='\0'){
    if(niz_g[i] == -Gx2 && niz_g[i+1] == -Gy2){
      pom=1;
    }
    i=i+2;
  }
  if(pom==0){
   niz_g[i] = -Gx2;
   niz_g[i+1] = -Gy2;
   j=0;
    while(niz_r[j+1]!= '\0'){
	if(niz_r[j] == -Gx2 && niz_r[j+1] == -Gy2){
	  niz_r[j] = niz_r[j+2];
	  niz_r[j+1] = niz_r[j+3];
	  j=j+2;
	  while(niz_r[j+3]!='\0'){
	    niz_r[j] = niz_r[j+2];
	    niz_r[j+1] = niz_r[j+3];
	    j=j+2;
	  }
	  niz_r[j] = '\0';
	  niz_r[j+1] = '\0';	
	} 

      j=j+2;
    }
  }
  for(j=0; niz_g[j+1]!='\0'; j=j+2){
    glPopMatrix();
    GLfloat model_ambient[] = {0.2,0.9, 0.4, 0.2};  
    glMaterialfv(GL_FRONT,GL_AMBIENT,model_ambient);
  
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
      glBegin(GL_POLYGON);
	glVertex3f(niz_g[j]+0.123,niz_g[j+1]+0.123,0);
	glVertex3f(niz_g[j]-0.123,niz_g[j+1]+0.123,0);
	glVertex3f(niz_g[j]-0.123,niz_g[j+1]-0.123,0);
	glVertex3f(niz_g[j]+0.123,niz_g[j+1]-0.123,0);
      glEnd();
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING);  
    glPopMatrix();
    green_num++;
  }
}

/*igrac broj 2 -zeleni napravljen u koorinatnom 
 *pocetku i zatim transliran na pocetnu poziciju*/
void Gamer2(){
  GLfloat model_ambient[] = {0.2,0.9, 0.4, 0.2};  
  glMaterialfv(GL_FRONT,GL_AMBIENT,model_ambient);
    
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  float rot2 = rot * 360 /24;

  glPushMatrix();
    glShadeModel(GL_SMOOTH);
    glTranslatef(-Gx2,-Gy2,0);

  GLfloat model_ambient1[] = {0.1,0.2, 0.9, 0.5};  
  glMaterialfv(GL_FRONT,GL_AMBIENT,model_ambient1);

    // TELO
    glPushMatrix();
      glTranslatef(0,0,0.2);
      glScalef(1,0.5,1);
      glutSolidCube(0.2);
      glScalef(1,-0.5,-1);
      glTranslatef(0,0,-0.2);
    glPopMatrix();

    //NOGE    
    glPushMatrix();
      glTranslatef(0.05,0,0);
      glScalef(0.3,0.3,0.8);
      glutSolidCube(0.2);
      glScalef(-0.3,-0.3,-0.8);
      glTranslatef(-0.05,0,0);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(-0.05,0,0);
      glScalef(0.3,0.3,0.8);
      glutSolidCube(0.2);
      glScalef(-0.3,-0.3,-0.8);
      glTranslatef(0.05,0,0);
    glPopMatrix();
    
    
    //RUKE
    glPushMatrix();
      glTranslatef(0.11,0,0.2);
      glScalef(0.3,0.3,0.8);
      glutSolidCube(0.2);
      glScalef(-0.3,-0.3,-0.8);
      glTranslatef(-0.11,0,-0.2);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(-0.11,0,0.2);
      glScalef(0.3,0.3,0.8);
      glutSolidCube(0.2);
      glScalef(-0.3,-0.3,-0.8);
      glTranslatef(0.11,0,-0.2);
    glPopMatrix();

    glMaterialfv(GL_FRONT,GL_AMBIENT,model_ambient);

    glTranslatef(0,0,0.4);
    glRotatef(rot2, 1, 0, 0);
    glShadeModel(GL_SMOOTH);
    glutSolidSphere(0.10,10,10);
    glTranslatef(0,0,-0.4);
    glTranslatef(Gx2,Gy2,0);
  glPopMatrix();  
  
  glDisable(GL_LIGHT0);
  glDisable(GL_LIGHTING);
  
}

/*funkcija koja pokazuje koje dugme je za pocetak igrice tj ukljucivanje tajmera*/
void startGame(void){
	char tekst1[256], *p1;
	sprintf(tekst1, "Pritisnite g za pocetak igrice");

	glPushMatrix();
			glColor3f(1,1,1);
			glRasterPos3f(1.5,-3,0);
			for(p1 = tekst1; *p1!= '\0'; p1++){
					glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p1);
			}
	glPopMatrix();
	  
}


/*Funkcija za ispis trenutnog skora tokom trajanja igre.*/
void Score(void){

	char tekst1[256], *p1;
	sprintf(tekst1, "Current score: R:G");

	char tekst2[256], *p2;
	sprintf(tekst2, "%d", red_num);

	char tekst3[256], *p3;
	sprintf(tekst3, "%d", green_num);
	glPushMatrix();
			glColor3f(1,1,1);
			glRasterPos3f(1.5,-3,0);
			for(p1 = tekst1; *p1!= '\0'; p1++){
					glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p1);
			}
	glPopMatrix();
	
	char tekst23[256], *p23;
	sprintf(tekst23, ":");
	glPushMatrix();
			glColor3f(1,1,1);
			glRasterPos3f(-1.6,-3,0);
			for(p23 = tekst23; *p23!= '\0'; p23++){
					glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p23);
			}
	glPopMatrix();
	
	glPushMatrix();
			glColor3f(1,1,1);
			glRasterPos3f(-1.2,-3,0);
			for(p2 = tekst2; *p2!= '\0'; p2++){
					glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p2);
			}
	glPopMatrix();
	
	
	glPushMatrix();
			glColor3f(1,1,1);
			glRasterPos3f(-1.7,-3,0);
			for(p3 = tekst3; *p3!= '\0'; p3++){
					glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p3);
			}
	glPopMatrix();
	
}


/*funkcija za ispisivanje konacnog rezultata*/
void finalScore(void){
	
	if(red_num > green_num){
	  
  	char tekst1[256], *p1;
	sprintf(tekst1, "Pobedio je crveni igrac!");

	glPushMatrix();
			glColor3f(1,0,0);
			glRasterPos3f(1.5,-3,0);
			for(p1 = tekst1; *p1!= '\0'; p1++){
					glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p1);
			}
	glPopMatrix();
	}else if (green_num > red_num){
	  
	char tekst2[256], *p2;
	sprintf(tekst2, "Pobedio je zeleni igrac!");
	  
	glPushMatrix();
			glColor3f(0,1,0);
			glRasterPos3f(1.5,-3,0);
			for(p2 = tekst2; *p2!= '\0'; p2++){
					glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p2);
			}
	glPopMatrix();
	}else{
	  
	char tekst3[256], *p3;
	sprintf(tekst3, "Nereseno je!");
	  
	glPushMatrix();
			glColor3f(1,1,1);
			glRasterPos3f(1.5,-3,0);
			for(p3 = tekst3; *p3!= '\0'; p3++){
					glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p3);
			}
	glPopMatrix();  
	}
	
	
	char tekst4[256], *p4;
	sprintf(tekst4, "Pritisnite ESC za izlazak iz igrice!");
	
	  
	glPushMatrix();
			glColor3f(1,1,1);
			glRasterPos3f(1.5,-2,0);
			for(p4 = tekst4; *p4!= '\0'; p4++){
					glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p4);
			}
	glPopMatrix();
}

void pause_print(void){
	char tekst1[256], *p1;
	sprintf(tekst1, "Pause");

	glPushMatrix();
			glColor3f(1,1,1);
			glRasterPos3f(1.5,-3,0);
			for(p1 = tekst1; *p1!= '\0'; p1++){
					glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p1);
			}
	glPopMatrix();
	  
}
