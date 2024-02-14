CharmRates (2 files):
CharmRates_gg.cpp -> calculates the production of charm (gluon scattering channel)
CharmRates_qq.cpp -> calculates the production if charm (quark/antiquark scattering channel)

dCharmdQdy_Q (2 files):
dNdQdy_Q_gg.cpp -> Monte Carlo integration to get the production of charm as a function on the mass of the charm/anticharm pair (gluon scattering channel)
dNdQdy_Q_qq.cpp -> Monte Carlo integration to get the production of charm as a function on the mass of the charm/anticharm pair (quark/antiquark scattering channel)
Return:
#1--Q [GeV] #2--dN_{tot}/dQdy [GeV-1] #3--dN_{PreEq}/dQdy [GeV-1] #4--dN_{Hydro}/dQdy [GeV-1]


dCharmdqTdy_Q (2 files):
dNdqTdy_qT_gg.cpp -> Monte Carlo integration to get the production of charm as a function on the transverse momentum of the charm/anticharm pair (gluon scattering channel)
dNdqTdy_qT_qq.cpp -> Monte Carlo integration to get the production of charm as a function on the transverse momentum of the charm/anticharm pair (quark/antiquark scattering channel)
Return:
#1--qT [GeV] #2--dN_{tot}/dQdy [GeV-1] #3--dN_{PreEq}/dQdy [GeV-1] #4--dN_{Hydro}/dQdy [GeV-1]

dCharmdtaudy_tau (2 files):
dNdtaudy_tau_gg_not_integrated.cpp -> Monte Carlo integration to get the instataneous production of charm as a function of the propre time tau (gluon scattering channel)
Return:
#1--Tau [fm/c] #2--dN_{tot}/dtaudy [c/fm] #3--dN_{PreEq}/dtaudy [c/fm] #4--dN_{Hydro}/dtaudy [c/fm]
dNdy_tau_gg.cpp -> Monte Carlo integration to get the production of the charm integrated between tau=0 and tau, as a function of tau (gluon scattering channel)
Return:
#1--Tau [fm/c] #2--dN_{tot}/dy #3--dN_{PreEq}/dy #4--dN_{Hydro}/dy

dCharmdy_y (2 files):
dNdy_y_gg.cpp -> Monte Carlo integration to get the production of charm as a function of y (gluon scattering channel)
dNdy_y_qq.cpp -> Monte Carlo integration to get the production of charm as a function of y (quark/antiquark scattering channel)
Return:
#1--y #2--dN_{tot}/dy #3--dN_{PreEq}/dy #4--dN_{Hydro}/dy

Distribution_Temperaure_Energydensity (2 files):
distribution.cpp -> Code to obtain the phase-space distribution of quarks and of gluons, the energy density and the temperature as a function of tau
Return:
#1--Tau [fm/c] #2--GLUON DISTRIBUTION #3--QUARK DISTRIBUTION #4--TEMPERATURE [GeV] #5--ENERGY DENSITY [GeV^{4}]
getphasedistribution.cpp -> Calcultes the phase-space distribution of quarks and of gluons, the energy density and te temperature


