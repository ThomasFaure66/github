To run the code:
Make


(not put the [])

To get the production of charm (gluon scattering channel) as a function of the rapidity y, in a txt file:
./dNdy_y_gg.exe -alphas [Value of alphas] -etas [Value of etaovers] -area [Value of area in fm^{2}] -Q [1 to take into account the quark suppression factor, 0 if not] -M [Value of the mass of the charm in GeV] -QMin [Value of the minimum mass of the charm/anticharm pair in GeV] -QMax [Value of the maximum mass of the charm/anticharm pair in GeV] -qTMin [Value of the minimum transver momentum of the charm/anticharm pair in GeV] -qTMax [Value of the maximum transverse momentums of the charm/anticharm pair in GeV] -TauMin [Value of the minimum Tau  in fm/c]] -TauMax [Value of the maximum Tau , in fm/c] -NSamples [Number of interation for each point] > results.txt

To get the production of charm (quark/antiquark scattering channel) as a function of the rapidity y, in a txt file:
./dNdy_y_qq.exe -alphas [Value of alphas] -etas [Value of etaovers] -area [Value of area in fm^{2}] -Q [1 to take into account the quark suppression factor, 0 if not] -M [Value of the mass of the charm in GeV] -QMin [Value of the minimum mass of the charm/anticharm pair in GeV] -QMax [Value of the maximum mass of the charm/anticharm pair in GeV] -qTMin [Value of the minimum transver momentum of the charm/anticharm pair in GeV] -qTMax [Value of the maximum transverse momentums of the charm/anticharm pair in GeV] -TauMin [Value of the minimum Tau  in fm/c]] -TauMax [Value of the maximum Tau , in fm/c] -NSamples [Number of interation for each point] > results.txt

To get the phase-space distribution of quarks and gluons, the energy density and the temperature in a txt file:
./distribution.exe -alphas [Value of alphas] -etas [Value of etaovers] -area [Value of area in fm^{2}] -Q [1 to take into account the quark suppression factor, 0 if not] -qT [Value of the transverse momentum of the char/anticharm pair, in GeV] -M_paire [Value of the mass of the charm/anticharm pair, in GeV] -TauMin [Value of the minimum Tau  in fm/c]] -TauMax [Value of the maximum Tau , in fm/c] -NSamples [Number of interation for each point] -Ntau [Number of points] > results.txt

To get the production of charm (gluon scattering channel) as a function of the mass of the charm/anticharm pair (mid-rapidity) in a txt file:
./dNdQdy_Q_gg.exe -alphas [Value of alphas] -etas [Value of etaovers] -area [Value of area in fm^{2}] -Q [1 to take into account the quark suppression factor, 0 if not] -M [Value of the mass of the charm in GeV] -QMin [Value of the minimum mass of the charm/anticharm pair in GeV] -QMax [Value of the maximum mass of the charm/anticharm pair in GeV] -qTMin [Value of the minimum transver momentum of the charm/anticharm pair in GeV] -qTMax [Value of the maximum transverse momentums of the charm/anticharm pair in GeV] -TauMin [Value of the minimum Tau  in fm/c]] -TauMax [Value of the maximum Tau , in fm/c] -NSamples [Number of interation for each point] -NQ [Number of points] > results.txt

To get the production of charm (quark/antiquark scattering channel) as a function of the mass of the charm/anticharm pair (mid-rapidity) in a txt file:
./dNdQdy_Q_qq.exe -alphas [Value of alphas] -etas [Value of etaovers] -area [Value of area in fm^{2}] -Q [1 to take into account the quark suppression factor, 0 if not] -M [Value of the mass of the charm in GeV] -QMin [Value of the minimum mass of the charm/anticharm pair in GeV] -QMax [Value of the maximum mass of the charm/anticharm pair in GeV] -qTMin [Value of the minimum transver momentum of the charm/anticharm pair in GeV] -qTMax [Value of the maximum transverse momentums of the charm/anticharm pair in GeV] -TauMin [Value of the minimum Tau  in fm/c]] -TauMax [Value of the maximum Tau , in fm/c] -NSamples [Number of interation for each point] -NQ [Number of points] > results.txt

