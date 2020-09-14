#include "bc.h"

#include <crypto++/sha.h>

#include <algorithm>
#include <sstream>

Block::Block(std::string content, Timestamp timestamp, Hash const &previous)
    : hash_{}, content_{content}, timestamp_{timestamp}, previous_{previous}, nonce_{}
{
  do
  {
    ++nonce_;

    CryptoPP::SHA256 sha{};

    sha.Update(reinterpret_cast<unsigned char const *>(content_.data()), content_.size());

    std::ostringstream os;
    os << std::chrono::duration_cast<std::chrono::microseconds>(timestamp_.time_since_epoch()).count();
    auto const str = os.str();
    sha.Update(reinterpret_cast<unsigned char const *>(str.data()), str.size());

    sha.Update(previous_.data(), previous_.size());

    sha.Update(reinterpret_cast<unsigned char const *>(&nonce_), sizeof(nonce_));

    sha.Final(hash_.data());
  } while (std::any_of(hash_.begin(), hash_.begin() + 2, [](unsigned char i) { return i != 0; }));
}

Hash const &Block::hash() const
{
  return hash_;
}

std::string const &Block::content() const
{
  return content_;
}

Timestamp Block::timestamp() const
{
  return timestamp_;
}

Hash const &Block::previous() const
{
  return previous_;
}

Blockchain::Blockchain()
{
  blocks_.emplace_back("Genesis Block", std::chrono::system_clock::now(), Hash{});
}

void Blockchain::add_block(std::string content)
{
  blocks_.emplace_back(content, std::chrono::system_clock::now(), blocks_.back().hash());
}

std::size_t Blockchain::length() const
{
  return blocks_.size();
}
