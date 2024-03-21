struct TimingData{
    unsigned frameNumber;

    unsigned lastFrameTimestamp;

    unsigned lastFrameDuration;

    unsigned lastFrameClockstamp;

    unsigned lastFrameClockTicks;

    bool isPaused;

    double averageFrameDuration;

    float fps;

    static TimingData& get();

    static void update();

    static void init();

    static void deinit();

    static unsigned getTime();

    static unsigned long getClock();

    private:
        TimingData();
        TimingData(const TimingData&);
        TimingData& operator=(const TimingData&);
};