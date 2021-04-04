class Event{
    public:
    void (*fun)();
    long interval = 0;
    void set(void (*EventFun)(), long interval){
        fun = EventFun;
        this->interval = interval;
    }

    void check(long currTime){
        if(currTime % interval == 0){
            fun();
        }
    }
};