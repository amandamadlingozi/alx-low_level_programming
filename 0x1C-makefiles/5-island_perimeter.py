#!/usr/bin/python3
""" Calculating island periemetre in a grid."""

def island_perimeter(grid):
    """
    Calculating the perimeter of the island described in grid.
    Args:
    grid: A list of list of integers representing the island.

    Returns:
    The perimeter of the island.
    """
    perimeter = 0
    rows = len(grid)
    cols = len(grid[0])

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:

                # Analyzing the top
                if i == 0 or grid[i - 1][j] == 0:
                    perimeter += 1
                    # Analyzing the bottom
                    if i == rows - 1 or grid[i + 1][j] == 0:
                        perimeter += 1
                        # Analyzing left
                        if j == 0 or grid[i][j - 1] == 0:
                            perimeter += 1
                            # Analyzing right
                            if j == cols - 1 or grid[i][j + 1] == 0:
                                perimeter += 1

                                return perimeter
