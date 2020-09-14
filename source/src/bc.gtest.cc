#include <gtest/gtest.h>

#include <iosfwd>

#include "bc.h"

namespace std
{
  std::ostream &operator<<(std::ostream &os, Hash const &hash)
  {
    os << std::hex << std::setfill('0');
    for (auto const v : hash)
    {
      os << std::setw(2) << static_cast<uint16_t>(v);
    }
    return os;
  }

  std::ostream &operator<<(std::ostream &os, Timestamp const &time)
  {
    os << time.time_since_epoch().count();
    return os;
  }

} // namespace std

TEST(BlockDefinition, block_contains_a_hash)
{
  Block b{"", {}, {}};
  ASSERT_TRUE(not b.hash().empty());
}

TEST(BlockDefinition, block_stores_some_kind_of_data)
{
  Block b{"Hello World", {}, {}};
  ASSERT_TRUE(b.content() == "Hello World");
}

TEST(BlockDefinition, block_has_a_timestamp)
{
  auto const now = std::chrono::system_clock::now();
  Block b{"", now, {}};
  ASSERT_TRUE(b.timestamp() == now);
}

TEST(BlockDefinition, block_stores_the_hash_of_the_previous_block)
{
  Hash previous{};
  std::fill(previous.begin(), previous.end(), 0x2A);
  Block b{"", {}, previous};
  ASSERT_TRUE(b.previous() == previous);
}

/*
TEST_SUITE("Properties of the hash of a block")
{
  TEST_CASE("the hash varies with the stored data")
  {
    Block b1{"hello", {}, {}};
    Block b2{"world", {}, {}};

    REQUIRE(b1.hash() != b2.hash());
  }

  TEST_CASE("the hash varies with different timestamps")
  {
    Block b1{"", std::chrono::system_clock::now(), {}};
    Block b2{"", std::chrono::system_clock::now(), {}};

    REQUIRE(b1.timestamp() != b2.timestamp());
    REQUIRE(b1.hash() != b2.hash());
  }

  TEST_CASE("the hash varies with the hash of the previous block")
  {
    Block b1{"", {}, {1, 2, 3}};
    Block b2{"", {}, {4, 5, 6}};

    REQUIRE(b1.hash() != b2.hash());
  }
}

TEST_SUITE("Creating a new blockchain")
{
  TEST_CASE("new blockchain consists of a genesis block")
  {
    Blockchain bc;
    REQUIRE(bc.front().content() == "Genesis Block");
  }

  TEST_CASE("a genesis block has no previous block")
  {
    Blockchain bc;
    REQUIRE(bc.front().previous() == Hash{});
  }

  TEST_CASE("a genesis block has a valid timestamp")
  {
    auto const older = std::chrono::system_clock::now();

    Blockchain bc;

    auto const newer = std::chrono::system_clock::now();

    REQUIRE(older < bc.front().timestamp());
    REQUIRE(bc.front().timestamp() < newer);
  }
}

TEST_SUITE("Adding new blocks")
{
  TEST_CASE("new blocks are appended")
  {
    Blockchain bc{};
    bc.add_block("");
    REQUIRE(bc.length() == 2);
    bc.add_block("");
    REQUIRE(bc.length() == 3);
  }

  TEST_CASE("a new block contains some data")
  {
    std::string data{"some data"};
    Blockchain bc;

    bc.add_block(data);

    REQUIRE(bc.back().content() == data);
  }

  TEST_CASE("any new block contains the hash of the previous block")
  {
    Blockchain bc;
    bc.add_block("");
    bc.add_block("");

    REQUIRE(bc[1].previous() == bc[0].hash());
    REQUIRE(bc[2].previous() == bc[1].hash());
  }

  TEST_CASE("new blocks are ordered chronologically")
  {
    Blockchain bc;
    bc.add_block("");
    bc.add_block("");

    REQUIRE(bc[0].timestamp() < bc[1].timestamp());
    REQUIRE(bc[1].timestamp() < bc[2].timestamp());
  }
}

TEST_SUITE("Proof of work")
{
  TEST_CASE("all block hashes start with two 0 bytes")
  {
    Blockchain bc;
    bc.add_block("");

    REQUIRE(bc[0].hash()[0] == 0);
    REQUIRE(bc[0].hash()[1] == 0);

    REQUIRE(bc[1].hash()[0] == 0);
    REQUIRE(bc[1].hash()[1] == 0);
  }
}
*/
