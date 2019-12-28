#include <vector>
#include <memory>
#include "Model3d.h"
#include "CoordPair.h"
#include "CoordTriple.h"

#ifndef SCENE_H
#define SCENE_H

namespace djf_3d {

class Scene {
private:
    std::vector<std::reference_wrapper<Model3d>> models;
    std::vector<std::reference_wrapper<CoordPair>> points_2d;
    std::vector<std::reference_wrapper<CoordTriple>> points_3d;

public:
    /**
     * Constructor for the Scene class.
     */
    Scene(void) noexcept;

    /**
     * Destructor for the Scene class.
     */
    ~Scene(void) noexcept;

    /**
     * Method to add 3d models to the Scene.
     *
     * @param model the Model3d to add
     */
    void add(Model3d& model) noexcept;

    /**
     * Method to add 2d points to the Scene.
     *
     * @param point the CoordPair to add
     */
    void add(CoordPair& point) noexcept;

    /**
     * Method to add 3d points to the Scene.
     *
     * @param point the CoordTriple to add
     */
    void add(CoordTriple& point) noexcept;

    /**
     * Method to get the nth Model3d from the
     * Scene.
     *
     * @param index the index of the desired Model3d
     * @return reference to that Model3d
     */
    Model3d& nth_model(const size_t index);

    /**
     * Method to get the nth CoordTriple from the Scene.
     *
     * @param index the index of the desired CoordTriple
     * @return reference to that CoordTriple
     */
    CoordTriple& nth_point_3d(const size_t index);

    /**
     * Method to get the nth CoordPair from the Scene.
     *
     * @param index the index of the desired CoordPair
     * @return reference to that CoordPair
     */
    CoordPair& nth_point_2d(const size_t index);

    /**
     * Method to get the number of 3d models in the Scene.
     *
     * @return number of Model3ds
     */
    size_t model_cnt(void) const noexcept;

    /**
     * Method to get the number of 2d points in the Scene.
     *
     * @return number of CoordPairs
     */
    size_t point_2d_cnt(void) const noexcept;

    /**
     * Method to get the number of 3d points (that are not
     * part of a model) in the Scene.
     *
     * @return number of CoordTriples
     */
    size_t point_3d_cnt(void) const noexcept;

};

} // end of namespace djf_3d

#endif // SCENE_H