/** Proofs GPU - Space and Time's cryptographic proof algorithms on the CPU and GPU.
 *
 * Copyright 2023-present Space and Time Labs, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "benchmark/reduce2/reduce_cpu.h"

#include "sxt/curve21/operation/add.h"
#include "sxt/curve21/type/element_p3.h"

namespace sxt {
//--------------------------------------------------------------------------------------------------
// reduce_cpu
//--------------------------------------------------------------------------------------------------
void reduce_cpu(c21t::element_p3* res, int m, int n) noexcept {
  // pretend like g is a random element rather than fixed
  c21t::element_p3 g{
      {3990542415680775, 3398198340507945, 4322667446711068, 2814063955482877, 2839572215813860},
      {1801439850948184, 1351079888211148, 450359962737049, 900719925474099, 1801439850948198},
      {1, 0, 0, 0, 0},
      {1841354044333475, 16398895984059, 755974180946558, 900171276175154, 1821297809914039},
  };

  for (int mi = 0; mi < m; ++mi) {
    auto& res_mi = res[mi];
    res_mi = c21t::element_p3::identity();
    for (int i = 0; i < n; ++i) {
      c21o::add(res_mi, res_mi, g);
    }
  }
}
} // namespace sxt
