#include <Arduino.h>
#include "./Event/Event.h"
#define MAX_EVENTS 50

long timems = 0;
class Timer
{
public:
    int currIndex = 0;
    Event *events[MAX_EVENTS];
    Timer()
    {
        for (int i = 0; i < MAX_EVENTS; i++)
        {
            events[i] = new Event();
        }
    }

    void attachEvent(void (*EventFun)(), long interval)
    {
        if (currIndex < MAX_EVENTS)
        {
            events[currIndex]->set(EventFun, interval);
            currIndex++;
            return;
        }
        Serial.println("Max Events Attached");
    }

    void update(long currTime){
        for (int i = 0; i < currIndex; i++)
        {
            events[i]->check(currTime);
        }
    }

} timeManager;


hw_timer_t *timer = NULL;

void timeUpdate()
{
    timems += 1;
    timeManager.update(timems);
}
void initTimer()
{
    timer = timerBegin(0, 80, true);
    timerAttachInterrupt(timer, &timeUpdate, true);
    timerAlarmWrite(timer, 1000, true);
    timerAlarmEnable(timer);
}