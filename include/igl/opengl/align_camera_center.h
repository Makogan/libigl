// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2014 Daniele Panozzo <daniele.panozzo@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
#ifndef IGL_OPENGL_ALIGN_CAMERA_CENTER_H
#define IGL_OPENGL_ALIGN_CAMERA_CENTER_H

#include <igl/igl_inline.h>
#include <Eigen/Geometry>
#include <Eigen/Core>

namespace igl
{
namespace opengl
{

// Adjust the view to see the entire model by fiting the model
// to the boundaries of the viewport
//
// Inputs:
//   V  #V by dim list of vertex positions
// Outputs:
//   zoom  zoom level to focus an object
//   shift  position opposite to the centroid of the set V
//   object_scale length of the diagonal of the AABB
IGL_INLINE void align_camera_center(
  const Eigen::MatrixXd& V,
  float& zoom,
  Eigen::Vector3f& shift,
  float& object_scale);

// Adjust the view to see the entire model by fiting the model
// to the boundaries of the viewport
//
// Inputs:
//   V  #V by dim list of vertex positions
//   F  #F by #simplex size list of triangle indices into V
// Outputs:
//   zoom  zoom level to focus an object
//   shift  position opposite to the centroid of the set V
//   object_scale length of the diagonal of the AABB
IGL_INLINE void align_camera_center(
  const Eigen::MatrixXd& V,
  const Eigen::MatrixXi& F,
  float& zoom,
  Eigen::Vector3f& shift,
  float& object_scale);

}
}
#endif