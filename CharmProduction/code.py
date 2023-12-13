import numpy as np
from scipy.stats import norm
import pandas as pd
import matplotlib.pyplot as plt

path_csv = 'results.csv'
results = pd.read_csv(path_csv)

dNdy=results["dNdy"]

fig, ax = plt.subplots()
num_bins = 50

# Histograme(PMF) des Tailles
counts, bins = np.histogram(dNdy ,np.linspace(min(dNdy),max(dNdy), num_bins))
ax.hist(dNdy,
		bins[:-1],
		facecolor='orange',
		alpha=0.5,
		color="b",
		weights=(1/sum(counts))*np.ones_like(dNdy),
		label="Height's distribution")
plt.xlabel("Taille(Inches)")
plt.ylabel("Proportion de la taille se situant dans une certaine fourchette")
plt.show()
