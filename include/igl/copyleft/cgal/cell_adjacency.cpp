// This file is part of libigl, a simple c++ geometry processing library.
// 
// Copyright (C) 2016 Qingnan Zhou <qnzhou@gmail.com>
// 
// This Source Code Form is subject to the terms of the Mozilla Public License 
// v. 2.0. If a copy of the MPL was not distributed with this file, You can 
// obtain one at http://mozilla.org/MPL/2.0/.
//

#include "cell_adjacency.h"

template <typename DerivedC>
IGL_INLINE void igl::copyleft::cgal::cell_adjacency(
    const Eigen::PlainObjectBase<DerivedC>& per_patch_cells,
    const size_t num_cells,
    std::vector<std::set<std::tuple<typename DerivedC::Scalar, bool, size_t> > >&
    adjacency_list) {

  const size_t num_patches = per_patch_cells.rows();
  adjacency_list.resize(num_cells);
  for (size_t i=0; i<num_patches; i++) {
    const int positive_cell = per_patch_cells(i,0);
    const int negative_cell = per_patch_cells(i,1);
    adjacency_list[positive_cell].emplace(negative_cell, false, i);
    adjacency_list[negative_cell].emplace(positive_cell, true, i);
  }
}

#ifdef IGL_STATIC_LIBRARY
template void igl::copyleft::cgal::cell_adjacency<Eigen::Matrix<int, -1, -1, 0, -1, -1> >(Eigen::PlainObjectBase<Eigen::Matrix<int, -1, -1, 0, -1, -1> > const&, unsigned long, std::__1::vector<std::__1::set<std::__1::tuple<Eigen::Matrix<int, -1, -1, 0, -1, -1>::Scalar, bool, unsigned long>, std::__1::less<std::__1::tuple<Eigen::Matrix<int, -1, -1, 0, -1, -1>::Scalar, bool, unsigned long> >, std::__1::allocator<std::__1::tuple<Eigen::Matrix<int, -1, -1, 0, -1, -1>::Scalar, bool, unsigned long> > >, std::__1::allocator<std::__1::set<std::__1::tuple<Eigen::Matrix<int, -1, -1, 0, -1, -1>::Scalar, bool, unsigned long>, std::__1::less<std::__1::tuple<Eigen::Matrix<int, -1, -1, 0, -1, -1>::Scalar, bool, unsigned long> >, std::__1::allocator<std::__1::tuple<Eigen::Matrix<int, -1, -1, 0, -1, -1>::Scalar, bool, unsigned long> > > > >&);
#endif