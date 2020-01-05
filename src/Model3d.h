#include <vector>
#include <string>
#include "Vec3f.h"
#include "Polygon.h"

#ifndef MODEL3D_H
#define MODEL3D_H

namespace djf_3d {

class Model3d {

private:
    std::vector<Vec3f> vertices;
    std::vector<Polygon> faces;
    Vec3f centroid;

public:
    /**
     * Ctor for a Model3d. Attempts to parse a .obj file;
     * throws an exception if it can't find the file.
     *
     * @param obj_filepath path to a .obj file
     */
    Model3d(const std::string& obj_filepath);

    /**
     * Dtor for Model3d.
     */
    ~Model3d(void) noexcept;

    /**
     * This method returns a const reference to a specific
     * vertex, throwing an exception if the index passed is
     * out of range.
     *
     * @param index the index of the vertex you want
     * @return const reference to that vertex
     */
    const Vec3f& nth_vertex(
        const size_t index
    ) const;

    /**
     * This method returns a const reference to a specific
     * face, throwing an exception if the index passed is
     * out of range.
     *
     * @param index the index of the face you want
     * @return const reference to that face
     */
    const Polygon& nth_face(
        const size_t index
    ) const;

    /**
     * This method moves a Model3d in space.
     *
     * @param axis the Axis along which to move
     * @param distance the number of pixels to move
     */
    void translate(
        const Axis axis,
        const float distance
    ) noexcept;

    /**
     * This method rotates the Model3d about its own
     * centroid.
     *
     * @param axis the djf_3d::Axis about which to rotate
     * @param theta_degrees number of degrees to rotate
     */
    void rotate_self(
        const Axis axis,
        const float theta_degrees
    ) noexcept;

    /**
     * This method resizes the Model3d.
     *
     * @param amount factor by which to scale the Model3d
     */
    void scale(const float amount) noexcept;

    /**
     * This method is for finding out the number of
     * vertices.
     *
     * @return number of vertices
     */
    size_t vertex_cnt(void) const noexcept;

    /**
     * This method is for finding out the number of
     * faces.
     *
     * @return number of faces
     */
    size_t face_cnt(void) const noexcept;
};

} // end of namespace djf_3d

#endif // MODEL3D_H