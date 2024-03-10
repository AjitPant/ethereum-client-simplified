//
// Created by Ajit Pant on 09/03/24.
//

#ifndef ETHEREUM_CLIENT_SIMPLIFIED_TYPES_H
#define ETHEREUM_CLIENT_SIMPLIFIED_TYPES_H

#include <boost/multiprecision/cpp_int.hpp>

// Define an 8-bit unsigned integer using Boost Multiprecision
using uint8_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<8, 8, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
using uint16_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<16, 16, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
using uint24_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<24, 24, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
using uint32_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<32, 32, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
using uint40_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<40, 40, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
using uint48_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<48, 48, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
using uint56_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<56, 56, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
using uint64_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<64, 64, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
using uint72_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<72, 72, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
using uint80_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<80, 80, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
using uint88_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<88, 88, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
using uint96_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<96, 96, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
using uint104_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<104, 104, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
using uint112_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<112, 112, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
using uint120_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<120, 120, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
using uint128_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<128, 128, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
using uint136_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<136, 136, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
using uint144_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<144, 144, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
using uint152_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<152, 152, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
using uint160_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<160, 160, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
using uint168_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<168, 168, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
using uint176_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<176, 176, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
using uint184_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<184, 184, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
using uint192_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<192, 192, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
using uint200_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<200, 200, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
using uint208_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<208, 208, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
using uint216_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<216, 216, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
using uint224_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<224, 224, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
using uint232_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<232, 232, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
using uint240_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<240, 240, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
using uint248_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<248, 248, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
using uint256_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<256, 256, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;
using uint512_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<512, 512, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;

using int256_c = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<512, 512, boost::multiprecision::signed_magnitude, boost::multiprecision::unchecked, void>>;


#endif //ETHEREUM_CLIENT_SIMPLIFIED_TYPES_H
