#!/bin/bash
./dNdQdy_Q_gg.exe -NSamples 1000000 -etas 0.16 -M 1.5 -Q 0 -alphas 0.3 -a 0 -b 5 > ./results/Charm_production_as_a_function_of_Q/dCharmdQdy_gg_mQ1.5_qSupp0_NSamples1million_etaovers0.16_alphas0.3_centrality0_5_midrapidity.txt;
./dNdQdy_Q_qq.exe -NSamples 1000000 -etas 0.16 -M 1.5 -Q 1 -alphas 0.3 -a 0 -b 5 > ./results/Charm_production_as_a_function_of_Q/dCharmdQdy_qq_mQ1.5_qSupp1_NSamples1million_etaovers0.16_alphas0.3_centrality0_5_midrapidity.txt

./dNdQdy_Q_gg.exe -NSamples 1000000 -etas 0.32 -M 1.5 -Q 0 -alphas 0.3 -a 0 -b 5 > ./results/Charm_production_as_a_function_of_Q/dCharmdQdy_gg_mQ1.5_qSupp0_NSamples1million_etaovers0.32_alphas0.3_centrality0_5_midrapidity.txt;
./dNdQdy_Q_qq.exe -NSamples 1000000 -etas 0.32 -M 1.5 -Q 1 -alphas 0.3 -a 0 -b 5 > ./results/Charm_production_as_a_function_of_Q/dCharmdQdy_qq_mQ1.5_qSupp1_NSamples1million_etaovers0.32_alphas0.3_centrality0_5_midrapidity.txt

./dNdqTdy_qT_gg.exe -NSamples 1000000 -etas 0.16 -M 1.5 -Q 0 -alphas 0.3 -a 0 -b 5 > ./results/Charm_production_as_a_function_of_qT/dCharmdqTdy_gg_mQ1.5_qSupp0_NSamples1million_etaovers0.16_alphas0.3_centrality0_5_midrapidity.txt;
./dNdqTdy_qT_qq.exe -NSamples 1000000 -etas 0.16 -M 1.5 -Q 1 -alphas 0.3 -a 0 -b 5 > ./results/Charm_production_as_a_function_of_qT/dCharmdqTdy_qq_mQ1.5_qSupp1_NSamples1million_etaovers0.16_alphas0.3_centrality0_5_midrapidity.txt

./dNdqTdy_qT_gg.exe -NSamples 1000000 -etas 0.32 -M 1.5 -Q 0 -alphas 0.3 -a 0 -b 5 > ./results/Charm_production_as_a_function_of_qT/dCharmdqTdy_gg_mQ1.5_qSupp0_NSamples1million_etaovers0.32_alphas0.3_centrality0_5_midrapidity.txt;
./dNdqTdy_qT_qq.exe -NSamples 1000000 -etas 0.32 -M 1.5 -Q 1 -alphas 0.3 -a 0 -b 5 > ./results/Charm_production_as_a_function_of_qT/dCharmdqTdy_qq_mQ1.5_qSupp1_NSamples1million_etaovers0.32_alphas0.3_centrality0_5_midrapidity.txt
