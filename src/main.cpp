#include <iostream>
#include "../include/solve_dlt.h"

int main()
{
	
	double dst_pts[4][2] = { {0, 0}, {8.000000,  0.000000}, {0.000000,   8.000000}, {8.000000,   8.000000} };
	double src_pts[4][2] = { {46.433670, -540.986450}, {56.608696,  -533.575256}, {38.550194, - 531.213562}, {48.718105, - 523.787170} };
	//double src_pts[4][2] = { {0, 0}, {8.000000,  0.000000}, {0.000000,   8.000000}, {8.000000,   8.000000} };

	solve_dlt_plu(src_pts, dst_pts);
	solve_dlt_gaussian(src_pts, dst_pts);
}
