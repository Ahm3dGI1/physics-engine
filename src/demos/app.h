#include <cstdlib>
#include "D:\Projects\physics-engine\include\vakiin\vakiin.h"

class App{
    protected:
        // Window properties
        int height, width;

    public:
        virtual const char* getTitle();

        virtual void initGraphics();

        virtual void setView();

        virtual void deinit();

        virtual void display();

        virtual void update();

        virtual void key(unsigned char key);

        virtual void mouse(int button, int state, int x, int y);

        virtual void mouseDrag(int x, int y);

        virtual void resize(int width, int height);

        virtual void renderText(float x, float y, void* font = NULL, const char* text);
};

/**
 * This application adds additional functionality used in the mass-aggregate demos.
 */
class MassAggregateApplication : public App
{
protected:
    vakiin::ParticleWorld world;
    vakiin::Particle *particleArray;
    vakiin::GroundContacts groundContactGenerator;

public:
    MassAggregateApplication(unsigned int particleCount);
    virtual ~MassAggregateApplication();

    /** Update the particle positions. */
    virtual void update();

    /** Sets up the graphic rendering. */
    virtual void initGraphics();

    /** Display the particles. */
    virtual void display();
};

/**
 * This application adds additional functionality used in many of the
 * demos. This includes the ability to track contacts (for rigid bodies)
 * and move the camera around.
 */
 class RigidBodyApplication : public App
 {
 protected:
    /** Holds the maximum number of contacts. */
    const static unsigned maxContacts = 256;

    /** Holds the array of contacts. */
    vakiin::Contact contacts[maxContacts];

    /** Holds the collision data structure for collision detection. */
    vakiin::CollisionData cData;

    /** Holds the contact resolver. */
    vakiin::ContactResolver resolver;

    /** Holds the camera angle. */
    float theta;

    /** Holds the camera elevation. */
    float phi;

    /** Holds the position of the mouse at the last frame of a drag. */
    int last_x, last_y;

    /** True if the contacts should be rendered. */
    bool renderDebugInfo;

    /** True if the simulation is paused. */
    bool pauseSimulation;

    /** Pauses the simulation after the next frame automatically */
    bool autoPauseSimulation;

    /** Processes the contact generation code. */
    virtual void generateContacts() = 0;

    /** Processes the objects in the simulation forward in time. */
    virtual void updateObjects(vakiin::real duration) = 0;

    /**
     * Finishes drawing the frame, adding debugging information
     * as needed.
     */
    void drawDebug();

    /** Resets the simulation. */
    virtual void reset() = 0;

public:
    /**
     * Creates a new application object.
     */
    RigidBodyApplication();

    /** Display the application. */
    virtual void display();

    /** Update the objects. */
    virtual void update();

    /** Handle a mouse click. */
    virtual void mouse(int button, int state, int x, int y);

    /** Handle a mouse drag */
    virtual void mouseDrag(int x, int y);

    /** Handles a key press. */
    virtual void key(unsigned char key);
 };