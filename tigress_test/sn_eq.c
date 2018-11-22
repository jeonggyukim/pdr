#include <stdio.h>
#include "cool_tigress.h"

int main() {
  //output directory TODO: mkdir
	const char dir[] 
	 =
   "/Users/munangong/chemistry_Athena/PDR_cvode/tigress/out_sn_eq/";
  //physical parameters TODO: check this, Setdvdr(true) SetNCOeffGlobal(false)
  const Real dvdr = 3 * 3e-14;
  const Real Z = 1;
  const Real xi_CR = 2e-16;
  const Real G0 = 1.;

  const Real G_PE = G0;
  const Real G_CI = G0;
  const Real G_CO = G0;
  const Real G_H2 = 0.;
  
  const int ngrid = 170;
  Real nH_arr[ngrid] = {
 1.0000e-04, 1.1000e-04, 1.2100e-04, 1.3310e-04, 1.4641e-04, 1.6105e-04,
 1.7716e-04, 1.9487e-04, 2.1436e-04, 2.3579e-04, 2.5937e-04, 2.8531e-04,
 3.1384e-04, 3.4523e-04, 3.7975e-04, 4.1772e-04, 4.5950e-04, 5.0545e-04,
 5.5599e-04, 6.1159e-04, 6.7275e-04, 7.4002e-04, 8.1403e-04, 8.9543e-04,
 9.8497e-04, 1.0835e-03, 1.1918e-03, 1.3110e-03, 1.4421e-03, 1.5863e-03,
 1.7449e-03, 1.9194e-03, 2.1114e-03, 2.3225e-03, 2.5548e-03, 2.8102e-03,
 3.0913e-03, 3.4004e-03, 3.7404e-03, 4.1145e-03, 4.5259e-03, 4.9785e-03,
 5.4764e-03, 6.0240e-03, 6.6264e-03, 7.2890e-03, 8.0180e-03, 8.8197e-03,
 9.7017e-03, 1.0672e-02, 1.1739e-02, 1.2913e-02, 1.4204e-02, 1.5625e-02,
 1.7187e-02, 1.8906e-02, 2.0797e-02, 2.2876e-02, 2.5164e-02, 2.7680e-02,
 3.0448e-02, 3.3493e-02, 3.6842e-02, 4.0527e-02, 4.4579e-02, 4.9037e-02,
 5.3941e-02, 5.9335e-02, 6.5268e-02, 7.1795e-02, 7.8975e-02, 8.6872e-02,
 9.5559e-02, 1.0512e-01, 1.1563e-01, 1.2719e-01, 1.3991e-01, 1.5390e-01,
 1.6929e-01, 1.8622e-01, 2.0484e-01, 2.2532e-01, 2.4786e-01, 2.7264e-01,
 2.9991e-01, 3.2990e-01, 3.6289e-01, 3.9918e-01, 4.3909e-01, 4.8300e-01,
 5.3130e-01, 5.8443e-01, 6.4288e-01, 7.0716e-01, 7.7788e-01, 8.5567e-01,
 9.4123e-01, 1.0354e+00, 1.1389e+00, 1.2528e+00, 1.3781e+00, 1.5159e+00,
 1.6675e+00, 1.8342e+00, 2.0176e+00, 2.2194e+00, 2.4413e+00, 2.6855e+00,
 2.9540e+00, 3.2494e+00, 3.5743e+00, 3.9318e+00, 4.3249e+00, 4.7574e+00,
 5.2332e+00, 5.7565e+00, 6.3322e+00, 6.9654e+00, 7.6619e+00, 8.4281e+00,
 9.2709e+00, 1.0198e+01, 1.1218e+01, 1.2340e+01, 1.3574e+01, 1.4931e+01,
 1.6424e+01, 1.8066e+01, 1.9873e+01, 2.1860e+01, 2.4046e+01, 2.6451e+01,
 2.9096e+01, 3.2006e+01, 3.5206e+01, 3.8727e+01, 4.2600e+01, 4.6860e+01,
 5.1545e+01, 5.6700e+01, 6.2370e+01, 6.8607e+01, 7.5468e+01, 8.3015e+01,
 9.1316e+01, 1.0045e+02, 1.1049e+02, 1.2154e+02, 1.3370e+02, 1.4707e+02,
 1.6177e+02, 1.7795e+02, 1.9574e+02, 2.1532e+02, 2.3685e+02, 2.6054e+02,
 2.8659e+02, 3.1525e+02, 3.4677e+02, 3.8145e+02, 4.1959e+02, 4.6155e+02,
 5.0771e+02, 5.5848e+02, 6.1433e+02, 6.7576e+02, 7.4334e+02, 8.1767e+02,
 8.9944e+02, 9.8938e+02
  };       
  Real T_arr[ngrid] = {
 12554.05477813, 12474.79446041, 12426.48489844, 12335.21603277,
 12273.16396412, 12213.56228183, 12155.88302497, 12108.36140131,
 12073.22722194, 12034.58687339, 12001.61055892, 11957.74344204,
 11940.05615286, 11914.25394726, 11887.34259238, 11864.91358605,
 11852.74418101, 11821.32532331, 11817.21397061, 11798.94662312,
 11758.9114038 , 11740.36724322, 11748.25428697, 11716.8758365 ,
 11702.09292004, 11693.29164239, 11674.17410723, 11653.35869187,
 11632.62030297, 11611.44775587, 11587.93941167, 11566.22523093,
 11542.7093892 , 11519.23715704, 11494.78097177, 11469.63546961,
 11444.06090394, 11418.23585563, 11385.38146093, 11362.49612691,
 11336.36329716, 11308.67015304, 11281.73883835, 11253.63211632,
 11224.84957055, 11195.89627781, 11166.16197975, 11136.26216179,
 11106.88147889, 11076.29880124, 11045.82866267, 11014.88057999,
 10982.4081359 , 10950.71554687, 10919.39701977, 10887.81289005,
 10856.13639492, 10824.69863978, 10791.09294608, 10759.67327794,
 10727.2617332 , 10693.99399095, 10660.64217498, 10627.2321385 ,
 10593.11042573, 10558.6726067 , 10521.9552942 , 10488.61089257,
 10452.94895007, 10416.99297677, 10380.13255424, 10343.61007788,
 10306.19147508, 10267.94735956, 10228.88264789, 10188.49450273,
 10146.96970046, 10104.01242835, 10059.57701839, 10013.04655887,
  9964.80111972,  9914.16486818,  9860.34303048,  9802.86310022,
  9742.28965725,  9677.38676484,  9606.2560569 ,  9529.13811349,
  9441.74594614,  9343.69465943,  9232.89823472,  9103.47801608,
  8949.90539108,  8761.84870722,  8527.28397101,  8223.39187091,
  7826.39187535,  7328.90271925,  6755.66280747,  6157.76389898,
  5582.93318453,  5001.54557728,  4449.01831095,  3918.94257333,
  3423.62045517,  2969.72505052,  2560.07758628,  2194.04150311,
  1865.33596371,  1583.10156634,  1345.16676835,  1146.01429305,
   976.90350441,   836.38252811,   719.88466035,   623.6111537 ,
   544.05481394,   478.26645673,   422.31979741,   375.51620955,
   335.99642375,   302.35322637,   273.50570754,   248.6165843 ,
   227.01400477,   208.15682298,   191.59089238,   176.98886314,
   164.02728442,   152.49650544,   142.17358575,   132.90555339,
   124.54809487,   116.99628104,   110.14512044,   103.91587969,
    98.23855543,    93.05187495,    88.29895111,    83.93600259,
    79.92363162,    76.23119749,    72.81927485,    69.67036189,
    66.74940322,    64.03888235,    61.52566801,    59.17907077,
    56.99472605,    54.95948929,    53.05143782,    51.26619843,
    49.59500769,    48.02471287,    46.55532469,    45.1736876 ,
    43.87717745,    42.66097525,    41.51982216,    40.45065433,
    39.44952936,    38.51425974,    37.64134258,    36.82946933,
    36.07557575,    35.37879295,    34.73781423,    34.15045495,
    33.61672775,    33.13532822
  };

  char file_out[100];
  FILE *pf_out = NULL;
	sprintf(file_out, "%seq.dat", dir);
	pf_out = fopen(file_out, "w+");
  Real nH, T;
  Real x_e, x_HI, x_H2, x_Cplus, x_CI, x_CO, x_OI;
  Real h_CR, h_PE, h_H2pump, h_tot;
  Real c_Lya, c_OI, c_CII, c_CI, c_CO, c_Rec, c_tot;

	for (int i=0; i < ngrid; i++) {
    nH = nH_arr[i];
    T = T_arr[i];
    get_abundances(nH, T, dvdr, Z, xi_CR, G_PE, G_CI, G_CO, G_H2,
                   &x_e, &x_HI, &x_H2, &x_Cplus, &x_CI, &x_CO, &x_OI);
    h_tot = heating(x_e, x_HI, x_H2, nH, T, Z, xi_CR, G_PE, G_H2);
    c_tot = cooling(x_e, x_HI, x_H2, x_Cplus, x_CI, x_CO, x_OI, 
                    nH, T, dvdr, Z, G_PE);
    h_PE = heatingPE(x_e, nH, T, Z, G_PE);
    h_CR = heatingCR(x_e, x_HI, x_H2, nH, xi_CR);
    h_H2pump =  heatingH2pump(x_HI, x_H2, nH, T, G_H2);
    c_Lya = coolingLya(x_e, x_HI, nH, T);
    c_OI = coolingOI(x_e, x_OI, x_HI, x_H2, nH, T);
    c_CII = coolingCII(x_e, x_Cplus, x_HI, x_H2, nH, T);
    c_CI = coolingCI(x_e, x_CI, x_HI, x_H2, nH, T);
    c_CO = coolingCO(x_e, x_CO, x_HI, x_H2, nH, T, dvdr);
    c_Rec = coolingRec(x_e, nH, T, Z, G_PE);
    fprintf(pf_out, "%12.4e  %12.4e  %12.4e  %12.4e  %12.4e  %12.4e  %12.4e  %12.4e  %12.4e  %12.4e  %12.4e  %12.4e  %12.4e  %12.4e  %12.4e  %12.4e %12.4e %12.4e\n",
           x_e, x_HI, x_H2, x_Cplus, x_CI, x_CO, x_OI, h_CR, h_PE, h_H2pump, h_tot,
           c_Lya, c_OI, c_CII, c_CI, c_CO, c_Rec, c_tot);
  }
  fclose(pf_out);

  return 0;
}
