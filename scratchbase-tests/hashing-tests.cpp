#include "catch.hpp"

#include "scratchbase/scratchbase.h"
#include "scratchbase/scratchbaseext.h"
#include "highwayhash/highwayhash.h"

#include <unordered_map>

TEST_CASE("Test unordered_map custom hashing algorithms","[set,get]") {

  // Story #7 on GitHub
  //   [Who]   As a database user
  //   [What]  I want to be able to logically segment my data
  //   [Value] To make storage, querying, retrieval, backups and restores easier and quicker
  SECTION("Produces known expected value for known input") {
    scratchbaseext::HighwayHash h;
    std::string text("Known");
    std::size_t r = h(text);

    using namespace highwayhash;
    const HHKey key HH_ALIGNAS(64) = {1, 2, 3, 4};
    HHResult64 result;  // or HHResult128 or HHResult256
    HHStateT<HH_TARGET> state(key);
    HighwayHashT(&state, text.c_str(), text.length(), &result);

    REQUIRE(result == r);
  }

  SECTION("Previous hash doesn't affect next hash result") {
    scratchbaseext::HighwayHash hfirst;
    std::size_t rfirst = hfirst("OtherThing");

    scratchbaseext::HighwayHash h;
    std::size_t r1 = h("Known");
    std::size_t r2 = h("OtherThing");

    REQUIRE(r1 != r2);
    REQUIRE(r1 != rfirst);
    REQUIRE(rfirst == r2);
  }

  SECTION("Different seed keys produce different results for the same input") {
    scratchbaseext::HighwayHash h1{1,2,3,4};
    std::size_t r1 = h1("AThing");

    scratchbaseext::HighwayHash h2{5,6,7,8};
    std::size_t r2 = h2("AThing");

    REQUIRE(r1 != r2);
  }

  SECTION("Unordered map works as expected with custom hash") {
    std::unordered_map<std::string,std::string,scratchbaseext::HighwayHash> m;
    std::string key("A very sensible key name");
    std::string value("A very valuable value");
    std::string k2("Some other key");
    std::string v2("Another value");
    m.emplace(key,value);
    m.emplace(k2,v2);

    REQUIRE(m[key] == value);
    REQUIRE(m[k2] == v2);
  }

}