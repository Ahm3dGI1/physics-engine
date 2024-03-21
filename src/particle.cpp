#include <assert.h>
#include "vakiin\particle.h"

using namespace vakiin;

void particle::integerate(real duration) {
	assert(duration > 0.0);
	
	// Update linear position
	position.addScaledVector(velocity, duration);

	// Get Acceleration from force
	vec3d resultingAcc = acceleration;

	resultingAcc.addScaledVector(forceAccum, inverseMass);

	// Update the velocity
	velocity.addScaledVector(resultingAcc, duration);

	// Apply drag
	velocity *= real_pow(damping, duration);
}

void particle::setMass(const real mass) {
    assert(mass != 0);
    particle::inverseMass = ((real)1.0) / mass;
}

void particle::setInverseMass(const real inverseMass) {
    particle::inverseMass = inverseMass;
}

real particle::getInverseMass() const {
    return inverseMass;
}

real particle::getMass() const {
	if (inverseMass == 0) {
		return REAL_MAX;
	} else {
		return ((real)1.0) / inverseMass;
	}
}

bool particle::hasFiniteMass() const {
	return inverseMass >= 0.0f;
}

void particle::setDamping(const real damping) {
	particle::damping = damping;
}

real particle::getDamping() const {
	return damping;
}

void particle::setPosition(const vec3d &position) {
	particle::velocity = velocity;
}

void particle::setPosition(const real x, const real y, const real z) {
	particle::position.x = x;
	particle::position.y = y;
	particle::position.z = z;
}

void particle::getPosition(vec3d *position) const {
	*position = particle::position;
}

vec3d particle::getPosition() const {
	return particle::position;
}

void particle::setVelocity(const vec3d &velocity) {
	particle::velocity = velocity;
}

void particle::setVelocity(const real x, const real y, const real z) {
	particle::velocity.x = x;
	particle::velocity.y = y;
	particle::velocity.z = z;
}

void particle::getVelocity(vec3d *velocity) const {
	*velocity = particle::velocity;
}

vec3d particle::getVelocity() const {
	return particle::velocity;
}

void particle::setAcceleration(const vec3d &acceleration) {
	particle::acceleration = acceleration;
}

void particle::setAcceleration(const real x, const real y, const real z) {
	particle::acceleration.x = x;
	particle::acceleration.y = y;
	particle::acceleration.z = z;
}

void particle::getAcceleration(vec3d *acceleration) const {
	*acceleration = particle::acceleration;
}

vec3d particle::getAcceleration() const {
	return particle::acceleration;
}