#pragma once

#include <cstdint>

#include "sxt/base/container/span.h"

namespace sxt::mtxb {
//--------------------------------------------------------------------------------------------------
// extract_digit
//--------------------------------------------------------------------------------------------------
void extract_digit(basct::span<uint8_t> digit, basct::cspan<uint8_t> e, size_t radix_log2,
                   size_t digit_index) noexcept;

//--------------------------------------------------------------------------------------------------
// is_digit_zero
//--------------------------------------------------------------------------------------------------
bool is_digit_zero(basct::cspan<uint8_t> e, size_t radix_log2, size_t digit_index) noexcept;

//--------------------------------------------------------------------------------------------------
// get_last_digit
//--------------------------------------------------------------------------------------------------
size_t get_last_digit(basct::cspan<uint8_t> e, size_t radix_log2) noexcept;

//--------------------------------------------------------------------------------------------------
// count_nonzero_digits
//--------------------------------------------------------------------------------------------------
size_t count_nonzero_digits(basct::cspan<uint8_t> e, size_t radix_log2) noexcept;

//--------------------------------------------------------------------------------------------------
// count_num_digits
//--------------------------------------------------------------------------------------------------
size_t count_num_digits(basct::cspan<uint8_t> e, size_t radix_log2) noexcept;
} // namespace sxt::mtxb