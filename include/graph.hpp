#pragma once
#include <vector>
#include <set>

struct Vertex {
  const int id;     // index for V in Graph
  const int index;  // index for U, width * y + x, in Graph
  const int x;
  const int y;
  std::vector<Vertex*> neighbor;

  Vertex(int _id, int _index, int _x, int _y);
};
using Vertices = std::vector<Vertex*>;
using Config = std::vector<Vertex*>;  // a set of locations for all agents
using VertexSet = std::set<Vertex*>;  // like Vertices but with constant lookup
using Solution = std::vector<Config>;

struct Graph {
  Vertices V;  // without nullptr
  Vertices U;  // with nullptr
  int width;   // grid width
  int height;  // grid height
  VertexSet sources; // MAPD source
  VertexSet sinks;   // MAPD sink
  VertexSet homes;   // Robot homes
  Graph();
  Graph(char* filename);  // taking map filename
  ~Graph();
};
