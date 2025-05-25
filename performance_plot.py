import pandas as pd
import matplotlib.pyplot as plt

# Load data
df = pd.read_csv("performance_data.csv")

# Convert data types
df["TimeMs"] = pd.to_numeric(df["TimeMs"], errors="coerce")
df["SolutionValue"] = pd.to_numeric(df["SolutionValue"], errors="coerce")

datasets = sorted(df["Dataset"].unique())

for dataset in datasets:
    subset = df[df["Dataset"] == dataset].copy()
    subset = subset[(subset["TimeMs"] > 0) & (subset["SolutionValue"] > 0)]

    if subset.empty:
        continue

    algorithms = subset["Algorithm"]
    times = subset["TimeMs"]
    values = subset["SolutionValue"]

    fig, (ax1, ax2) = plt.subplots(2, 1, sharex=True, figsize=(10, 6),
                                   gridspec_kw={'height_ratios': [1, 3]})
    fig.suptitle(f"Performance Comparison - {dataset}")

    # Bar chart for execution time (with broken y-axis)
    ax1.bar(algorithms, times, color="skyblue")
    ax2.bar(algorithms, times, color="skyblue")

    # Set y-axis limits to break scale
    ax1.set_ylim(max(times) * 0.9, max(times) * 1.1)
    ax2.set_ylim(0, max([t for t in times if t < max(times) * 0.5]) * 1.2)

    # Hide spines between axes
    ax1.spines['bottom'].set_visible(False)
    ax2.spines['top'].set_visible(False)
    ax1.tick_params(labeltop=False)
    ax2.xaxis.tick_bottom()

    # Diagonal lines to show axis break
    d = .015
    kwargs = dict(transform=ax1.transAxes, color='k', clip_on=False)
    ax1.plot((-d, +d), (-d, +d), **kwargs)
    ax1.plot((1 - d, 1 + d), (-d, +d), **kwargs)
    kwargs.update(transform=ax2.transAxes)
    ax2.plot((-d, +d), (1 - d, 1 + d), **kwargs)
    ax2.plot((1 - d, 1 + d), (1 - d, 1 + d), **kwargs)

    # Plot solution values as a line on ax2
    ax3 = ax2.twinx()
    ax3.plot(algorithms, values, color="red", marker="o", linewidth=2)
    ax3.set_ylabel("Solution Value", color="red")
    ax3.tick_params(axis="y", labelcolor="red")

    ax2.set_ylabel("Execution Time (ms)")
    plt.xticks(rotation=45)
    plt.tight_layout()
    plt.subplots_adjust(hspace=0.05)

    # Save output
    plt.savefig(f"performance_{dataset}_brokenaxis.png")
    plt.close()
