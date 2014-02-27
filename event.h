#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED

struct Events
{
    int keys[ALLEGRO_KEY_MAX];
    int mouse[10];
    int xMouse, yMouse;
    int quit;
    int time;
};

void initEvents(Events *event);

void updateEvents(Events *event, ALLEGRO_EVENT_QUEUE *event_queue);

bool keyPressed(Events *events, int key);
bool keyDown(Events *events, int key);

#endif // EVENT_H_INCLUDED
