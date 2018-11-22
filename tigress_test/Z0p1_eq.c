#include <stdio.h>
#include "cool_tigress.h"

int main() {
  //output directory TODO: mkdir
	const char dir[] 
	 =
   "/Users/munangong/chemistry_Athena/PDR_cvode/tigress/out_Z0p1_eq/";
  //physical parameters TODO: check this, Setdvdr(true) SetNCOeffGlobal(false)
  const Real dvdr = 3 * 3e-14;
  const Real Z = 0.1;
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
 12770.35589596, 12699.83775376, 12652.40582965, 12570.48303645,
 12527.82776653, 12464.19655969, 12414.52171601, 12378.57928214,
 12339.33944908, 12300.86455991, 12264.63359394, 12233.81314747,
 12201.6064722 , 12171.28092107, 12142.80174273, 12116.49360389,
 12088.66587642, 12064.30489821, 12036.48954929, 12026.47893307,
 11997.46809566, 11959.82261256, 11942.81379164, 11925.15180841,
 11911.86136051, 11882.01952326, 11858.7654551 , 11833.1867696 ,
 11808.60830186, 11782.79972659, 11756.15167684, 11728.86898754,
 11700.79076814, 11672.1567462 , 11642.96445552, 11613.29546052,
 11583.09384453, 11552.4680633 , 11512.43806832, 11488.41378808,
 11453.95254251, 11422.60253859, 11393.46880943, 11360.991249  ,
 11327.72924277, 11294.15065121, 11259.57492567, 11225.95032492,
 11191.22853544, 11156.30357358, 11120.79661345, 11082.12686736,
 11046.61372452, 11012.2185106 , 10977.61959872, 10941.65019093,
 10904.75975768, 10868.25469319, 10832.04161226, 10794.71953309,
 10756.98154345, 10719.88958344, 10682.50537833, 10644.58239551,
 10604.44690591, 10562.84131725, 10523.70209183, 10487.68477022,
 10451.43493141, 10412.46023776, 10373.96777394, 10337.18526992,
 10298.08741682, 10259.41776831, 10222.27784537, 10182.57811402,
 10143.17587849, 10104.1425498 , 10064.31623954, 10024.6603204 ,
  9984.4318117 ,  9943.8059876 ,  9902.72784525,  9862.4439923 ,
  9820.76784733,  9779.19929882,  9737.04484323,  9696.82079962,
  9654.99314707,  9611.99820441,  9568.36389985,  9523.26547856,
  9478.56386791,  9432.09139391,  9384.72630061,  9336.10582539,
  9285.84944535,  9233.95972963,  9179.63117605,  9123.30583525,
  9063.7276373 ,  9001.33501504,  8934.04667589,  8861.84946098,
  8783.03102244,  8695.05696005,  8595.75308514,  8482.9563979 ,
  8360.04877045,  8151.71781157,  8019.57479662,  7636.1718802 ,
  7092.73103375,  6149.10167823,  5184.7578258 ,  4298.47626992,
  3562.95263793,  2893.88541747,  2318.72744784,  1847.35551456,
  1483.43261759,  1189.10343268,   957.85467725,   788.37479161,
   645.79017639,   546.76451445,   457.31059703,   398.15976053,
   347.61264893,   306.15419781,   273.20774819,   242.38195733,
   217.94279588,   197.23059096,   179.52851306,   164.28133919,
   151.04304045,   138.95525393,   128.98723056,   119.86381916,
   112.20792119,   105.0114375 ,    98.5595304 ,    92.73836722,
    87.48231506,    82.71694062,    78.38094256,    74.42615751,
    70.81317955,    67.49820111,    64.45933935,    61.6571541 ,
    59.08290749,    56.7146951 ,    54.50867066,    52.46485613,
    50.57449478,    48.83321714,    47.21032408,    45.70582852,
    44.31096609,    43.01170478,    41.80717643,    40.68949   ,
    39.65294788,    38.69229061,    37.80357435,    36.98241605,
    36.22618753,    35.53094368
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
