// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2014 Daniele Panozzo <daniele.panozzo@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#include "align_camera_center.h"

#include "../barycenter.h"

namespace igl
{
namespace opengl
{

IGL_INLINE void align_camera_center(
  const Eigen::MatrixXd& V,
  float& zoom,
  Eigen::Vector3f& shift,
  float& object_scale
  )
{
  if (V.rows() == 0)
    return;

  auto min_point = V.colwise().minCoeff();
  auto max_point = V.colwise().maxCoeff();
  auto centroid  = (0.5*(min_point + max_point)).eval();
  shift.setConstant(0);
  shift.head(centroid.size()) = -centroid.cast<float>();
  zoom = 2.0 / (max_point-min_point).array().abs().maxCoeff();

  if(V.size() > 0)
  {
    object_scale = (V.colwise().maxCoeff() - V.colwise().minCoeff()).norm();
  }
}

IGL_INLINE void align_camera_center(
  const Eigen::MatrixXd& V,
  const Eigen::MatrixXi& F,
  float& zoom,
  Eigen::Vector3f& shift,
  float& object_scale
  )
{
  Eigen::MatrixXd BC;
  if (F.rows() <= 1)
  {
    BC = V;
  } else
  {
    igl::barycenter(V,F,BC);
  }

  align_camera_center(BC, zoom, shift, object_scale);
}

}
}