#ifndef HAMMINGCODE_15_11_H
#define HAMMINGCODE_15_11_H
#include <bitset>
#include <iostream>
#include <vector>

///
/// The FHammingCode namespace is for (15,11) Hamming Code encoding and decoding
///
namespace FHammingCode_15_11
{

std::bitset<15> encode(std::bitset<11> Data);
std::bitset<11> decode(std::bitset<15> Message);

}

#endif // HAMMINGCODE_15_11_H
