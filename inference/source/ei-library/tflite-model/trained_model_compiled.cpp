/* Generated by Edge Impulse
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
// Generated on: 19.12.2022 11:18:19

#include <stdio.h>
#include <stdlib.h>
#include "edge-impulse-sdk/tensorflow/lite/c/builtin_op_data.h"
#include "edge-impulse-sdk/tensorflow/lite/c/common.h"
#include "edge-impulse-sdk/tensorflow/lite/micro/micro_mutable_op_resolver.h"
#include "edge-impulse-sdk/porting/ei_classifier_porting.h"

#if EI_CLASSIFIER_PRINT_STATE
#if defined(__cplusplus) && EI_C_LINKAGE == 1
extern "C" {
    extern void ei_printf(const char *format, ...);
}
#else
extern void ei_printf(const char *format, ...);
#endif
#endif

#if defined __GNUC__
#define ALIGN(X) __attribute__((aligned(X)))
#elif defined _MSC_VER
#define ALIGN(X) __declspec(align(X))
#elif defined __TASKING__
#define ALIGN(X) __align(X)
#endif

#ifndef EI_MAX_SCRATCH_BUFFER_COUNT
#define EI_MAX_SCRATCH_BUFFER_COUNT 4
#endif // EI_MAX_SCRATCH_BUFFER_COUNT

#ifndef EI_MAX_OVERFLOW_BUFFER_COUNT
#define EI_MAX_OVERFLOW_BUFFER_COUNT 10
#endif // EI_MAX_OVERFLOW_BUFFER_COUNT

using namespace tflite;
using namespace tflite::ops;
using namespace tflite::ops::micro;

namespace {

constexpr int kTensorArenaSize = 14288;

#if defined(EI_CLASSIFIER_ALLOCATION_STATIC)
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#elif defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX)
#pragma Bss(".tensor_arena")
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#pragma Bss()
#elif defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX_GNU)
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16) __attribute__((section(".tensor_arena")));
#else
#define EI_CLASSIFIER_ALLOCATION_HEAP 1
uint8_t* tensor_arena = NULL;
#endif

static uint8_t* tensor_boundary;
static uint8_t* current_location;

template <int SZ, class T> struct TfArray {
  int sz; T elem[SZ];
};
enum used_operators_e {
  OP_RESHAPE, OP_CONV_2D, OP_MAX_POOL_2D, OP_FULLY_CONNECTED, OP_SOFTMAX,  OP_LAST
};
struct TensorInfo_t { // subset of TfLiteTensor used for initialization from constant memory
  TfLiteAllocationType allocation_type;
  TfLiteType type;
  void* data;
  TfLiteIntArray* dims;
  size_t bytes;
  TfLiteQuantization quantization;
};
struct NodeInfo_t { // subset of TfLiteNode used for initialization from constant memory
  struct TfLiteIntArray* inputs;
  struct TfLiteIntArray* outputs;
  void* builtin_data;
  used_operators_e used_op_index;
};

TfLiteContext ctx{};
TfLiteTensor tflTensors[23];
TfLiteEvalTensor tflEvalTensors[23];
TfLiteRegistration registrations[OP_LAST];
TfLiteNode tflNodes[11];

const TfArray<2, int> tensor_dimension0 = { 2, { 1,6435 } };
const TfArray<1, float> quant0_scale = { 1, { 0.0029847295954823494, } };
const TfArray<1, int> quant0_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant0 = { (TfLiteFloatArray*)&quant0_scale, (TfLiteIntArray*)&quant0_zero, 0 };
const ALIGN(16) int32_t tensor_data1[4] = { 1, 1, 99, 65, };
const TfArray<1, int> tensor_dimension1 = { 1, { 4 } };
const ALIGN(16) int32_t tensor_data2[4] = { 1, 99, 1, 8, };
const TfArray<1, int> tensor_dimension2 = { 1, { 4 } };
const ALIGN(16) int32_t tensor_data3[4] = { 1, 1, 50, 8, };
const TfArray<1, int> tensor_dimension3 = { 1, { 4 } };
const ALIGN(16) int32_t tensor_data4[4] = { 1, 50, 1, 16, };
const TfArray<1, int> tensor_dimension4 = { 1, { 4 } };
const ALIGN(8) int32_t tensor_data5[2] = { -1, 400, };
const TfArray<1, int> tensor_dimension5 = { 1, { 2 } };
const ALIGN(16) int8_t tensor_data6[8*1*3*65] = { 
  /* [0][0][][] */ -79,39,-80,68,82,-62,50,102,59,-63,-15,75,1,111,-2,-115,-43,-11,-40,-42,-77,81,-17,13,102,106,-104,21,36,-25,-102,-23,-68,-19,109,76,-85,-80,-21,-117,108,41,116,-10,-10,55,49,-103,35,7,127,14,-75,-68,-48,113,10,-19,59,-11,-81,-76,57,-34,7, -103,-97,-24,46,34,-44,89,112,-1,-47,-71,-40,8,-60,-38,22,-49,-10,63,94,34,78,28,-43,-63,-58,-18,-10,58,-13,32,-96,-89,-58,104,77,57,30,-92,24,74,-79,-65,-30,86,-92,-32,49,-6,-48,-25,88,57,85,-48,-51,-79,108,37,47,56,-113,99,-102,-40, -94,24,-19,-62,-87,15,-33,-28,-24,76,13,-95,-93,-87,2,-16,66,7,32,46,13,-19,-49,24,-65,-58,-60,-26,-65,-15,-53,96,-27,-7,70,54,-112,-17,-73,95,-2,4,5,-109,-92,96,43,-43,-8,-91,-11,50,74,23,-11,-20,-79,27,42,78,67,48,91,28,34, 
  /* [1][0][][] */ 13,68,6,-35,17,3,3,-72,-23,32,-2,-61,81,44,-10,31,4,6,-2,-12,-56,43,-17,-84,49,39,13,-3,-26,89,-13,-39,17,-59,-40,-40,15,-6,50,-2,-36,40,18,37,-42,43,56,-44,82,45,-4,82,-15,-58,-35,-34,14,16,-10,-38,14,65,54,56,45, 25,39,-9,-1,41,-15,84,93,57,-11,66,-36,73,98,117,-21,24,26,84,60,-39,45,-2,59,45,-7,10,97,52,8,72,17,-45,-30,-40,3,-21,-25,48,-13,29,49,-13,36,-1,-33,37,80,81,50,50,108,84,30,0,18,2,24,26,63,64,10,-21,34,-16, -47,29,24,30,39,116,98,127,97,87,-12,-4,44,34,120,37,52,52,42,7,94,-2,102,32,43,-3,111,88,47,20,12,80,84,17,79,70,115,7,67,72,80,78,41,-28,67,-43,49,80,4,-43,-26,9,-44,-32,26,58,41,31,-70,-42,-41,57,-57,72,39, 
  /* [2][0][][] */ -11,36,38,127,14,19,4,76,23,11,-4,114,90,61,-2,-65,36,2,-26,48,-50,-11,-9,-13,-34,-26,30,-57,-44,-1,-43,13,47,-64,-35,45,30,-36,36,17,-45,-11,4,14,-35,42,-17,-57,-20,-47,60,1,57,-11,-8,-15,72,-23,-10,-2,-38,-9,-7,11,35, -10,37,120,79,59,50,73,64,34,44,-1,104,80,36,56,2,0,85,30,78,-1,108,85,9,-15,14,-4,63,70,49,13,17,32,10,18,85,21,10,25,-27,24,87,68,15,-15,24,55,74,52,41,82,47,8,68,-33,93,7,59,43,22,80,81,36,52,22, -3,30,31,54,100,108,106,87,89,37,97,67,69,89,63,75,-2,-4,69,101,82,35,70,36,87,-7,72,105,27,35,82,9,87,2,46,32,101,10,38,82,69,-15,14,39,1,81,31,67,78,39,18,7,41,62,34,25,40,73,18,23,-2,-22,5,67,22, 
  /* [3][0][][] */ -58,122,48,127,119,9,53,100,44,74,69,58,70,109,108,-3,71,46,-12,17,56,98,104,-5,80,29,20,17,7,62,62,60,34,16,27,56,15,88,32,-7,7,47,45,4,91,91,91,58,41,92,-20,61,15,10,19,102,26,98,15,-32,31,72,83,0,19, 1,47,58,76,78,101,7,-8,88,55,44,-5,-4,107,-6,34,-1,92,-3,65,18,78,45,52,17,37,79,74,43,59,-14,86,54,48,68,41,8,-20,-21,-6,7,-47,79,-18,7,-21,-20,-7,68,72,81,-28,17,85,74,28,2,-25,29,51,61,-4,72,69,42, -31,109,36,111,73,-7,113,35,59,80,61,81,81,88,11,79,-35,23,-12,-26,-34,20,56,44,-26,-10,45,25,52,11,-6,31,-17,27,32,14,89,77,-21,-46,-52,20,23,4,4,34,-26,52,39,-17,-11,13,16,41,-19,33,-4,-54,57,28,-40,-39,33,38,-15, 
  /* [4][0][][] */ -23,100,27,97,127,28,75,75,1,70,84,115,71,104,66,7,76,3,44,33,64,53,75,7,68,61,64,27,111,-6,41,10,104,15,-10,0,106,75,26,80,25,88,32,43,58,76,-8,14,42,23,56,-10,5,31,-15,24,94,-25,11,51,26,-4,28,97,60, 29,24,94,82,73,123,117,48,58,121,65,109,1,88,37,14,28,92,63,81,5,-14,32,34,29,63,-4,74,55,8,-10,-1,19,36,57,75,37,88,-19,80,-21,22,61,58,-34,-53,29,65,64,55,55,58,58,49,50,43,5,-3,86,28,29,-14,74,-14,67, -15,50,120,27,89,111,117,83,74,71,90,95,28,74,48,88,70,21,58,9,-3,9,36,63,-18,-25,36,21,90,113,80,17,-11,69,-1,55,103,69,23,21,-10,74,-15,-31,90,-2,-20,-6,-20,-49,-5,56,24,76,-9,52,-4,65,118,-51,37,10,61,90,48, 
  /* [5][0][][] */ 12,76,81,79,70,54,42,34,81,10,49,67,116,62,29,61,81,95,25,93,46,70,94,34,50,16,107,15,28,79,102,74,-5,28,12,80,46,11,28,28,22,16,5,100,29,85,61,80,3,90,25,8,15,16,15,32,71,5,96,-19,-3,-12,26,17,53, -4,103,91,31,118,92,110,62,89,85,81,-1,112,81,68,50,74,34,10,65,28,101,113,86,-8,37,89,80,80,67,99,92,4,86,58,55,38,40,26,77,92,76,49,84,80,30,20,0,6,99,3,29,52,19,62,19,38,6,82,-18,24,0,87,120,74, -32,65,42,127,122,60,106,61,10,22,74,72,120,41,43,100,4,6,71,6,52,62,69,32,15,52,88,73,20,98,65,43,13,79,26,85,77,10,17,3,32,-21,41,65,58,-13,79,64,32,72,1,33,6,35,-27,6,83,41,51,50,46,40,-14,98,25, 
  /* [6][0][][] */ -25,31,25,30,59,23,92,24,-22,23,-35,61,19,37,-5,-7,12,-24,-2,-17,-16,-1,0,14,9,-25,-9,-13,-3,2,-55,-58,-19,0,-38,41,-6,-68,-21,16,-22,-7,22,18,-35,-15,-2,-55,16,-17,-4,47,8,-2,-93,4,-11,-6,-67,15,-15,0,29,31,-12, -32,71,81,127,81,46,81,14,-4,35,29,15,59,-5,12,-32,51,9,-28,2,-22,70,48,-15,8,2,-6,-3,10,-19,7,-16,-41,-31,21,21,54,-23,-4,-28,-59,56,14,62,3,57,-34,10,57,20,30,55,-29,16,-5,12,-11,-54,-56,5,-30,-39,-10,14,-55, 19,121,68,78,77,23,78,81,24,-12,-33,1,23,55,31,7,19,60,86,25,32,-26,-13,29,13,11,-34,-6,-29,18,3,22,19,-8,-15,33,45,24,-27,30,-19,11,57,-6,33,-51,36,15,-30,-35,-38,51,29,-12,-64,-53,16,27,-6,-75,-13,5,-82,-3,-17, 
  /* [7][0][][] */ -23,21,39,91,86,12,28,69,30,72,-9,33,63,110,35,36,6,45,64,-16,89,24,93,87,82,51,-9,-38,78,67,-17,21,62,-17,28,14,97,-4,61,38,14,13,21,80,-31,35,87,70,87,41,0,44,-31,24,63,-41,31,12,41,-24,11,4,93,11,81, 33,101,44,109,113,73,63,70,94,-10,-9,-9,99,70,-3,-20,-12,-16,17,72,45,94,96,3,45,-27,19,23,76,1,72,46,23,15,21,65,104,27,22,10,76,74,76,-9,61,-8,19,-12,33,43,70,-17,-23,45,77,25,1,66,32,-32,87,13,13,36,64, -42,84,122,127,43,90,75,27,32,59,48,42,55,74,-6,33,38,-4,65,15,23,87,23,31,-4,42,-26,63,27,20,2,43,59,65,65,72,10,-6,0,70,55,-8,78,63,-8,-21,79,0,-24,5,20,23,0,80,-14,32,4,-5,48,41,34,-4,47,72,41, 
};
const TfArray<4, int> tensor_dimension6 = { 4, { 8,1,3,65 } };
const TfArray<8, float> quant6_scale = { 8, { 0.0014494308270514011, 0.0023662243038415909, 0.0028254645876586437, 0.0026432550512254238, 0.0024793688207864761, 0.0028113829903304577, 0.0038409193512052298, 0.002622668631374836, } };
const TfArray<8, int> quant6_zero = { 8, { 0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant6 = { (TfLiteFloatArray*)&quant6_scale, (TfLiteIntArray*)&quant6_zero, 0 };
const ALIGN(16) int32_t tensor_data7[8] = { -2792, -7471, -5878, 12876, -9465, -6153, 4077, -4918, };
const TfArray<1, int> tensor_dimension7 = { 1, { 8 } };
const TfArray<8, float> quant7_scale = { 8, { 4.3261588871246204e-06, 7.0625396801915485e-06, 8.4332477854331955e-06, 7.8894017860875465e-06, 7.4002455221489072e-06, 8.391218216274865e-06, 1.1464105227787513e-05, 7.8279563240357675e-06, } };
const TfArray<8, int> quant7_zero = { 8, { 0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant7 = { (TfLiteFloatArray*)&quant7_scale, (TfLiteIntArray*)&quant7_zero, 0 };
const ALIGN(16) int8_t tensor_data8[16*1*3*8] = { 
  /* [0][0][][] */ -51,-57,-85,32,-75,-127,96,-93, 87,27,-48,-23,-14,-64,12,-44, 63,-5,113,99,80,126,95,56, 
  /* [1][0][][] */ -51,71,-29,-8,31,19,127,94, -81,-27,16,45,-34,69,40,39, 40,89,48,121,54,-21,70,21, 
  /* [2][0][][] */ -74,93,-4,1,46,112,26,-20, 54,49,34,127,65,20,61,107, -28,-15,9,-8,66,77,123,67, 
  /* [3][0][][] */ -33,71,51,60,17,120,14,127, -5,29,59,125,96,118,77,50, 16,-24,88,67,15,103,121,23, 
  /* [4][0][][] */ 6,11,78,-29,21,-105,99,38, -113,8,57,-24,-33,-86,66,126, 112,-55,123,127,-29,117,106,117, 
  /* [5][0][][] */ 52,-18,-44,82,103,127,27,124, -62,-97,-52,77,41,79,-56,-24, -43,22,67,25,58,30,-3,70, 
  /* [6][0][][] */ 63,41,77,127,38,81,8,98, 45,1,63,-28,17,104,27,-57, -46,76,27,-4,68,-38,51,-6, 
  /* [7][0][][] */ -45,-75,80,18,-56,77,127,29, 44,-35,-14,42,112,71,73,-74, -97,-78,-37,36,79,22,18,77, 
  /* [8][0][][] */ -55,-7,92,9,7,23,3,102, -7,-16,-34,107,87,51,63,87, 4,-34,87,-30,15,-10,127,68, 
  /* [9][0][][] */ -22,-10,52,33,83,92,10,32, -11,102,100,-10,63,71,127,14, -51,38,86,54,52,31,98,65, 
  /* [10][0][][] */ -18,1,45,3,-21,-105,-104,11, 110,2,-12,24,80,18,79,-125, -3,-20,-24,-127,-74,-37,46,-15, 
  /* [11][0][][] */ 9,-2,42,80,22,-24,87,41, -13,90,83,12,-5,32,61,122, 32,65,-24,101,113,-13,127,79, 
  /* [12][0][][] */ 60,7,-59,15,58,89,127,-19, -37,-12,115,28,74,-31,66,82, -26,87,16,7,22,106,99,101, 
  /* [13][0][][] */ 2,7,-82,92,-114,-121,-8,-127, -54,-20,36,-16,73,2,-110,-57, -19,-77,-66,80,9,32,98,-38, 
  /* [14][0][][] */ -15,33,95,66,-77,103,17,-60, 22,103,-4,61,115,33,102,4, -61,127,116,-16,57,82,72,41, 
  /* [15][0][][] */ 57,61,8,78,-22,-61,-13,23, -5,23,22,-34,85,77,127,40, 51,-16,87,-30,3,53,39,68, 
};
const TfArray<4, int> tensor_dimension8 = { 4, { 16,1,3,8 } };
const TfArray<16, float> quant8_scale = { 16, { 0.0031639181543141603, 0.0032471928279846907, 0.0035907570272684097, 0.0036035319790244102, 0.0026631285436451435, 0.0031934420112520456, 0.003371774684637785, 0.0028802724555134773, 0.0038730313535779715, 0.004395162221044302, 0.0025532655417919159, 0.003802592633292079, 0.0032613049261271954, 0.002874796511605382, 0.0031479629687964916, 0.0034715705551207066, } };
const TfArray<16, int> quant8_zero = { 16, { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant8 = { (TfLiteFloatArray*)&quant8_scale, (TfLiteIntArray*)&quant8_zero, 0 };
const ALIGN(16) int32_t tensor_data9[16] = { 3187, -860, -966, 1977, -128, -1122, 755, -526, -513, -1391, -2539, 987, 49, 3827, -462, 767, };
const TfArray<1, int> tensor_dimension9 = { 1, { 16 } };
const TfArray<16, float> quant9_scale = { 16, { 3.4013133699772879e-05, 3.4908363886643201e-05, 3.8601789128733799e-05, 3.8739122828701511e-05, 2.8629485314013436e-05, 3.4330525522818789e-05, 3.6247660318622366e-05, 3.0963852623244748e-05, 4.1636329115135595e-05, 4.724940299638547e-05, 2.7448422770248726e-05, 4.0879091102397069e-05, 3.506007487885654e-05, 3.0904982850188389e-05, 3.3841610274976119e-05, 3.7320496630854905e-05, } };
const TfArray<16, int> quant9_zero = { 16, { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant9 = { (TfLiteFloatArray*)&quant9_scale, (TfLiteIntArray*)&quant9_zero, 0 };
const ALIGN(16) int8_t tensor_data10[2*400] = { 
  -85, -110, -46, -93, -75, -79, 17, 11, -8, -33, 5, -27, -100, 58, -57, -64, -65, -80, -70, -107, -59, -30, -68, -44, -109, -118, 6, -117, -30, 16, -76, -24, -3, -49, -106, -114, -69, -118, -28, -39, -112, -67, -24, -65, -109, 28, -37, -78, 37, -121, -44, -68, -39, -40, -103, -65, -54, -127, 0, -73, -66, 29, -79, -53, 34, 29, 2, -37, 56, -46, 3, 48, -15, -29, -22, 32, -4, 55, -6, -1, -14, 13, 50, -12, 5, 7, 29, -17, 16, -12, -14, -3, 3, 42, -2, 66, 65, 43, 42, 57, 40, 28, 80, -6, 19, 39, 3, 67, -6, 44, -28, 31, 69, 28, -9, 60, 7, -2, -6, -5, 56, -39, 0, 74, 21, 54, 37, 87, 56, 22, 38, 74, 43, 45, 43, 80, 56, -38, 41, 31, 79, 58, 21, 22, -1, 2, 49, 78, 39, 27, -11, 25, 32, -31, 9, 83, 0, 45, 44, 14, 32, 39, 23, 46, 5, 16, -22, 72, -31, -23, 10, 29, -21, 71, 48, 24, 60, 92, -3, 54, 0, 13, 65, 3, -27, -1, -16, 36, 2, 37, 26, 10, -14, 4, -16, 9, 47, 81, 53, 58, 80, 11, -26, 39, 98, 36, -34, 6, 85, 7, 37, 75, -21, 46, 12, 74, -23, -33, 5, 19, 13, 78, 37, 54, 82, -31, 47, 49, 55, 55, 27, -4, 58, 28, -30, 28, 35, 4, 23, 43, 27, 40, 0, 56, 17, 31, 10, -31, -22, 16, 0, 11, 25, 57, 19, -3, 73, 17, 29, 82, -6, 83, 53, -21, -16, 15, -31, -7, -17, -12, 62, 15, 75, 32, -40, 48, -23, 29, 56, 4, -11, 0, 25, 58, 20, 27, -3, 74, 22, 55, 35, 66, -28, 34, -15, -20, -6, 48, 42, 42, 31, -12, -29, 72, 0, 96, -21, 23, 13, -22, 53, 22, -12, -2, -2, 47, 102, 87, -30, 53, 14, 66, -3, 52, 43, -12, 13, 32, 58, 19, 16, 24, 3, 73, -33, -34, -9, 20, 4, 99, -1, 75, 42, 12, 1, -13, 26, 79, 36, -5, 1, 9, 57, 75, 49, 3, 2, 21, -13, -31, -2, 8, 35, 59, 30, 58, 10, 40, 72, 6, 45, 61, 56, 8, 57, -43, 56, -1, -22, 19, 104, 19, 49, 41, 37, 46, 3, 54, 75, 67, 40, -22, 51, -2, 33, 39, 62, 64, -5, 26, 
  99, 21, 38, 90, 116, 72, 26, 17, 19, 49, -2, 41, 98, -55, 40, 15, 98, 48, 124, 113, 36, 45, 41, 30, 43, 92, 77, 86, 39, 6, 92, 80, -2, 58, 114, 75, 72, 67, 60, 23, 61, 103, 43, 127, 81, -73, 71, 101, -2, 125, 74, 108, 43, 39, 87, 109, 82, 65, 52, 69, 68, -98, 85, 81, -61, -3, -18, -53, -64, 5, 34, -14, 10, -44, -15, -27, -20, -33, -33, -19, -26, 4, 3, -26, -35, -35, 30, -7, -59, -51, 7, -63, -22, -23, 11, -64, -37, 10, 35, -48, -45, -31, -14, 3, 26, -26, -5, -58, -53, -66, 42, -30, -49, -59, 17, -68, -40, -70, 7, 30, -16, 43, 14, -33, -39, -80, -15, -93, -63, -25, -24, -24, -16, -69, -47, -52, 16, 38, 10, -3, -82, -7, -20, -23, 9, -46, -13, -13, 2, -45, 8, -51, 20, 51, 40, -68, 28, -63, -11, -83, -36, -4, 33, -15, 20, -29, 20, -19, -46, -36, 41, -55, -52, -40, 27, -65, -17, -49, 7, -18, -71, -35, -16, 1, -56, 65, 20, -5, -12, -20, -55, -10, 14, -1, -22, -57, 19, -107, -43, -75, -17, -43, 40, -9, -74, -32, 40, 33, -20, -41, 8, -88, 1, -91, -6, -63, -53, 55, -27, -46, 11, -92, -69, -54, -54, 26, -10, -8, 24, 4, -12, -28, -51, 30, 22, -57, -23, -76, 32, 4, -70, -27, 26, -1, -58, -26, -67, 27, 20, 46, 22, -60, -19, -49, -2, -20, 3, -4, 37, -54, -15, 1, -8, 2, -17, -7, -46, -17, 28, -23, -10, -12, -62, -32, -33, -58, -51, -36, -9, 0, -49, -13, 1, -83, -36, -61, 8, -84, -7, -58, -15, -54, -34, -65, -22, 40, -43, -30, 46, -26, -23, -53, 23, -2, -72, -73, 12, -78, -38, 0, 24, -48, -9, -38, 39, -56, -24, -81, -61, -39, -40, 20, -12, -74, -16, 14, -73, 13, -100, -45, -30, -63, -5, -13, -29, 23, 4, -62, -24, -47, -31, -41, -54, 30, -32, -38, 27, 12, -36, -62, -40, -22, 5, -2, -20, -57, -27, -23, -11, 28, -22, -3, 9, -22, -79, -35, 31, -43, -8, -93, -53, -85, -64, -22, -41, 43, -40, -40, 13, -8, -98, -81, 26, -17, -31, -40, 35, -46, -54, 1, -42, 10, 25, -16, -17, 13, 13, -45, 16, 35, 
};
const TfArray<2, int> tensor_dimension10 = { 2, { 2,400 } };
const TfArray<1, float> quant10_scale = { 1, { 0.0025923207867890596, } };
const TfArray<1, int> quant10_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant10 = { (TfLiteFloatArray*)&quant10_scale, (TfLiteIntArray*)&quant10_zero, 0 };
const ALIGN(8) int32_t tensor_data11[2] = { 795, -795, };
const TfArray<1, int> tensor_dimension11 = { 1, { 2 } };
const TfArray<1, float> quant11_scale = { 1, { 7.5393880251795053e-05, } };
const TfArray<1, int> quant11_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant11 = { (TfLiteFloatArray*)&quant11_scale, (TfLiteIntArray*)&quant11_zero, 0 };
const TfArray<4, int> tensor_dimension12 = { 4, { 1,1,99,65 } };
const TfArray<1, float> quant12_scale = { 1, { 0.0029847295954823494, } };
const TfArray<1, int> quant12_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant12 = { (TfLiteFloatArray*)&quant12_scale, (TfLiteIntArray*)&quant12_zero, 0 };
const TfArray<4, int> tensor_dimension13 = { 4, { 1,1,99,8 } };
const TfArray<1, float> quant13_scale = { 1, { 0.010750320740044117, } };
const TfArray<1, int> quant13_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant13 = { (TfLiteFloatArray*)&quant13_scale, (TfLiteIntArray*)&quant13_zero, 0 };
const TfArray<4, int> tensor_dimension14 = { 4, { 1,99,1,8 } };
const TfArray<1, float> quant14_scale = { 1, { 0.010750320740044117, } };
const TfArray<1, int> quant14_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant14 = { (TfLiteFloatArray*)&quant14_scale, (TfLiteIntArray*)&quant14_zero, 0 };
const TfArray<4, int> tensor_dimension15 = { 4, { 1,50,1,8 } };
const TfArray<1, float> quant15_scale = { 1, { 0.010750320740044117, } };
const TfArray<1, int> quant15_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant15 = { (TfLiteFloatArray*)&quant15_scale, (TfLiteIntArray*)&quant15_zero, 0 };
const TfArray<4, int> tensor_dimension16 = { 4, { 1,1,50,8 } };
const TfArray<1, float> quant16_scale = { 1, { 0.010750320740044117, } };
const TfArray<1, int> quant16_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant16 = { (TfLiteFloatArray*)&quant16_scale, (TfLiteIntArray*)&quant16_zero, 0 };
const TfArray<4, int> tensor_dimension17 = { 4, { 1,1,50,16 } };
const TfArray<1, float> quant17_scale = { 1, { 0.029083544388413429, } };
const TfArray<1, int> quant17_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant17 = { (TfLiteFloatArray*)&quant17_scale, (TfLiteIntArray*)&quant17_zero, 0 };
const TfArray<4, int> tensor_dimension18 = { 4, { 1,50,1,16 } };
const TfArray<1, float> quant18_scale = { 1, { 0.029083544388413429, } };
const TfArray<1, int> quant18_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant18 = { (TfLiteFloatArray*)&quant18_scale, (TfLiteIntArray*)&quant18_zero, 0 };
const TfArray<4, int> tensor_dimension19 = { 4, { 1,25,1,16 } };
const TfArray<1, float> quant19_scale = { 1, { 0.029083544388413429, } };
const TfArray<1, int> quant19_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant19 = { (TfLiteFloatArray*)&quant19_scale, (TfLiteIntArray*)&quant19_zero, 0 };
const TfArray<2, int> tensor_dimension20 = { 2, { 1,400 } };
const TfArray<1, float> quant20_scale = { 1, { 0.029083544388413429, } };
const TfArray<1, int> quant20_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant20 = { (TfLiteFloatArray*)&quant20_scale, (TfLiteIntArray*)&quant20_zero, 0 };
const TfArray<2, int> tensor_dimension21 = { 2, { 1,2 } };
const TfArray<1, float> quant21_scale = { 1, { 0.14778576791286469, } };
const TfArray<1, int> quant21_zero = { 1, { 16 } };
const TfLiteAffineQuantization quant21 = { (TfLiteFloatArray*)&quant21_scale, (TfLiteIntArray*)&quant21_zero, 0 };
const TfArray<2, int> tensor_dimension22 = { 2, { 1,2 } };
const TfArray<1, float> quant22_scale = { 1, { 0.00390625, } };
const TfArray<1, int> quant22_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant22 = { (TfLiteFloatArray*)&quant22_scale, (TfLiteIntArray*)&quant22_zero, 0 };
const TfLiteReshapeParams opdata0 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs0 = { 2, { 0,1 } };
const TfArray<1, int> outputs0 = { 1, { 12 } };
const TfLiteConvParams opdata1 = { kTfLitePaddingSame, 1,1, kTfLiteActRelu, 1,1 };
const TfArray<3, int> inputs1 = { 3, { 12,6,7 } };
const TfArray<1, int> outputs1 = { 1, { 13 } };
const TfLiteReshapeParams opdata2 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs2 = { 2, { 13,2 } };
const TfArray<1, int> outputs2 = { 1, { 14 } };
const TfLitePoolParams opdata3 = { kTfLitePaddingSame, 1,2, 1,2, kTfLiteActNone, { { 0,0, 0, 0 } } };
const TfArray<1, int> inputs3 = { 1, { 14 } };
const TfArray<1, int> outputs3 = { 1, { 15 } };
const TfLiteReshapeParams opdata4 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs4 = { 2, { 15,3 } };
const TfArray<1, int> outputs4 = { 1, { 16 } };
const TfLiteConvParams opdata5 = { kTfLitePaddingSame, 1,1, kTfLiteActRelu, 1,1 };
const TfArray<3, int> inputs5 = { 3, { 16,8,9 } };
const TfArray<1, int> outputs5 = { 1, { 17 } };
const TfLiteReshapeParams opdata6 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs6 = { 2, { 17,4 } };
const TfArray<1, int> outputs6 = { 1, { 18 } };
const TfLitePoolParams opdata7 = { kTfLitePaddingSame, 1,2, 1,2, kTfLiteActNone, { { 0,0, 0, 0 } } };
const TfArray<1, int> inputs7 = { 1, { 18 } };
const TfArray<1, int> outputs7 = { 1, { 19 } };
const TfLiteReshapeParams opdata8 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs8 = { 2, { 19,5 } };
const TfArray<1, int> outputs8 = { 1, { 20 } };
const TfLiteFullyConnectedParams opdata9 = { kTfLiteActNone, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs9 = { 3, { 20,10,11 } };
const TfArray<1, int> outputs9 = { 1, { 21 } };
const TfLiteSoftmaxParams opdata10 = { 1 };
const TfArray<1, int> inputs10 = { 1, { 21 } };
const TfArray<1, int> outputs10 = { 1, { 22 } };
const TensorInfo_t tensorData[] = {
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 6448, (TfLiteIntArray*)&tensor_dimension0, 6435, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant0))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data1, (TfLiteIntArray*)&tensor_dimension1, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data2, (TfLiteIntArray*)&tensor_dimension2, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data3, (TfLiteIntArray*)&tensor_dimension3, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data4, (TfLiteIntArray*)&tensor_dimension4, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data5, (TfLiteIntArray*)&tensor_dimension5, 8, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data6, (TfLiteIntArray*)&tensor_dimension6, 1560, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant6))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data7, (TfLiteIntArray*)&tensor_dimension7, 32, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant7))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data8, (TfLiteIntArray*)&tensor_dimension8, 384, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant8))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data9, (TfLiteIntArray*)&tensor_dimension9, 64, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant9))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data10, (TfLiteIntArray*)&tensor_dimension10, 800, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant10))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data11, (TfLiteIntArray*)&tensor_dimension11, 8, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant11))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension12, 6435, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant12))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 6448, (TfLiteIntArray*)&tensor_dimension13, 792, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant13))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension14, 792, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant14))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 800, (TfLiteIntArray*)&tensor_dimension15, 400, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant15))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension16, 400, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant16))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 800, (TfLiteIntArray*)&tensor_dimension17, 800, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant17))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension18, 800, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant18))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 800, (TfLiteIntArray*)&tensor_dimension19, 400, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant19))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension20, 400, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant20))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 400, (TfLiteIntArray*)&tensor_dimension21, 2, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant21))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension22, 2, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant22))}, },
};const NodeInfo_t nodeData[] = {
  { (TfLiteIntArray*)&inputs0, (TfLiteIntArray*)&outputs0, const_cast<void*>(static_cast<const void*>(&opdata0)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs1, (TfLiteIntArray*)&outputs1, const_cast<void*>(static_cast<const void*>(&opdata1)), OP_CONV_2D, },
  { (TfLiteIntArray*)&inputs2, (TfLiteIntArray*)&outputs2, const_cast<void*>(static_cast<const void*>(&opdata2)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs3, (TfLiteIntArray*)&outputs3, const_cast<void*>(static_cast<const void*>(&opdata3)), OP_MAX_POOL_2D, },
  { (TfLiteIntArray*)&inputs4, (TfLiteIntArray*)&outputs4, const_cast<void*>(static_cast<const void*>(&opdata4)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs5, (TfLiteIntArray*)&outputs5, const_cast<void*>(static_cast<const void*>(&opdata5)), OP_CONV_2D, },
  { (TfLiteIntArray*)&inputs6, (TfLiteIntArray*)&outputs6, const_cast<void*>(static_cast<const void*>(&opdata6)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs7, (TfLiteIntArray*)&outputs7, const_cast<void*>(static_cast<const void*>(&opdata7)), OP_MAX_POOL_2D, },
  { (TfLiteIntArray*)&inputs8, (TfLiteIntArray*)&outputs8, const_cast<void*>(static_cast<const void*>(&opdata8)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs9, (TfLiteIntArray*)&outputs9, const_cast<void*>(static_cast<const void*>(&opdata9)), OP_FULLY_CONNECTED, },
  { (TfLiteIntArray*)&inputs10, (TfLiteIntArray*)&outputs10, const_cast<void*>(static_cast<const void*>(&opdata10)), OP_SOFTMAX, },
};
static void* overflow_buffers[EI_MAX_OVERFLOW_BUFFER_COUNT];
static size_t overflow_buffers_ix = 0;
static void * AllocatePersistentBuffer(struct TfLiteContext* ctx,
                                       size_t bytes) {
  void *ptr;
  if (current_location - bytes < tensor_boundary) {
    if (overflow_buffers_ix > EI_MAX_OVERFLOW_BUFFER_COUNT - 1) {
      ei_printf("ERR: Failed to allocate persistent buffer of size %d, does not fit in tensor arena and reached EI_MAX_OVERFLOW_BUFFER_COUNT\n",
        (int)bytes);
      return NULL;
    }

    // OK, this will look super weird, but.... we have CMSIS-NN buffers which
    // we cannot calculate beforehand easily.
    ptr = ei_calloc(bytes, 1);
    if (ptr == NULL) {
      ei_printf("ERR: Failed to allocate persistent buffer of size %d\n", (int)bytes);
      return NULL;
    }
    overflow_buffers[overflow_buffers_ix++] = ptr;
    return ptr;
  }

  current_location -= bytes;

  ptr = current_location;
  memset(ptr, 0, bytes);

  return ptr;
}
typedef struct {
  size_t bytes;
  void *ptr;
} scratch_buffer_t;
static scratch_buffer_t scratch_buffers[EI_MAX_SCRATCH_BUFFER_COUNT];
static size_t scratch_buffers_ix = 0;

static TfLiteStatus RequestScratchBufferInArena(struct TfLiteContext* ctx, size_t bytes,
                                                int* buffer_idx) {
  if (scratch_buffers_ix > EI_MAX_SCRATCH_BUFFER_COUNT - 1) {
    ei_printf("ERR: Failed to allocate scratch buffer of size %d, reached EI_MAX_SCRATCH_BUFFER_COUNT\n",
      (int)bytes);
    return kTfLiteError;
  }

  scratch_buffer_t b;
  b.bytes = bytes;

  b.ptr = AllocatePersistentBuffer(ctx, b.bytes);
  if (!b.ptr) {
    ei_printf("ERR: Failed to allocate scratch buffer of size %d\n",
      (int)bytes);
    return kTfLiteError;
  }

  scratch_buffers[scratch_buffers_ix] = b;
  *buffer_idx = scratch_buffers_ix;

  scratch_buffers_ix++;

  return kTfLiteOk;
}

static void* GetScratchBuffer(struct TfLiteContext* ctx, int buffer_idx) {
  if (buffer_idx > (int)scratch_buffers_ix) {
    return NULL;
  }
  return scratch_buffers[buffer_idx].ptr;
}

static TfLiteTensor* GetTensor(const struct TfLiteContext* context,
                               int tensor_idx) {
  return &tflTensors[tensor_idx];
}

static TfLiteEvalTensor* GetEvalTensor(const struct TfLiteContext* context,
                                       int tensor_idx) {
  return &tflEvalTensors[tensor_idx];
}

} // namespace

TfLiteStatus trained_model_init( void*(*alloc_fnc)(size_t,size_t) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  tensor_arena = (uint8_t*) alloc_fnc(16, kTensorArenaSize);
  if (!tensor_arena) {
    ei_printf("ERR: failed to allocate tensor arena\n");
    return kTfLiteError;
  }
#else
  memset(tensor_arena, 0, kTensorArenaSize);
#endif
  tensor_boundary = tensor_arena;
  current_location = tensor_arena + kTensorArenaSize;
  ctx.AllocatePersistentBuffer = &AllocatePersistentBuffer;
  ctx.RequestScratchBufferInArena = &RequestScratchBufferInArena;
  ctx.GetScratchBuffer = &GetScratchBuffer;
  ctx.GetTensor = &GetTensor;
  ctx.GetEvalTensor = &GetEvalTensor;
  ctx.tensors = tflTensors;
  ctx.tensors_size = 23;
  for (size_t i = 0; i < 23; ++i) {
    tflTensors[i].type = tensorData[i].type;
    tflEvalTensors[i].type = tensorData[i].type;
    tflTensors[i].is_variable = 0;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
    tflTensors[i].allocation_type = tensorData[i].allocation_type;
#else
    tflTensors[i].allocation_type = (tensor_arena <= tensorData[i].data && tensorData[i].data < tensor_arena + kTensorArenaSize) ? kTfLiteArenaRw : kTfLiteMmapRo;
#endif
    tflTensors[i].bytes = tensorData[i].bytes;
    tflTensors[i].dims = tensorData[i].dims;
    tflEvalTensors[i].dims = tensorData[i].dims;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
    if(tflTensors[i].allocation_type == kTfLiteArenaRw){
      uint8_t* start = (uint8_t*) ((uintptr_t)tensorData[i].data + (uintptr_t) tensor_arena);

     tflTensors[i].data.data =  start;
     tflEvalTensors[i].data.data =  start;
    }
    else {
       tflTensors[i].data.data = tensorData[i].data;
       tflEvalTensors[i].data.data = tensorData[i].data;
    }
#else
    tflTensors[i].data.data = tensorData[i].data;
    tflEvalTensors[i].data.data = tensorData[i].data;
#endif // EI_CLASSIFIER_ALLOCATION_HEAP
    tflTensors[i].quantization = tensorData[i].quantization;
    if (tflTensors[i].quantization.type == kTfLiteAffineQuantization) {
      TfLiteAffineQuantization const* quant = ((TfLiteAffineQuantization const*)(tensorData[i].quantization.params));
      tflTensors[i].params.scale = quant->scale->data[0];
      tflTensors[i].params.zero_point = quant->zero_point->data[0];
    }
    if (tflTensors[i].allocation_type == kTfLiteArenaRw) {
      auto data_end_ptr = (uint8_t*)tflTensors[i].data.data + tensorData[i].bytes;
      if (data_end_ptr > tensor_boundary) {
        tensor_boundary = data_end_ptr;
      }
    }
  }
  if (tensor_boundary > current_location /* end of arena size */) {
    ei_printf("ERR: tensor arena is too small, does not fit model - even without scratch buffers\n");
    return kTfLiteError;
  }
  registrations[OP_RESHAPE] = Register_RESHAPE();
  registrations[OP_CONV_2D] = Register_CONV_2D();
  registrations[OP_MAX_POOL_2D] = Register_MAX_POOL_2D();
  registrations[OP_FULLY_CONNECTED] = Register_FULLY_CONNECTED();
  registrations[OP_SOFTMAX] = Register_SOFTMAX();

  for (size_t i = 0; i < 11; ++i) {
    tflNodes[i].inputs = nodeData[i].inputs;
    tflNodes[i].outputs = nodeData[i].outputs;
    tflNodes[i].builtin_data = nodeData[i].builtin_data;
tflNodes[i].custom_initial_data = nullptr;
      tflNodes[i].custom_initial_data_size = 0;
if (registrations[nodeData[i].used_op_index].init) {
      tflNodes[i].user_data = registrations[nodeData[i].used_op_index].init(&ctx, (const char*)tflNodes[i].builtin_data, 0);
    }
  }
  for (size_t i = 0; i < 11; ++i) {
    if (registrations[nodeData[i].used_op_index].prepare) {
      TfLiteStatus status = registrations[nodeData[i].used_op_index].prepare(&ctx, &tflNodes[i]);
      if (status != kTfLiteOk) {
        return status;
      }
    }
  }
  return kTfLiteOk;
}

static const int inTensorIndices[] = {
  0, 
};
TfLiteTensor* trained_model_input(int index) {
  return &ctx.tensors[inTensorIndices[index]];
}

static const int outTensorIndices[] = {
  22, 
};
TfLiteTensor* trained_model_output(int index) {
  return &ctx.tensors[outTensorIndices[index]];
}

TfLiteStatus trained_model_invoke() {
  for (size_t i = 0; i < 11; ++i) {
    TfLiteStatus status = registrations[nodeData[i].used_op_index].invoke(&ctx, &tflNodes[i]);

#if EI_CLASSIFIER_PRINT_STATE
    ei_printf("layer %lu\n", i);
    ei_printf("    inputs:\n");
    for (size_t ix = 0; ix < tflNodes[i].inputs->size; ix++) {
      auto d = tensorData[tflNodes[i].inputs->data[ix]];

      size_t data_ptr = (size_t)d.data;

      if (d.allocation_type == kTfLiteArenaRw) {
        data_ptr = (size_t)tensor_arena + data_ptr;
      }

      if (d.type == TfLiteType::kTfLiteInt8) {
        int8_t* data = (int8_t*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes; jx++) {
          ei_printf("%d ", data[jx]);
        }
      }
      else {
        float* data = (float*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes / 4; jx++) {
          ei_printf("%f ", data[jx]);
        }
      }
      ei_printf("\n");
    }
    ei_printf("\n");

    ei_printf("    outputs:\n");
    for (size_t ix = 0; ix < tflNodes[i].outputs->size; ix++) {
      auto d = tensorData[tflNodes[i].outputs->data[ix]];

      size_t data_ptr = (size_t)d.data;

      if (d.allocation_type == kTfLiteArenaRw) {
        data_ptr = (size_t)tensor_arena + data_ptr;
      }

      if (d.type == TfLiteType::kTfLiteInt8) {
        int8_t* data = (int8_t*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes; jx++) {
          ei_printf("%d ", data[jx]);
        }
      }
      else {
        float* data = (float*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes / 4; jx++) {
          ei_printf("%f ", data[jx]);
        }
      }
      ei_printf("\n");
    }
    ei_printf("\n");
#endif // EI_CLASSIFIER_PRINT_STATE

    if (status != kTfLiteOk) {
      return status;
    }
  }
  return kTfLiteOk;
}

TfLiteStatus trained_model_reset( void (*free_fnc)(void* ptr) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  free_fnc(tensor_arena);
#endif

  // scratch buffers are allocated within the arena, so just reset the counter so memory can be reused
  scratch_buffers_ix = 0;

  // overflow buffers are on the heap, so free them first
  for (size_t ix = 0; ix < overflow_buffers_ix; ix++) {
    ei_free(overflow_buffers[ix]);
  }
  overflow_buffers_ix = 0;
  return kTfLiteOk;
}
