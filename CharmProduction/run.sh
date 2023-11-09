#!/bin/bash
./dNdy_y_gg.exe -NSamples 5000000 -etas 0.16 -M 1.5 -Q 0 > dCharmdy_gg_mQ1.5_qSupp0_NSamples5million_QMin3_QMax12_etaovers0.16.txt;
./dNdy_y_gg.exe -NSamples 5000000 -etas 0.16 -M 1.27 -Q 0 > dCharmdy_gg_mQ1.27_qSupp0_NSamples5million_QMin3_QMax12_etaovers0.16.txt;
./dNdy_y_gg.exe -NSamples 5000000 -etas 0.16 -M 1.67 -Q 0 > dCharmdy_gg_mQ1.67_qSupp0_NSamples5million_QMin3_QMax12_etaovers0.16.txt;
