#ifndef VECTOR
#define VECTOR
#include <vector>
#endif

#ifndef MEMORY
#define MEMORY
#include <memory>
#endif

#ifndef COORDTRIPLE_HPP
#define COORDTRIPLE_HPP
#include "CoordTriple.hpp"
#endif

namespace djf_3d {

class Model3d {
private:
    std::vector<CoordTriple> vertices;
    CoordTriple centroid;

public:
    /**
     * Ctor for a Model3d. Attempts to parse a .obj file; throws
     * an exception if it can't find the file.
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
     * vertex, throwing an exception if the index passed is out
     * of range.
     *
     * @param index the index of the vertex you want
     * @return const reference to that vertex
     */
    const CoordTriple& nth_vertex(
        const unsigned int index
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
     * This method rotates the Model3d about its own centroid.
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
     * This method finds out how many vertices there are.
     *
     * @return number of vertices
     */
    unsigned int vertex_cnt(void) const noexcept;
};

} // end of namespace djf_3d
