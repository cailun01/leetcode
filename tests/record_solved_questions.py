"""
统计做了多少题，len(solutions_by_order)是做题总数
"""

from pathlib import Path
from collections import OrderedDict


def solved_questions():
    p = Path("../solutions/")

    solutions = {}

    for x in p.iterdir():
        if x.suffix != ".cc":
            continue
        file_name = x.stem  # file_name example: leetcode_997_solution_2
        split_file_name = file_name.split("_")
        question_number = int(split_file_name[1])
        num_solutions = int(split_file_name[3])
        solutions[question_number] = num_solutions

    solutions_by_order = OrderedDict(sorted(solutions.items()))
    return solutions_by_order
