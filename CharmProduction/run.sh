#!/bin/bash
./dNdy_centrality_midrapidity.exe -NSamples 50000000 -etas 0.16 -M 1.5 -Q 0  > dCharmdy_centrality_gg_mQ1.5_qSupp0_NSamples50milliosn_QMin3_QMax12_etaovers0.16.txt;
./dNdy_centrality_midrapidity.exe -NSamples 50000000 -etas 0.32 -M 1.5 -Q 0  > dCharmdy_centrality_gg_mQ1.5_qSupp0_NSamples50millions_QMin3_QMax12_etaovers0.32.txt;

