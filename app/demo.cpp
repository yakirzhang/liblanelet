#include <iostream>

#include <BoundingBox.hpp>
#include <Lanelet.hpp>
#include <LaneletMap.hpp>
#include <llet_xml.hpp>

#include <boost/foreach.hpp>

#include <memory>
#include <tuple>
#include <vector>

using namespace LLet;

int main(int argc, char *argv[]) {
  std::string source = argv[1];
  LaneletMap the_map(source);

  BoundingBox world(std::make_tuple(-180, -180, 180, 180));
  auto query_result = the_map.query(world);

  // print all attributes of each lanelet
  for (const lanelet_ptr_t &lanelet : query_result) {
    const AttributeMap &attributes = lanelet->attributes();
    for (const auto &a : attributes) {
      std::cout << a.first << ": " << a.second.as_string() << std::endl;
    }
  }

  // exploiting the lanelet graph directly
  const Graph &G = the_map.graph();

  BOOST_FOREACH (const auto &edge, boost::edges(G)) {
    auto src_vtx = boost::source(edge, G);
    auto dest_vtx = boost::target(edge, G);

    std::cout << G[src_vtx].lanelet << " --> " << G[dest_vtx].lanelet << std::endl;
  }
}
