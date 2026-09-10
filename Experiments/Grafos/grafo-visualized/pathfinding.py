"""Pathfinding algorithms for the Snake AI gym.

The grid is treated as a graph: each free cell is a vertex, and edges
connect a cell to its up/down/left/right neighbors -- same graph model
as the adjacency-matrix Grafo you built earlier, just with grid cells
as vertices and neighbors() (below) doing the job matriz_adj_ did.
"""

from typing import Dict, List, Optional, Set, Tuple
from collections import deque

Point = Tuple[int, int]


def neighbors(width: int, height: int, obstacles: Set[Point], cell: Point) -> List[Point]:
    """Free neighbors of `cell` (up/down/left/right), skipping anything
    outside the grid or inside `obstacles`."""
    x, y = cell
    candidates = [(x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)]
    return [
        (nx, ny) for nx, ny in candidates
        if 0 <= nx < width and 0 <= ny < height and (nx, ny) not in obstacles
    ]


def find_path_bfs(width: int, height: int, obstacles: Set[Point],
                   start: Point, goal: Point) -> Optional[List[Point]]:
    """Find a path from `start` to `goal` using breadth-first search.

    Returns the list of cells from start to goal (inclusive), or None if
    goal is unreachable.

    TODO: implement this. Same shape as Grafo::busca_largura:
    - a "visited" set
    - a queue (FIFO) of cells to explore
    - use neighbors() above instead of matriz_adj_ to find where to go next

    One thing busca_largura didn't need: this has to return the actual
    route, not just visit order. Keep a dict mapping cell -> the cell you
    came from (parent) as you visit each one, then walk it backwards from
    `goal` to `start` once you get there, and reverse the result.
    """
    explored = set()
    scheduled = deque()
    parent_pathing: Dict[Point,Point] = {} # son, parent
    scheduled.append(start)
    list_points: List[Point] = []
    explored.add(start)
    reached_goal = False
    parent = start
    while(not reached_goal):
        if not scheduled:
            return list_points
        vertex = scheduled.popleft()
        parent = vertex
        for neighbour in neighbors(width, height, obstacles, vertex):
            if(neighbour in explored): continue 
            elif(neighbour == goal):
                explored.add(neighbour)
                scheduled.append(neighbour)
                parent_pathing[neighbour] = parent
                reached_goal = True
                break
            explored.add(neighbour)
            scheduled.append(neighbour)
            parent_pathing[neighbour] = parent

    parent = goal
    while True:
        list_points.append(parent)
        parent = parent_pathing[parent]
        if parent == start:
            break

    
    list_points.reverse()
    return list_points
    #raise NotImplementedError("find_path_bfs: not implemented yet")


def find_path_dfs(width: int, height: int, obstacles: Set[Point],
                   start: Point, goal: Point) -> Optional[List[Point]]:
    """Find a path from `start` to `goal` using depth-first search.

    Same idea as find_path_bfs (visited set + parent-tracking to rebuild
    the route), but swap the queue for a stack (or recursion) -- same
    trade-off you already saw in Grafo::busca_profundidade. Expect this
    to find *a* path, not necessarily a short one -- watch the snake take
    a noticeably worse route than the BFS version.
    """
    explored = set()
    scheduled = deque()
    parent_pathing: Dict[Point,Point] = {} # son, parent
    scheduled.append(start)
    list_points: List[Point] = []
    explored.add(start)
    reached_goal = False
    parent = start
    while(not reached_goal):
        if not scheduled:
            return list_points
        vertex = scheduled.pop()
        parent = vertex
        for neighbour in neighbors(width, height, obstacles, vertex):
            if(neighbour in explored): continue 
            elif(neighbour == goal):
                explored.add(neighbour)
                scheduled.append(neighbour)
                parent_pathing[neighbour] = parent
                reached_goal = True
                break
            explored.add(neighbour)
            scheduled.append(neighbour)
            parent_pathing[neighbour] = parent

    parent = goal
    while True:
        list_points.append(parent)
        parent = parent_pathing[parent]
        if parent == start:
            break

    
    list_points.reverse()
    return list_points
