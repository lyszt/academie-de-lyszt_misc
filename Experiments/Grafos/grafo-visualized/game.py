"""Snake AI playground.

The snake is fully autonomous: every frame it asks your pathfinding
function (find_path_bfs or find_path_dfs, from pathfinding.py) for a
route from its head to the food, then takes one step along that route.
This file only handles game mechanics and drawing -- the pathfinding
itself is yours to implement.

Run with:
    .venv/bin/python game.py bfs
    .venv/bin/python game.py dfs
"""

import random
import sys
from typing import List, Optional, Set, Tuple

import matplotlib.animation as animation
import matplotlib.colors as mcolors
import matplotlib.pyplot as plt
import numpy as np

from pathfinding import find_path_bfs, find_path_dfs

GRID_WIDTH = 20
GRID_HEIGHT = 20
FRAME_MS = 120

EMPTY, BODY, HEAD, FOOD = 0, 1, 2, 3
COLORS = ["#141414", "#4caf78", "#8ee6aa", "#dc5a5a"]

Point = Tuple[int, int]


def random_free_cell(occupied: Set[Point]) -> Point:
    while True:
        cell = (random.randrange(GRID_WIDTH), random.randrange(GRID_HEIGHT))
        if cell not in occupied:
            return cell


class SnakeGame:
    def __init__(self, algorithm: str):
        self.find_path = find_path_bfs if algorithm == "bfs" else find_path_dfs
        self.algorithm = algorithm
        self.snake: List[Point] = [(GRID_WIDTH // 2, GRID_HEIGHT // 2)]
        self.food = random_free_cell(set(self.snake))
        self.path: Optional[List[Point]] = None
        self.eaten = 0
        self.game_over = False

    def step(self) -> None:
        if self.game_over:
            return

        head = self.snake[0]
        obstacles = set(self.snake[:-1])  # tail moves away, so it isn't a real wall

        if not self.path or self.path[0] != head:
            self.path = self.find_path(GRID_WIDTH, GRID_HEIGHT, obstacles, head, self.food)

        if not self.path or len(self.path) < 2:
            self.game_over = True
            return

        next_cell = self.path[1]
        self.path = self.path[1:]

        ate_food = next_cell == self.food
        self.snake.insert(0, next_cell)
        if ate_food:
            self.eaten += 1
            if len(self.snake) == GRID_WIDTH * GRID_HEIGHT:
                self.game_over = True
            else:
                self.food = random_free_cell(set(self.snake))
                self.path = None
        else:
            self.snake.pop()

    def grid(self) -> np.ndarray:
        grid = np.zeros((GRID_HEIGHT, GRID_WIDTH), dtype=int)
        for x, y in self.snake:
            grid[y, x] = BODY
        hx, hy = self.snake[0]
        grid[hy, hx] = HEAD
        fx, fy = self.food
        grid[fy, fx] = FOOD
        return grid


def run(algorithm: str) -> None:
    game = SnakeGame(algorithm)

    fig, ax = plt.subplots(figsize=(6, 6.4))
    cmap = mcolors.ListedColormap(COLORS)
    img = ax.imshow(game.grid(), cmap=cmap, vmin=0, vmax=3)
    ax.set_xticks([])
    ax.set_yticks([])
    title = ax.set_title("")

    def update(_frame):
        game.step()
        img.set_data(game.grid())
        status = f"{algorithm.upper()}  |  length {len(game.snake)}  |  food eaten {game.eaten}"
        if game.game_over:
            status += "  |  GAME OVER"
        title.set_text(status)
        return img, title

    anim = animation.FuncAnimation(fig, update, interval=FRAME_MS, cache_frame_data=False)
    plt.show()


if __name__ == "__main__":
    algo = sys.argv[1].lower() if len(sys.argv) > 1 else "bfs"
    if algo not in ("bfs", "dfs"):
        print("Usage: python game.py [bfs|dfs]")
        sys.exit(1)
    run(algo)
