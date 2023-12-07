#!/bin/bash
./dNdy_y_gg.exe -NSamples 10000000 -etas 0.16 -M 1.4 -Q 0 -alphas 0.2703 > dCharmdy_gg_mQ1.4_qSupp0_NSamples10million_QMin3_QMax12_etaovers0.16_alphas0.2703.txt;
./dNdy_y_gg.exe -NSamples 10000000 -etas 0.32 -M 1.4 -Q 0 -alphas 0.2703 > dCharmdy_gg_mQ1.4_qSupp0_NSamples10million_QMin3_QMax12_etaovers0.32_alphas0.2703.txt;
./dNdy_y_gg.exe -NSamples 10000000 -etas 0.16 -M 1.6 -Q 0 -alphas 0.2395 > dCharmdy_gg_mQ1.6_qSupp0_NSamples10million_QMin3_QMax12_etaovers0.16_alphas0.2395.txt;
./dNdy_y_gg.exe -NSamples 10000000 -etas 0.32 -M 1.6 -Q 0 -alphas 0.2395 > dCharmdy_gg_mQ1.6_qSupp0_NSamples10million_QMin3_QMax12_etaovers0.32_alphas0.2395.txt;
./dNdy_y_qq.exe -NSamples 10000000 -etas 0.16 -M 1.4 -Q 1 -alphas 0.2703 > dCharmdy_qq_mQ1.4_qSupp1_NSamples10million_QMin3_QMax12_etaovers0.16_alphas0.2703.txt;
./dNdy_y_qq.exe -NSamples 10000000 -etas 0.32 -M 1.4 -Q 1 -alphas 0.2703 > dCharmdy_qq_mQ1.4_qSupp1_NSamples10million_QMin3_QMax12_etaovers0.32_alphas0.2703.txt;
./dNdy_y_qq.exe -NSamples 10000000 -etas 0.16 -M 1.6 -Q 1 -alphas 0.2395 > dCharmdy_qq_mQ1.6_qSupp1_NSamples10million_QMin3_QMax12_etaovers0.16_alphas0.2395.txt;
./dNdy_y_qq.exe -NSamples 10000000 -etas 0.32 -M 1.6 -Q 1 -alphas 0.2395 > dCharmdy_qq_mQ1.6_qSupp1_NSamples10million_QMin3_QMax12_etaovers0.32_alphas0.2395.txt;


