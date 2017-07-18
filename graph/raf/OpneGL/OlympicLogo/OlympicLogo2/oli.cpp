#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>


/* GLUT callback Handlers */

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);




    //top row - 1st right
    glPushMatrix();
        glTranslated(2.4,1.2,-6);
        glColor3d(1,0,0);
        glRotated(360,1,0,0);
        glRotated(a,0,1,0);
        glutSolidTorus(0.2,1,16,30);
    glPopMatrix();

    //top row - middle
    glPushMatrix();
        glTranslated(-.2,1.2,-6);
        glColor3d(0,0,0);
        //glRotated(360,1,0,0);
        glRotated(a,0,1,0);
         glutSolidTorus(0.2,1,16,30);
    glPopMatrix();

    //top row - 1st left
    glPushMatrix();
        glTranslated(-2.8,1.2,-6);
        glColor3d(0,0,1);
        glRotated(360,0,0,0);
        glRotated(a,0,1,0);
         glutSolidTorus(0.2,1,16,30);
    glPopMatrix();

    //bottom row - 1st right
     glPushMatrix();
        glTranslated(1.1,.4,-6);
        glColor3d(0,1,0);
        glRotated(360,0,0,0);
        glRotated(a,0,1,0);
         glutSolidTorus(0.2,1,16,30);
    glPopMatrix();

    //bottom row - 1st left
     glPushMatrix();
        glTranslated(-1.5,.4,-6);
        glColor3d(1,1,0);
        glRotated(360,0,0,0);
        glRotated(a,0,1,0);
        glutSolidTorus(0.2,1,16,30);
    glPopMatrix();

    /*roll no 77
    glPushMatrix();
    glLineWidth(6);
    glTranslated(.60,0,-2);
    glBegin(GL_LINES);
        glColor3f(1,0,0);
        glVertex3f(.72,-.7,0);
        glVertex3f(.8,-.7,0);
        glVertex3f(.8,-.7,0);
        glVertex3f(.72,-.9,0);

        glVertex3f(.82,-.7,0);
        glVertex3f(.9,-.7,0);
        glVertex3f(.9,-.7,0);
        glVertex3f(.82,-.9,0);
    glEnd();
    glPopMatrix();*/



    glutSwapBuffers();
}


static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(800,480);
    glutInitWindowPosition(200,200);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Olympic Logo");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutIdleFunc(idle);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return EXIT_SUCCESS;
}