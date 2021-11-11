#!/usr/bin/python3
"""boi rarted"""


def island_perimeter(grid):
    """red beach blue beach yellow beach jap"""
    island_coordinates = []
    island_beaches = 0
    for longitude in range(0, len(grid)):
        for latitude in range(0, len(grid[longitude])):
            if grid[longitude][latitude] == 1:
                island_coordinates.append([longitude, latitude])
    for current_coordinates in island_coordinates:
        island_beaches += 4
        for adjacent_coordinates in island_coordinates:
            if (current_coordinates != adjacent_coordinates):
                if (
                    (
                        abs(
                            adjacent_coordinates[0] - current_coordinates[0]
                            ) < 2 and
                        abs(
                            adjacent_coordinates[1] - current_coordinates[1]
                            ) < 1
                    ) or
                    (
                        abs(
                            adjacent_coordinates[0] - current_coordinates[0]
                            ) < 1 and
                        abs(
                            adjacent_coordinates[1] - current_coordinates[1]
                            ) < 2
                    )
                ):
                    island_beaches -= 1
    return(island_beaches)
