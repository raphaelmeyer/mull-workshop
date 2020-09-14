#include <array>
#include <chrono>
#include <string>
#include <vector>
#include <iosfwd>

using Hash = std::array<unsigned char, 32>;
using Timestamp = std::chrono::system_clock::time_point;

class Block
{
public:
  Block(std::string content, Timestamp timestamp, Hash const &previous);

  Hash const &hash() const;
  std::string const &content() const;
  Timestamp timestamp() const;
  Hash const &previous() const;

private:
  Hash hash_;
  std::string content_;
  Timestamp timestamp_;
  Hash previous_;
  std::size_t nonce_;
};

class Blockchain
{
public:
  Blockchain();

  void add_block(std::string content);
  std::size_t length() const;

  Block const &operator[](std::size_t n) { return blocks_[n]; }

  Block const &front() const { return blocks_.front(); }
  Block const &back() const { return blocks_.back(); };

  // std::vector<Block>::const_iterator begin() const { return {}; }
  // std::vector<Block>::const_iterator end() const { return {}; }

private:
  std::vector<Block> blocks_;
};