To get the production of charm (gluon scattering channel) as a function of the transverse momentum of the charm/anticharm pair (mid-rapidity) in a txt file:
./dNdqTdy_qT_gg.exe -alphas [Value of alphas] -etas [Value of etaovers] -area [Value of area in fm^{2}] -Q [1 to take into account the quark suppression factor, 0 if not] -M [Value of the mass of the charm in GeV] -QMin [Value of the minimum mass of the charm/anticharm pair in GeV] -QMax [Value of the maximum mass of the charm/anticharm pair in GeV] -qTMin [Value of the minimum transver momentum of the charm/anticharm pair in GeV] -qTMax [Value of the maximum transverse momentums of the charm/anticharm pair in GeV] -TauMin [Value of the minimum Tau  in fm/c]] -TauMax [Value of the maximum Tau , in fm/c] -NSamples [Number of interation for each point] -NQ [Number of points] > results.txt

To get the production of charm (quark/antiquark scattering channel) as a function of the transverse momentum of the charm/anticharm pair (mid-rapidity) in a txt file:
./dNdqTdy_qT_qq.exe -alphas [Value of alphas] -etas [Value of etaovers] -area [Value of area in fm^{2}] -Q [1 to take into account the quark suppression factor, 0 if not] -M [Value of the mass of the charm in GeV] -QMin [Value of the minimum mass of the charm/anticharm pair in GeV] -QMax [Value of the maximum mass of the charm/anticharm pair in GeV] -qTMin [Value of the minimum transver momentum of the charm/anticharm pair in GeV] -qTMax [Value of the maximum transverse momentums of the charm/anticharm pair in GeV] -TauMin [Value of the minimum Tau  in fm/c]] -TauMax [Value of the maximum Tau , in fm/c] -NSamples [Number of interation for each point] -NQ [Number of points] > results.txt

To get the instataneous charm production (gluon scattering channel) as a function of tau (mid-rapidity) in a txt file:
./dNdtaudy_tau_gg_not_integrated_.exe -alphas [Value of alphas] -etas [Value of etaovers] -area [Value of area in fm^{2}] -Q [1 to take into account the quark suppression factor, 0 if not] -M [Value of the mass of the charm in GeV] -QMin [Value of the minimum mass of the charm/anticharm pair in GeV] -QMax [Value of the maximum mass of the charm/anticharm pair in GeV] -qTMin [Value of the minimum transver momentum of the charm/anticharm pair in GeV] -qTMax [Value of the maximum transverse momentums of the charm/anticharm pair in GeV] -TauMin [Value of the minimum Tau  in fm/c]] -TauMax [Value of the maximum Tau , in fm/c] -NSamples [Number of interation for each point] -Ntau [Number of points] > results.txt

To get the production of charm (gluon scattering channel) integrated between tau=0 and tau, as a function of tau in a txt file:
./dNdy_tau_gg.exe -alphas [Value of alphas] -etas [Value of etaovers] -area [Value of area in fm^{2}] -Q [1 to take into account the quark suppression factor, 0 if not] -M [Value of the mass of the charm in GeV] -QMin [Value of the minimum mass of the charm/anticharm pair in GeV] -QMax [Value of the maximum mass of the charm/anticharm pair in GeV] -qTMin [Value of the minimum transver momentum of the charm/anticharm pair in GeV] -qTMax [Value of the maximum transverse momentums of the charm/anticharm pair in GeV] -TauMin [Value of the minimum Tau  in fm/c]] -TauMax [Value of the maximum Tau , in fm/c] -NSamples [Number of interation for each point] -NQ [Number of points] > results.txt

















