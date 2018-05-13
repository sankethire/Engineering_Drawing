#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

inline float degToRad(float angle) { return 3.141593f * angle / 180.f; }

struct Vec2 {
  float x, y;
  Vec2(float x, float y): x(x), y(y) { }
};

ostream& operator<<(ostream &out, const Vec2 &v)
{
  return out << "( " << v.x << ", " << v.y << " )";
}

struct Vec3 {
  float x, y, z;
  Vec3(float x, float y, float z): x(x), y(y), z(z) { }
  Vec3(const Vec2 &xy, float z): x(xy.x), y(xy.y), z(z) { }
};

ostream& operator<<(ostream &out, const Vec3 &v)
{
  return out << "( " << v.x << ", " << v.y << ", " << v.z << " )";
}

enum ArgInitRotX { InitRotX };
enum ArgInitRotY { InitRotY };

struct Mat3x3 {
  float _00, _01, _02, _10, _11, _12, _20, _21, _22;

  // constructor to build a matrix by elements
  Mat3x3(
    float _00, float _01, float _02,
    float _10, float _11, float _12,
    float _20, float _21, float _22)
  {
    this->_00 = _00; this->_01 = _01; this->_02 = _02;
    this->_10 = _10; this->_11 = _11; this->_12 = _12;
    this->_20 = _20; this->_21 = _21; this->_22 = _22;
  }
  // constructor to build a matrix for rotation about x axis
  Mat3x3(ArgInitRotX, float angle)
  {
    this->_00 = 1.0f; this->_01 = 0.0f;        this->_02 = 0.0f;
    this->_10 = 0.0f; this->_11 = cos(angle);  this->_12 = sin(angle);
    this->_20 = 0.0f; this->_21 = -sin(angle); this->_22 = cos(angle);
  }
  // constructor to build a matrix for rotation about y axis
  Mat3x3(ArgInitRotY, float angle)
  {
    this->_00 = cos(angle); this->_01 = 0.0f; this->_02 = -sin(angle);
    this->_10 = 0.0f;       this->_11 = 1.0f; this->_12 = 0.0f;
    this->_20 = sin(angle); this->_21 = 0.0f; this->_22 = cos(angle);
  }
  // multiply matrix with matrix -> matrix
  Mat3x3 operator * (const Mat3x3 &mat) const
  {
    return Mat3x3(
      _00 * mat._00 + _01 * mat._10 + _02 * mat._20,
      _00 * mat._01 + _01 * mat._11 + _02 * mat._21,
      _00 * mat._02 + _01 * mat._12 + _02 * mat._22,
      _10 * mat._00 + _11 * mat._10 + _12 * mat._20,
      _10 * mat._01 + _11 * mat._11 + _12 * mat._21,
      _10 * mat._02 + _11 * mat._12 + _12 * mat._22,
      _20 * mat._00 + _21 * mat._10 + _22 * mat._20,
      _20 * mat._01 + _21 * mat._11 + _22 * mat._21,
      _20 * mat._02 + _21 * mat._12 + _22 * mat._22);
  }
  // multiply matrix with vector -> vector
  Vec3 operator * (const Vec3 &vec) const
  {
    return Vec3(
      _00 * vec.x + _01 * vec.y + _02 * vec.z,
      _10 * vec.x + _11 * vec.y + _12 * vec.z,
      _20 * vec.x + _21 * vec.y + _22 * vec.z);
  }
};

ostream& operator<<(ostream &out, const Mat3x3 &mat)
{
  return out
    << mat._20 << ", " << mat._21 << ", " << mat._22 << endl
    << mat._10 << ", " << mat._11 << ", " << mat._12 << endl
    << mat._20 << ", " << mat._21 << ", " << mat._22;
}

int main()
{
  // some 2D vector samples (for a quad)
  Vec2 quad[] = {
    { 0.0f, 0.0f }, { 0.0f, 1.0f }, { 1.0f, 1.0f }, { 1.0f, 0.0f }
  };
  /* Something like this:
   * ^ y
   * |
   * v[3] ---- v[2]
   * |         |
   * |         |
   * |         |
   * v[0] ---- v[1] --> x
   */
  // the rotation matrix for isometric view build by multiplying the rotations
  Mat3x3 matIso = Mat3x3(InitRotX, degToRad(30.0)) * Mat3x3(InitRotY, degToRad(45.0));
  // prepare output formatting
  cout << fixed << setprecision(5);
  // the rotation matrix for isometric view:
  cout << "The matrix for isometric projection:" << endl
    << matIso << endl;
  // prepare output formatting
  cout << fixed << setprecision(3);
  // do it for all sample 2D vectors:
  cout << "Isometric projection of the 2d quad:" << endl;
  for (const Vec2 &v : quad) {
    // 2D vector -> 3D vector
    Vec3 v_(v, 0.0f);
    // project v_ to iso view
    v_ = matIso * v_;
    // print the result:
    cout << v << " -> " << v_ << endl;
  }
  // doing it again with a 3d cube (centered)
  Vec3 cube[] = {
    { -0.5f, -0.5f, -0.5f }, { +0.5f, -0.5f, -0.5f }, { +0.5f, +0.5f, -0.5f }, { -0.5f, +0.5f, -0.5f },
    { -0.5f, -0.5f, +0.5f }, { +0.5f, -0.5f, +0.5f }, { +0.5f, +0.5f, +0.5f }, { -0.5f, +0.5f, +0.5f }
  };
  cout << "Isometric projection of the centered 3d cube:" << endl;
  for (const Vec3 &v : cube) {
    // project v to iso view
    Vec3 v_ = matIso * v;
    // print the result:
    cout << v << " -> " << v_ << endl;
  }
  // done
  return 0;
}