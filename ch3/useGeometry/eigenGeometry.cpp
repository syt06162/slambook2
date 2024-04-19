// yejoon _USE_MATH_DEFINES: use M_PI
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

using namespace std;

#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace Eigen;

// This program demonstrates the usage of Eigen's geometry module.

int main(int argc, char** argv) {

    // Eigen/Geometry module provides various representations for rotation and translation.
    // 3D rotation matrices are directly represented using Matrix3d or Matrix3f.
    Matrix3d rotation_matrix = Matrix3d::Identity();
    // Rotation vectors use AngleAxis. Although it's not directly a Matrix, operations can be performed as if it were (because operators are overloaded).
    AngleAxisd rotation_vector(M_PI / 4, Vector3d(0, 0, 1));     // Rotates 45 degrees about the Z-axis.
    cout.precision(3);
    cout << "rotation matrix =\n" << rotation_vector.matrix() << endl;   // Converted to a matrix using matrix()
    // Alternatively, it can be assigned directly.
    rotation_matrix = rotation_vector.toRotationMatrix();
    // Coordinate transformation can be done using AngleAxis.
    Vector3d v(1, 0, 0);
    Vector3d v_rotated = rotation_vector * v;
    cout << "(1,0,0) after rotation (by angle axis) = " << v_rotated.transpose() << endl;
    // Or using rotation matrices.
    v_rotated = rotation_matrix * v;
    cout << "(1,0,0) after rotation (by matrix) = " << v_rotated.transpose() << endl;

    // Euler angles: Rotation matrices can be directly converted into Euler angles.
    Vector3d euler_angles = rotation_matrix.eulerAngles(2, 1, 0); // ZYX order, i.e., yaw-pitch-roll order.
    cout << "yaw pitch roll = " << euler_angles.transpose() << endl;

    // Euclidean transformation matrices use Eigen::Isometry.
    Isometry3d T = Isometry3d::Identity();                // Although named 3d, it's essentially a 4*4 matrix.
    T.rotate(rotation_vector);                                     // Rotate according to rotation_vector.
    T.pretranslate(Vector3d(1, 3, 4));                     // Set translation vector to (1,3,4).
    cout << "Transform matrix = \n" << T.matrix() << endl;

    // Coordinate transformation using transformation matrices.
    Vector3d v_transformed = T * v;                              // Equivalent to R*v+t
    cout << "v transformed = " << v_transformed.transpose() << endl;

    // For affine and projective transformations, use Eigen::Affine3d and Eigen::Projective3d respectively. Skipped for now.

    // Quaternions
    // AngleAxis can be directly assigned to quaternions, and vice versa.
    Quaterniond q = Quaterniond(rotation_vector);
    cout << "quaternion from rotation vector = " << q.coeffs().transpose()
        << endl;   // Note that the order of coeffs is (x, y, z, w), where w is the real part and the first three are the imaginary parts.
    // It can also be assigned with a rotation matrix.
    q = Quaterniond(rotation_matrix);
    cout << "quaternion from rotation matrix = " << q.coeffs().transpose() << endl;
    // Rotating a vector using a quaternion, using overloaded multiplication.
    v_rotated = q * v; // Note mathematically it's qvq^{-1}.
    cout << "(1,0,0) after rotation = " << v_rotated.transpose() << endl;
    // Using regular vector multiplication, it should be calculated as follows
    cout << "should be equal to " << (q * Quaterniond(0, 1, 0, 0) * q.inverse()).coeffs().transpose() << endl;

    return 0;
}
