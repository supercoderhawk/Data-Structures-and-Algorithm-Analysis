#-*- coding: UTF-8 -*-

from chapter9.graph import Graph

def init_graph():
  vertex_ids = [1,2,3,4,5,6,7]
  edges = [[2,4],[4,5],[1,6],[3,5,6,7],[7],[],[6]]
  weights = [[2,1],[3,10],[4,5],[2,2,8,4],[6],[],[1]]
  return Graph(vertex_ids,edges,weights)

def dijkstra(graph, start_id = 1):
  vertices = graph.vertices

  # 初始化
  vertices[start_id].dist = 0
  for v in vertices[start_id].adjacency_list:
    v[0].dist = v[1]
    v[0].path = start_id

  unknown_vertex_ids = list(vertices.keys())
  unknown_vertex_ids.remove(start_id)

  while unknown_vertex_ids:
    id_dist_dict = dict([(vertices[i].dist,i)for i in unknown_vertex_ids])
    curr_vertex = vertices[id_dist_dict[min(id_dist_dict)]]

    for vertex, dist in curr_vertex.adjacency_list:
      if curr_vertex.dist + dist < vertex.dist:
        vertex.dist = curr_vertex.dist + dist
        vertex.path = curr_vertex.idx

    unknown_vertex_ids.remove(curr_vertex.idx)

  result = {}
  for vertex in vertices.values():
    if vertex.idx == start_id:
      result[start_id] = {'length':0,'path':[]}
    else:
      path = [vertex.idx]
      v = vertex
      while v.path:
        path.insert(0,v.path)
        v = vertices[v.path]
      result[vertex.idx] = {'length':vertex.dist,'path':path}

  return result

if __name__ == '__main__':
  dijkstra(init_graph())
