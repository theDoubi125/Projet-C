#include <allegro5/allegro5.h>
#include "event.h"
#include <stdio.h>

void initEvents(Events* events)
{
    for(int i=0; i<ALLEGRO_KEY_MAX; i++)
        events->keys[i] = 0;
    for(int i=0; i<10; i++)
        events->mouse[i] = 0;
    events->time = 1;
}

void updateEvents(Events *event, ALLEGRO_EVENT_QUEUE* event_queue)
{
    event->time++;
    ALLEGRO_EVENT ev;
    while(al_get_next_event(event_queue, &ev))
    {
        if(ev.type==ALLEGRO_EVENT_KEY_DOWN)
        {
            if(ev.keyboard.keycode==ALLEGRO_KEY_ESCAPE)
                event->quit = 1;
        }
        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            event->quit = 1;
        if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
            event->keys[ev.keyboard.keycode] = event->time;
        if(ev.type == ALLEGRO_EVENT_KEY_UP)
            event->keys[ev.keyboard.keycode] = -event->time;
        if(ev.type == ALLEGRO_EVENT_MOUSE_AXES || ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY)
        {
            event->xMouse = ev.mouse.x;
            event->yMouse = ev.mouse.y;
        }
    }
}

bool keyPressed(Events *events, int key)
{
    return events->keys[key] == events->time;
}

bool keyDown(Events *events, int key)
{
    return events->keys[key] > 0;
}
