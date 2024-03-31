#! /bin/sh

for x in .deploy_*; 
do 
    echo "deploying...$x";
    cp -av ajp_study_64.dll $x
done
#cp -v ajp_study*.dll  ~/.fxcm
#echo "deploying...lmax"
#cp -v ajp_study*.dll  ~/.lmax
#cp -v ajp_study*.dll  ~/.lmax2
#cp -v ajp_study*.dll  ~/.lmax3
