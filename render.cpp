#include "render.h"

void initRender()
{
    glPushMatrix();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glBegin(GL_TRIANGLES);
}

void display()
{
    glEnd();
    glFlush();
    glPopMatrix();
    al_flip_display();
}
