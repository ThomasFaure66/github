For the production of Charm/Dilepton as a function of y:

Column: y dNch/dy SUM PreEq Hydro

Name:
dXdy_channel_mQ_qSupp_Nsamples_Qmin_Qmax_etaovers_Area_alphas.txt

X = {Charm, Dilepton}
channel = {gg for gluon scattering, qq for quark scattering, PreEq gluon scattering and quark scattering}
mQ = Charm mass (GeV)
qSupp = {1 if we take into account the quark suppression factor, 0 if not}
NSamples = number of samples to perform the monte carlo integration
QMin, QMax = invariant mass of the quarkonia for integration
etaovers = value of η/s
Area = value of the area A (if nothing, Area = 110)
alphas = value of alphas (if nothing, alphas=0.3)



For the production of Charm/Dilepton as a function of Q:

Column: Q Sum PreEq Hydro

Name:
dXdQdy_channel_mQ_qSupp_Nsamples_Qmin_Qmax_y_etaovers_Area_alphas.txt

X = {Charm, Dilepton}
channel = {gg for gluon scattering, qq for quark scattering, PreEq gluon scattering and quark scattering}
mQ = Charm mass (GeV)
qSupp = {1 if we take into account the quark suppression factor, 0 if not}
NSamples = number of samples to perform the monte carlo integration
QMin, QMax = invariant mass of the quarkonia
y = value of the rapidity y (if y=2, dNdeta/dy = 1900)
etaovers = value of η/s
Area = value of the area A (if nothing, Area = 110)
alphas = value of alphas (if nothing, alphas=0.3)

For the production of Charm/Dilepton as a function of tau:

Column: tau Sum PreEq Hydro

Name:
dXdtaudy_channel_mQ_qSupp_Nsamples_Qmin_Qmax_tauMax_etaovers_Area_alphas.txt

X = {Charm, Dilepton}
channel = {gg for gluon scattering, qq for quark scattering, PreEq gluon scattering and quark scattering}
mQ = Charm mass (GeV)
qSupp = {1 if we take into account the quark suppression factor, 0 if not}
NSamples = number of samples to perform the monte carlo integration
QMin, QMax = invariant mass of the quarkonia
tauMax = value of the upper limit of tau
etaovers = value of η/s
Area = value of the area A (if nothing, Area = 110)
alphas = value of alphas (if nothing, alphas=0.3)

