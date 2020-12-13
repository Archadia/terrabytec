#ifndef TERRABYTE_MATH_DEF
namespace pkr
{
    struct VEC2F
    {
        float x;
        float y;

        VEC2F operator+(const VEC2F& v)
        {
            VEC2F vec;
            vec.x = x + v.x;
            vec.y = y + v.y;
            return vec;
        }

        VEC2F operator-(const VEC2F& v)
        {
            VEC2F vec;
            vec.x = x - v.x;
            vec.y = y - v.y;
            return vec;
        }

        VEC2F operator*(const VEC2F& v)
        {
            VEC2F vec;
            vec.x = x * v.x;
            vec.y = y * v.y;
            return vec;
        }

        VEC2F operator/(const VEC2F& v)
        {
            VEC2F vec;
            vec.x = x / v.x;
            vec.y = y / v.y;
            return vec;
        }
    };

    struct VEC2I
    {
        int32_t x;
        int32_t y;

        VEC2I operator+(const VEC2I& v)
        {
            VEC2I vec;
            vec.x = x + v.x;
            vec.y = y + v.y;
            return vec;
        }

        VEC2I operator-(const VEC2I& v)
        {
            VEC2I vec;
            vec.x = x - v.x;
            vec.y = y - v.y;
            return vec;
        }

        VEC2I operator*(const VEC2I& v)
        {
            VEC2I vec;
            vec.x = x * v.x;
            vec.y = y * v.y;
            return vec;
        }

        VEC2I operator/(const VEC2I& v)
        {
            VEC2I vec;
            vec.x = x / v.x;
            vec.y = y / v.y;
            return vec;
        }
    };

    struct VEC2D
    {
        double x;
        double y;

        VEC2D operator+(const VEC2D& v)
        {
            VEC2D vec;
            vec.x = x + v.x;
            vec.y = y + v.y;
            return vec;
        }

        VEC2D operator-(const VEC2D& v)
        {
            VEC2D vec;
            vec.x = x - v.x;
            vec.y = y - v.y;
            return vec;
        }

        VEC2D operator*(const VEC2D& v)
        {
            VEC2D vec;
            vec.x = x * v.x;
            vec.y = y * v.y;
            return vec;
        }

        VEC2D operator/(const VEC2D& v)
        {
            VEC2D vec;
            vec.x = x / v.x;
            vec.y = y / v.y;
            return vec;
        }
    };
}
#define TERRABYTE_MATH_DEF
#endif