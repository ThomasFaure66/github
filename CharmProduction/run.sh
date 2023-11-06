#!/bin/bash
./dNdy_y_qq.exe -NSamples 10000000 -etas 0.16 -Q 1 > dCharmdy_qq_mQ1.5_qSupp1_NSamples10million_QMin3_QMax12_etaovers0.16.txt; 
./dNdy_y_qq.exe -NSamples 10000000 -etas 0.16 -Q 0 > dCharmdy_qq_mQ1.5_qSupp0_NSamples10million_QMin3_QMax12_etaovers0.16.txt;
./dNdy_y_qq.exe -NSamples 10000000 -etas 0.32 -Q 1 > dCharmdy_qq_mQ1.5_qSupp1_NSamples10million_QMin3_QMax12_etaovers0.32.txt; 
./dNdy_y_qq.exe -NSamples 10000000 -etas 0.32 -Q 0 > dCharmdy_qq_mQ1.5_qSupp0_NSamples10million_QMin3_QMax12_etaovers0.32.txt;
./dNdy_y_gg.exe -NSamples 10000000 -etas 0.16 -Q 0 > dCharmdy_gg_mQ1.5_qSupp0_NSamples10million_QMin3_QMax12_etaovers0.16.txt;
./dNdy_y_gg.exe -NSamples 10000000 -etas 0.32 -Q 0 > dCharmdy_gg_mQ1.5_qSupp0_NSamples10million_QMin3_QMax12_etaovers0.32.txt;
