#include "vakiin\core.h"

namespace vakiin{
    class particle{

        protected:
            // Linear position of the particle in the world
            vec3d position;
            // Linear velocity of the particle
            vec3d velocity;
            // Acceleration of the particle
            vec3d acceleration;

            // Damping is required to remove energy added through numerical instability in the integrator
            real damping; // 1.0 = no damping, 0.0 = full damping

            // Holds the inverse of the mass of the particle. It is more useful in simulating things like immovable objects
            real inverseMass;

            // Holds the accumulated force to be applied at the next iteration
            vec3d forceAccum;

        public:
            void integerate(real duration);
            
            // Setters and getters
            void setMass(const real mass);

            void setInverseMass(const real inverseMass);

            real getInverseMass() const;

            real getMass() const;

            bool hasFiniteMass() const;

            void setDamping(const real damping);

            real getDamping() const;

            void setPosition(const vec3d &position);
            
            void setPosition(const real x, const real y, const real z);

            void getPosition(vec3d *position) const;

            vec3d getPosition() const;

            void setVelocity(const vec3d &velocity);

            void setVelocity(const real x, const real y, const real z);

            void getVelocity(vec3d *velocity) const;

            vec3d getVelocity() const;

            void setAcceleration(const vec3d &acceleration);

            void setAcceleration(const real x, const real y, const real z);

            void getAcceleration(vec3d *acceleration) const;

            vec3d getAcceleration() const;

    };
}