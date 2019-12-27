#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <stdexcept>
#include <string>

#ifndef COORDTRIPLE_H
#define COORDTRIPLE_H
#include "CoordTriple.h"
#endif

#include "Model3d.h"

namespace djf_3d {

Model3d::Model3d(const std::string& obj_filepath):
    centroid(0.0, 0.0, 0.0)
{
    std::cout << "Calling ctor djf_3d::Model3d::Model3d()."
        << std::endl;

    std::cout
        << "djf_3d::Model3d::Model3d(): Attempting to open \""
        << obj_filepath
        << "\"...";

    // We attempt to open the file...
    std::ifstream obj_file(obj_filepath);
    // ...and complain and throw an exception if we can't.
    if (obj_file.fail()) {
        std::cerr
            << " failed."
            << "\nError in djf_3d::Model3d::Model3d(): \""
            << obj_filepath
            << "\": no such file or directory."
            << std::endl;
        throw std::exception();
    }
    // If we successfully open the file then let's say so
    std::cout << " success." << std::endl;


    // Next we read the file (which should be a .obj file).
    std::string file_line;
    while (std::getline(obj_file, file_line)) {
        if (file_line[0] == 'v' && file_line[1] == ' ') {
            float vertex_x, vertex_y, vertex_z;
            /* I tried to do this with regexes and string
               streams, but that's really complicated, and I
               wanted to use a simpler solution. */
            std::sscanf(
                file_line.c_str(),
                "v %f %f %f",
                &vertex_x,
                &vertex_y,
                &vertex_z
            );
            CoordTriple vertex(vertex_x, vertex_y, vertex_z);
            vertices.push_back(vertex);
        }
    }

    // Lastly we calculate where the centroid should be.
    float vertices_x_sum = 0.0;
    float vertices_y_sum = 0.0;
    float vertices_z_sum = 0.0;
    int num_vertices = vertices.size();
    for (auto vertex: vertices) {
        vertices_x_sum += vertex.get_pos(Axis::X);
        vertices_y_sum += vertex.get_pos(Axis::Y);
        vertices_z_sum += vertex.get_pos(Axis::Z);
    }
    centroid.teleport(
        vertices_x_sum / num_vertices,
        vertices_y_sum / num_vertices,
        vertices_z_sum / num_vertices
    );

    std::cout << "ctor djf_3d::Model3d::Model3d() succeeded."
        << std::endl;
}

Model3d::~Model3d(void) noexcept {
    std::cout << "Calling dtor djf_3d::Model3d::~Model3d."
        << std::endl;
}

const CoordTriple& Model3d::nth_vertex(
    const unsigned int index
) const {
    if (index >= vertices.size()) {
        throw std::invalid_argument(
            "djf_3d::Model3d::nth_vertex(): error: index out of bounds"
        );
    }

    return vertices[index];
}

void Model3d::translate(
    const Axis axis,
    const float distance
) noexcept {
    centroid.translate(axis, distance);
    for (auto& vertex: vertices) {
        vertex.translate(axis, distance);
    }
}

void Model3d::rotate_self(
    const Axis axis,
    const float theta_degrees
) noexcept {
    for (auto& vertex: vertices) {
        vertex.rotate_3d(
            axis,
            centroid,
            theta_degrees
        );
    }
}

void Model3d::scale(const float amount) noexcept {
    for (auto& vertex: vertices) {
        float new_x = vertex.get_pos(Axis::X) * amount;
        float new_y = vertex.get_pos(Axis::Y) * amount;
        float new_z = vertex.get_pos(Axis::Z) * amount;
        vertex.teleport(new_x, new_y, new_z);
    }

    float new_centroid_x = centroid.get_pos(Axis::X) * amount;
    float new_centroid_y = centroid.get_pos(Axis::Y) * amount;
    float new_centroid_z = centroid.get_pos(Axis::Z) * amount;
    centroid.teleport(
        new_centroid_x,
        new_centroid_y,
        new_centroid_z
    );
}

unsigned int Model3d::vertex_cnt(void) const noexcept {
    return vertices.size();
}

} // end of namespace djf_3d
