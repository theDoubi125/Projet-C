#include <allegro5/allegro5.h>
#include <allegro5/allegro_opengl.h>
#include <cstdio>
#include <math.h>

#include "event.h"
#include "render.h"
#include "chained_list.h"

void init(ALLEGRO_EVENT_QUEUE** e_queue, int w, int h, int full=0, int opengl=1)
{
    if(full)
        al_set_new_display_flags(ALLEGRO_FULLSCREEN);
    if(opengl)
        al_set_new_display_flags(ALLEGRO_OPENGL);
    ALLEGRO_DISPLAY* display = al_create_display(w,h);
    if(!display)
        printf("ERROR INITIALIZING THE DISPLAY AT %i %i!",w,h);
    *e_queue = al_create_event_queue();
    if(!e_queue)
        printf("ERROR CREATING EVENT QUEUE!");
    al_register_event_source(*e_queue, al_get_display_event_source(display));
    al_register_event_source(*e_queue, al_get_keyboard_event_source());
    al_register_event_source(*e_queue, al_get_mouse_event_source());
}

int install_allegro()
{
    if(!al_init())
    {
        printf("ERROR INITIALIZING ALLEGRO!");
        return 0;
    }
    if(!al_install_keyboard())
    {
        printf("ERROR INITIALIZING KEYBOARD!");
        return 0;
    }
    if(!al_install_mouse())
    {
        printf("ERROR INITIALIZING MOUSE!");
        return 0;
    }
    return 1;
}
void render(int x, int y)
{

    glColor3f(1.0f,0.0f,0.0f);
    for(int i=0; i<360; i++)
    {
        glVertex3f(x,y,0.0f);
        glVertex3f(x + 100*cos(((float)i/180*3.14)), y + 100*sin(((float)i/180*3.14)),0.0f);
        glVertex3f(x + 100*cos(((float)(i+1)/180*3.14)), y + 100*sin(((float)(i+1)/180*3.14)),0.0f);
    }
}
void init_opengl()
{
    glEnable(GL_DEPTH_TEST);
    glViewport(0,0,800,600);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,800,600,0,-200,200);
    glClearColor(0,0,0,1);
}

int main()
{
    ALLEGRO_EVENT_QUEUE* event_queue = NULL;
    ALLEGRO_EVENT_QUEUE* timer_queue = NULL;
    if(!install_allegro())
        return 1;

    init(&event_queue,800,600);
    timer_queue = al_create_event_queue();
    init_opengl();

    ALLEGRO_TIMER* fps = al_create_timer(1.0f/25.0f);
    al_register_event_source(timer_queue, al_get_timer_event_source(fps));
    bool quit = false;
    al_start_timer(fps);
    Events events;
    initEvents(&events);

    int time = 1;

    while(!quit)
    {
        ALLEGRO_EVENT ev;
        while(al_get_next_event(timer_queue, &ev))
        {
            updateEvents(&events, event_queue);
            initRender();
            if(keyDown(&events, ALLEGRO_KEY_A))
                render(events.xMouse, events.yMouse);
            if(keyPressed(&events, ALLEGRO_KEY_ESCAPE))
                quit = true;
            display();
        }
        time++;
    }

    al_destroy_display(al_get_current_display());
    al_destroy_event_queue(event_queue);

    ListContent content;
    content.i = 10;
    ChainedList l = addToChainedList(content, NULL);
    ListContent contentBis;
    contentBis.i = 20;
    ChainedList l2 = addToChainedList(contentBis, &l);
    printChainedList(&l2);
    return 0;
}
