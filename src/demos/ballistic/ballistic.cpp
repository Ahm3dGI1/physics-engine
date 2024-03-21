#include "include\vakiin\vakiin.h"

using namespace vakiin;

switch (currentShotType)
{
    case PISTOL:
        shot->particle.setMass(2.0f); // 2.0kg
        shot->particle.setVelocity(0.0f, 0.0f, 35.0f); // 35m/s
        shot->particle.setAcceleration(0.0f, -1.0f, 0.0f); // 1m/s^2
        shot->particle.setDamping(0.99f);
        break;
    
    case ARTILLERY:
        shot->particle.setMass(200.0f); // 200.0kg
        shot->particle.setVelocity(0.0f, 30.0f, 40.0f); // 50m/s
        shot->particle.setAcceleration(0.0f, -20.0f, 0.0f); // 20m/s^2
        shot->particle.setDamping(0.99f);
        break;
    
    case FIREBALL:
        shot->particle.setMass(1.0f); // 1.0kg
        shot->particle.setVelocity(0.0f, 0.0f, 10.0f); // 10m/s
        shot->particle.setAcceleration(0.0f, 0.6f, 0.0f); // 0.6m/s^2
        shot->particle.setDamping(0.9f);
        break;
    
    case LASER:
        shot->particle.setMass(0.1f); // 0.1kg
        shot->particle.setVelocity(0.0f, 0.0f, 100.0f); // 100m/s
        shot->particle.setAcceleration(0.0f, 0.0f, 0.0f); // 0m/s^2
        shot->particle.setDamping(0.99f);
        break;
}

// Set the data common to all particle types
shot->particle.setPosition(0.0f, 1.5f, 0.0f);
shot->startTine = TimingData::get().lastFrameTimestamp;
shot->type = currentShotType;

// Clear the force accumulators
shot->particle.clearAccumulator();