#include"dft.h"
#include"ap_int.h"
void dft(DTYPE real_sample[SIZE], DTYPE imag_sample[SIZE],DTYPE real_op[SIZE], DTYPE imag_op[SIZE])
{
#pragma HLS INTERFACE m_axi port=imag_op bundle=out depth=1024
#pragma HLS INTERFACE m_axi port=real_op bundle=out depth=1024
#pragma HLS INTERFACE m_axi port=imag_sample bundle=in depth=1024
#pragma HLS INTERFACE m_axi port=real_sample bundle=in depth=1024

#pragma HLS INTERFACE s_axilite port=return bundle=ctrl

	int i, j;
	DTYPE c;
	DTYPE s;
	DTYPE temp_real[SIZE]={0};
	DTYPE temp_imag[SIZE]={0};


	for (j = 0; j < SIZE; j += 1) {
		for (i = 0; i < SIZE; i += 1) {
#pragma HLS PIPELINE II=1
			c = cos_coefficients_table[(ap_uint<10>)(i * j)];
			s = sin_coefficients_table[(ap_uint<10>)(i * j)];
			temp_real[i] += (real_sample[j] * c - imag_sample[j]* s) ;
			temp_imag[i] += (real_sample[j] * s + imag_sample[j]* c) ;
		}
	}

	for (i = 0; i < SIZE; i += 1) {
#pragma HLS PIPELINE II=1
		real_op[i] = temp_real[i];
		imag_op[i] = temp_imag[i];
}

}

