# knapsack_ilp.py
import sys
from pulp import LpMaximize, LpProblem, LpVariable, lpSum, LpBinary

def read_input(filename):
    with open(filename, 'r') as f:
        capacity = int(f.readline())
        n = int(f.readline())
        weights = list(map(int, f.readline().split()))
        profits = list(map(int, f.readline().split()))
    return capacity, n, weights, profits

def write_output(filename, total_profit, selected_ids):
    with open(filename, 'w') as f:
        f.write(f"{total_profit}\n")
        f.write(" ".join(map(str, selected_ids)))

def solve_knapsack(input_file, output_file):
    capacity, n, weights, profits = read_input(input_file)

    model = LpProblem(name="0-1-knapsack", sense=LpMaximize)

    x = [LpVariable(f"x{i}", cat=LpBinary) for i in range(n)]

    # Objective: maximize total profit
    model += lpSum(profits[i] * x[i] for i in range(n)), "Total_Profit"

    # Constraint: total weight ≤ capacity
    model += lpSum(weights[i] * x[i] for i in range(n)) <= capacity, "Weight_Limit"

    # Solve
    model.solve()

    selected = [i for i in range(n) if x[i].value() == 1]
    total_profit = sum(profits[i] for i in selected)

    write_output(output_file, total_profit, selected)

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python knapsack_ilp.py input.txt output.txt")
        sys.exit(1)

    solve_knapsack(sys.argv[1], sys.argv[2])
