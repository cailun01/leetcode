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
    num_solved_questions = len(solutions_by_order)
    return solutions_by_order, num_solved_questions


if __name__ == "__main__":
    _, num_solved_questions = solved_questions()
    print("num_solved_questions: ", num_solved_questions)
