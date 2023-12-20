import numpy as np
from scipy.stats import norm
import pandas as pd
import matplotlib.pyplot as plt

path_csv = 'dCharmdy_gg_y0_mQ1.5_qSupp0_NSamples10million_QMin3_QMax12_etaovers0.16.csv'
results = pd.read_csv(path_csv)

dNdy=results["dNdy"]

fig, ax = plt.subplots()
num_bins = 50

# Histograme(PMF) des Tailles
counts, bins = np.histogram(dNdy ,np.linspace(min(dNdy),max(dNdy), num_bins))
pmf = counts/sum(counts)
cdf = np.cumsum(pmf)
ax.scatter(bins[:-1], cdf, c='b', marker="+", label="Distribution de la taille CDF")
# CDF of Normal Distribution
mean, std = np.mean(dNdy), np.std(dNdy)
rvs = np.linspace(mean - 3*std, mean + 3*std, 100)
cdf = norm.cdf(rvs, mean, std)
ax.plot(rvs, cdf, c='g', label="Distribution normale CDF")
leg = ax.legend()

plt.xlabel("Taille(Inches)")
plt.ylabel("CDF de la distribution de la hauteur \n CDF de la distribution normale")
plt.show()
