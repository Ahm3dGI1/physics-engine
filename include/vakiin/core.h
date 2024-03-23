#include "precision.h"

namespace vakiin{
    class vec3d{
        public:
            // The x, y, and z components of the vector
            real x;
            real y;
            real z;
        private:
            // Padding to ensure 4 word alignment purely for performance reasons
            real pad;
        
        public:
            // Default constructor creates a zero vector
            vec3d(): x(0), y(0), z(0) {}

            // Constructor creates a vector with the given components
            vec3d(const real x, const real y, const real z): x(x), y(y), z(z) {}

            // Flips the vector
            void invert(){
                x = -x;
                y = -y;
                z = -z;
            }

            // Find the magnitude of the vector
            real magnitude() const{
                return real_sqrt(x*x+y*y+z*z);
            }

            // Find the squared magnitude of the vector (useful for avoiding the square root)
            real squareMagnitude() const{
                return x*x+y*y+z*z;
            }

            // Turns a non-zero vector into a vector of unit length
            void normalize(){
                real l = magnitude();
                if(l > 0){
                    (*this) *= ((real)1)/l;
                }
            }

            // Overload the * operator to multiply by scalars
            void operator*= (const real value){
                x *= value;
                y *= value;
                z *= value;
            }

            // Returns a copy of the current vector scaled by the given value
            vec3d operator*(const real value) const{
                return vec3d(x*value, y*value, z*value);
            }

            // Add a vector to this vector
            void operator+=(const vec3d& v){
                x += v.x;
                y += v.y;
                z += v.z;
            }

            // Returns the value of the given vector added to this
            vec3d operator+(const vec3d& v) const{
                return vec3d(x+v.x, y+v.y, z+v.z);
            }

            // Subtract a vector from this vector
            void operator-=(const vec3d& v){
                x -= v.x;
                y -= v.y;
                z -= v.z;
            }

            // Returns the value of the given vector subtracted from this
            vec3d operator-(const vec3d& v) const{
                return vec3d(x-v.x, y-v.y, z-v.z);
            }

            // Add a scaled vector to this vector
            void addScaledVector(const vec3d& vector, real scale){
                x += vector.x * scale;
                y += vector.y * scale;
                z += vector.z * scale;
            }

            // Returns the component product of this vector and the given vector
            vec3d componentProduct(const vec3d& vector) const{
                return vec3d(x*vector.x, y*vector.y, z*vector.z);
            }

            // Updates this vector to be the component product of itself and the given vector
            void componentProductUpdate(const vec3d& vector){
                x *= vector.x;
                y *= vector.y;
                z *= vector.z;
            }

            // Returns the scalar product of this vector and the given vector
            real scalarProduct(const vec3d& vector) const{
                return x*vector.x + y*vector.y + z*vector.z;
            }

            // Returns the vector product of this vector and the given vector
            real operator *(const vec3d& vector) const{
                return x*vector.x + y*vector.y + z*vector.z;
            }

            // Returns the vector product of this vector and the given vector
            vec3d vectorProduct(const vec3d& vector) const{
                return vec3d(y*vector.z - z*vector.y, z*vector.x - x*vector.z, x*vector.y - y*vector.x);
            }

            // Updates this vector to be the vector product of itself and the given vector
            void operator %=(const vec3d& vector){
                *this = vectorProduct(vector);
            }

            // Returns the vector product of this vector and the given vector
            vec3d operator%(const vec3d& vector) const{
                return vec3d(y*vector.z - z*vector.y, z*vector.x - x*vector.z, x*vector.y - y*vector.x);
            }
    };
}