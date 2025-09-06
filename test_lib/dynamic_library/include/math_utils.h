#pragma once

#ifdef MATHUTILS_EXPORTS
#define MATHUTILS_API __declspec(dllexport)
#else
#define MATHUTILS_API __declspec(dllimport)
#endif

namespace MathUtils {
    MATHUTILS_API int add(int a, int b);
    MATHUTILS_API int multiply(int a, int b);
}
