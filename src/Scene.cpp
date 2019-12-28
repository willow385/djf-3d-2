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

Model3d& Scene::nth_model(const size_t index) {
    if (index >= models.size()) {
        throw std::invalid_argument(
            "djf_3d::Scene::nth_model(): invalid index"
        );
    }

    return models[index];
}

CoordTriple& Scene::nth_point_3d(const size_t index) {
    if (index >= points_3d.size()) {
        throw std::invalid_argument(
            "djf_3d::Scene::nth_point_3d(): invalid index"
        );
    }

    return points_3d[index];
}

CoordPair& Scene::nth_point_2d(const size_t index) {
    if (index >= points_2d.size()) {
        throw std::invalid_argument(
            "djf_3d::Scene::nth_point_2d(): invalid index"
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