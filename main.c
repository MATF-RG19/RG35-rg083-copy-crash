#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "Calbacks.h"
#include "Globals.h"
#include "SOIL.h"

int main(int argc, char** argv){

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);  

  glutInitWindowSize(600,433);
  glutInitWindowPosition(100,100);
  glutCreateWindow(argv[0]);

  glShadeModel(GL_SMOOTH);
 
  game_time = 100;
  timer_id = 10;
  rot = 0;
  mod11 = 0,no_mod= 0, mod7 = 0, mod5 = 0, mod4 = 0, mod3 = 0, mod13= 0;
  Cube_x=0, Cube_y=0;
  hours = 0.0, timer = 0, time = 10;
  Gx1 = 0.875, Gy1 = 0.875;
  Gx2 = -0.875, Gy2 = -0.875;
  bonusR = 0, bonusG = 0;
  pause = 0;
  
  /*parametri za osvetljenje zelenog igraca i njegova polja*/
  GLfloat light_ambient[] = {0.6,0.5,0.1,0,0};
  GLfloat light_diffuse[] = {0.4,0.2,0.8,0};
  GLfloat light_specular[] = {0.6,0.6,0,0.5};
  GLfloat light_position[] = {0.3,-0.3,0,0};

  GLfloat model_ambient[] = {0.2,0.9, 0.4, 0.2};
  GLfloat model_diffuse[] = {0.1,0.2,0.8,0.4};
  GLfloat model_specular[] = {0.75,0.6,0,1};
  //model_shininess = 20;

  /*osvetljenja za zelenog igraca*/ 
  
   glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient);
   glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse);
   glLightfv(GL_LIGHT0,GL_SPECULAR,light_specular);
   glLightfv(GL_LIGHT0,GL_POSITION,light_position);
      
  // glMaterialfv(GL_FRONT,GL_AMBIENT,model_ambient);
   glMaterialfv(GL_FRONT,GL_DIFFUSE,model_diffuse);
   glMaterialfv(GL_FRONT,GL_SPECULAR,model_specular);
  // glMaterialf(GL_FRONT,GL_SHININESS,model_shininess);
 
   
   /* ubacivanje slike */
  slika_pozadine=SOIL_load_OGL_texture("deixis_darksky.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    if(slika_pozadine==0){
      printf("Nije ucitana slika\n");   
  }
 
  glutKeyboardFunc(on_keyboard);
  glutReshapeFunc(on_reshape);
  glutDisplayFunc(on_display);
 
 // glColor3f(1,0,0);
  glClearColor(0, 0, 0, 0); 
  glLineWidth(1);
    
  glutMainLoop();

return 0;
}