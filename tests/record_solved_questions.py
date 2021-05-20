"""
统计做了多少题，len(solutions_by_order)是做题总数
"""

from pathlib import Path
from collections import OrderedDict


def parse_file_name(file_name):
    """file_name: a list of strings
    """
    number = [name for name in file_name if name.isdigit()]
    if (len(number) == 2):
        return int(number[0]), int(number[1])
    elif (len(number) == 1):
        return int(number[0]), -1
    else:
        -1, -1


def solved_questions():
    p = Path("../solutions")

    solutions = {}

    for x in p.glob("**/*.cc"):
        if x.suffix != ".cc":
            continue
        file_name = x.stem  # file_name example: leetcode_997_solution_2
        split_file_name = file_name.split("_")
        question_number, num_solutions = parse_file_name(split_file_name)
        if question_number != -1:
            solutions[question_number] = num_solutions

    solutions_by_order = OrderedDict(sorted(solutions.items()))
    num_solved_questions = len(solutions_by_order)
    return solutions_by_order, num_solved_questions


if __name__ == "__main__":
    _, num_solved_questions = solved_questions()
