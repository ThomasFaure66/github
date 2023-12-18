#!/bin/bash
./dNdy_y_qq.exe -NSamples 10000000 -etas 0.16 -M 1.6 -Q 0 -alphas 0.2395 -a 40 -b 50 > ./centrality/mQ1.6/etaovers0.16/dCharmdy_qq_mQ1.6_qSupp0_NSamples10million_QMin3.2_QMax12_etaovers0.16_alphas0.2395_centrality40_50.txt;
./dNdy_y_qq.exe -NSamples 10000000 -etas 0.32 -M 1.6 -Q 0 -alphas 0.2395 -a 40 -b 50 > ./centrality/mQ1.6/etaovers0.32/dCharmdy_qq_mQ1.6_qSupp0_NSamples10million_QMin3.2_QMax12_etaovers0.32_alphas0.2395_centrality40_50.txt;
./dNdy_y_qq.exe -NSamples 10000000 -etas 0.16 -M 1.4 -Q 0 -alphas 0.2703 -a 40 -b 50 > ./centrality/mQ1.4/etaovers0.16/dCharmdy_qq_mQ1.4_qSupp0_NSamples10million_QMin2.8_QMax12_etaovers0.16_alphas0.2703_centrality40_50.txt;
./dNdy_y_qq.exe -NSamples 10000000 -etas 0.32 -M 1.4 -Q 0 -alphas 0.2703 -a 40 -b 50 > ./centrality/mQ1.4/etaovers0.32/dCharmdy_qq_mQ1.4_qSupp0_NSamples10million_QMin2.8_QMax12_etaovers0.32_alphas0.2703_centrality40_50.txt;


