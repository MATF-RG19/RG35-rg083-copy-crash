#include "Check.h"

/* funkcija koja odredjuje random koordinate predmeta 
 * i proverava da li se mogu naci na polju */
void draw_rand_elements(){
  i_rand = 0;
  int t=0;
  float tmpX=0 , tmpY=0;
  tmpX = (Gx1 - 0.25)+0.125;
  tmpY = (Gy1 - 0.75)+0.125;
  if(tmpX < 0.875 && tmpY < 0.875 && tmpX > -0.875 && tmpY > -0.875){
    niz_rand[t]=tmpX;
    niz_rand[t+1]=tmpY;
    t = t+2;
    i_rand = 1;
  }
  tmpX = (Gx1 - 0.5)+0.125;
  tmpY = (Gy1 + 0.25)+0.125;
  if(tmpX < 0.875 && tmpY < 0.875 && tmpX > -0.875 && tmpY > -0.875){
    niz_rand[t]=tmpX;
    niz_rand[t+1]=tmpY;
    t = t+2;
    i_rand = 2;
  }  
  tmpX = (Gx1 + 0.25)+0.125;
  tmpY = (Gy1 - 0.25)+0.125;
  if(tmpX < 0.875 && tmpY < 0.875 && tmpX > -0.875 && tmpY > -0.875){
    niz_rand[t]=tmpX;
    niz_rand[t+1]=tmpY;
    t = t+2;
    i_rand = 3;
  }
  tmpX = (Gx2 + 0.75)+0.125;
  tmpY = (Gy2 - 0.25)+0.125;
  if(tmpX < 0.875 && tmpY < 0.875 && tmpX > -0.875 && tmpY > -0.875){
    niz_rand[t]=tmpX;
    niz_rand[t+1]=tmpY;
    t = t+2;
    i_rand = 4;
  }
  tmpX = (Gx2 + 0.25)+0.125;
  tmpY = (Gy2 - 0.5)+0.125;
  if(tmpX < 0.875 && tmpY < 0.875 && tmpX > -0.875 && tmpY > -0.875){
    niz_rand[t]=tmpX;
    niz_rand[t+1]=tmpY;
    t = t+2;
    i_rand = 5;
  } 
  niz_rand[t+1]='\0';
}

void check_random(){

        int rand_num = rand(); 
      if((rand_num % 11) == 0){
	 mod11 = 1;
	 mod7=mod5=mod4=mod3=no_mod = 0;
	 glutPostRedisplay();
      }else if((rand_num % 7) == 0){
	mod7 = 1;
	mod11=mod5=mod4=mod3=no_mod =0;
	glutPostRedisplay();
      }else if((rand_num % 5) == 0){
	mod5 = 1;
	mod11=mod7=mod4=mod3=no_mod =0;
	glutPostRedisplay();
      }else if((rand_num % 4) == 0){
	mod4 = 1;
	mod11=mod7=mod5=mod3=no_mod =0;
      }else if((rand_num % 3) == 0){
	mod3 = 1;
	mod11=mod7=mod5=mod4=no_mod =0;
      }else{
	no_mod = 1;
	mod11=mod7=mod5=mod4=mod3 = 0;
      }

}

/* funkcija koja rotira celo polje sa sve igracima i
 * elementima dok igrac stoji na polju gde je kupa */
void check_Cone_rand(){

  float rotate = rot * 360 / 24;

  glTranslatef(0,0.3,0);
    glRotatef(rotate,1,0,0);
  glTranslatef(0,-0.3,0);

}

/* funkcija koja postavlja koordinate kocke u dve pomocne
 * promenljive pomocu kojih se postavlja ogranicenje da se
 * samo jednom moze proci preko polja gde se pojavila kocka */
void check_Cube_rand(float pomX, float pomY){
  
  Cube_x = pomX;
  Cube_y = pomY;
  
}

/* funkcija koja boji polja i vodoravno i vertikalno
 * u odnosu na polje igraca */
void check_X_rand(float pomX, float pomY, char* s){
  
  float koord = -0.875;
  if(strcmp(s,"red")== 0){
	while(koord <= 0.875){
	  RedCube(pomX, koord);
	  koord = koord + 0.25;
	}	
	koord = koord - 0.25;
	while(koord >= -0.875){
	  RedCube(koord, pomY);
	  koord = koord - 0.25;
	}	
      }
    else{
      while(koord <= 0.875){
	  GreenCube(pomX, koord);
	  koord = koord + 0.25;
	}
	koord = koord - 0.25;
      while(koord >= -0.875){
	 GreenCube(koord, pomY);
	 koord = koord - 0.25;
	}	
      }    
}

/* funkcija koja boji ceo red u zavisnosi od toga koja strelica
 * je u pitanju ako je vodotravna boji vodoravno jedan red, a ako
 * je vertikalno onda boji vertikalno */
void check_Arrow_rand(float pomX, float pomY, char* s){
  float koord = -0.875;
  if(strcmp(s,"red")== 0){
      if(mod7 == 1){
	
	while(koord <= 0.875){
	  RedCube(pomX, koord);
	  koord = koord + 0.25;
	}	
      }
      else{
	while(koord <= 0.875){
	  RedCube(koord, pomY);
	  koord = koord + 0.25;
	}	
      }
    }
    else{
      if(mod7 == 1){
	
	while(koord <= 0.875){
	  GreenCube(pomX, koord);
	  koord = koord + 0.25;
	}	
      }
      else{
	while(koord <= 0.875){
	  GreenCube(koord, pomY);
	  koord = koord + 0.25;
	}	
      }
    }
  
}

/* funkcija koja prolazi kroz niz u kome su sacuvane koordinate
 * random elemenata i odredjuje koja akcija treba da se desi kada 
 * neki igrac stane na odredjeno polje */
void check_position(){
  
    for(i=0; niz_rand[i+1]!='\0'; i=i+2){
      	float tmp = -(niz_rand[i]+0.125), tmp2 = -(niz_rand[i+1]+0.125);
	
	if(Gx1 == tmp && Gy1 == tmp2){
	    if(mod3 == 1){
	    check_Cone_rand();
	    }
	    if(mod5 == 1){
	    check_Cube_rand(tmp,tmp2);
	    }
	   if(mod11 == 1){
	     check_X_rand(-tmp, -tmp2, "red");
	   //   printf("Crveni igrac je stao na X\n");	
	  }
	  if(mod7 == 1 || mod4 == 1){
	    check_Arrow_rand(-tmp,-tmp2,"red");
	   }	  
	  }
	if(Gx2 == tmp && Gy2 == tmp2){
	   if(mod3 == 1){
	    check_Cone_rand();
	    }
	   if(mod5 == 1){
	    check_Cube_rand(tmp,tmp2);
	    }
	   if(mod11 == 1){
	      check_X_rand(tmp, tmp2,"green");
	     // printf("Zeleni igrac je stao na X\n");
	   }
	   if(mod7 == 1 || mod4 == 1){
	    check_Arrow_rand(tmp,tmp2,"green");
	   }
	}
    }
}

