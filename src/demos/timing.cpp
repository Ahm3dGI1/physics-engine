#include "timing.h"

// Hold the internal timing data for the performance counter
static bool qpcFlag;

#if (__APPLE__ || __linux__)
    #define TIMING_UNIX 1

    #include <stdlib.h>
    #include <sys/time.h>

    // Assume linux based OS
    typedef unsigned long long LONGLONG;

#else
    #define TIMING_WINDOWS 1

    // Assume Windows OS
    #include <windows.h>
    #include <mmsystem.h>

    static double qpcFrequency;
#endif

// Initialize the timing system

unsigned systemTime(){
    #if TIMING_UNIX
        struct timeval tv;
        gettimeofday(&tv, 0);
        return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
    #else
        if(qpcFlag){
            static LONGLONG qpcMillisPerTick;
            QueryPerformanceCounter((LARGE_INTEGER*)&qpcMillisPerTick);
            return (unsigned)(qpcMillisPerTick / qpcFrequency);
        }

        else{
            return unsigned(timeGetTime());
        }
    
    #endif
}

unsigned TimingData::getTime(){
    return systemTime();
}

#if TIMING_WINDOWS
    unsigned long systemClock(){
        _asm{
            rdtsc;
        }
    }
#endif

#if TIMING_UNIX
    struct timeval tv;
    gettimeofday(&tv, 0);

    return (tv.tv_sec * 1000000) + tv.tv_usec;

#else
    return systemClock();

#endif

// Sets up the timing system and registers the performance counter

void initTime(){
    #if TIMING_UNIX
        qpcFlag = false;
    
    #else
        LONGLONG time;
        qpcFlag = (QueryPerformanceFrequency((LARGE_INTEGER*)&time) > 0);
        
        if (qpcFlag){
            qpcFrequency = 1000.0 / time;
        }
        
    #endif
}

// Holds the global frame time
static TimingData *timingData = NULL;

TimingData& TimingData::get(){
    return (TimingData&)*timingData;
}

void TimingData::update(){
    if (!timingData){
        return;
    }

    // Advance the frame number
    if (!timingData->isPaused){
        timingData->frameNumber++;
    }

    // Update the timing information
    unsigned thisTime = systemTime();
    timingData->lastFrameDuration = thisTime - timingData->lastFrameTimestamp;
}