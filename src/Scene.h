#include <vector>
#include <memory>
#include "Model3d.h"
#include "Vec2f.h"
#include "Vec3f.h"

#ifndef SCENE_H
#define SCENE_H

namespace djf_3d {

class Scene {
private:
    std::vector<std::reference_wrapper<Model3d>>
        models;

    std::vector<std::reference_wrapper<Vec2f>>
        points_2d;

    std::vector<std::reference_wrapper<Vec3f>>
        points_3d;

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
     * @param point the Vec2f to add
     */
    void add(Vec2f& point) noexcept;

    /**
     * Method to add 3d points to the Scene.
     *
     * @param point the Vec3f to add
     */
    void add(Vec3f& point) noexcept;

    /**
     * The specializations of this method return a mutable
     * reference to one of the Scene's members.
     *
     * @param T either Model3d, Vec2f, or Vec3f,
     * depending on which you want
     * @param index the index of that object
     * @return mutable reference to the desired object
     */
    template <class T>
    T& nth_mutable(const size_t index);

    /**
     * The specializations of this method return a const
     * reference to one of the Scene's members.
     *
     * @param T either Model3d, Vec2f, or Vec3f,
     * depending on which you want
     * @param index the index of that object
     * @return const reference to the desired object
     */
    template <class T>
    const T& nth_const(const size_t index) const;


    /**
     * Method to get the number of 3d models in the Scene.
     *
     * @return number of Model3ds
     */
    size_t model_cnt(void) const noexcept;

    /**
     * Method to get the number of 2d points in the Scene.
     *
     * @return number of Vec2fs
     */
    size_t point_2d_cnt(void) const noexcept;

    /**
     * Method to get the number of 3d points (that are not
     * part of a model) in the Scene.
     *
     * @return number of Vec3fs
     */
    size_t point_3d_cnt(void) const noexcept;

};

} // end of namespace djf_3d

#endif // SCENE_H