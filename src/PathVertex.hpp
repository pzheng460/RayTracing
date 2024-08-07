#ifndef RAYTRACING_PATHVERTEX_H
#define RAYTRACING_PATHVERTEX_H

#include "Intersection.hpp"
#include "Light.hpp"

class Intersection;

class PathVertex {
public:
    PathVertex() {}

    double pdfRev;
    double pdfFwd;
    Intersection inter;
    Vector3f alpha; // 不断跟踪 BSDF 间接照明的权重，在部分实现中也用beta表示

    using PathVertexPtr = std::shared_ptr<PathVertex>;

    friend std::ostream &operator<<(std::ostream &os, const PathVertex &v);
};


#endif //RAYTRACING_PATHVERTEX_H
