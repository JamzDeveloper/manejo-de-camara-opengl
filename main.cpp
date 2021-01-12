#include <gl\glut.h>
#include <iostream>
#include <math.h>

using namespace std;


float posX=0,posY=1,posZ=5,visX=0,visY=1,visZ=- 1;

float angle=0.0;

void inicializar()
{
    glClearColor(0.8,0.8,0.8,0);
    glEnable(GL_DEPTH_TEST);
}

void graficarEjes()
{/*
    glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex3f(0,0,0);
    glVertex3f(20,0,0);

    glColor3f(0,1,0);
    glVertex3f(0,0,0);
    glVertex3f(0,20,0);

    glColor3f(0,0,1);
    glVertex3f(0,0,0);
    glVertex3f(0,0,20);
    glEnd();*/
}

void graficar()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);//carga el matriz modelo vista
    glLoadIdentity();// carga la matriz identidad al modelo vista

    gluLookAt(posX,posY,posZ,visX+posX,visY,visZ+posZ,0,1,0);

    graficarEjes();//grafica los ejes


    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(5,0,2);
    glutWireTeapot(2);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(13,0,5);
    glutWireTeapot(2);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(18,0,10);
    glutWireTeapot(2);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(4,0,15);
    glutWireTeapot(2);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-2,0,2);
    glutWireTeapot(2);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-7,0,25);
    glutWireTeapot(2);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(7,0,45);
    glutWireTeapot(2);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0,0,35);
    glutWireTeapot(2);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(15,0,35);
    glutWireTeapot(2);
    glPopMatrix();




    glPushMatrix();
    glTranslatef(20,0,35);
    glutWireTeapot(2);
    glPopMatrix();



     glPushMatrix();
    glTranslatef(25,0,25);
    glutWireTeapot(2);
    glPopMatrix();





    glutSwapBuffers();
}

void redimensionar(int w,int h)
{
    cout<<"Ancho: "<<w<<"   "<<"Alto: "<<h<<endl;

    glViewport(0,0,w,h);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
 //  glOrtho(-50,50,-50,50,-1,1);
    gluPerspective(50,(float)w/(float)h,1,100);

}


/*void rotarTrompo(int i)
{
    rotZ = rotZ + 5 ;
    trasX = trasX + 0.1;

    glutPostRedisplay();
    glutTimerFunc(100,rotarTrompo,1);
}
*/


/** funcion del teclado a mover***********/
void eventoMover(unsigned char key,int x, int y)
{
float fraction = 0.5;
    switch(key)
    {

    case 'a':
/*
        if( (visX >= -15) && (visX <= 45)  && (visZ >= 10) )
        {
            visX += 1;
            visZ = (sqrt((900 - pow((visX-15),2)))) + 10;
            cout<<"X: "<<visX<<endl;
            cout<<"Z: "<<visZ<<endl;
        }

        if( (visX >= -15) && (visX <= 45)  && (visZ<= 10) )
        {
            visX -= 1;
            visZ = -(sqrt((900 - pow((visX-15),2)))) + 10;
            cout<<"X: "<<visX<<endl;
            cout<<"Z: "<<visZ<<endl;
        }*/


        angle -=0.05;
        visX= sin(angle);
        visZ = -cos(angle);
        break;

    case 'd':
       /* if( (visX >= -15) && (visX <= 45)  && (visZ<= 10) )
        {
            visX += 1;
            visZ = -(sqrt((900 - pow((visX-15),2)))) + 10;
            cout<<"X: "<<visX<<endl;
            cout<<"Z: "<<visZ<<endl;
           }

        if( (visX >= -15) && (visX <= 45)  && (visZ >= 10) )
        {
            visX -= 1;
            visZ = (sqrt((900 - pow((visX-15),2)))) + 10;
            cout<<"X: "<<visX<<endl;
            cout<<"Z: "<<visZ<<endl;

        }
*/
        angle +=0.05;
        visX= sin(angle);
        visZ = -cos(angle);

        break;
    case 'w':


        posX += visX * fraction;
            posZ+= visZ * fraction;
        //visY++;

        break;



    case 's':
       posX -= visX * fraction;
            posZ -= visZ * fraction;

        break;



    case '4':


      //  posX--;

        break;

    case '8':
/*
        if(visX<=45&&visX>=0&&visZ>0){
            posZ++;
        }else{
            posZ--;
        }*/
        visY+=0.05;

        break;

    case '6':
        /*   if(visX<=45&&visX>=0&&visZ>0){
           posX--;
        }else{
        posX++;
        }
*/
        break;

    case '5':
/*
        if(visX<=45&&visX>=0&&visZ>0){
            posZ--;
        }else{
             posZ++;
        }*/
        visY-=0.05;

        break;

    }


    cout<<"\n\n\n posicion en x: "<<posX;
    cout<<"\n posicion en y: "<<posY;
    cout<<"\n posicion en z: "<<posZ;
    cout<<"\n vista en x: "<<visX;
    cout<<"\n vista en y: "<<visY;
    cout<<"\n vista en z: "<<visZ;
    glutPostRedisplay();
}




int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(200,50);
    glutCreateWindow("Hola Mundo");

    inicializar();

    glutDisplayFunc(graficar);
    glutReshapeFunc(redimensionar);

    glutKeyboardFunc(eventoMover);//evnento del teclado


    //glutTimerFunc(500,rotarTrompo,1);

    glutMainLoop();

    return 0;
}
