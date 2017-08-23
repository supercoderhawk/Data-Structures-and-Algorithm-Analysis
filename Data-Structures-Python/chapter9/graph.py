#-*- coding: UTF-8 -*-
from functools import reduce
class TableEntry:
  def __init__(self, idx):
    self.idx = idx
    self.adjacency_list = []
    self.dist = float('Inf')
    self.path = None

class Graph:
  def __init__(self,vertex_ids, edges,weights):
    '''

    :param vertex_ids: 顶点序号
    :param edges: 每个顶点对应的邻接点
    :param weights: 顶点和邻接点对应的权重
    '''

    if not vertex_ids or len(vertex_ids) != len(weights) != len(edges):
      raise Exception('Length error!')
    if not isinstance(vertex_ids[0],int) or not reduce(lambda x,y:x and isinstance(y,int),vertex_ids):
      raise Exception('Vertex id type error')

    self.vertices = {}

    for idx in vertex_ids:
      self.vertices[idx] = TableEntry(idx)

    for vertex,edge,weight in zip(self.vertices.values(),edges,weights):
      vertex.adjacency_list = [(self.vertices[e],w) for e,w in zip(edge,weight)]


  def __getitem__(self, item):
    print(item)
    return self.vertices[item]

