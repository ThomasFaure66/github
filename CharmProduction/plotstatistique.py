import numpy as np
from scipy.stats import norm
import pandas as pd
import matplotlib.pyplot as plt

path_csv = 'dCharmdy_gg_y0_mQ1.5_qSupp0_NSamples1million_QMin3_QMax12_etaovers0.16.csv'
results = pd.read_csv(path_csv)

dNdy=results["dNdy"]

fig, ax = plt.subplots()
num_bins = 50

# Histograme(PMF) des Tailles
counts, bins = np.histogram(dNdy ,np.linspace(min(dNdy),max(dNdy), num_bins))
ax.hist(dNdy,
		bins[:-1],
		facecolor='orange',
		alpha=1,
		color="b",
		weights=(1/sum(counts))*np.ones_like(dNdy),
		label="Height's distribution")

path_csv = 'dCharmdy_gg_y0_mQ1.5_qSupp0_NSamples10million_QMin3_QMax12_etaovers0.16.csv'

results = pd.read_csv(path_csv)

dNdy2=results["dNdy"]

num_bins = 50

# Histograme(PMF) des Tailles
counts, bins = np.histogram(dNdy2,np.linspace(min(dNdy2),max(dNdy2), num_bins))
ax.hist(dNdy2,
		bins[:-1],
		facecolor='blue',
		alpha=0.5,
		color="b",
		weights=(1/sum(counts))*np.ones_like(dNdy2),
		label="Height's distribution")


plt.xlabel("dNdy")
plt.ylabel("Proportion de dNdy")
plt.show()
print(f"""
       Moyenne empirique: {np.mean(dNdy2)} \n 
       Variance empirique: {np.var(dNdy2)} \n
       Ecart-type empirique:{np.std(dNdy2)}
       """)
