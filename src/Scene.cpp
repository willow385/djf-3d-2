#include <iostream>
#include <stdexcept>
#include <vector>
#include <memory>
#include "Model3d.h"
#include "CoordPair.h"
#include "CoordTriple.h"
#include "Scene.h"

namespace djf_3d {

Scene::Scene(void) noexcept {
    std::cout << "Calling ctor djf_3d::Scene::Scene()."
        << std::endl;
}

Scene::~Scene(void) noexcept {
    std::cout << "Calling dtor djf_3d::Scene::~Scene()."
        << std::endl;
}

void Scene::add(Model3d& model) noexcept {
    models.emplace_back(model);
}

void Scene::add(CoordPair& point) noexcept {
    points_2d.emplace_back(point);
}

void Scene::add(CoordTriple& point) noexcept {
    points_3d.emplace_back(point);
}

template<>
Model3d& Scene::nth_mutable<Model3d>(const size_t index) {
    if (index >= models.size()) {
        throw std::invalid_argument(
            "djf_3d::Scene::nth_mutable<Model3d>(): invalid index"
        );
    }

    return models[index];
}

template<>
CoordTriple& Scene::nth_mutable<CoordTriple>(
    const size_t index
) {
    if (index >= points_3d.size()) {
        throw std::invalid_argument(
            "djf_3d::Scene::nth_mutable<CoordTriple>(): invalid index"
        );
    }

    return points_3d[index];
}

template<>
CoordPair& Scene::nth_mutable<CoordPair>(
    const size_t index
) {
    if (index >= points_2d.size()) {
        throw std::invalid_argument(
            "djf_3d::Scene::nth_mutable<CoordPair>(): invalid index"
        );
    }

    return points_2d[index];
}

template<>
const Model3d& Scene::nth_const<Model3d>(
    const size_t index
) const {
    if (index >= models.size()) {
        throw std::invalid_argument(
            "djf_3d::Scene::nth_const<Model3d>(): invalid index"
        );
    }

    return models[index];
}

template<>
const CoordTriple& Scene::nth_const<CoordTriple>(
    const size_t index
) const {
    if (index >= points_3d.size()) {
        throw std::invalid_argument(
            "djf_3d::Scene::nth_const<CoordTriple>(): invalid index"
        );
    }

    return points_3d[index];
}

template<>
const CoordPair& Scene::nth_const<CoordPair>(
    const size_t index
) const {
    if (index >= points_2d.size()) {
        throw std::invalid_argument(
            "djf_3d::Scene::nth_const<CoordPair>(): invalid index"
        );
    }

    return points_2d[index];
}

size_t Scene::model_cnt(void) const noexcept {
    return models.size();
}

size_t Scene::point_2d_cnt(void) const noexcept {
    return points_2d.size();
}

size_t Scene::point_3d_cnt(void) const noexcept {
    return points_3d.size();
}

} // end of namespace djf_3d