#include <regex>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <stdexcept>
#include <string>
#include "Vec3f.h"
#include "Polygon.h"
#include "Model3d.h"

namespace djf_3d {

Model3d::Model3d(const std::string& obj_filepath):
    centroid(0.0, 0.0, 0.0)
{
    std::cout << "Calling ctor djf_3d::Model3d::Model3d()."
        << std::endl;

    std::cout
        << "djf_3d::Model3d::Model3d(): Attempting to open"
        << " \""
        << obj_filepath
        << "\"...";

    std::ifstream obj_file(obj_filepath);
    if (obj_file.fail()) {
        std::cerr
            << " failed."
            << "\nError in djf_3d::Model3d::Model3d(): \""
            << obj_filepath
            << "\": no such file or directory."
            << std::endl;
        throw std::exception();
    }
    std::cout << " success." << std::endl;


    std::string file_line;
    while (std::getline(obj_file, file_line)) {
        if (file_line[0] == 'v' && file_line[1] == ' ') {
            float vertex_x, vertex_y, vertex_z;
            std::sscanf(
                file_line.c_str(),
                "v %f %f %f",
                &vertex_x,
                &vertex_y,
                &vertex_z
            );
            Vec3f vertex(
                vertex_x,
                vertex_y,
                vertex_z
            );
            vertices.push_back(vertex);
        }
    }

    obj_file.clear();
    obj_file.seekg(0);
    while (std::getline(obj_file, file_line)) {
        if (file_line[0] == 'f') {
            unsigned indx_0, indx_1, indx_2, ignore;
            std::regex opt_0(
                "f\\s+\\d+\\s+\\d+\\s+\\d+"
            );
            std::regex opt_1(
                "f\\s+\\d+\\/\\d+\\s+\\d+\\/\\d+\\s+\\d+\\/\\d+"
            );
            std::regex opt_2(
                "f\\s+\\d+\\/\\d+\\/\\d+\\/\\s+\\d+\\/\\d+\\/\\d+\\/\\s+\\d+\\/\\d+\\/\\d+"
            );
            std::regex opt_3(
                "f\\s+\\d+\\/\\/\\d+\\s+\\d+\\/\\/\\d+\\s+\\d+\\/\\/\\d+"
            );

            if (std::regex_search(file_line, opt_0)) {
                std::sscanf(
                    file_line.c_str(),
                    "f %d %d %d",
                    &indx_0,
                    &indx_1,
                    &indx_2
                );
            }

            if (std::regex_search(file_line, opt_1)) {
                std::sscanf(
                    file_line.c_str(),
                    "f %d/%d %d/%d %d/%d",
                    &indx_0, &ignore,
                    &indx_1, &ignore,
                    &indx_2, &ignore
                );
            }

            if (std::regex_search(file_line, opt_2)) {
                std::sscanf(
                    file_line.c_str(),
                    "f %d/%d/%d %d/%d/%d %d/%d/%d",
                    &indx_0, &ignore, &ignore,
                    &indx_1, &ignore, &ignore,
                    &indx_2, &ignore, &ignore
                );
            }

            if (std::regex_search(file_line, opt_3)) {
                std::sscanf(
                    file_line.c_str(),
                    "f %d//%d %d//%d %d//%d",
                    &indx_0, &ignore,
                    &indx_1, &ignore,
                    &indx_2, &ignore
                );
            }

            Polygon poly;

            if (indx_0 <= this->vertex_cnt()) {
                poly.vertices.push_back(
                    &(this->nth_vertex(indx_0 - 1))
                );
            }

            if (indx_1 <= this->vertex_cnt()) {
                poly.vertices.push_back(
                    &(this->nth_vertex(indx_1 - 1))
                );
            }

            if (indx_2 <= this->vertex_cnt()) {
                poly.vertices.push_back(
                    &(this->nth_vertex(indx_2 - 1))
                );
            }

            faces.push_back(poly);
        }
    }

    if (vertices.size() == 0) {
        std::cout
            << "djf_3d::Model3d::Model3d(): Note: no verti"
            << "ces found in \"" << obj_filepath << "\"; a"
            << "re you sure that this is a .obj file?"
            << std::endl;
    }

    float vertices_x_sum = 0.0;
    float vertices_y_sum = 0.0;
    float vertices_z_sum = 0.0;
    int num_vertices = vertices.size();
    for (auto vertex: vertices) {
        vertices_x_sum += vertex.get_pos<Axis::X>();
        vertices_y_sum += vertex.get_pos<Axis::Y>();
        vertices_z_sum += vertex.get_pos<Axis::Z>();
    }
    centroid.set_position(
        vertices_x_sum / num_vertices,
        vertices_y_sum / num_vertices,
        vertices_z_sum / num_vertices
    );

    std::cout
        << "ctor djf_3d::Model3d::Model3d() succeeded."
        << std::endl;
}

Model3d::~Model3d(void) noexcept {
    std::cout
        << "Calling dtor djf_3d::Model3d::~Model3d()."
        << std::endl;
}

const Vec3f& Model3d::nth_vertex(
    const size_t index
) const {
    if (index >= vertices.size()) {
        std::cerr
            << "djf_3d::Model3d::nth_vertex(): Index "
            << index
            << " was passed; only "
            << vertices.size()
            << " indices exist"
            << std::endl;
        throw std::invalid_argument(
            "djf_3d::Model3d::nth_vertex(): invalid index"
        );
    }

    return vertices[index];
}

const Polygon& Model3d::nth_face(
    const size_t index
) const {
    if (index >= faces.size()) {
        throw std::invalid_argument(
            "djf_3d::Model3d::nth_face(): invalid index"
        );
    }

    return faces[index];
}

template <Axis axis>
void Model3d::translate(
    const float distance
) noexcept {
    centroid.translate<axis>(distance);
    for (auto& vertex: vertices) {
        vertex.translate<axis>(distance);
    }
}

template void Model3d::translate<Axis::X>(
    const float distance
) noexcept;

template void Model3d::translate<Axis::Y>(
    const float distance
) noexcept;

template void Model3d::translate<Axis::Z>(
    const float distance
) noexcept;


template <Axis axis>
void Model3d::rotate_self(
    const float theta_degrees
) noexcept {
    for (auto& vertex: vertices) {
        vertex.rotate_3d<axis>(
            centroid,
            theta_degrees
        );
    }
}

template
void Model3d::rotate_self<Axis::X>(
    const float theta_degrees
) noexcept;

template
void Model3d::rotate_self<Axis::Y>(
    const float theta_degrees
) noexcept;

template
void Model3d::rotate_self<Axis::Z>(
    const float theta_degrees
) noexcept;


void Model3d::scale(const float amount) noexcept {
    for (auto& vertex: vertices) {
        float new_x = vertex.get_pos<Axis::X>() * amount;
        float new_y = vertex.get_pos<Axis::Y>() * amount;
        float new_z = vertex.get_pos<Axis::Z>() * amount;
        vertex.set_position(new_x, new_y, new_z);
    }

    float new_centroid_x
        = centroid.get_pos<Axis::X>() * amount;
    float new_centroid_y
        = centroid.get_pos<Axis::Y>() * amount;
    float new_centroid_z
        = centroid.get_pos<Axis::Z>() * amount;
    centroid.set_position(
        new_centroid_x,
        new_centroid_y,
        new_centroid_z
    );
}

size_t Model3d::vertex_cnt(void) const noexcept {
    return vertices.size();
}

size_t Model3d::face_cnt(void) const noexcept {
    return faces.size();
}

} // end of namespace djf_3d