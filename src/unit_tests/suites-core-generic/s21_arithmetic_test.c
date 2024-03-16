#include "suites-core-generic/s21_decimal_core_generic_test.h"

START_TEST(invalid_dec_s21_add_1) {
  // ссылка на результат - NULL
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x0}};
  int result_value = s21_add(dec_1, dec_2, NULL);

  ck_assert_int_eq(result_value, 1);
}

START_TEST(invalid_dec_s21_add_2) {
  // степень 56 (допустимое значение от 0 до 28)
  // биты 0-15 не пустые
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x380000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_3) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_4) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_5) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C8000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x140000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_6) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_7) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0xA, 0x0, 0x0, 0x401C0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_8) {
  // Все биты имеют максимальное значение
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_9) {
  // степень 56 (допустимое значение от 0 до 28)
  // биты 0-15 не пустые
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x380000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_10) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_11) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_12) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_13) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C8000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_14) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_15) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x401C0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_16) {
  // Все биты имеют максимальное значение
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

// START_TEST(s21_add_1) {
//   // 526498388649
//   s21_decimal dec_1 = {{0x95bfdaa9, 0x7a, 0x0, 0x0}};
//   // -22560459930.877620
//   s21_decimal dec_2 = {{0x68263eb4, 0x50269e, 0x0, 0x80060000}};
//   // 503937928718.122380
//   s21_decimal dec_check = {{0x4e16fd8c, 0x6fe58e0, 0x0, 0x60000}};
//   s21_decimal result;
//   int return_value = s21_add(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_add_2) {
  // 82834107784443291418950066
  s21_decimal dec_1 = {{0x4182f9b2, 0xfb1506d8, 0x4484cd, 0x0}};
  // 0
  s21_decimal dec_2 = {{0x0, 0x0, 0x0, 0x0}};
  // 82834107784443291418950066
  s21_decimal dec_check = {{0x4182f9b2, 0xfb1506d8, 0x4484cd, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_3) {
  // 5335776507328747599467779982
  s21_decimal dec_1 = {{0xbe16178e, 0xea133f0, 0x113da6a0, 0x0}};
  // -71534677320544154031
  s21_decimal dec_2 = {{0x1d39f1af, 0xe0be3a04, 0x3, 0x80000000}};
  // 5335776435794070278923625951
  s21_decimal dec_check = {{0xa0dc25df, 0x2de2f9ec, 0x113da69c, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_4) {
  // 0.28679
  s21_decimal dec_1 = {{0x7007, 0x0, 0x0, 0x50000}};
  // -91386226837
  s21_decimal dec_2 = {{0x470b2895, 0x15, 0x0, 0x80000000}};
  // -91386226836.71321
  s21_decimal dec_check = {{0x66cbeb19, 0x207787, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_5) {
  // -2160163824.9467444
  s21_decimal dec_1 = {{0x566d0e34, 0x4cbe93, 0x0, 0x80070000}};
  // -3493.4276022687244159737042016
  s21_decimal dec_2 = {{0xac2e9460, 0xe67954c0, 0x70e0f4b1, 0x80190000}};
  // -2160167318.3743466687244159737
  s21_decimal dec_check = {{0x3fa24af9, 0xc1bf617c, 0x45cc7c39, 0x80130000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_6) {
  // 132.8
  s21_decimal dec_1 = {{0x530, 0x0, 0x0, 0x10000}};
  // 90.87626049881421218486386552
  s21_decimal dec_2 = {{0xedc37f78, 0x4d057d10, 0x1d5d1bab, 0x1a0000}};
  // 223.67626049881421218486386552
  s21_decimal dec_check = {{0xcdc37f78, 0xd4cc2410, 0x4846110d, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_7) {
  // 7581607123012019836676335576
  s21_decimal dec_1 = {{0x56c5e7d8, 0xaf601d6f, 0x187f5bc1, 0x0}};
  // -557.260957
  s21_decimal dec_2 = {{0x2137209d, 0x0, 0x0, 0x80060000}};
  // 7581607123012019836676335018.7
  s21_decimal dec_check = {{0x63baf8ab, 0xd9c12659, 0xf4f99590, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

// START_TEST(s21_add_8) {
//   // 183.5989090789614377
//   s21_decimal dec_1 = {{0xc001e329, 0x197abe59, 0x0, 0x100000}};
//   // -98873000775428868
//   s21_decimal dec_2 = {{0x6918ab04, 0x15f4478, 0x0, 0x80000000}};
//   // -98873000775428684.401090921039
//   s21_decimal dec_check = {{0xa082824f, 0xb4605bb, 0x3f79d450, 0x800c0000}};
//   s21_decimal result;
//   int return_value = s21_add(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_add_9) {
  // -1431831206840459
  s21_decimal dec_1 = {{0x2e76488b, 0x5163e, 0x0, 0x80000000}};
  // 80706632.145759
  s21_decimal dec_2 = {{0xfa23db5f, 0x4966, 0x0, 0x60000}};
  // -1431831126133826.854241
  s21_decimal dec_check = {{0x62471d61, 0x9ea6070d, 0x4d, 0x80060000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_10) {
  // -0.41228546128350865
  s21_decimal dec_1 = {{0xee960e91, 0x927924, 0x0, 0x80110000}};
  // -438.8610135815498177220478673
  s21_decimal dec_2 = {{0xe33086d1, 0x2c123e9a, 0xe2e2c58, 0x80190000}};
  // -439.2732990428333263720478673
  s21_decimal dec_check = {{0x8bc2f7d1, 0x918cf831, 0xe319564, 0x80190000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_11) {
  // -2574485
  s21_decimal dec_1 = {{0x274895, 0x0, 0x0, 0x80000000}};
  // -2028170783344437755542174139
  s21_decimal dec_2 = {{0x8f6ef9bb, 0x79434faa, 0x68da9de, 0x80000000}};
  // -2028170783344437755544748624
  s21_decimal dec_check = {{0x8f964250, 0x79434faa, 0x68da9de, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_12) {
  // 11319752901
  s21_decimal dec_1 = {{0xa2b5b8c5, 0x2, 0x0, 0x0}};
  // 8.1
  s21_decimal dec_2 = {{0x51, 0x0, 0x0, 0x10000}};
  // 11319752909.1
  s21_decimal dec_check = {{0x5b193803, 0x1a, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_13) {
  // 766511846113921143784
  s21_decimal dec_1 = {{0x52713e8, 0x8d7d1ee3, 0x29, 0x0}};
  // -937749289396279533667
  s21_decimal dec_2 = {{0x18396063, 0xd5e2ba4c, 0x32, 0x80000000}};
  // -171237443282358389883
  s21_decimal dec_check = {{0x13124c7b, 0x48659b69, 0x9, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_14) {
  // -26
  s21_decimal dec_1 = {{0x1a, 0x0, 0x0, 0x80000000}};
  // -773734
  s21_decimal dec_2 = {{0xbce66, 0x0, 0x0, 0x80000000}};
  // -773760
  s21_decimal dec_check = {{0xbce80, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_15) {
  // 6.4243
  s21_decimal dec_1 = {{0xfaf3, 0x0, 0x0, 0x40000}};
  // 4
  s21_decimal dec_2 = {{0x4, 0x0, 0x0, 0x0}};
  // 10.4243
  s21_decimal dec_check = {{0x19733, 0x0, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_16) {
  // -746627.971
  s21_decimal dec_1 = {{0x2c80a383, 0x0, 0x0, 0x80030000}};
  // -89698338742712
  s21_decimal dec_2 = {{0x859e21b8, 0x5194, 0x0, 0x80000000}};
  // -89698339489339.971
  s21_decimal dec_check = {{0x1e345a43, 0x13eac2a, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_17) {
  // 501994252682254670174930.78
  s21_decimal dec_1 = {{0x86ae7a56, 0x4bf2591e, 0x298624, 0x20000}};
  // 291090
  s21_decimal dec_2 = {{0x47112, 0x0, 0x0, 0x0}};
  // 501994252682254670466020.78
  s21_decimal dec_check = {{0x886aa55e, 0x4bf2591e, 0x298624, 0x20000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_18) {
  // -7
  s21_decimal dec_1 = {{0x7, 0x0, 0x0, 0x80000000}};
  // 4.5035868820345158
  s21_decimal dec_2 = {{0x53301146, 0x9fffe2, 0x0, 0x100000}};
  // -2.4964131179654842
  s21_decimal dec_check = {{0xbb16eeba, 0x58b0be, 0x0, 0x80100000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_19) {
  // -7874599571132424818183574
  s21_decimal dec_1 = {{0x353acd96, 0xe5eb7050, 0x68382, 0x80000000}};
  // -2677109483890600
  s21_decimal dec_2 = {{0x1fcfe7a8, 0x982d1, 0x0, 0x80000000}};
  // -7874599573809534302074174
  s21_decimal dec_check = {{0x550ab53e, 0xe5f4f321, 0x68382, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_20) {
  // -12.3935798875537532511
  s21_decimal dec_1 = {{0xf2abe65f, 0xb7f4686f, 0x6, 0x80130000}};
  // -4928782418.15664883789713
  s21_decimal dec_2 = {{0xdafdef91, 0xfba7ae80, 0x685e, 0x800e0000}};
  // -4928782430.5502287254508832511
  s21_decimal dec_check = {{0xac5886ff, 0x7499c697, 0x9f41eec5, 0x80130000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_21) {
  // 68862930501753147296866691
  s21_decimal dec_1 = {{0xb9986183, 0xf153dddc, 0x38f64a, 0x0}};
  // -4290773694485345421886
  s21_decimal dec_2 = {{0x1d794a3e, 0x9a7265a4, 0xe8, 0x80000000}};
  // 68858639728058661951444805
  s21_decimal dec_check = {{0x9c1f1745, 0x56e17838, 0x38f562, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

// START_TEST(s21_add_22) {
//   // 2470385366811.09529583777710
//   s21_decimal dec_1 = {{0x81977ae, 0xe869d64e, 0xcc5871, 0xe0000}};
//   // -2404080857.66458829
//   s21_decimal dec_2 = {{0x593dcdcd, 0x35619e1, 0x0, 0x80080000}};
//   // 2467981285953.43070754777710
//   s21_decimal dec_check = {{0xba942a6e, 0x5c030a56, 0xcc2589, 0xe0000}};
//   s21_decimal result;
//   int return_value = s21_add(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_add_23) {
  // 8019198.4
  s21_decimal dec_1 = {{0x4c7a1f0, 0x0, 0x0, 0x10000}};
  // -72.202324946330614
  s21_decimal dec_2 = {{0xca6223f6, 0x10083a1, 0x0, 0x800f0000}};
  // 8019126.197675053669386
  s21_decimal dec_check = {{0x4a79dc0a, 0xb7bb55a2, 0x1b2, 0xf0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_24) {
  // 7186720768
  s21_decimal dec_1 = {{0xac5ca800, 0x1, 0x0, 0x0}};
  // -1.6674457661469551902648272
  s21_decimal dec_2 = {{0x89a8e7d0, 0x293c7b91, 0xdcaf4, 0x80190000}};
  // 7186720766.3325542338530448097
  s21_decimal dec_check = {{0x59d112e1, 0xf3c4d6fa, 0xe837292d, 0x130000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_25) {
  // -895783914293964042549916
  s21_decimal dec_1 = {{0x6f463a9c, 0x8b158fc6, 0xbdb0, 0x80000000}};
  // -3300
  s21_decimal dec_2 = {{0xce4, 0x0, 0x0, 0x80000000}};
  // -895783914293964042553216
  s21_decimal dec_check = {{0x6f464780, 0x8b158fc6, 0xbdb0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_26) {
  // -511515821.609502667889719
  s21_decimal dec_1 = {{0x7626dc37, 0x54085ade, 0x6c51, 0x800f0000}};
  // -29.5599
  s21_decimal dec_2 = {{0x482af, 0x0, 0x0, 0x80040000}};
  // -511515851.169402667889719
  s21_decimal dec_check = {{0x13f7437, 0x54715f71, 0x6c51, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_27) {
  // 85972506.342525015092
  s21_decimal dec_1 = {{0x44389434, 0xa91bb304, 0x4, 0xc0000}};
  // -440642480631647043255
  s21_decimal dec_2 = {{0xb443feb7, 0xe3249182, 0x17, 0x80000000}};
  // -440642480631561070748.65747498
  s21_decimal dec_check = {{0xb4e8562a, 0xf3612e54, 0x8e611779, 0x80080000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_28) {
  // -16449698264641664698
  s21_decimal dec_1 = {{0xde5376ba, 0xe449116a, 0x0, 0x80000000}};
  // -73569.4887555067379006248582
  s21_decimal dec_2 = {{0xe04f1686, 0xc4c87bfa, 0x2608d73, 0x80160000}};
  // -16449698264641738267.488755507
  s21_decimal dec_check = {{0x60d11f33, 0xc34590e9, 0x3526df19, 0x80090000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_29) {
  // -643621176
  s21_decimal dec_1 = {{0x265ce138, 0x0, 0x0, 0x80000000}};
  // -4529034
  s21_decimal dec_2 = {{0x451b8a, 0x0, 0x0, 0x80000000}};
  // -648150210
  s21_decimal dec_check = {{0x26a1fcc2, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_30) {
  // -9537318
  s21_decimal dec_1 = {{0x918726, 0x0, 0x0, 0x80000000}};
  // -5027974941296070930478
  s21_decimal dec_2 = {{0x7dd6b02e, 0x912b59c1, 0x110, 0x80000000}};
  // -5027974941296080467796
  s21_decimal dec_check = {{0x7e683754, 0x912b59c1, 0x110, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_31) {
  // 0.4
  s21_decimal dec_1 = {{0x4, 0x0, 0x0, 0x10000}};
  // -43091433.4864989741289517
  s21_decimal dec_2 = {{0xad06902d, 0xe9b3ddb6, 0x5b3f, 0x80100000}};
  // -43091433.0864989741289517
  s21_decimal dec_check = {{0x19ec902d, 0xe9a5a7bc, 0x5b3f, 0x80100000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_32) {
  // -7495264528762.304
  s21_decimal dec_1 = {{0x43bc05c0, 0x1aa0e7, 0x0, 0x80030000}};
  // 18.831895
  s21_decimal dec_2 = {{0x11f5a17, 0x0, 0x0, 0x60000}};
  // -7495264528743.472105
  s21_decimal dec_check = {{0x95571be9, 0x68048760, 0x0, 0x80060000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_33) {
  // 32.44372475740340757250497377
  s21_decimal dec_1 = {{0x4bb4db61, 0x53d68e12, 0xa7bae98, 0x1a0000}};
  // 24631.2709418226
  s21_decimal dec_2 = {{0x258c6cf2, 0xe005, 0x0, 0xa0000}};
  // 24663.714666580003407572504974
  s21_decimal dec_check = {{0xd048118e, 0x27475068, 0x4fb158bb, 0x180000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_34) {
  // 12407.8899345688668377
  s21_decimal dec_1 = {{0x8538a8d9, 0xb9f0cd8e, 0x6, 0x100000}};
  // 8391272.30213677406
  s21_decimal dec_2 = {{0x1e3e615e, 0xba52dc5, 0x0, 0xb0000}};
  // 8403680.1920713429268377
  s21_decimal dec_check = {{0x748ab799, 0xa4e7b4d4, 0x11cb, 0x100000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_35) {
  // 63405.7512840
  s21_decimal dec_1 = {{0xa0c5d788, 0x93, 0x0, 0x70000}};
  // -2981589615.636762955856
  s21_decimal dec_2 = {{0x66b99050, 0xa1de3648, 0xa1, 0x800c0000}};
  // -2981526209.885478955856
  s21_decimal dec_check = {{0x84b9ab50, 0xa0fcf316, 0xa1, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_36) {
  // 1143519333338892230779163924
  s21_decimal dec_1 = {{0x232f5514, 0x4635e981, 0x3b1e5a3, 0x0}};
  // 88036541782048713
  s21_decimal dec_2 = {{0xb02c3fc9, 0x138c4c4, 0x0, 0x0}};
  // 1143519333426928772561212637
  s21_decimal dec_check = {{0xd35b94dd, 0x476eae45, 0x3b1e5a3, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_37) {
  // -1648836934440.302295888
  s21_decimal dec_1 = {{0x2423b50, 0x623587f6, 0x59, 0x80090000}};
  // -5688134575009821554
  s21_decimal dec_2 = {{0x4a13f372, 0x4ef05042, 0x0, 0x80000000}};
  // -5688136223846755994.302295888
  s21_decimal dec_check = {{0x78ee2f50, 0x907cff85, 0x12611db2, 0x80090000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_38) {
  // 351181014225008657141113
  s21_decimal dec_1 = {{0x83038d79, 0x8f98f8e3, 0x4a5d, 0x0}};
  // 21933
  s21_decimal dec_2 = {{0x55ad, 0x0, 0x0, 0x0}};
  // 351181014225008657163046
  s21_decimal dec_check = {{0x8303e326, 0x8f98f8e3, 0x4a5d, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_39) {
  // 387.853037017
  s21_decimal dec_1 = {{0x4dd7add9, 0x5a, 0x0, 0x90000}};
  // 8071554146
  s21_decimal dec_2 = {{0xe11a2462, 0x1, 0x0, 0x0}};
  // 8071554533.853037017
  s21_decimal dec_check = {{0x678101d9, 0x7003ec15, 0x0, 0x90000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_40) {
  // 77401516531616291059512950
  s21_decimal dec_1 = {{0xc499b676, 0x9e6dc6bb, 0x400668, 0x0}};
  // -811757609238637156075
  s21_decimal dec_2 = {{0xf55196eb, 0x1665cb9, 0x2c, 0x80000000}};
  // 77400704774007052422356875
  s21_decimal dec_check = {{0xcf481f8b, 0x9d076a01, 0x40063c, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_41) {
  // -18146570869.377582102965734
  s21_decimal dec_1 = {{0x2d76de6, 0x93f6f5df, 0xf02af, 0x800f0000}};
  // 0.6350839951100
  s21_decimal dec_2 = {{0xab8f2efc, 0x5c6, 0x0, 0xd0000}};
  // -18146570868.742498107855734
  s21_decimal dec_check = {{0xfee91376, 0x93f4b443, 0xf02af, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_42) {
  // -234
  s21_decimal dec_1 = {{0xea, 0x0, 0x0, 0x80000000}};
  // 89084893145694234600851
  s21_decimal dec_2 = {{0x2ff5e593, 0x4d3e7404, 0x12dd, 0x0}};
  // 89084893145694234600617
  s21_decimal dec_check = {{0x2ff5e4a9, 0x4d3e7404, 0x12dd, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_43) {
  // -222249713618284020
  s21_decimal dec_1 = {{0xdfa66df4, 0x31596ef, 0x0, 0x80000000}};
  // 39.8567
  s21_decimal dec_2 = {{0x614e7, 0x0, 0x0, 0x40000}};
  // -222249713618283980.1433
  s21_decimal dec_check = {{0x5520f659, 0x7b57fa10, 0x78, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_44) {
  // -300.01449043
  s21_decimal dec_1 = {{0xfc39c853, 0x6, 0x0, 0x80080000}};
  // -843581225149830
  s21_decimal dec_2 = {{0x8f43a586, 0x2ff3b, 0x0, 0x80000000}};
  // -843581225150130.01449043
  s21_decimal dec_check = {{0x77f28e53, 0x101fc6ea, 0x11dd, 0x80080000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_45) {
  // -448103046
  s21_decimal dec_1 = {{0x1ab58286, 0x0, 0x0, 0x80000000}};
  // 0.5
  s21_decimal dec_2 = {{0x5, 0x0, 0x0, 0x10000}};
  // -448103045.5
  s21_decimal dec_check = {{0xb171937, 0x1, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

// START_TEST(s21_add_46) {
//   // 0.1493308000
//   s21_decimal dec_1 = {{0x59021260, 0x0, 0x0, 0xa0000}};
//   // 0.4669296529060622720040
//   s21_decimal dec_2 = {{0xf6d35c28, 0x1f81a62f, 0xfd, 0x160000}};
//   // 0.6162604529060622720040
//   s21_decimal dec_check = {{0x6fd95c28, 0x1351684d, 0x14e, 0x160000}};
//   s21_decimal result;
//   int return_value = s21_add(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_add_47) {
//   // 680949304457
//   s21_decimal dec_1 = {{0x8bbdcc89, 0x9e, 0x0, 0x0}};
//   // -82.01437567255334599800
//   s21_decimal dec_2 = {{0x1613bc78, 0x99cf6e57, 0x1bc, 0x80140000}};
//   // 680949304374.98562432744665400
//   s21_decimal dec_check = {{0x5b0db138, 0xc77db8d2, 0xdc06ce67, 0x110000}};
//   s21_decimal result;
//   int return_value = s21_add(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_add_48) {
  // 2496
  s21_decimal dec_1 = {{0x9c0, 0x0, 0x0, 0x0}};
  // 284737057453103
  s21_decimal dec_2 = {{0x8329f42f, 0x102f7, 0x0, 0x0}};
  // 284737057455599
  s21_decimal dec_check = {{0x8329fdef, 0x102f7, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

// START_TEST(s21_add_49) {
//   // 96448305460609846190601
//   s21_decimal dec_1 = {{0xd1c1a209, 0x791e1b66, 0x146c, 0x0}};
//   // -76.278012440811590173
//   s21_decimal dec_2 = {{0x3b66d21d, 0x2291f02d, 0x4, 0x80120000}};
//   // 96448305460609846190524.721988
//   s21_decimal dec_check = {{0xd629eb44, 0xa59da620, 0x37a42b1b, 0x60000}};
//   s21_decimal result;
//   int return_value = s21_add(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_add_50) {
  // -88.6221630219998352816912912
  s21_decimal dec_1 = {{0x6d0aba10, 0xd6e377b0, 0x2dd10ba, 0x80190000}};
  // 0.59637375
  s21_decimal dec_2 = {{0x38dfe7f, 0x0, 0x0, 0x80000}};
  // -88.0257892719998352816912912
  s21_decimal dec_check = {{0x1994ba10, 0xfb527129, 0x2d821db, 0x80190000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_51) {
  // 730864500451856694508.21328
  s21_decimal dec_1 = {{0x7115eed0, 0x655a8028, 0x3c74a8, 0x50000}};
  // 87059252884704108473887
  s21_decimal dec_2 = {{0xa9efee1f, 0x7dd696f2, 0x126f, 0x0}};
  // 87790117385155965168395.21328
  s21_decimal dec_check = {{0x2bcdfc30, 0xf56e86b6, 0x1c5dd40b, 0x50000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_52) {
  // -7
  s21_decimal dec_1 = {{0x7, 0x0, 0x0, 0x80000000}};
  // 259080.44
  s21_decimal dec_2 = {{0x18b534c, 0x0, 0x0, 0x20000}};
  // 259073.44
  s21_decimal dec_check = {{0x18b5090, 0x0, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_53) {
  // 4004307121124447272
  s21_decimal dec_1 = {{0x66309428, 0x3792281c, 0x0, 0x0}};
  // 2981818590100073827013
  s21_decimal dec_2 = {{0x13014ac5, 0xa50bb158, 0xa1, 0x0}};
  // 2985822897221198274285
  s21_decimal dec_check = {{0x7931deed, 0xdc9dd974, 0xa1, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_54) {
  // 4813411403.9820
  s21_decimal dec_1 = {{0x18c4d80c, 0x2bc7, 0x0, 0x40000}};
  // 0.8493763
  s21_decimal dec_2 = {{0x819ac3, 0x0, 0x0, 0x70000}};
  // 4813411404.8313763
  s21_decimal dec_check = {{0xc16d89a3, 0xab01b8, 0x0, 0x70000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_55) {
  // 6822430629
  s21_decimal dec_1 = {{0x96a607a5, 0x1, 0x0, 0x0}};
  // 38.23295382339669213558
  s21_decimal dec_2 = {{0x3444176, 0x42e1cd8d, 0xcf, 0x140000}};
  // 6822430667.2329538233966921356
  s21_decimal dec_check = {{0x2142068c, 0x85d96f7d, 0xdc71d2e3, 0x130000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_56) {
  // -23789487
  s21_decimal dec_1 = {{0x16affaf, 0x0, 0x0, 0x80000000}};
  // -5072554958090672433382699
  s21_decimal dec_2 = {{0xf169c52b, 0xc15a1376, 0x43227, 0x80000000}};
  // -5072554958090672457172186
  s21_decimal dec_check = {{0xf2d4c4da, 0xc15a1376, 0x43227, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

// START_TEST(s21_add_57) {
//   // 217939669.0625150
//   s21_decimal dec_1 = {{0x5591c27e, 0x7be26, 0x0, 0x70000}};
//   // -8
//   s21_decimal dec_2 = {{0x8, 0x0, 0x0, 0x80000000}};
//   // 217939661.0625150
//   s21_decimal dec_check = {{0x50cd0e7e, 0x7be26, 0x0, 0x70000}};
//   s21_decimal result;
//   int return_value = s21_add(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_add_58) {
  // 746643735710386847451071
  s21_decimal dec_1 = {{0x180787bf, 0xa3550c8b, 0x9e1b, 0x0}};
  // -1.4978739367
  s21_decimal dec_2 = {{0x7ccd6ca7, 0x3, 0x0, 0x800a0000}};
  // 746643735710386847451069.50213
  s21_decimal dec_check = {{0x7d7f8845, 0xa643bd8a, 0xf140ec19, 0x50000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_59) {
  // 2948569493423434
  s21_decimal dec_1 = {{0x5540454a, 0xa79b5, 0x0, 0x0}};
  // -62987716368332825235400890
  s21_decimal dec_2 = {{0x43d5a8ba, 0xf2422ea7, 0x341a2a, 0x80000000}};
  // -62987716365384255741977456
  s21_decimal dec_check = {{0xee956370, 0xf237b4f1, 0x341a2a, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

// START_TEST(s21_add_60) {
//   // -790852439
//   s21_decimal dec_1 = {{0x2f237357, 0x0, 0x0, 0x80000000}};
//   // 214385920701702326.44330
//   s21_decimal dec_2 = {{0x7b0a62ea, 0x303b4d4a, 0x48a, 0x50000}};
//   // 214385919910849887.44330
//   s21_decimal dec_check = {{0x32bc28a, 0x303b055d, 0x48a, 0x50000}};
//   s21_decimal result;
//   int return_value = s21_add(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_add_61) {
  // 3652644340858856910085533.9
  s21_decimal dec_1 = {{0x4356a82b, 0x76ffa000, 0x1e36c6, 0x10000}};
  // 74143954.4022251126
  s21_decimal dec_2 = {{0x43dfb676, 0xa4a1f56, 0x0, 0xa0000}};
  // 3652644340858856984229488.3022
  s21_decimal dec_check = {{0xabbe82ce, 0xd68901b3, 0x7605f740, 0x40000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_62) {
  // -65
  s21_decimal dec_1 = {{0x41, 0x0, 0x0, 0x80000000}};
  // 1016424289011936
  s21_decimal dec_2 = {{0xb8b008e0, 0x39c6e, 0x0, 0x0}};
  // 1016424289011871
  s21_decimal dec_check = {{0xb8b0089f, 0x39c6e, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_63) {
  // 96.81741425
  s21_decimal dec_1 = {{0x4113a671, 0x2, 0x0, 0x80000}};
  // -14942909.66099336172677
  s21_decimal dec_2 = {{0x12351485, 0x173f493, 0x51, 0x800e0000}};
  // -14942812.84357911172677
  s21_decimal dec_check = {{0xfbc35645, 0x1518f14, 0x51, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_64) {
  // -767539853
  s21_decimal dec_1 = {{0x2dbfba8d, 0x0, 0x0, 0x80000000}};
  // -87842587206135
  s21_decimal dec_2 = {{0x7234e1f7, 0x4fe4, 0x0, 0x80000000}};
  // -87843354745988
  s21_decimal dec_check = {{0x9ff49c84, 0x4fe4, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_65) {
  // -0.65
  s21_decimal dec_1 = {{0x41, 0x0, 0x0, 0x80020000}};
  // -88615176
  s21_decimal dec_2 = {{0x5482908, 0x0, 0x0, 0x80000000}};
  // -88615176.65
  s21_decimal dec_check = {{0x10300761, 0x2, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_66) {
  // 48
  s21_decimal dec_1 = {{0x30, 0x0, 0x0, 0x0}};
  // -3.390616718506351047
  s21_decimal dec_2 = {{0xf41259c7, 0x2f0de3f0, 0x0, 0x80120000}};
  // 44.609383281493648953
  s21_decimal dec_check = {{0x6eada639, 0x6b145dbe, 0x2, 0x120000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_67) {
  // -73025171357.742710725641458
  s21_decimal dec_1 = {{0x103584f2, 0x78bb6730, 0x3c67ae, 0x800f0000}};
  // -41489714113374.1503096
  s21_decimal dec_2 = {{0x51c5b278, 0x7ddabfa4, 0x16, 0x80070000}};
  // -41562739284731.893020325641458
  s21_decimal dec_check = {{0xf6e8fcf2, 0x5905f1be, 0x864be463, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_68) {
  // -534721547466
  s21_decimal dec_1 = {{0x7fe34cca, 0x7c, 0x0, 0x80000000}};
  // 8301552564037210992591
  s21_decimal dec_2 = {{0x3731efcf, 0x72f597b, 0x1c2, 0x0}};
  // 8301552563502489445125
  s21_decimal dec_check = {{0xb74ea305, 0x72f58fe, 0x1c2, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

// START_TEST(s21_add_69) {
//   // -1439721.4221714
//   s21_decimal dec_1 = {{0x1cd6e592, 0xd18, 0x0, 0x80070000}};
//   // 9703654873178746616516272370
//   s21_decimal dec_2 = {{0x9e0560f2, 0xba3d45ef, 0x1f5aacd8, 0x0}};
//   // 9703654873178746616514832648.6
//   s21_decimal dec_check = {{0x2b5a1a56, 0x4664bb5c, 0x398ac077, 0x10000}};
//   s21_decimal result;
//   int return_value = s21_add(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_add_70) {
  // -845648411
  s21_decimal dec_1 = {{0x3267921b, 0x0, 0x0, 0x80000000}};
  // -1655450345
  s21_decimal dec_2 = {{0x62ac2ae9, 0x0, 0x0, 0x80000000}};
  // -2501098756
  s21_decimal dec_check = {{0x9513bd04, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_71) {
  // -772086605949777244371
  s21_decimal dec_1 = {{0xd17870d3, 0xdadaa56b, 0x29, 0x80000000}};
  // -756220360465011770241.081
  s21_decimal dec_2 = {{0xfef5b039, 0xc9b2cfbd, 0xa022, 0x80030000}};
  // -1528306966414789014612.081
  s21_decimal dec_check = {{0x3d6e6871, 0xafc8fce8, 0x143a1, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_72) {
  // -969489295936726925793
  s21_decimal dec_1 = {{0x7c2a81e1, 0x8e5de214, 0x34, 0x80000000}};
  // -197833781187660
  s21_decimal dec_2 = {{0xc440944c, 0xb3ed, 0x0, 0x80000000}};
  // -969489493770508113453
  s21_decimal dec_check = {{0x406b162d, 0x8e5e9602, 0x34, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_73) {
  // -8253749108750203175965297090
  s21_decimal dec_1 = {{0xaa1809c2, 0xbe2c4a46, 0x1aab575b, 0x80000000}};
  // -5715162
  s21_decimal dec_2 = {{0x5734da, 0x0, 0x0, 0x80000000}};
  // -8253749108750203175971012252
  s21_decimal dec_check = {{0xaa6f3e9c, 0xbe2c4a46, 0x1aab575b, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_74) {
  // 84480.3503
  s21_decimal dec_1 = {{0x325aadaf, 0x0, 0x0, 0x40000}};
  // -32582456.4979516365617
  s21_decimal dec_2 = {{0x6c40db31, 0xa9b9638e, 0x11, 0x800d0000}};
  // -32497976.1476516365617
  s21_decimal dec_check = {{0xeeec531, 0x9e000b3f, 0x11, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_75) {
  // -0.11053747771
  s21_decimal dec_1 = {{0x92dace3b, 0x2, 0x0, 0x800b0000}};
  // -71776756613156.627
  s21_decimal dec_2 = {{0x710e8f13, 0xff0094, 0x0, 0x80030000}};
  // -71776756613156.73753747771
  s21_decimal dec_check = {{0xaac9813b, 0x93c7f31a, 0x5efee, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_76) {
  // -67297
  s21_decimal dec_1 = {{0x106e1, 0x0, 0x0, 0x80000000}};
  // -62423909707.7405809528
  s21_decimal dec_2 = {{0x715b7b78, 0xd70ec76e, 0x21, 0x800a0000}};
  // -62423977004.7405809528
  s21_decimal dec_check = {{0x7b26df78, 0xd7112b7e, 0x21, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_77) {
  // 691.675051031
  s21_decimal dec_1 = {{0xb0bb417, 0xa1, 0x0, 0x90000}};
  // -727.77
  s21_decimal dec_2 = {{0x11c49, 0x0, 0x0, 0x80020000}};
  // -36.094948969
  s21_decimal dec_check = {{0x676d3669, 0x8, 0x0, 0x80090000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_78) {
  // 100652914
  s21_decimal dec_1 = {{0x5ffd772, 0x0, 0x0, 0x0}};
  // -36381858
  s21_decimal dec_2 = {{0x22b24a2, 0x0, 0x0, 0x80000000}};
  // 64271056
  s21_decimal dec_check = {{0x3d4b2d0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_79) {
  // 7561343225166580
  s21_decimal dec_1 = {{0x68f5faf4, 0x1add00, 0x0, 0x0}};
  // 80721573
  s21_decimal dec_2 = {{0x4cfb6a5, 0x0, 0x0, 0x0}};
  // 7561343305888153
  s21_decimal dec_check = {{0x6dc5b199, 0x1add00, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_80) {
  // 9313768140
  s21_decimal dec_1 = {{0x2b24d2cc, 0x2, 0x0, 0x0}};
  // -544781901903
  s21_decimal dec_2 = {{0xd788204f, 0x7e, 0x0, 0x80000000}};
  // -535468133763
  s21_decimal dec_check = {{0xac634d83, 0x7c, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_81) {
  // 3887.322
  s21_decimal dec_1 = {{0x3b50da, 0x0, 0x0, 0x30000}};
  // -663620026092601334
  s21_decimal dec_2 = {{0xd115bff6, 0x935a6e5, 0x0, 0x80000000}};
  // -663620026092597446.678
  s21_decimal dec_check = {{0xbcba8816, 0xf993f1b8, 0x23, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_82) {
  // -8
  s21_decimal dec_1 = {{0x8, 0x0, 0x0, 0x80000000}};
  // 29865120002063873894813993
  s21_decimal dec_2 = {{0x4dc9129, 0x663e59cc, 0x18b42f, 0x0}};
  // 29865120002063873894813985
  s21_decimal dec_check = {{0x4dc9121, 0x663e59cc, 0x18b42f, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_83) {
  // -0.6
  s21_decimal dec_1 = {{0x6, 0x0, 0x0, 0x80010000}};
  // -3516924382
  s21_decimal dec_2 = {{0xd1a001de, 0x0, 0x0, 0x80000000}};
  // -3516924382.6
  s21_decimal dec_check = {{0x304012b2, 0x8, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

// START_TEST(s21_add_84) {
//   // -97245531823737
//   s21_decimal dec_1 = {{0xbd615e79, 0x5871, 0x0, 0x80000000}};
//   // 8.70543107069794320663834
//   s21_decimal dec_2 = {{0xc184451a, 0x3c8478eb, 0xb858, 0x170000}};
//   // -97245531823728.294568929302057
//   s21_decimal dec_check = {{0x263c9629, 0x63c4ef88, 0x3a379e5b, 0x800f0000}};
//   s21_decimal result;
//   int return_value = s21_add(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_add_85) {
//   // 8009179987324892959511611917
//   s21_decimal dec_1 = {{0xd3230a0d, 0x1ab05eaf, 0x19e109d5, 0x0}};
//   // -15.19
//   s21_decimal dec_2 = {{0x5ef, 0x0, 0x0, 0x80020000}};
//   // 8009179987324892959511611901.8
//   s21_decimal dec_check = {{0x3f5e63ea, 0xae3b2de, 0x2ca6253, 0x10000}};
//   s21_decimal result;
//   int return_value = s21_add(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_add_86) {
  // -82021962422470.41
  s21_decimal dec_1 = {{0xa165ad81, 0x1d23da, 0x0, 0x80020000}};
  // -45958537917888324253356.8
  s21_decimal dec_2 = {{0x1e6422c0, 0x2c5f2f7f, 0x6152, 0x80010000}};
  // -45958537999910286675827.21
  s21_decimal dec_check = {{0xd14f0901, 0xbbd4fed1, 0x3cd35, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_87) {
  // 0.8125556317504184489
  s21_decimal dec_1 = {{0x7344a0a9, 0x70c3c66b, 0x0, 0x130000}};
  // -655411826249285323378728742
  s21_decimal dec_2 = {{0xbe3d1f26, 0x4b6b7403, 0x21e24da, 0x80000000}};
  // -655411826249285323378728741.19
  s21_decimal dec_check = {{0x4fe02a87, 0x75f95176, 0xd3c66545, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_88) {
  // 5
  s21_decimal dec_1 = {{0x5, 0x0, 0x0, 0x0}};
  // 17809679394635.52350931
  s21_decimal dec_2 = {{0x346ebad3, 0x8be528f8, 0x60, 0x80000}};
  // 17809679394640.52350931
  s21_decimal dec_check = {{0x523c1fd3, 0x8be528f8, 0x60, 0x80000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_89) {
  // -0.0442543056342971159
  s21_decimal dec_1 = {{0xa7237317, 0x6243a90, 0x0, 0x80130000}};
  // 555.4141030
  s21_decimal dec_2 = {{0x4b0d7766, 0x1, 0x0, 0x70000}};
  // 555.3698486943657028841
  s21_decimal dec_check = {{0x9d10ece9, 0x110c951e, 0x12d, 0x130000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_90) {
  // 3979697400816911
  s21_decimal dec_1 = {{0x81e3a50f, 0xe2383, 0x0, 0x0}};
  // 512884726594839837865706
  s21_decimal dec_2 = {{0x817af6ea, 0x8967d243, 0x6c9b, 0x0}};
  // 512884730574537238682617
  s21_decimal dec_check = {{0x35e9bf9, 0x8975f5c7, 0x6c9b, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_91) {
  // -47162933015692220775
  s21_decimal dec_1 = {{0xa5e09967, 0x8e8465b2, 0x2, 0x80000000}};
  // -628697586446195789
  s21_decimal dec_2 = {{0xb7455c4d, 0x8b9951f, 0x0, 0x80000000}};
  // -47791630602138416564
  s21_decimal dec_check = {{0x5d25f5b4, 0x973dfad2, 0x2, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_92) {
  // -8588642.49
  s21_decimal dec_1 = {{0x33313a79, 0x0, 0x0, 0x80020000}};
  // 294238808851
  s21_decimal dec_2 = {{0x81ffeb13, 0x44, 0x0, 0x0}};
  // 294230220208.51
  s21_decimal dec_check = {{0x94c698f3, 0x1ac2, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_93) {
  // 7698851599087331
  s21_decimal dec_1 = {{0x92bdf6e3, 0x1b5a10, 0x0, 0x0}};
  // -311606799444.0835957
  s21_decimal dec_2 = {{0xd09c2375, 0x2b3e7f54, 0x0, 0x80070000}};
  // 7698539992287886.9164043
  s21_decimal dec_check = {{0x73d0500b, 0x630b5fba, 0x104d, 0x70000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_94) {
  // -87476898
  s21_decimal dec_1 = {{0x536caa2, 0x0, 0x0, 0x80000000}};
  // 4502008
  s21_decimal dec_2 = {{0x44b1f8, 0x0, 0x0, 0x0}};
  // -82974890
  s21_decimal dec_check = {{0x4f218aa, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_95) {
  // 49770910
  s21_decimal dec_1 = {{0x2f7719e, 0x0, 0x0, 0x0}};
  // -584627047584874577070
  s21_decimal dec_2 = {{0xa5d73cae, 0xb154824a, 0x1f, 0x80000000}};
  // -584627047584824806160
  s21_decimal dec_check = {{0xa2dfcb10, 0xb154824a, 0x1f, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_96) {
  // 328
  s21_decimal dec_1 = {{0x148, 0x0, 0x0, 0x0}};
  // 912
  s21_decimal dec_2 = {{0x390, 0x0, 0x0, 0x0}};
  // 1240
  s21_decimal dec_check = {{0x4d8, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_97) {
  // 52928043697574047332
  s21_decimal dec_1 = {{0x7240ee64, 0xde862f51, 0x2, 0x0}};
  // -3412924930225
  s21_decimal dec_2 = {{0xa22d98b1, 0x31a, 0x0, 0x80000000}};
  // 52928040284649117107
  s21_decimal dec_check = {{0xd01355b3, 0xde862c36, 0x2, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_98) {
  // -115068
  s21_decimal dec_1 = {{0x1c17c, 0x0, 0x0, 0x80000000}};
  // -11.04096021685462914
  s21_decimal dec_2 = {{0x627be782, 0xf52897b, 0x0, 0x80110000}};
  // -115079.04096021685462914
  s21_decimal dec_check = {{0xbb53e782, 0xd8404bd7, 0x26f, 0x80110000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_99) {
  // -0.92638601324
  s21_decimal dec_1 = {{0x91b0e06c, 0x15, 0x0, 0x800b0000}};
  // 433403114433224929517444
  s21_decimal dec_2 = {{0x79791f84, 0xd47514e7, 0x5bc6, 0x0}};
  // 433403114433224929517443.07361
  s21_decimal dec_check = {{0x71b560a1, 0x2705b3ba, 0x8c0a43ef, 0x50000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_100) {
  // -60876665245074510340349
  s21_decimal dec_1 = {{0xda7460fd, 0x217155ff, 0xce4, 0x80000000}};
  // -15229313739837693898904
  s21_decimal dec_2 = {{0x21763098, 0x952f3e05, 0x339, 0x80000000}};
  // -76105978984912204239253
  s21_decimal dec_check = {{0xfbea9195, 0xb6a09404, 0x101d, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(fail_s21_add_1) {
  // 19212045921398027500
  s21_decimal dec_1 = {{0xc96bf4ec, 0xa9ee5f9, 0x1, 0x0}};
  // 79228162514264337591863968376
  s21_decimal dec_2 = {{0x9bdd8278, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_2) {
  // -79228162514264337592873376543
  s21_decimal dec_1 = {{0xd807db1f, 0xffffffff, 0xffffffff, 0x80000000}};
  // -78034793614874881
  s21_decimal dec_2 = {{0x39891901, 0x1153c3b, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_3) {
  // 5744280547775300406085540304.2
  s21_decimal dec_1 = {{0xbe2a8222, 0xa1d170ff, 0xb99b9334, 0x10000}};
  // 79228162514264337593114339869
  s21_decimal dec_2 = {{0xe664aa1d, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_4) {
  // 41432251688412281735336537
  s21_decimal dec_1 = {{0x3de5d259, 0xdd54ed6e, 0x22459e, 0x0}};
  // 79228162514264337591561108364
  s21_decimal dec_2 = {{0x89d03b8c, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_5) {
  // -1629553687805020144213764129
  s21_decimal dec_1 = {{0xeee12821, 0x6cccb233, 0x543ef6a, 0x80000000}};
  // -79228162514264337593374249354
  s21_decimal dec_2 = {{0xf5e2918a, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_6) {
  // -79228162514264337591822583106
  s21_decimal dec_1 = {{0x99660542, 0xffffffff, 0xffffffff, 0x80000000}};
  // -20330025050863
  s21_decimal dec_2 = {{0x73ebe2ef, 0x127d, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_7) {
  // -636238863
  s21_decimal dec_1 = {{0x25ec3c0f, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593022642211
  s21_decimal dec_2 = {{0xe0ed7823, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_8) {
  // 79228162514264337591933614901
  s21_decimal dec_1 = {{0xa0043b35, 0xffffffff, 0xffffffff, 0x0}};
  // 3632313835.73047870784781
  s21_decimal dec_2 = {{0x57dc850d, 0xd010fd56, 0x4cea, 0xe0000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_9) {
  // -80422527225489557384350997.575
  s21_decimal dec_1 = {{0x37ad1c47, 0xbb8672d4, 0x3dbf490, 0x80030000}};
  // -79228162514264337592623559579
  s21_decimal dec_2 = {{0xc923f39b, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_10) {
  // 34922916335320785
  s21_decimal dec_1 = {{0x16affed1, 0x7c1235, 0x0, 0x0}};
  // 79228162514264337592879321879
  s21_decimal dec_2 = {{0xd8629317, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_11) {
  // -79228162514264337592474910867
  s21_decimal dec_1 = {{0xc047c093, 0xffffffff, 0xffffffff, 0x80000000}};
  // -936307821693
  s21_decimal dec_2 = {{0x4b8c7d, 0xda, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_12) {
  // 11998736137.708847
  s21_decimal dec_1 = {{0x753de52f, 0x2aa0c9, 0x0, 0x60000}};
  // 79228162514264337592066734496
  s21_decimal dec_2 = {{0xa7f379a0, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_13) {
  // -306895571298855
  s21_decimal dec_1 = {{0xb182aa27, 0x1171e, 0x0, 0x80000000}};
  // -79228162514264337591612935677
  s21_decimal dec_2 = {{0x8ce70dfd, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_14) {
  // 918929944899395849083
  s21_decimal dec_1 = {{0xbdc50b7b, 0xd0b6fc2f, 0x31, 0x0}};
  // 79228162514264337592918775845
  s21_decimal dec_2 = {{0xdabc9825, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_15) {
  // -79228162514264337593497363739
  s21_decimal dec_1 = {{0xfd39251b, 0xffffffff, 0xffffffff, 0x80000000}};
  // -20561097005343844.5563
  s21_decimal dec_2 = {{0xd6ad97fb, 0x256ce7e3, 0xb, 0x80040000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_16) {
  // 79228162514264337591924341608
  s21_decimal dec_1 = {{0x9f76bb68, 0xffffffff, 0xffffffff, 0x0}};
  // 5839261630660644569549.949018
  s21_decimal dec_2 = {{0x7308c85a, 0x489efd91, 0x12de1fbf, 0x60000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_17) {
  // 6377665233944931441312626460
  s21_decimal dec_1 = {{0xe12d771c, 0x19f68e05, 0x149b7b25, 0x0}};
  // 79228162514264337592462062634
  s21_decimal dec_2 = {{0xbf83b42a, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_18) {
  // -33580433937507022761509
  s21_decimal dec_1 = {{0x1ff6e25, 0x6622fd66, 0x71c, 0x80000000}};
  // -79228162514264337591580999864
  s21_decimal dec_2 = {{0x8affc0b8, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_19) {
  // -79228162514264337592234290923
  s21_decimal dec_1 = {{0xb1f02eeb, 0xffffffff, 0xffffffff, 0x80000000}};
  // -784407268974391726253.33
  s21_decimal dec_2 = {{0x2aa683b5, 0x47c36c70, 0x109c, 0x80020000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_20) {
  // 8236661222823930224.3616
  s21_decimal dec_1 = {{0xa54ab520, 0x1a5df091, 0x1171, 0x40000}};
  // 79228162514264337592076403376
  s21_decimal dec_2 = {{0xa88702b0, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_21) {
  // 79228162514264337591480659526
  s21_decimal dec_1 = {{0x8504ae46, 0xffffffff, 0xffffffff, 0x0}};
  // 7125356821237916939594
  s21_decimal dec_2 = {{0x508eb54a, 0x4430a528, 0x182, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_22) {
  // -79228162514264337592529700692
  s21_decimal dec_1 = {{0xc38bc754, 0xffffffff, 0xffffffff, 0x80000000}};
  // -83560053060001253783751
  s21_decimal dec_2 = {{0x972378c7, 0xccaf81ef, 0x11b1, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_23) {
  // 936458392667196911
  s21_decimal dec_1 = {{0x51dc8def, 0xcfef7f2, 0x0, 0x0}};
  // 79228162514264337592762462968
  s21_decimal dec_2 = {{0xd16b72f8, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_24) {
  // -516307410
  s21_decimal dec_1 = {{0x1ec639d2, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593123493089
  s21_decimal dec_2 = {{0xe6f054e1, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_25) {
  // 79228162514264337591816758651
  s21_decimal dec_1 = {{0x990d257b, 0xffffffff, 0xffffffff, 0x0}};
  // 7708606450
  s21_decimal dec_2 = {{0xcb77fff2, 0x1, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_26) {
  // 77706452460967368513441
  s21_decimal dec_1 = {{0xdaa2d7a1, 0x79a896d1, 0x1074, 0x0}};
  // 79228162514264337592174075945
  s21_decimal dec_2 = {{0xae596029, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_27) {
  // -44689577091542595010
  s21_decimal dec_1 = {{0xd7d4b5c2, 0x6c314596, 0x2, 0x80000000}};
  // -79228162514264337591834521680
  s21_decimal dec_2 = {{0x9a1c3050, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_28) {
  // 717571587616354
  s21_decimal dec_1 = {{0xa794ae62, 0x28ca0, 0x0, 0x0}};
  // 79228162514264337592017969605
  s21_decimal dec_2 = {{0xa50b61c5, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_29) {
  // -909585586258589664982
  s21_decimal dec_1 = {{0xdeaa46d6, 0x4f092782, 0x31, 0x80000000}};
  // -79228162514264337593048173609
  s21_decimal dec_2 = {{0xe2730c29, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_30) {
  // 79228162514264337592685880522
  s21_decimal dec_1 = {{0xccdae4ca, 0xffffffff, 0xffffffff, 0x0}};
  // 3606651122314
  s21_decimal dec_2 = {{0xbd28b28a, 0x347, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_31) {
  // 9606860314843249
  s21_decimal dec_1 = {{0x78791871, 0x222163, 0x0, 0x0}};
  // 79228162514264337592844450868
  s21_decimal dec_2 = {{0xd64e7c34, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_32) {
  // -79228162514264337592761826591
  s21_decimal dec_1 = {{0xd161bd1f, 0xffffffff, 0xffffffff, 0x80000000}};
  // -484028553251465307269
  s21_decimal dec_2 = {{0x63d5a485, 0x3d3edcb0, 0x1a, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_33) {
  // 79228162514264337593444264766
  s21_decimal dec_1 = {{0xfa0eeb3e, 0xffffffff, 0xffffffff, 0x0}};
  // 55933713971958551
  s21_decimal dec_2 = {{0xa0445317, 0xc6b76a, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(invalid_dec_s21_sub_1) {
  // ссылка на результат - NULL
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x0}};
  int result_value = s21_sub(dec_1, dec_2, NULL);

  ck_assert_int_eq(result_value, 1);
}

START_TEST(invalid_dec_s21_sub_2) {
  // степень 56 (допустимое значение от 0 до 28)
  // биты 0-15 не пустые
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x380000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_3) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_4) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_5) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C8000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x140000}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_6) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_7) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0xA, 0x0, 0x0, 0x401C0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_8) {
  // Все биты имеют максимальное значение
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_9) {
  // степень 56 (допустимое значение от 0 до 28)
  // биты 0-15 не пустые
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x380000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_10) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_11) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_12) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_13) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C8000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_14) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_15) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x401C0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_16) {
  // Все биты имеют максимальное значение
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(s21_sub_1) {
  // -80260554677.627
  s21_decimal dec_1 = {{0x1dd9dd7b, 0x48ff, 0x0, 0x80030000}};
  // 3
  s21_decimal dec_2 = {{0x3, 0x0, 0x0, 0x0}};
  // -80260554680.627
  s21_decimal dec_check = {{0x1dd9e933, 0x48ff, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

// START_TEST(s21_sub_2) {
//   // 9
//   s21_decimal dec_1 = {{0x9, 0x0, 0x0, 0x0}};
//   // 31594626036.0
//   s21_decimal dec_2 = {{0x8fdd5788, 0x49, 0x0, 0x10000}};
//   // -31594626027.0
//   s21_decimal dec_check = {{0x8fdd572e, 0x49, 0x0, 0x80010000}};
//   s21_decimal result;
//   int return_value = s21_sub(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_sub_3) {
  // 280323791115436691683905808
  s21_decimal dec_1 = {{0x6bb99110, 0x2a9506b9, 0xe7e0df, 0x0}};
  // 9473921235665583167248923
  s21_decimal dec_2 = {{0x9fdc1a1b, 0x4c9dd3e1, 0x7d62e, 0x0}};
  // 270849869879771108516656885
  s21_decimal dec_check = {{0xcbdd76f5, 0xddf732d7, 0xe00ab0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_4) {
  // 8209805752
  s21_decimal dec_1 = {{0xe957b1b8, 0x1, 0x0, 0x0}};
  // 3185151474377517142
  s21_decimal dec_2 = {{0xea156856, 0x2c33ee63, 0x0, 0x0}};
  // -3185151466167711390
  s21_decimal dec_check = {{0xbdb69e, 0x2c33ee62, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_5) {
  // -71328585438779.688916767713
  s21_decimal dec_1 = {{0xcc0e53e1, 0x5d59d7c3, 0x3b006a, 0x800c0000}};
  // 77669
  s21_decimal dec_2 = {{0x12f65, 0x0, 0x0, 0x0}};
  // -71328585516448.688916767713
  s21_decimal dec_check = {{0xf1da3e1, 0x5e6dc74f, 0x3b006a, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_6) {
  // -8437980064297435423
  s21_decimal dec_1 = {{0x8246c11f, 0x7519ba29, 0x0, 0x80000000}};
  // -6201439460139
  s21_decimal dec_2 = {{0xe2989b2b, 0x5a3, 0x0, 0x80000000}};
  // -8437973862857975284
  s21_decimal dec_check = {{0x9fae25f4, 0x7519b485, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_7) {
  // -3496463336817531858892238
  s21_decimal dec_1 = {{0xb36eb5ce, 0xa84422d6, 0x2e467, 0x80000000}};
  // 277132935485080934888641250
  s21_decimal dec_2 = {{0xa91612e2, 0x8937fbd8, 0xe53d2e, 0x0}};
  // -280629398821898466747533488
  s21_decimal dec_check = {{0x5c84c8b0, 0x317c1eaf, 0xe82196, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_8) {
  // -3.858
  s21_decimal dec_1 = {{0xf12, 0x0, 0x0, 0x80030000}};
  // -5769973.5375400325391706
  s21_decimal dec_2 = {{0x68a0a55a, 0xe8af21a0, 0xc37, 0x80100000}};
  // 5769969.6795400325391706
  s21_decimal dec_check = {{0x2d31655a, 0xe8261152, 0xc37, 0x100000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_9) {
  // 1062.6
  s21_decimal dec_1 = {{0x2982, 0x0, 0x0, 0x10000}};
  // -37982205941336
  s21_decimal dec_2 = {{0x6be49658, 0x228b, 0x0, 0x80000000}};
  // 37982205942398.6
  s21_decimal dec_check = {{0x36ee08f2, 0x15972, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_10) {
  // -376463521333051371416.75047
  s21_decimal dec_1 = {{0x18507427, 0xd6a4eeff, 0x1f23ec, 0x80050000}};
  // -412477561652243377
  s21_decimal dec_2 = {{0x2c19ebb1, 0x5b96a28, 0x0, 0x80000000}};
  // -376051043771399128039.75047
  s21_decimal dec_check = {{0xb0d7f87, 0xcb0962b4, 0x1f1b30, 0x80050000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_11) {
  // 42586362888207847278749
  s21_decimal dec_1 = {{0xb312489d, 0x9c81f69a, 0x904, 0x0}};
  // 53.7239059437
  s21_decimal dec_2 = {{0x15f17bed, 0x7d, 0x0, 0xa0000}};
  // 42586362888207847278695.276094
  s21_decimal dec_check = {{0xb949de3e, 0x152206e9, 0x899a9d1e, 0x60000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_12) {
  // 7822712602447187332423025
  s21_decimal dec_1 = {{0x2fc1dd71, 0x19940a08, 0x67886, 0x0}};
  // 8071.60190
  s21_decimal dec_2 = {{0x301c497e, 0x0, 0x0, 0x50000}};
  // 7822712602447187332414953.3981
  s21_decimal dec_check = {{0x800a6d1d, 0x26c7dfc9, 0xfcc3f647, 0x40000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_13) {
  // -7667.816790724176228389
  s21_decimal dec_1 = {{0x4247b025, 0xac559954, 0x19f, 0x80120000}};
  // 7092085689812857281734745485
  s21_decimal dec_2 = {{0xbe279d8d, 0x9e0f6cac, 0x16ea6f8f, 0x0}};
  // -7092085689812857281734753152.8
  s21_decimal dec_check = {{0x6d8d5308, 0x2c9a3ebf, 0xe5285b9c, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_14) {
  // 142637.905
  s21_decimal dec_1 = {{0x8807b51, 0x0, 0x0, 0x30000}};
  // -749775595.8
  s21_decimal dec_2 = {{0xbee6ad36, 0x1, 0x0, 0x80010000}};
  // 749918233.705
  s21_decimal dec_check = {{0x9a9c2469, 0xae, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_15) {
  // 2189813924792303831945967733
  s21_decimal dec_1 = {{0x561f875, 0xbadd6de1, 0x7135f22, 0x0}};
  // 5642775849829177702600727798
  s21_decimal dec_2 = {{0x9634dcf6, 0xc2fd3dab, 0x123b9843, 0x0}};
  // -3452961925036873870654760065
  s21_decimal dec_check = {{0x90d2e481, 0x81fcfca, 0xb283921, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_16) {
  // -99505088105280661682424742
  s21_decimal dec_1 = {{0x304c8ba6, 0xa285e12f, 0x524f05, 0x80000000}};
  // -4752962827717
  s21_decimal dec_2 = {{0xa2a935c5, 0x452, 0x0, 0x80000000}};
  // -99505088105275908719597025
  s21_decimal dec_check = {{0x8da355e1, 0xa285dcdc, 0x524f05, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_17) {
  // 37095384338223797232541
  s21_decimal dec_1 = {{0x5245e39d, 0xf1df5bd8, 0x7da, 0x0}};
  // -2045
  s21_decimal dec_2 = {{0x7fd, 0x0, 0x0, 0x80000000}};
  // 37095384338223797234586
  s21_decimal dec_check = {{0x5245eb9a, 0xf1df5bd8, 0x7da, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_18) {
  // 961095748789302
  s21_decimal dec_1 = {{0x8ab3a436, 0x36a1c, 0x0, 0x0}};
  // -154795937
  s21_decimal dec_2 = {{0x939ffa1, 0x0, 0x0, 0x80000000}};
  // 961095903585239
  s21_decimal dec_check = {{0x93eda3d7, 0x36a1c, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_19) {
  // -14622
  s21_decimal dec_1 = {{0x391e, 0x0, 0x0, 0x80000000}};
  // 2592081.023
  s21_decimal dec_2 = {{0x9a80047f, 0x0, 0x0, 0x30000}};
  // -2606703.023
  s21_decimal dec_check = {{0x9b5f21af, 0x0, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_20) {
  // -8595906353264445
  s21_decimal dec_1 = {{0x68b5773d, 0x1e89ee, 0x0, 0x80000000}};
  // 92
  s21_decimal dec_2 = {{0x5c, 0x0, 0x0, 0x0}};
  // -8595906353264537
  s21_decimal dec_check = {{0x68b57799, 0x1e89ee, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_21) {
  // 3781
  s21_decimal dec_1 = {{0xec5, 0x0, 0x0, 0x0}};
  // 0.1287518915417979
  s21_decimal dec_2 = {{0xdb98577b, 0x492fd, 0x0, 0x100000}};
  // 3780.8712481084582021
  s21_decimal dec_check = {{0xb1eca885, 0xcb387ae, 0x2, 0x100000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_22) {
  // 1999679.24
  s21_decimal dec_1 = {{0xbeb44b4, 0x0, 0x0, 0x20000}};
  // 584073
  s21_decimal dec_2 = {{0x8e989, 0x0, 0x0, 0x0}};
  // 1415606.24
  s21_decimal dec_check = {{0x8700b30, 0x0, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_23) {
  // 4897579039334473611327
  s21_decimal dec_1 = {{0xf22b383f, 0x7f900bc9, 0x109, 0x0}};
  // 5
  s21_decimal dec_2 = {{0x5, 0x0, 0x0, 0x0}};
  // 4897579039334473611322
  s21_decimal dec_check = {{0xf22b383a, 0x7f900bc9, 0x109, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

// START_TEST(s21_sub_24) {
//   // -16543.8075325143529177202
//   s21_decimal dec_1 = {{0x88ee4072, 0x6a8133ba, 0x2308, 0x80130000}};
//   // -9131833988374474.6
//   s21_decimal dec_2 = {{0xda3fbdea, 0x1446d8b, 0x0, 0x80010000}};
//   // 9131833988357930.7924674856471
//   s21_decimal dec_check = {{0x9b9c4617, 0x7a318d01, 0x2710c2a4, 0xd0000}};
//   s21_decimal result;
//   int return_value = s21_sub(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_sub_25) {
  // 21641544959.8136
  s21_decimal dec_1 = {{0x25ff48b8, 0xc4d4, 0x0, 0x40000}};
  // -0.516133808838
  s21_decimal dec_2 = {{0x2bf8eac6, 0x78, 0x0, 0x800c0000}};
  // 21641544960.329733808838
  s21_decimal dec_check = {{0xbafaa2c6, 0x30c4cf99, 0x495, 0xc0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_26) {
  // -8068040186513094870098072025
  s21_decimal dec_1 = {{0x47ed51d9, 0xe5593789, 0x1a11b9f6, 0x80000000}};
  // -13299558356865304
  s21_decimal dec_2 = {{0xbb87d118, 0x2f3fe0, 0x0, 0x80000000}};
  // -8068040186499795311741206721
  s21_decimal dec_check = {{0x8c6580c1, 0xe529f7a8, 0x1a11b9f6, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_27) {
  // 37056231718629002266534820
  s21_decimal dec_1 = {{0x289fe3a4, 0x58bf9302, 0x1ea6f6, 0x0}};
  // 415126
  s21_decimal dec_2 = {{0x65596, 0x0, 0x0, 0x0}};
  // 37056231718629002266119694
  s21_decimal dec_check = {{0x28998e0e, 0x58bf9302, 0x1ea6f6, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_28) {
  // 69383054729.9738873
  s21_decimal dec_1 = {{0xea1da4f9, 0x9a0fb34, 0x0, 0x70000}};
  // -200398793122796846204006805
  s21_decimal dec_2 = {{0x270b3195, 0x57e678dc, 0xa5c418, 0x80000000}};
  // 200398793122796915587061534.97
  s21_decimal dec_check = {{0xb39b0819, 0x56073c4e, 0x40c09982, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

// START_TEST(s21_sub_29) {
//   // 817319
//   s21_decimal dec_1 = {{0xc78a7, 0x0, 0x0, 0x0}};
//   // 11640.30793485184630340047149
//   s21_decimal dec_2 = {{0x6d69d12d, 0xc1bfd103, 0x3c2dd1b, 0x170000}};
//   // 805678.69206514815369659952851
//   s21_decimal dec_check = {{0x60162ed3, 0x4fc2d86f, 0x4542ded, 0x170000}};
//   s21_decimal result;
//   int return_value = s21_sub(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_sub_30) {
  // -151264872341104528553
  s21_decimal dec_1 = {{0x66588ca9, 0x3338c7f5, 0x8, 0x80000000}};
  // 7181280466144
  s21_decimal dec_2 = {{0x5abd4e0, 0x688, 0x0, 0x0}};
  // -151264879522384994697
  s21_decimal dec_check = {{0x6c046189, 0x3338ce7d, 0x8, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_31) {
  // -4955725919486672741121192769
  s21_decimal dec_1 = {{0x2e80f341, 0x68527e00, 0x100347c8, 0x80000000}};
  // 63894843744502
  s21_decimal dec_2 = {{0xad76e0f6, 0x3a1c, 0x0, 0x0}};
  // -4955725919486736635964937271
  s21_decimal dec_check = {{0xdbf7d437, 0x6852b81c, 0x100347c8, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_32) {
  // 50158593047970331
  s21_decimal dec_1 = {{0x810ec21b, 0xb232f9, 0x0, 0x0}};
  // 31.68993271
  s21_decimal dec_2 = {{0xbce2fff7, 0x0, 0x0, 0x80000}};
  // 50158593047970299.31006729
  s21_decimal dec_check = {{0x868dbb09, 0x471b1757, 0x42626, 0x80000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_33) {
  // 59
  s21_decimal dec_1 = {{0x3b, 0x0, 0x0, 0x0}};
  // 1915415850736566
  s21_decimal dec_2 = {{0x81615bb6, 0x6ce0f, 0x0, 0x0}};
  // -1915415850736507
  s21_decimal dec_check = {{0x81615b7b, 0x6ce0f, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_34) {
  // -86820436
  s21_decimal dec_1 = {{0x52cc654, 0x0, 0x0, 0x80000000}};
  // -699397180655963024892
  s21_decimal dec_2 = {{0xd4612dfc, 0xea15ee3d, 0x25, 0x80000000}};
  // 699397180655876204456
  s21_decimal dec_check = {{0xcf3467a8, 0xea15ee3d, 0x25, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_35) {
  // 838635
  s21_decimal dec_1 = {{0xccbeb, 0x0, 0x0, 0x0}};
  // 548081629302569499692894776.14
  s21_decimal dec_2 = {{0xcf13fdee, 0xf23a695c, 0xb1183ff1, 0x20000}};
  // -548081629302569499692056141.14
  s21_decimal dec_check = {{0xca145622, 0xf23a695c, 0xb1183ff1, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_36) {
  // 8650.660115348403
  s21_decimal dec_1 = {{0xc33f7bb3, 0x1ebbba, 0x0, 0xc0000}};
  // -3898798203209720094
  s21_decimal dec_2 = {{0x213f211e, 0x361b504f, 0x0, 0x80000000}};
  // 3898798203209728744.6601153484
  s21_decimal dec_check = {{0xe1043bcc, 0x542f19, 0x7dfa1a55, 0xa0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_37) {
  // -3045.35147887598032560224
  s21_decimal dec_1 = {{0xd366a060, 0xe2299367, 0x407c, 0x80140000}};
  // 6586.261661
  s21_decimal dec_2 = {{0x8892609d, 0x1, 0x0, 0x60000}};
  // -9631.61313987598032560224
  s21_decimal dec_check = {{0x465fe060, 0x1457185f, 0xcbf5, 0x80140000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_38) {
  // 9398510.0305371
  s21_decimal dec_1 = {{0x9c8493db, 0x557a, 0x0, 0x70000}};
  // 32064763
  s21_decimal dec_2 = {{0x1e944fb, 0x0, 0x0, 0x0}};
  // -22666252.9694629
  s21_decimal dec_check = {{0xfb90fba5, 0xce25, 0x0, 0x80070000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_39) {
  // -79393365361864204831949
  s21_decimal dec_1 = {{0xae4b4ccd, 0xec472089, 0x10cf, 0x80000000}};
  // 70887.34
  s21_decimal dec_2 = {{0x6c2a5e, 0x0, 0x0, 0x20000}};
  // -79393365361864204902836.34
  s21_decimal dec_check = {{0x15d62a72, 0x4bc8b5c8, 0x69138, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

// START_TEST(s21_sub_40) {
//   // 7247.3
//   s21_decimal dec_1 = {{0x11b19, 0x0, 0x0, 0x10000}};
//   // -9057303473890714342595281846
//   s21_decimal dec_2 = {{0x7ae0c3b6, 0x29a2d629, 0x1d44069d, 0x80000000}};
//   // 9057303473890714342595289093.3
//   s21_decimal dec_check = {{0xccc8c035, 0xa05c5d9e, 0x24a84223, 0x10000}};
//   s21_decimal result;
//   int return_value = s21_sub(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_sub_41) {
  // 26391940180205585
  s21_decimal dec_1 = {{0x6b5fe011, 0x5dc354, 0x0, 0x0}};
  // -5943353897
  s21_decimal dec_2 = {{0x62406229, 0x1, 0x0, 0x80000000}};
  // 26391946123559482
  s21_decimal dec_check = {{0xcda0423a, 0x5dc355, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_42) {
  // 6902308
  s21_decimal dec_1 = {{0x695224, 0x0, 0x0, 0x0}};
  // 3753
  s21_decimal dec_2 = {{0xea9, 0x0, 0x0, 0x0}};
  // 6898555
  s21_decimal dec_check = {{0x69437b, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_43) {
  // 435520.82
  s21_decimal dec_1 = {{0x2988d52, 0x0, 0x0, 0x20000}};
  // -91368124417219437.1817
  s21_decimal dec_2 = {{0x149758e9, 0x87dfdaaf, 0x31, 0x80040000}};
  // 91368124417654958.0017
  s21_decimal dec_check = {{0x182e8cf1, 0x87dfdab0, 0x31, 0x40000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_44) {
  // -688175650459968
  s21_decimal dec_1 = {{0x61305140, 0x271e4, 0x0, 0x80000000}};
  // 5294868545.73915
  s21_decimal dec_2 = {{0xc3e14f5b, 0x1e190, 0x0, 0x50000}};
  // -688180945328513.73915
  s21_decimal dec_check = {{0x1ddb975b, 0xbb0afc5d, 0x3, 0x80050000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_45) {
  // -67
  s21_decimal dec_1 = {{0x43, 0x0, 0x0, 0x80000000}};
  // -109666
  s21_decimal dec_2 = {{0x1ac62, 0x0, 0x0, 0x80000000}};
  // 109599
  s21_decimal dec_check = {{0x1ac1f, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_46) {
  // 636390.77694886
  s21_decimal dec_1 = {{0x209eada6, 0x39e1, 0x0, 0x80000}};
  // 3.0043787627
  s21_decimal dec_2 = {{0xfebfd16b, 0x6, 0x0, 0xa0000}};
  // 636387.7725700973
  s21_decimal dec_check = {{0xbf3c036d, 0x169be9, 0x0, 0xa0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_47) {
  // -1349
  s21_decimal dec_1 = {{0x545, 0x0, 0x0, 0x80000000}};
  // 849022771.1184359083788777262
  s21_decimal dec_2 = {{0xdcf4b72e, 0x77d7bdc3, 0x1b6ef3a6, 0x130000}};
  // -849024120.1184359083788777262
  s21_decimal dec_check = {{0x907cb72e, 0xc33344ae, 0x1b6ef681, 0x80130000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_48) {
  // -0.3094
  s21_decimal dec_1 = {{0xc16, 0x0, 0x0, 0x80040000}};
  // 843911429224143516316
  s21_decimal dec_2 = {{0x1d47f29c, 0xbf9fada5, 0x2d, 0x0}};
  // -843911429224143516316.3094
  s21_decimal dec_check = {{0xca74f9d6, 0x4d6f01c7, 0x6fb0d, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_49) {
  // 580236921870313681.90
  s21_decimal dec_1 = {{0x149cf1fe, 0x253d909f, 0x3, 0x20000}};
  // -101867443564992.8176321551
  s21_decimal dec_2 = {{0x2ce7c40f, 0x73a9c723, 0xd7b6, 0x800a0000}};
  // 580338789313878674.7176321551
  s21_decimal dec_check = {{0xabae020f, 0x136b632e, 0x12c07330, 0xa0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_50) {
  // -139128267
  s21_decimal dec_1 = {{0x84aedcb, 0x0, 0x0, 0x80000000}};
  // -38745480.0229
  s21_decimal dec_2 = {{0x361b1165, 0x5a, 0x0, 0x80040000}};
  // -100382786.9771
  s21_decimal dec_check = {{0xb8cdb84b, 0xe9, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

// START_TEST(s21_sub_51) {
//   // -8456415761151240581.36528984
//   s21_decimal dec_1 = {{0xaf44858, 0xb2ca9dc0, 0x2bb7f91, 0x80080000}};
//   // 8213925827470882458828800530
//   s21_decimal dec_2 = {{0x56a00212, 0x56c4870b, 0x1a8a6673, 0x0}};
//   // -8213925835927298219980041111.4
//   s21_decimal dec_check = {{0x1e97b3ea, 0xf93d83c0, 0x9680085, 0x80010000}};
//   s21_decimal result;
//   int return_value = s21_sub(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_sub_52) {
  // -4306
  s21_decimal dec_1 = {{0x10d2, 0x0, 0x0, 0x80000000}};
  // 78839567.583
  s21_decimal dec_2 = {{0x5b3454df, 0x12, 0x0, 0x30000}};
  // -78843873.583
  s21_decimal dec_check = {{0x5b76092f, 0x12, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

// START_TEST(s21_sub_53) {
//   // 7204919844517271635438
//   s21_decimal dec_1 = {{0x7ea105ee, 0x94594949, 0x186, 0x0}};
//   // 0.0
//   s21_decimal dec_2 = {{0x0, 0x0, 0x0, 0x10000}};
//   // 7204919844517271635438.0
//   s21_decimal dec_check = {{0xf24a3b4c, 0xcb7cdcde, 0xf41, 0x10000}};
//   s21_decimal result;
//   int return_value = s21_sub(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_sub_54) {
  // -3027737
  s21_decimal dec_1 = {{0x2e3319, 0x0, 0x0, 0x80000000}};
  // -111184198678.636678
  s21_decimal dec_2 = {{0x8ae06886, 0x18b0170, 0x0, 0x80060000}};
  // 111181170941.636678
  s21_decimal dec_check = {{0x97b03046, 0x18afeaf, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_55) {
  // -0.01101
  s21_decimal dec_1 = {{0x44d, 0x0, 0x0, 0x80050000}};
  // -8356624446539
  s21_decimal dec_2 = {{0xada1b44b, 0x799, 0x0, 0x80000000}};
  // 8356624446538.98899
  s21_decimal dec_check = {{0xddbaec93, 0xb98de90, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

// START_TEST(s21_sub_56) {
//   // -87
//   s21_decimal dec_1 = {{0x57, 0x0, 0x0, 0x80000000}};
//   // -6420854762.34894808017389790
//   s21_decimal dec_2 = {{0x4285c8de, 0x69aad841, 0x2131ee3, 0x80110000}};
//   // 6420854675.34894808017389790
//   s21_decimal dec_check = {{0x789fc8de, 0xf0ee3c59, 0x2131ee2, 0x110000}};
//   s21_decimal result;
//   int return_value = s21_sub(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_sub_57) {
  // 648682004331701.1192494556136
  s21_decimal dec_1 = {{0x4ac203e8, 0x2ca19a87, 0x14f5c593, 0xd0000}};
  // -37732567230763958278662097911
  s21_decimal dec_2 = {{0x1b178bf7, 0x40a2a6f0, 0x79eba5e8, 0x80000000}};
  // 37732567230764606960666429612
  s21_decimal dec_check = {{0x278848ac, 0x40a4f4e9, 0x79eba5e8, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_58) {
  // -6590587422446498436.29652
  s21_decimal dec_1 = {{0x94e51e54, 0xa560b4a3, 0x8b8f, 0x80050000}};
  // 16
  s21_decimal dec_2 = {{0x10, 0x0, 0x0, 0x0}};
  // -6590587422446498452.29652
  s21_decimal dec_check = {{0x94fd8854, 0xa560b4a3, 0x8b8f, 0x80050000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_59) {
  // -1059622774899
  s21_decimal dec_1 = {{0xb6706873, 0xf6, 0x0, 0x80000000}};
  // -4054435756160426365455.3
  s21_decimal dec_2 = {{0xf4f43499, 0xe9fdb510, 0x895, 0x80010000}};
  // 4054435755100803590556.3
  s21_decimal dec_check = {{0xd490201b, 0xe9fdab6d, 0x895, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_60) {
  // -8636700134.01
  s21_decimal dec_1 = {{0x16be8dd9, 0xc9, 0x0, 0x80020000}};
  // -195297642.509339537654722
  s21_decimal dec_2 = {{0xdae743c2, 0x1b3dfafc, 0x295b, 0x800f0000}};
  // -8441402491.500660462345278
  s21_decimal dec_check = {{0x86625c3e, 0x5893d0a5, 0x6fb89, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_61) {
  // -5116534889459170.3648
  s21_decimal dec_1 = {{0xe7105a60, 0xc60fd5bb, 0x2, 0x80040000}};
  // -99482343
  s21_decimal dec_2 = {{0x5edfae7, 0x0, 0x0, 0x80000000}};
  // -5116534789976827.3648
  s21_decimal dec_check = {{0x46f77af0, 0xc60fd4d4, 0x2, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_62) {
  // -1416541857329.7735
  s21_decimal dec_1 = {{0x8627f847, 0x32535f, 0x0, 0x80040000}};
  // 37.7049
  s21_decimal dec_2 = {{0x5c0d9, 0x0, 0x0, 0x40000}};
  // -1416541857367.4784
  s21_decimal dec_check = {{0x862db920, 0x32535f, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_63) {
  // 265090.2038538019515261211
  s21_decimal dec_1 = {{0x3225e11b, 0xaffd7962, 0x23159, 0x130000}};
  // -43643814477418214329581844
  s21_decimal dec_2 = {{0x99428114, 0xec70f47c, 0x2419ef, 0x80000000}};
  // 43643814477418214329846934.204
  s21_decimal dec_check = {{0xbb952abc, 0x993b06b6, 0x8d055133, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_64) {
  // 907
  s21_decimal dec_1 = {{0x38b, 0x0, 0x0, 0x0}};
  // -4925
  s21_decimal dec_2 = {{0x133d, 0x0, 0x0, 0x80000000}};
  // 5832
  s21_decimal dec_check = {{0x16c8, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_65) {
  // -2957134157334658817448
  s21_decimal dec_1 = {{0x126e1da8, 0x4e7af887, 0xa0, 0x80000000}};
  // 0.4204346051176750322736943469
  s21_decimal dec_2 = {{0x91d7d16d, 0x20da8304, 0xd95c0e8, 0x1c0000}};
  // -2957134157334658817448.4204346
  s21_decimal dec_check = {{0x586f6b3a, 0xdb4e59b7, 0x5f8cd726, 0x80070000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_66) {
  // -7.2
  s21_decimal dec_1 = {{0x48, 0x0, 0x0, 0x80010000}};
  // -827576415899273696320
  s21_decimal dec_2 = {{0x97249440, 0xdcee0d92, 0x2c, 0x80000000}};
  // 827576415899273696312.8
  s21_decimal dec_check = {{0xe76dca38, 0xa14c87b9, 0x1c0, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_67) {
  // 107485503
  s21_decimal dec_1 = {{0x668193f, 0x0, 0x0, 0x0}};
  // -1167903.610126095690758971
  s21_decimal dec_2 = {{0xdef3fb3b, 0x2e7b3728, 0xf750, 0x80120000}};
  // 108653406.610126095690758971
  s21_decimal dec_check = {{0xd48ffb3b, 0xf9881157, 0x59e040, 0x120000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

// START_TEST(s21_sub_68) {
//   // -926566722375760105756
//   s21_decimal dec_1 = {{0x12a511c, 0x3ab244d7, 0x32, 0x80000000}};
//   // 2347907.331747627798155050001
//   s21_decimal dec_2 = {{0xaf693c11, 0x7e67c86d, 0x79624b7, 0x150000}};
//   // -926566722375762453663.33174763
//   s21_decimal dec_check = {{0xd754f3eb, 0xc34bbea5, 0x2b63cd8a, 0x80080000}};
//   s21_decimal result;
//   int return_value = s21_sub(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_sub_69) {
  // -685023553676968483431475519
  s21_decimal dec_1 = {{0x1f75693f, 0x4148b1f3, 0x236a361, 0x80000000}};
  // 846326302963368598027
  s21_decimal dec_2 = {{0x29361a0b, 0xe1230884, 0x2d, 0x0}};
  // -685024400003271446800073546
  s21_decimal dec_check = {{0x48ab834a, 0x226bba77, 0x236a38f, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_70) {
  // -2401709.388216744042688
  s21_decimal dec_1 = {{0xbc460c0, 0x3269cbc8, 0x82, 0x800f0000}};
  // -41243612304.43104011
  s21_decimal dec_2 = {{0xf1f4470b, 0x393cacaf, 0x0, 0x80080000}};
  // 41241210595.042823365957312
  s21_decimal dec_check = {{0x3e8796c0, 0x81934d00, 0x221d2a, 0xf0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_71) {
  // 644453.3262613
  s21_decimal dec_1 = {{0x7c1da915, 0x5dc, 0x0, 0x70000}};
  // -787
  s21_decimal dec_2 = {{0x313, 0x0, 0x0, 0x80000000}};
  // 645240.3262613
  s21_decimal dec_check = {{0x51345495, 0x5de, 0x0, 0x70000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_72) {
  // 4634627282503.7604146964
  s21_decimal dec_1 = {{0x5a224f14, 0x6fbd6d4b, 0x9d0, 0xa0000}};
  // 726814242
  s21_decimal dec_2 = {{0x2b524e22, 0x0, 0x0, 0x0}};
  // 4633900468261.7604146964
  s21_decimal dec_check = {{0x89160714, 0xadfcc45, 0x9d0, 0xa0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_73) {
  // -43
  s21_decimal dec_1 = {{0x2b, 0x0, 0x0, 0x80000000}};
  // -37975808289320
  s21_decimal dec_2 = {{0xee902a28, 0x2289, 0x0, 0x80000000}};
  // 37975808289277
  s21_decimal dec_check = {{0xee9029fd, 0x2289, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_74) {
  // 7
  s21_decimal dec_1 = {{0x7, 0x0, 0x0, 0x0}};
  // 428880579.416425
  s21_decimal dec_2 = {{0x8a965169, 0x18610, 0x0, 0x60000}};
  // -428880572.416425
  s21_decimal dec_check = {{0x8a2b81a9, 0x18610, 0x0, 0x80060000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_75) {
  // -6704718714766692334
  s21_decimal dec_1 = {{0xe0950fee, 0x5d0bf225, 0x0, 0x80000000}};
  // 73537.540817
  s21_decimal dec_2 = {{0x1f2dd2d1, 0x11, 0x0, 0x60000}};
  // -6704718714766765871.540817
  s21_decimal dec_check = {{0xa17f2a51, 0x87a2762b, 0x58bc7, 0x80060000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_76) {
  // -778872799433795874582657313
  s21_decimal dec_1 = {{0xbda37921, 0xfd215ed, 0x28444bb, 0x80000000}};
  // -886791547878525566605
  s21_decimal dec_2 = {{0x5e52fe8d, 0x12b4765f, 0x30, 0x80000000}};
  // -778871912642247996057090708
  s21_decimal dec_check = {{0x5f507a94, 0xfd1d9f8e, 0x284448a, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_77) {
  // -773549547804308401
  s21_decimal dec_1 = {{0x1d0a33b1, 0xabc3337, 0x0, 0x80000000}};
  // -0.1518
  s21_decimal dec_2 = {{0x5ee, 0x0, 0x0, 0x80040000}};
  // -773549547804308400.8482
  s21_decimal dec_check = {{0x5e832c22, 0x579098de, 0x1a3, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_78) {
  // 94.8312585058053
  s21_decimal dec_1 = {{0x3ac4b705, 0x35e7c, 0x0, 0xd0000}};
  // 50715965428
  s21_decimal dec_2 = {{0xcee837f4, 0xb, 0x0, 0x0}};
  // -50715965333.1687414941947
  s21_decimal dec_check = {{0x2adbc8fb, 0x2e0dba2a, 0x6b65, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_79) {
  // 41
  s21_decimal dec_1 = {{0x29, 0x0, 0x0, 0x0}};
  // 983980380721993
  s21_decimal dec_2 = {{0xc90f1349, 0x37eec, 0x0, 0x0}};
  // -983980380721952
  s21_decimal dec_check = {{0xc90f1320, 0x37eec, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_80) {
  // 433316
  s21_decimal dec_1 = {{0x69ca4, 0x0, 0x0, 0x0}};
  // 7139445.7468316481776895
  s21_decimal dec_2 = {{0xf22c6cff, 0x4d21a362, 0xf1e, 0x100000}};
  // -6706129.7468316481776895
  s21_decimal dec_check = {{0xbe886cff, 0x6674d573, 0xe33, 0x80100000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_81) {
  // 31242305903455008841931
  s21_decimal dec_1 = {{0x8545e0cb, 0xa6178a5c, 0x69d, 0x0}};
  // -2780928
  s21_decimal dec_2 = {{0x2a6f00, 0x0, 0x0, 0x80000000}};
  // 31242305903455011622859
  s21_decimal dec_check = {{0x85704fcb, 0xa6178a5c, 0x69d, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_82) {
  // -4395838594610
  s21_decimal dec_1 = {{0x7c65de32, 0x3ff, 0x0, 0x80000000}};
  // 57494862687811240987.316869
  s21_decimal dec_2 = {{0x809d285, 0xc06bbe58, 0x2f8f02, 0x60000}};
  // -57494867083649835597.316869
  s21_decimal dec_check = {{0x69b84305, 0xfd6ce641, 0x2f8f02, 0x80060000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_83) {
  // 7410272596759368202753188572
  s21_decimal dec_1 = {{0xdba4a2dc, 0x67e38417, 0x17f1a242, 0x0}};
  // 31183841562171238854.906664
  s21_decimal dec_2 = {{0xedc75328, 0x703b792c, 0x19cb6f, 0x60000}};
  // 7410272565575526640581949717.1
  s21_decimal dec_check = {{0x5fa43ad3, 0x27428e1d, 0xef705687, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_84) {
  // 5842139.183123150746448461610
  s21_decimal dec_1 = {{0x2b3e7f2a, 0xb71a0094, 0x12e08117, 0x150000}};
  // -557388782763
  s21_decimal dec_2 = {{0xc6f5dcab, 0x81, 0x0, 0x80000000}};
  // 557394624902.18312315074644846
  s21_decimal dec_check = {{0x9b460b6e, 0x40e207e8, 0xb41a9a4c, 0x110000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_85) {
  // -83159221271.711305
  s21_decimal dec_1 = {{0x3b2ce49, 0x12770df, 0x0, 0x80060000}};
  // 294382156569037323
  s21_decimal dec_2 = {{0xfe82ca0b, 0x415db02, 0x0, 0x0}};
  // -294382239728258594.711305
  s21_decimal dec_check = {{0x33212709, 0x7e41e0e6, 0x3e56, 0x80060000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

// START_TEST(s21_sub_86) {
//   // -776530103487.5653839693054
//   s21_decimal dec_1 = {{0x6a20a4fe, 0xd0069b3e, 0x66c5d, 0x800d0000}};
//   // -9234374537659039700
//   s21_decimal dec_2 = {{0x58143fd4, 0x802716b7, 0x0, 0x80000000}};
//   // 9234373761128936212.4346160307
//   s21_decimal dec_check = {{0x2e66f4b3, 0xadf80306, 0x2a60f30e, 0xa0000}};
//   s21_decimal result;
//   int return_value = s21_sub(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_sub_87) {
  // 90697253
  s21_decimal dec_1 = {{0x567ee25, 0x0, 0x0, 0x0}};
  // 30705922910.797841622254
  s21_decimal dec_2 = {{0x29dce4ee, 0x9248586b, 0x680, 0xc0000}};
  // -30615225657.797841622254
  s21_decimal dec_check = {{0x892194ee, 0xa79af959, 0x67b, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_88) {
  // -7278.4
  s21_decimal dec_1 = {{0x11c50, 0x0, 0x0, 0x80010000}};
  // -56263183086169994
  s21_decimal dec_2 = {{0x21c8af8a, 0xc7e311, 0x0, 0x80000000}};
  // 56263183086162715.6
  s21_decimal dec_check = {{0x51d5bf14, 0x7cedeab, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_89) {
  // -50295758829707.06988167
  s21_decimal dec_1 = {{0xca3cc87, 0xa76309ba, 0x110, 0x80080000}};
  // 33379740
  s21_decimal dec_2 = {{0x1fd559c, 0x0, 0x0, 0x0}};
  // -50295792209447.06988167
  s21_decimal dec_check = {{0xaf2de887, 0xa76ee598, 0x110, 0x80080000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_90) {
  // -351326.5
  s21_decimal dec_1 = {{0x359bb1, 0x0, 0x0, 0x80010000}};
  // 888.86992158494084
  s21_decimal dec_2 = {{0x98c28d84, 0x13bca3f, 0x0, 0xe0000}};
  // -352215.36992158494084
  s21_decimal dec_check = {{0x5ce32d84, 0xe8cc0948, 0x1, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_91) {
  // -0.818329291655
  s21_decimal dec_1 = {{0x883a0b87, 0xbe, 0x0, 0x800c0000}};
  // -40124348224685922104087222899
  s21_decimal dec_2 = {{0x52b51a73, 0xbd0c4550, 0x81a6153b, 0x80000000}};
  // 40124348224685922104087222898
  s21_decimal dec_check = {{0x52b51a72, 0xbd0c4550, 0x81a6153b, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_92) {
  // 69187503.36
  s21_decimal dec_1 = {{0x9c63c080, 0x1, 0x0, 0x20000}};
  // -978271428575.797405
  s21_decimal dec_2 = {{0x622ca09d, 0xd9384ae, 0x0, 0x80060000}};
  // 978340616079.157405
  s21_decimal dec_check = {{0x5abc289d, 0xd93c39b, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_93) {
  // -5889561442193741801268723117
  s21_decimal dec_1 = {{0xcb0c3dad, 0x87d9b654, 0x1307bb25, 0x80000000}};
  // -2.656921393
  s21_decimal dec_2 = {{0x9e5d6731, 0x0, 0x0, 0x80090000}};
  // -5889561442193741801268723114.3
  s21_decimal dec_check = {{0xee7a68a7, 0x4e811f4f, 0xbe4d4f77, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

// START_TEST(s21_sub_94) {
//   // 551
//   s21_decimal dec_1 = {{0x227, 0x0, 0x0, 0x0}};
//   // 469.60
//   s21_decimal dec_2 = {{0xb770, 0x0, 0x0, 0x20000}};
//   // 81.40
//   s21_decimal dec_check = {{0x1fcc, 0x0, 0x0, 0x20000}};
//   s21_decimal result;
//   int return_value = s21_sub(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_sub_95) {
  // -517406263514107
  s21_decimal dec_1 = {{0x88a93fb, 0x1d694, 0x0, 0x80000000}};
  // 65
  s21_decimal dec_2 = {{0x41, 0x0, 0x0, 0x0}};
  // -517406263514172
  s21_decimal dec_check = {{0x88a943c, 0x1d694, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_96) {
  // 0
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
  // -3769599526111225202
  s21_decimal dec_2 = {{0xfb572572, 0x34504ecb, 0x0, 0x80000000}};
  // 3769599526111225202
  s21_decimal dec_check = {{0xfb572572, 0x34504ecb, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_97) {
  // -5166
  s21_decimal dec_1 = {{0x142e, 0x0, 0x0, 0x80000000}};
  // -0.54292686
  s21_decimal dec_2 = {{0x33c70ce, 0x0, 0x0, 0x80080000}};
  // -5165.45707314
  s21_decimal dec_check = {{0x4485fd32, 0x78, 0x0, 0x80080000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

// START_TEST(s21_sub_98) {
//   // -216149799269856432135787759
//   s21_decimal dec_1 = {{0xa60ad4ef, 0x18f80060, 0xb2cb80, 0x80000000}};
//   // -529.901
//   s21_decimal dec_2 = {{0x815ed, 0x0, 0x0, 0x80030000}};
//   // -216149799269856432135787229.10
//   s21_decimal dec_check = {{0xdc3a5e5e, 0xc0e025c0, 0x45d77e09, 0x80020000}};
//   s21_decimal result;
//   int return_value = s21_sub(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_sub_99) {
  // 0.11
  s21_decimal dec_1 = {{0xb, 0x0, 0x0, 0x20000}};
  // -797993630163537505251801
  s21_decimal dec_2 = {{0x6e6b71d9, 0x52457a48, 0xa8fb, 0x80000000}};
  // 797993630163537505251801.11
  s21_decimal dec_check = {{0x21f878cf, 0x2323c44b, 0x42022c, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_100) {
  // -309330742091
  s21_decimal dec_1 = {{0x58c8b4b, 0x48, 0x0, 0x80000000}};
  // 373340
  s21_decimal dec_2 = {{0x5b25c, 0x0, 0x0, 0x0}};
  // -309331115431
  s21_decimal dec_check = {{0x5923da7, 0x48, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(fail_s21_sub_1) {
  // 7828730740673037869877105476
  s21_decimal dec_1 = {{0x37b91344, 0xd793142c, 0x194bc637, 0x0}};
  // -79228162514264337592932885829
  s21_decimal dec_2 = {{0xdb93e545, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_2) {
  // -98428948422
  s21_decimal dec_1 = {{0xead28fc6, 0x16, 0x0, 0x80000000}};
  // 79228162514264337593119797013
  s21_decimal dec_2 = {{0xe6b7ef15, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_3) {
  // -5817577964138442407192284
  s21_decimal dec_1 = {{0x7fea6dc, 0x888aaeda, 0x4cfeb, 0x80000000}};
  // 79228162514264337592864972515
  s21_decimal dec_2 = {{0xd7879ee3, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_4) {
  // -79228162514264337592825007854
  s21_decimal dec_1 = {{0xd525ceee, 0xffffffff, 0xffffffff, 0x80000000}};
  // 16832528706
  s21_decimal dec_2 = {{0xeb4c0142, 0x3, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_5) {
  // 5836255799092534579
  s21_decimal dec_1 = {{0x3b395d33, 0x50fe8bba, 0x0, 0x0}};
  // -79228162514264337591496736313
  s21_decimal dec_2 = {{0x85f9fe39, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_6) {
  // -3430498933453.08015725
  s21_decimal dec_1 = {{0xfab97c6d, 0x98c60c70, 0x12, 0x80080000}};
  // 79228162514264337592496071992
  s21_decimal dec_2 = {{0xc18aa538, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_7) {
  // 79228162514264337592058392884
  s21_decimal dec_1 = {{0xa7743134, 0xffffffff, 0xffffffff, 0x0}};
  // -452361250841
  s21_decimal dec_2 = {{0x52d4e819, 0x69, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_8) {
  // 77220659841376708002.1061033
  s21_decimal dec_1 = {{0x3cbfeda9, 0x94949873, 0x27ec11b, 0x70000}};
  // -79228162514264337593327974047
  s21_decimal dec_2 = {{0xf320769f, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_9) {
  // -79228162514264337593170113825
  s21_decimal dec_1 = {{0xe9b7b521, 0xffffffff, 0xffffffff, 0x80000000}};
  // 536353668362610856201389
  s21_decimal dec_2 = {{0xd1208cad, 0xca664444, 0x7193, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_10) {
  // -79228162514264337592151465531
  s21_decimal dec_1 = {{0xad005e3b, 0xffffffff, 0xffffffff, 0x80000000}};
  // 2636900795027401016911337761
  s21_decimal dec_2 = {{0xb1881921, 0x87a5c375, 0x8853176, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_11) {
  // 79228162514264337592865537625
  s21_decimal dec_1 = {{0xd7903e59, 0xffffffff, 0xffffffff, 0x0}};
  // -37877500384
  s21_decimal dec_2 = {{0xd1acc9e0, 0x8, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_12) {
  // -79228162514264337591754606055
  s21_decimal dec_1 = {{0x9558c5e7, 0xffffffff, 0xffffffff, 0x80000000}};
  // 587695499387223862363
  s21_decimal dec_2 = {{0xcf46ec5b, 0xdbe9d6f2, 0x1f, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_13) {
  // -79228162514264337591751316051
  s21_decimal dec_1 = {{0x95269253, 0xffffffff, 0xffffffff, 0x80000000}};
  // 7197697938
  s21_decimal dec_2 = {{0xad042792, 0x1, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_14) {
  // -993372961312
  s21_decimal dec_1 = {{0x49a47a20, 0xe7, 0x0, 0x80000000}};
  // 79228162514264337591780552715
  s21_decimal dec_2 = {{0x96e4b00b, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_15) {
  // -43043113352.283880144
  s21_decimal dec_1 = {{0xadc0fad0, 0x5557db8a, 0x2, 0x80090000}};
  // 79228162514264337593378589185
  s21_decimal dec_2 = {{0xf624ca01, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_16) {
  // -79228162514264337591863536942
  s21_decimal dec_1 = {{0x9bd6ed2e, 0xffffffff, 0xffffffff, 0x80000000}};
  // 93739886420
  s21_decimal dec_2 = {{0xd3552754, 0x15, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_17) {
  // -79228162514264337592371847813
  s21_decimal dec_1 = {{0xba232285, 0xffffffff, 0xffffffff, 0x80000000}};
  // 400045439820604521916
  s21_decimal dec_2 = {{0x3a0a3dbc, 0xafbee7fc, 0x15, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_18) {
  // 231161185823
  s21_decimal dec_1 = {{0xd247c61f, 0x35, 0x0, 0x0}};
  // -79228162514264337591952442614
  s21_decimal dec_2 = {{0xa12384f6, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_19) {
  // -16565251882542993128065098273
  s21_decimal dec_1 = {{0x54346221, 0xf0ee3d9a, 0x35867487, 0x80000000}};
  // 79228162514264337591543015474
  s21_decimal dec_2 = {{0x88bc2832, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_20) {
  // 4435359056622269549305211
  s21_decimal dec_1 = {{0x1f8dd7b, 0x4bd6da87, 0x3ab39, 0x0}};
  // -79228162514264337592387826838
  s21_decimal dec_2 = {{0xbb16f496, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_21) {
  // -79228162514264337591875272789
  s21_decimal dec_1 = {{0x9c8a0055, 0xffffffff, 0xffffffff, 0x80000000}};
  // 9108606559340142897114
  s21_decimal dec_2 = {{0x639a7da, 0xc74f1e41, 0x1ed, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_22) {
  // 658334600211159282704.4176620
  s21_decimal dec_1 = {{0x97b22ec, 0xe2ba7283, 0x15459dbd, 0x70000}};
  // -79228162514264337591484262016
  s21_decimal dec_2 = {{0x853ba680, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_23) {
  // 79228162514264337593294192529
  s21_decimal dec_1 = {{0xf11cff91, 0xffffffff, 0xffffffff, 0x0}};
  // -1415665846141778784622045016
  s21_decimal dec_2 = {{0xf2d6758, 0x4b869535, 0x49302e7, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_24) {
  // 79228162514264337593011352486
  s21_decimal dec_1 = {{0xe04133a6, 0xffffffff, 0xffffffff, 0x0}};
  // -2721618278245
  s21_decimal dec_2 = {{0xad173765, 0x279, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_25) {
  // -760635981
  s21_decimal dec_1 = {{0x2d56624d, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593457099699
  s21_decimal dec_2 = {{0xfad2c3b3, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_26) {
  // 79228162514264337593384087338
  s21_decimal dec_1 = {{0xf678af2a, 0xffffffff, 0xffffffff, 0x0}};
  // -529456429
  s21_decimal dec_2 = {{0x1f8edd2d, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_27) {
  // -2570190255232.8891716897974395
  s21_decimal dec_1 = {{0xffa5a87b, 0x36585c79, 0x530c1d91, 0x80100000}};
  // 79228162514264337593372096976
  s21_decimal dec_2 = {{0xf5c1b9d0, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_28) {
  // 79228162514264337592595966780
  s21_decimal dec_1 = {{0xc77eeb3c, 0xffffffff, 0xffffffff, 0x0}};
  // -4980715069649466141
  s21_decimal dec_2 = {{0x85e4331d, 0x451f0df7, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_29) {
  // 4285740902
  s21_decimal dec_1 = {{0xff733766, 0x0, 0x0, 0x0}};
  // -79228162514264337593054688704
  s21_decimal dec_2 = {{0xe2d675c0, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_30) {
  // -65476866188.5
  s21_decimal dec_1 = {{0x7340e57d, 0x98, 0x0, 0x80010000}};
  // 79228162514264337593372281999
  s21_decimal dec_2 = {{0xf5c48c8f, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_31) {
  // 79228162514264337591710174531
  s21_decimal dec_1 = {{0x92b2cd43, 0xffffffff, 0xffffffff, 0x0}};
  // -690620615228.39578530857793
  s21_decimal dec_2 = {{0xcb6cc341, 0xdb625a9a, 0x392075, 0x800e0000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_32) {
  // -79228162514264337593242264332
  s21_decimal dec_1 = {{0xee04a30c, 0xffffffff, 0xffffffff, 0x80000000}};
  // 2025776878.266488
  s21_decimal dec_2 = {{0xef392878, 0x7326e, 0x0, 0x60000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_33) {
  // 79228162514264337593050275518
  s21_decimal dec_1 = {{0xe2931ebe, 0xffffffff, 0xffffffff, 0x0}};
  // -44546065215082644639.5
  s21_decimal dec_2 = {{0xbfdbae3b, 0x260226fa, 0x18, 0x80010000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(invalid_dec_s21_mul_1) {
  // ссылка на результат - NULL
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x0}};
  int result_value = s21_mul(dec_1, dec_2, NULL);

  ck_assert_int_eq(result_value, 1);
}

START_TEST(invalid_dec_s21_mul_2) {
  // степень 56 (допустимое значение от 0 до 28)
  // биты 0-15 не пустые
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x380000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_3) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_4) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_5) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C8000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x140000}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_6) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_7) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0xA, 0x0, 0x0, 0x401C0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_8) {
  // Все биты имеют максимальное значение
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_9) {
  // степень 56 (допустимое значение от 0 до 28)
  // биты 0-15 не пустые
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x380000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_10) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_11) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_12) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_13) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C8000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_14) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_15) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x401C0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_16) {
  // Все биты имеют максимальное значение
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(s21_mul_1) {
  // -2041879027
  s21_decimal dec_1 = {{0x79b499f3, 0x0, 0x0, 0x80000000}};
  // -8480046.57913249301712
  s21_decimal dec_2 = {{0x6bde84d0, 0xf86dbf73, 0x2d, 0x800e0000}};
  // 17315229257913733.345881279942
  s21_decimal dec_check = {{0xc032cdc6, 0xecfcc46e, 0x37f2d26a, 0xc0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_2) {
  // -1.994206
  s21_decimal dec_1 = {{0x1e6dde, 0x0, 0x0, 0x80060000}};
  // 88554568842363486
  s21_decimal dec_2 = {{0x4316425e, 0x13a9be9, 0x0, 0x0}};
  // -176596052512854317.962116
  s21_decimal dec_check = {{0x6e939384, 0x4a8b6274, 0x2565, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_3) {
  // 5
  s21_decimal dec_1 = {{0x5, 0x0, 0x0, 0x0}};
  // -27948651161265692961033
  s21_decimal dec_2 = {{0xf64f6909, 0x197348de, 0x5eb, 0x80000000}};
  // -139743255806328464805165
  s21_decimal dec_check = {{0xcf8d0d2d, 0x7f406c5a, 0x1d97, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_4) {
  // -9611254239674
  s21_decimal dec_1 = {{0xcb6511ba, 0x8bd, 0x0, 0x80000000}};
  // 89686904565.04917508956
  s21_decimal dec_2 = {{0x5b97435c, 0x31954408, 0x1e6, 0xb0000}};
  // DEFECT: Ожидаемое значение больше максимума dec
  // -862003641744066308999829.89866
  // -862003641744066308999829.8987
  // s21_decimal dec_check = {{0x35a6fa2a, 0x58bf1636, 0x16874521, 0x80050000}};
  s21_decimal dec_check = s21_dec_init("-862003641744066308999829.8987");
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_5) {
  // -1679.60
  s21_decimal dec_1 = {{0x29018, 0x0, 0x0, 0x80020000}};
  // -919699791213877122270
  s21_decimal dec_2 = {{0xa811d4de, 0xdb660754, 0x31, 0x80000000}};
  // DEFECT: При произведении убираем конечные нули
  // 1544727769322828014564692.00
  // s21_decimal dec_check = {{0x7324d4d0, 0x4599e9d, 0x7fc6e2, 0x20000}};
  s21_decimal dec_check = s21_dec_init("1544727769322828014564692");
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_6) {
  // 831328007101882
  s21_decimal dec_1 = {{0xa28e1dba, 0x2f416, 0x0, 0x0}};
  // -128870.6120096469845
  s21_decimal dec_2 = {{0x6c38d355, 0x11e26763, 0x0, 0x800d0000}};
  // -107133749055979688090.71174557
  s21_decimal dec_check = {{0x2ab7639d, 0x5d73eddb, 0x229de561, 0x80080000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_7) {
  // -6100.14147645
  s21_decimal dec_1 = {{0x7ad343d, 0x8e, 0x0, 0x80080000}};
  // 3405821603160726488212778
  s21_decimal dec_2 = {{0x169fe52a, 0xf5851a76, 0x2d135, 0x0}};
  // -20775993622830180066460919111
  s21_decimal dec_check = {{0xff9b6547, 0x1224c188, 0x43217fc7, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_8) {
  // 9042523831050258684525
  s21_decimal dec_1 = {{0xe3051a6d, 0x323a1afe, 0x1ea, 0x0}};
  // -9
  s21_decimal dec_2 = {{0x9, 0x0, 0x0, 0x80000000}};
  // -81382714479452328160725
  s21_decimal dec_check = {{0xfb2dedd5, 0xc40af2f5, 0x113b, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_9) {
  // 871360885938226907660349.735
  s21_decimal dec_1 = {{0x5282f127, 0x47147638, 0x2d0c5d8, 0x30000}};
  // -469.1
  s21_decimal dec_2 = {{0x1253, 0x0, 0x0, 0x80010000}};
  // -408755391593622242383470060.69
  s21_decimal dec_check = {{0xccb1b075, 0xe7a3b3f0, 0x84137419, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_10) {
  // -93925460
  s21_decimal dec_1 = {{0x5993054, 0x0, 0x0, 0x80000000}};
  // -30182716.8493
  s21_decimal dec_2 = {{0x464d18ed, 0x46, 0x0, 0x80040000}};
  // DEFECT: При произведении убираем последние нули
  // 2834925564120253.1780
  // s21_decimal dec_check = {{0xc9d9dc4, 0x896cc9ce, 0x1, 0x40000}};
  s21_decimal dec_check = s21_dec_init("2834925564120253.178");
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_11) {
  // -6588.98483258
  s21_decimal dec_1 = {{0x6968f83a, 0x99, 0x0, 0x80080000}};
  // 284622
  s21_decimal dec_2 = {{0x457ce, 0x0, 0x0, 0x0}};
  // -1875370041.01858476
  s21_decimal dec_check = {{0x5fbb74ac, 0x29a43e9, 0x0, 0x80080000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_12) {
  // -6527622816642
  s21_decimal dec_1 = {{0xd4a3a382, 0x5ef, 0x0, 0x80000000}};
  // -9695532124.28312451053404
  s21_decimal dec_2 = {{0xfa85775c, 0x95c01e78, 0xcd4f, 0x800e0000}};
  // 63288776713956002822520.597784
  s21_decimal dec_check = {{0xc3206d18, 0x5c6e1bfa, 0xcc7f3fc4, 0x60000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_13) {
  // 6937
  s21_decimal dec_1 = {{0x1b19, 0x0, 0x0, 0x0}};
  // -1.93690850
  s21_decimal dec_2 = {{0xb8b7ce2, 0x0, 0x0, 0x80080000}};
  // DEFECT: При произведении убираем последние нули
  // -13436.33426450
  // s21_decimal dec_check = {{0xd6cb0812, 0x138, 0x0, 0x80080000}};
  s21_decimal dec_check = s21_dec_init("-13436.3342645");
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_14) {
  // -999
  s21_decimal dec_1 = {{0x3e7, 0x0, 0x0, 0x80000000}};
  // 63
  s21_decimal dec_2 = {{0x3f, 0x0, 0x0, 0x0}};
  // -62937
  s21_decimal dec_check = {{0xf5d9, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_15) {
  // 100594524025
  s21_decimal dec_1 = {{0x6be69f79, 0x17, 0x0, 0x0}};
  // -7484834.77200573832032457
  s21_decimal dec_2 = {{0xf0af0c9, 0x5edfce80, 0x9e7f, 0x80110000}};
  // -752933391295686640.90175310266
  s21_decimal dec_check = {{0x87af89ba, 0xe5f79858, 0xf34930bc, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_16) {
  // 3948100264611044025555804
  s21_decimal dec_1 = {{0x6159db5c, 0xf1b75c0a, 0x3440a, 0x0}};
  // -6.61911220
  s21_decimal dec_2 = {{0x2773f6b4, 0x0, 0x0, 0x80080000}};
  // -26132918628310189764293534.037
  s21_decimal dec_check = {{0xbda155, 0x829208ec, 0x5470a4c5, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_17) {
  // -40
  s21_decimal dec_1 = {{0x28, 0x0, 0x0, 0x80000000}};
  // -31026988005782128053
  s21_decimal dec_2 = {{0x6f305b5, 0xae960134, 0x1, 0x80000000}};
  // 1241079520231285122120
  s21_decimal dec_check = {{0x15f8e448, 0x47703021, 0x43, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_18) {
  // 2096208.92361308679
  s21_decimal dec_1 = {{0x4ab23a07, 0x2e8b917, 0x0, 0xb0000}};
  // 8.4924274
  s21_decimal dec_2 = {{0x50fd772, 0x0, 0x0, 0x70000}};
  // 17801902.099016285253974046
  s21_decimal dec_check = {{0x7b82b81e, 0xbe7d7ae, 0xeb9b3, 0x120000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_19) {
  // -67242198.57173026010
  s21_decimal dec_1 = {{0x6a6d14da, 0x5d513a55, 0x0, 0x800b0000}};
  // 256103
  s21_decimal dec_2 = {{0x3e867, 0x0, 0x0, 0x0}};
  // DEFECT: При произведении убираем конечные нули
  // -17220928780815.83480239030
  // s21_decimal dec_check = {{0xeb56f3b6, 0xd78c2017, 0x16caa, 0x800b0000}};
  s21_decimal dec_check = s21_dec_init("-17220928780815.8348023903");
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_20) {
  // -46003590.3419981969078
  s21_decimal dec_1 = {{0x29ef36b6, 0xf047d8c9, 0x18, 0x800d0000}};
  // -77291666619843019
  s21_decimal dec_2 = {{0x7cf941cb, 0x112985c, 0x0, 0x80000000}};
  // 3555694168029554730423315.2587
  s21_decimal dec_check = {{0x6ae4304b, 0xd5f9a8aa, 0x72e40346, 0x40000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_21) {
  // -2073612
  s21_decimal dec_1 = {{0x1fa40c, 0x0, 0x0, 0x80000000}};
  // 7830220685.968774
  s21_decimal dec_2 = {{0x52800586, 0x1bd18b, 0x0, 0x60000}};
  // -16236839577073081.391688
  s21_decimal dec_check = {{0x8cc41a48, 0x336a10e2, 0x370, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_22) {
  // -56.6242708953149
  s21_decimal dec_1 = {{0xa786183d, 0x202fe, 0x0, 0x800d0000}};
  // -99382508581576498078585275
  s21_decimal dec_2 = {{0x1e091bb, 0x95e74666, 0x523510, 0x80000000}};
  // 5627462088179145385319598049.2
  s21_decimal dec_check = {{0x5c804ecc, 0xcab4ce39, 0xb5d5467e, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_23) {
  // -13830827.7035
  s21_decimal dec_1 = {{0x33d0d32b, 0x20, 0x0, 0x80040000}};
  // -7359677765198
  s21_decimal dec_2 = {{0x8efa964e, 0x6b1, 0x0, 0x80000000}};
  // DEFECT: При произведении убираем конечные нули
  // 101790435123733466562.7930
  // s21_decimal dec_check = {{0x3759891a, 0xb49859f7, 0xd78c, 0x40000}};
  s21_decimal dec_check = s21_dec_init("101790435123733466562.793");
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_24) {
  // 308712796.48641567564055
  s21_decimal dec_1 = {{0xd28a2117, 0x89117d63, 0x689, 0xe0000}};
  // 12.2301484067096564953104
  s21_decimal dec_2 = {{0x93097010, 0xfa0b61fd, 0x19e5, 0x160000}};
  // DEFECT: При произведении убираем конечные нули
  // 3775603316.0792191173007081270
  // s21_decimal dec_check = {{0x2697f36, 0xde47bb04, 0x79ff0f02, 0x130000}};
  s21_decimal dec_check = s21_dec_init("3775603316.079219117300708127");
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_25) {
  // -63.99619
  s21_decimal dec_1 = {{0x61a683, 0x0, 0x0, 0x80050000}};
  // -54291277784.957388696
  s21_decimal dec_2 = {{0x76710798, 0xf1715d7f, 0x2, 0x80090000}};
  // 3474434928468.91218889306824
  s21_decimal dec_check = {{0xc75b72c8, 0x7cef5fda, 0x11f6605, 0xe0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_26) {
  // -11056945251143678271383
  s21_decimal dec_1 = {{0x61399f97, 0x65f0a3b5, 0x257, 0x80000000}};
  // -1250797.6
  s21_decimal dec_2 = {{0xbedb48, 0x0, 0x0, 0x80010000}};
  // 13830000583461910037018005081
  s21_decimal dec_check = {{0x35614e59, 0xe73c0965, 0x2cafe889, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_27) {
  // -0.7962
  s21_decimal dec_1 = {{0x1f1a, 0x0, 0x0, 0x80040000}};
  // -7587213700282399
  s21_decimal dec_2 = {{0xd970b81f, 0x1af487, 0x0, 0x80000000}};
  // 6040939548164846.0838
  s21_decimal dec_check = {{0xbbbe7426, 0x46594920, 0x3, 0x40000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_28) {
  // 44481297794
  s21_decimal dec_1 = {{0x5b4abd82, 0xa, 0x0, 0x0}};
  // 64143.896352083304931038711499
  s21_decimal dec_2 = {{0xff19cecb, 0xd4a7e8ec, 0xcf429664, 0x180000}};
  // 2853203755304487.7589332415599
  s21_decimal dec_check = {{0xbaacd46f, 0x5c01c17, 0x5c3125f7, 0xd0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_29) {
  // -32731.825177940952553
  s21_decimal dec_1 = {{0x255b85e9, 0xc63ecd94, 0x1, 0x800f0000}};
  // -7763649149343012831
  s21_decimal dec_2 = {{0x8b5a97df, 0x6bbe05c4, 0x0, 0x80000000}};
  // 254118406699165485878430.43228
  s21_decimal dec_check = {{0xb6193f9c, 0xf176848, 0x521c2e93, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_30) {
  // 6769865095
  s21_decimal dec_1 = {{0x9383f187, 0x1, 0x0, 0x0}};
  // 786593
  s21_decimal dec_2 = {{0xc00a1, 0x0, 0x0, 0x0}};
  // 5325128494671335
  s21_decimal dec_check = {{0x184ee5e7, 0x12eb2d, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_31) {
  // 0.16853
  s21_decimal dec_1 = {{0x41d5, 0x0, 0x0, 0x50000}};
  // 68400002715372.20
  s21_decimal dec_2 = {{0xaa72d444, 0x184cf1, 0x0, 0x20000}};
  // DEFECT: При произведении убираем конечные нули
  // 11527452457621.6768660
  // s21_decimal dec_check = {{0xf96fe094, 0x3fc16159, 0x6, 0x70000}};
  s21_decimal dec_check = s21_dec_init("11527452457621.676866");
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_32) {
  // -1.97
  s21_decimal dec_1 = {{0xc5, 0x0, 0x0, 0x80020000}};
  // -49253324112454
  s21_decimal dec_2 = {{0xaee34246, 0x2ccb, 0x0, 0x80000000}};
  // 97029048501534.38
  s21_decimal dec_check = {{0x94e1ffde, 0x2278bd, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_33) {
  // 70696359892.097573302489512666
  s21_decimal dec_1 = {{0x6d42fada, 0x176a2792, 0xe46ea885, 0x120000}};
  // 9957
  s21_decimal dec_2 = {{0x26e5, 0x0, 0x0, 0x0}};
  // 703923655445615.53737288807762
  s21_decimal dec_check = {{0x30047552, 0x7d88e78e, 0xe3733336, 0xe0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_34) {
  // 62.64911355817981199139
  s21_decimal dec_1 = {{0x89a14323, 0x9f1c4531, 0x153, 0x140000}};
  // -58561435.70436
  s21_decimal dec_2 = {{0x7d5b7604, 0x553, 0x0, 0x80050000}};
  // -3668822035.5724954040855384189
  s21_decimal dec_check = {{0xb4d7507d, 0xb7170639, 0x768bc8da, 0x80130000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_35) {
  // 577502.40
  s21_decimal dec_1 = {{0x37132e0, 0x0, 0x0, 0x20000}};
  // -333040
  s21_decimal dec_2 = {{0x514f0, 0x0, 0x0, 0x80000000}};
  // DEFECT: При произведении убираем конечные нули
  // -192331399296.00
  // s21_decimal dec_check = {{0x10793200, 0x117e, 0x0, 0x80020000}};
  s21_decimal dec_check = s21_dec_init("-192331399296");
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_36) {
  // 6924046.9894845
  s21_decimal dec_1 = {{0x4d9cb6bd, 0x3ef9, 0x0, 0x70000}};
  // 0.0
  s21_decimal dec_2 = {{0x0, 0x0, 0x0, 0x10000}};
  // DEFECT: При произведении убираем конечные нули
  // 0.00000000
  // s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x80000}};
  s21_decimal dec_check = s21_dec_init("0");
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_37) {
  // 0.47
  s21_decimal dec_1 = {{0x2f, 0x0, 0x0, 0x20000}};
  // -4694.77
  s21_decimal dec_2 = {{0x729e5, 0x0, 0x0, 0x80020000}};
  // -2206.5419
  s21_decimal dec_check = {{0x150b10b, 0x0, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_38) {
  // 653979410
  s21_decimal dec_1 = {{0x26faef12, 0x0, 0x0, 0x0}};
  // 0
  s21_decimal dec_2 = {{0x0, 0x0, 0x0, 0x0}};
  // 0
  s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_39) {
  // 653383226513.65
  s21_decimal dec_1 = {{0xc38308e5, 0x3b6c, 0x0, 0x20000}};
  // 39.93765
  s21_decimal dec_2 = {{0x3cf0a5, 0x0, 0x0, 0x50000}};
  // 26094590616372.8739225
  s21_decimal dec_check = {{0xf1776b99, 0x255a171a, 0xe, 0x70000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_40) {
  // -54946894516
  s21_decimal dec_1 = {{0xcb1712b4, 0xc, 0x0, 0x80000000}};
  // -90557
  s21_decimal dec_2 = {{0x161bd, 0x0, 0x0, 0x80000000}};
  // 4975825926685412
  s21_decimal dec_check = {{0xc0d302e4, 0x11ad7c, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_41) {
  // -60219.4002097145045
  s21_decimal dec_1 = {{0x1cdf04d5, 0x85b6c41, 0x0, 0x800d0000}};
  // 580764031877688.456261051326
  s21_decimal dec_2 = {{0xa182a3be, 0x40cf31a6, 0x1e06591, 0xc0000}};
  // -34973261663049913399.618393431
  s21_decimal dec_check = {{0x2fe55557, 0xb2fa953f, 0x71013439, 0x80090000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_42) {
  // -95809393520540707.227
  s21_decimal dec_1 = {{0x7970e99b, 0x319f57c9, 0x5, 0x80030000}};
  // 32.2177788596253479995
  s21_decimal dec_2 = {{0xd895d43b, 0x771d6fc1, 0x11, 0x130000}};
  // -3086765853119602192.1183275074
  s21_decimal dec_check = {{0xf2fd9842, 0xf403160b, 0x63bd20f1, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_43) {
  // 73830852529
  s21_decimal dec_1 = {{0x30a967b1, 0x11, 0x0, 0x0}};
  // -78
  s21_decimal dec_2 = {{0x4e, 0x0, 0x0, 0x80000000}};
  // -5758806497262
  s21_decimal dec_check = {{0xd39d97ee, 0x53c, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_44) {
  // -4
  s21_decimal dec_1 = {{0x4, 0x0, 0x0, 0x80000000}};
  // -9964225302.2398596334
  s21_decimal dec_2 = {{0x53a944ee, 0x66d06532, 0x5, 0x800a0000}};
  // 39856901208.9594385336
  s21_decimal dec_check = {{0x4ea513b8, 0x9b4194c9, 0x15, 0xa0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_45) {
  // -643017909
  s21_decimal dec_1 = {{0x2653acb5, 0x0, 0x0, 0x80000000}};
  // -72.0267465393144255
  s21_decimal dec_2 = {{0x920781bf, 0x9fee771, 0x0, 0x80100000}};
  // 46314487951.7829481785462795
  s21_decimal dec_check = {{0xb568100b, 0x3a39671a, 0x17f1abe, 0x100000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_46) {
  // -0.3
  s21_decimal dec_1 = {{0x3, 0x0, 0x0, 0x80010000}};
  // 28738152794352
  s21_decimal dec_2 = {{0x1f6388f0, 0x1a23, 0x0, 0x0}};
  // -8621445838305.6
  s21_decimal dec_check = {{0x5e2a9ad0, 0x4e69, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_47) {
  // -0.879
  s21_decimal dec_1 = {{0x36f, 0x0, 0x0, 0x80030000}};
  // -4524174836412892073839128
  s21_decimal dec_2 = {{0xff164a18, 0x2629bed, 0x3be08, 0x80000000}};
  // 3976749681206932132904593.512
  s21_decimal dec_check = {{0xdd886868, 0x3095662e, 0xcd97d80, 0x30000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_48) {
  // 443290972213.5
  s21_decimal dec_1 = {{0x1e026217, 0x408, 0x0, 0x10000}};
  // -0.926773
  s21_decimal dec_2 = {{0xe2435, 0x0, 0x0, 0x80060000}};
  // -410830104191.2220355
  s21_decimal dec_check = {{0xe98b8ac3, 0x39039e07, 0x0, 0x80070000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_49) {
  // -0.044271576488
  s21_decimal dec_1 = {{0x4ecaa5a8, 0xa, 0x0, 0x800c0000}};
  // -68.5905
  s21_decimal dec_2 = {{0xa7751, 0x0, 0x0, 0x80040000}};
  // DEFECT: При произведении убираем конечные нули
  // 3.0366095671001640
  // s21_decimal dec_check = {{0x99af8228, 0x6be1cd, 0x0, 0x100000}};
  s21_decimal dec_check = s21_dec_init("3.036609567100164");
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_50) {
  // 85921
  s21_decimal dec_1 = {{0x14fa1, 0x0, 0x0, 0x0}};
  // -5429971375243206018041
  s21_decimal dec_2 = {{0xf69b43f9, 0x5bfd948f, 0x126, 0x80000000}};
  // -466548570532271504276100761
  s21_decimal dec_check = {{0x45989699, 0xafe2d23f, 0x181eb80, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_51) {
  // 5
  s21_decimal dec_1 = {{0x5, 0x0, 0x0, 0x0}};
  // -670148170
  s21_decimal dec_2 = {{0x27f1a64a, 0x0, 0x0, 0x80000000}};
  // -3350740850
  s21_decimal dec_check = {{0xc7b83f72, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_52) {
  // -7683559
  s21_decimal dec_1 = {{0x753de7, 0x0, 0x0, 0x80000000}};
  // 9578425189973909141854
  s21_decimal dec_2 = {{0x1051795e, 0x3f5a319c, 0x207, 0x0}};
  // -73596395074250739352074578386
  s21_decimal dec_check = {{0x9b65e9d2, 0x548868f2, 0xedcd82db, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_53) {
  // 88259468937.6147799584673
  s21_decimal dec_1 = {{0x9f80afa1, 0x8dd1c887, 0xbae5, 0xd0000}};
  // 614113541.80392
  s21_decimal dec_2 = {{0x71f37b28, 0x37da, 0x0, 0x50000}};
  // DEFECT: При произведении убираем конечные нули
  // 54201335067011672882.557460440
  // s21_decimal dec_check = {{0x3de39fd8, 0x903da2cc, 0xaf224b25, 0x90000}};
  s21_decimal dec_check = s21_dec_init("54201335067011672882.55746044");
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_54) {
  // -2736
  s21_decimal dec_1 = {{0xab0, 0x0, 0x0, 0x80000000}};
  // 0.1
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x10000}};
  // -273.6
  s21_decimal dec_check = {{0xab0, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_55) {
  // -63.588
  s21_decimal dec_1 = {{0xf864, 0x0, 0x0, 0x80030000}};
  // -238.5327770
  s21_decimal dec_2 = {{0x8e2d369a, 0x0, 0x0, 0x80070000}};
  // DEFECT: При произведении убираем конечные нули
  // 15167.8222238760
  // s21_decimal dec_check = {{0x568e8428, 0x89f3, 0x0, 0xa0000}};
  s21_decimal dec_check = s21_dec_init("15167.822223876");
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_56) {
  // 950618840994128923.31
  s21_decimal dec_1 = {{0xd0dc1aab, 0x273fa7ed, 0x5, 0x20000}};
  // 8929299.50
  s21_decimal dec_2 = {{0x3539079e, 0x0, 0x0, 0x20000}};
  // DEFECT: При произведении убираем конечные нули
  // 8488360341579454897847521.3450
  // s21_decimal dec_check = {{0x43a6228a, 0x97123804, 0x12461231, 0x40000}};
  s21_decimal dec_check = s21_dec_init("8488360341579454897847521.345");
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_57) {
  // 2
  s21_decimal dec_1 = {{0x2, 0x0, 0x0, 0x0}};
  // 706945152
  s21_decimal dec_2 = {{0x2a232080, 0x0, 0x0, 0x0}};
  // 1413890304
  s21_decimal dec_check = {{0x54464100, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_58) {
  // 572394920900.1462166832339719
  s21_decimal dec_1 = {{0x6968db07, 0x613acd51, 0x127ebd64, 0x100000}};
  // -3902
  s21_decimal dec_2 = {{0xf3e, 0x0, 0x0, 0x80000000}};
  // -2233484981352370.5374979789584
  s21_decimal dec_check = {{0x71d61310, 0x7f7c7c49, 0x482af46a, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_59) {
  // -78
  s21_decimal dec_1 = {{0x4e, 0x0, 0x0, 0x80000000}};
  // 0.7039970
  s21_decimal dec_2 = {{0x6b6be2, 0x0, 0x0, 0x70000}};
  // DEFECT: При произведении убираем конечные нули
  // -54.9117660
  // s21_decimal dec_check = {{0x20badedc, 0x0, 0x0, 0x80070000}};
  s21_decimal dec_check = s21_dec_init("-54.911766");
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

// DEFECT: dec_2 больше dec_max
// START_TEST(s21_mul_60) {
//   // -92686.17966324781582
//   s21_decimal dec_1 = {{0xe197920e, 0x80a0beee, 0x0, 0x800e0000}};
//   // -861256879729.04702563656095740
//   s21_decimal dec_2 = {{0xc22b57fc, 0x5a0252cd, 0x16497fd4, 0x80110000}};
//   // DEFECT: Ожидаемое значение больше максимума dec
//   // 79826609890774668.457806751006
//   // 79826609890774668.45780675101
//   //s21_decimal dec_check = {{0x448d651e, 0x495a86ab, 0x1ef0629, 0xc0000}};
//   s21_decimal dec_check = s21_dec_init("79826609890774668.45780675101");
//   s21_decimal result;
//   int return_value = s21_mul(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_mul_61) {
  // 46
  s21_decimal dec_1 = {{0x2e, 0x0, 0x0, 0x0}};
  // -8.8985
  s21_decimal dec_2 = {{0x15b99, 0x0, 0x0, 0x80040000}};
  // DEFECT: При произведении убираем конечные нули
  // -409.3310
  // s21_decimal dec_check = {{0x3e757e, 0x0, 0x0, 0x80040000}};
  s21_decimal dec_check = s21_dec_init("-409.331");
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_62) {
  // 38.5387331
  s21_decimal dec_1 = {{0x16f88b43, 0x0, 0x0, 0x70000}};
  // -5719071565197678
  s21_decimal dec_2 = {{0x1d16b16e, 0x145177, 0x0, 0x80000000}};
  // -220405772630952561.1817418
  s21_decimal dec_check = {{0x45d729ca, 0x35712033, 0x1d2ba, 0x80070000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_63) {
  // 144.365447787
  s21_decimal dec_1 = {{0x9cd9ea6b, 0x21, 0x0, 0x90000}};
  // 684893381756139254070016
  s21_decimal dec_2 = {{0x5a643b00, 0x2505e28d, 0x9108, 0x0}};
  // DEFECT: При произведении убираем конечные нули
  // 98874939743577779850146022.090
  // s21_decimal dec_check = {{0x487102ca, 0xb7d01281, 0x3f7b6ee7, 0x30000}};
  s21_decimal dec_check = s21_dec_init("98874939743577779850146022.09");
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_64) {
  // -64.52
  s21_decimal dec_1 = {{0x1934, 0x0, 0x0, 0x80020000}};
  // -0.080692
  s21_decimal dec_2 = {{0x13b34, 0x0, 0x0, 0x80060000}};
  // 5.20624784
  s21_decimal dec_check = {{0x1f081a90, 0x0, 0x0, 0x80000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_65) {
  // -760.6879250732
  s21_decimal dec_1 = {{0x1d55e92c, 0x6eb, 0x0, 0x800a0000}};
  // -67151475020485180307
  s21_decimal dec_2 = {{0x53893b93, 0xa3e9f6bf, 0x3, 0x80000000}};
  // 51081316198937692272482.208173
  s21_decimal dec_check = {{0xc7c649ad, 0xd0bb8cab, 0xa50d7973, 0x60000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_66) {
  // -629.9092325760517992346
  s21_decimal dec_1 = {{0xf8d6ef9a, 0x79777841, 0x155, 0x80130000}};
  // 8911676620.3408226098
  s21_decimal dec_2 = {{0x7daf1732, 0xd4be5ab3, 0x4, 0xa0000}};
  // -5613547380884.8304997316038662
  s21_decimal dec_check = {{0xda761006, 0xda52a129, 0xb5622cf4, 0x80100000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_67) {
  // 75475402.50
  s21_decimal dec_1 = {{0xc1de531a, 0x1, 0x0, 0x20000}};
  // -88393917017671532.1471
  s21_decimal dec_2 = {{0x1cadf07f, 0xeb1ec7f7, 0x2f, 0x80040000}};
  // -6671566465460358501594061.7078
  s21_decimal dec_check = {{0x4e5b9376, 0xdde540f3, 0xd791e783, 0x80040000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_68) {
  // -0.9374775
  s21_decimal dec_1 = {{0x8f0c37, 0x0, 0x0, 0x80070000}};
  // 44956
  s21_decimal dec_2 = {{0xaf9c, 0x0, 0x0, 0x0}};
  // DEFECT: При произведении убираем конечные нули
  // -42145.2384900
  // s21_decimal dec_check = {{0x20850a84, 0x62, 0x0, 0x80070000}};
  s21_decimal dec_check = s21_dec_init("-42145.23849");
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_69) {
  // -597750040542.962
  s21_decimal dec_1 = {{0x86d4bef2, 0x21fa6, 0x0, 0x80030000}};
  // -873089795
  s21_decimal dec_2 = {{0x340a4b03, 0x0, 0x0, 0x80000000}};
  // DEFECT: При произведении убираем конечные нули
  // 521889460358896381272.790
  // s21_decimal dec_check = {{0x85e322d6, 0xaf30a38c, 0x6e83, 0x30000}};
  s21_decimal dec_check = s21_dec_init("521889460358896381272.79");
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_70) {
  // -27445854159569665
  s21_decimal dec_1 = {{0xe3bd0301, 0x6181db, 0x0, 0x80000000}};
  // -4.6209070242740926842624
  s21_decimal dec_2 = {{0x3e628700, 0xffabefa0, 0x9c8, 0x80160000}};
  // DEFECT: При произведении убираем конечные нули
  // 126824740273157789.65429776590
  // s21_decimal dec_check = {{0x6bc770ce, 0xa534d886, 0x28fab256, 0xb0000}};
  s21_decimal dec_check = s21_dec_init("126824740273157789.6542977659");
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_71) {
  // -0.7
  s21_decimal dec_1 = {{0x7, 0x0, 0x0, 0x80010000}};
  // -3.19
  s21_decimal dec_2 = {{0x13f, 0x0, 0x0, 0x80020000}};
  // 2.233
  s21_decimal dec_check = {{0x8b9, 0x0, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_72) {
  // -201.117
  s21_decimal dec_1 = {{0x3119d, 0x0, 0x0, 0x80030000}};
  // 6332.2749407516401
  s21_decimal dec_2 = {{0x80a2d6f1, 0xe0f7b4, 0x0, 0xd0000}};
  // -1273528.1392591476019917
  s21_decimal dec_check = {{0x38f6d2cd, 0x61886826, 0x2b2, 0x80100000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_73) {
  // -146023748582.78008852
  s21_decimal dec_1 = {{0x20c17814, 0xcaa60e91, 0x0, 0x80080000}};
  // 366373312480
  s21_decimal dec_2 = {{0x4d8d17e0, 0x55, 0x0, 0x0}};
  // DEFECT: При произведении убираем конечные нули
  // -53499204469019846518460.020730
  // s21_decimal dec_check = {{0x978a77fa, 0x93efb2e9, 0xacdd8135, 0x80060000}};
  s21_decimal dec_check = s21_dec_init("-53499204469019846518460.02073");
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_74) {
  // -2149396.36018679327292348
  s21_decimal dec_1 = {{0x915cfbbc, 0xe6a8fffd, 0x2d83, 0x80110000}};
  // 0
  s21_decimal dec_2 = {{0x0, 0x0, 0x0, 0x0}};
  // DEFECT: При произведении убираем конечные нули
  // 0.00000000000000000
  // s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x110000}};
  s21_decimal dec_check = s21_dec_init("0");
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_75) {
  // 0
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
  // DEFECT: При произведении убираем конечные нули
  // 735.9552276516925
  s21_decimal dec_2 = {{0x4b25d03d, 0x1a2579, 0x0, 0xd0000}};
  // 0.0000000000000
  // s21_decimal dec_check = {{0x0, 0x0, 0x0, 0xd0000}};
  s21_decimal dec_check = s21_dec_init("0");
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_76) {
  // -666335401093748085.04177
  s21_decimal dec_1 = {{0xacd5b771, 0x362169d9, 0xe1c, 0x80050000}};
  // -9923573448
  s21_decimal dec_2 = {{0x4f7db6c8, 0x2, 0x0, 0x80000000}};
  // 6612428293756348655521354742.9
  s21_decimal dec_check = {{0xc7a47a5, 0xbf645e5e, 0xd5a8b990, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_77) {
  // -119416211177535
  s21_decimal dec_1 = {{0xc0d9003f, 0x6c9b, 0x0, 0x80000000}};
  // 658775639804161.123557783879
  s21_decimal dec_2 = {{0x9ad33947, 0xfe28cb83, 0x220ed2a, 0xc0000}};
  // -78668490921469436621405135458
  s21_decimal dec_check = {{0xd86da262, 0x29217dce, 0xfe310cee, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_78) {
  // -90
  s21_decimal dec_1 = {{0x5a, 0x0, 0x0, 0x80000000}};
  // 718103.12624061
  s21_decimal dec_2 = {{0xa42cd7bd, 0x414f, 0x0, 0x80000}};
  // DEFECT: При произведении убираем конечные нули
  // -64629281.36165490
  // s21_decimal dec_check = {{0xb7c3d872, 0x16f5ff, 0x0, 0x80080000}};
  s21_decimal dec_check = s21_dec_init("-64629281.3616549");
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_79) {
  // -6792792292.31234080402
  s21_decimal dec_1 = {{0x9cd8de92, 0xd2e49c02, 0x24, 0x800b0000}};
  // -3819141123693021.6
  s21_decimal dec_2 = {{0xdc3f82a8, 0x87aee2, 0x0, 0x80010000}};
  // 25942632388275049307909631.838
  s21_decimal dec_check = {{0xca3baf5e, 0xc49dad03, 0x53d33e17, 0x30000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_80) {
  // -4327079563.450638275
  s21_decimal dec_1 = {{0xe653dfc3, 0x3c0cdfef, 0x0, 0x80090000}};
  // -956328971201083.190101026
  s21_decimal dec_2 = {{0x26a54422, 0xb2896b57, 0xca82, 0x80090000}};
  // 4138111547219981073263574.3169
  s21_decimal dec_check = {{0xe45063c1, 0xbddb5156, 0x85b5a80c, 0x40000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_81) {
  // 81303469227.6526313
  s21_decimal dec_1 = {{0xb7361ce9, 0xb487abe, 0x0, 0x70000}};
  // 42310943253483740
  s21_decimal dec_2 = {{0x26bc50dc, 0x965194, 0x0, 0x0}};
  // 3440026472802571961534616302.8
  s21_decimal dec_check = {{0x91d7bd54, 0x9c2f5e2e, 0x6f273b67, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_82) {
  // -838747700893214797.2167799594
  s21_decimal dec_1 = {{0x569932a, 0xbce1f413, 0x1b19f557, 0x800a0000}};
  // 12763178343
  s21_decimal dec_2 = {{0xf8bea567, 0x2, 0x0, 0x0}};
  // -10705086491281320855484342654
  s21_decimal dec_check = {{0x2299a17e, 0x864d9ba8, 0x22970a3d, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_83) {
  // -1270.247289211881506942697
  s21_decimal dec_1 = {{0x75472ee9, 0x3e57d7a1, 0x10cfc, 0x80150000}};
  // 840.888819056069873302
  s21_decimal dec_2 = {{0x2ac48e96, 0x95ad35b6, 0x2d, 0x120000}};
  // -1068136.7429345530857093039285
  s21_decimal dec_check = {{0xdeeb84b5, 0x99c202b7, 0x22836b88, 0x80160000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_84) {
  // -0.8361
  s21_decimal dec_1 = {{0x20a9, 0x0, 0x0, 0x80040000}};
  // -89425911793.8591
  s21_decimal dec_2 = {{0xed0fd79f, 0x32d52, 0x0, 0x80040000}};
  // 74769004850.84559351
  s21_decimal dec_check = {{0x7a6937f7, 0x67c34960, 0x0, 0x80000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_85) {
  // 1068546.5060
  s21_decimal dec_1 = {{0x7ce741e4, 0x2, 0x0, 0x40000}};
  // 904.3491446023
  s21_decimal dec_2 = {{0x9a185d07, 0x839, 0x0, 0xa0000}};
  // DEFECT: При произведении убираем конечные нули
  // 966339118.66887642456380
  // s21_decimal dec_check = {{0xc2a2a13c, 0x88ec8686, 0x1476, 0xe0000}};
  s21_decimal dec_check = s21_dec_init("966339118.6688764245638");
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_86) {
  // 5032031.206
  s21_decimal dec_1 = {{0x2beeb3e6, 0x1, 0x0, 0x30000}};
  // 7385204441092
  s21_decimal dec_2 = {{0x807cc004, 0x6b7, 0x0, 0x0}};
  // 37162579210264732716.952
  s21_decimal dec_check = {{0xda0f4f98, 0x96637ff3, 0x7de, 0x30000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_87) {
  // 85.164813668774632893712
  s21_decimal dec_1 = {{0xac022d10, 0xcb36793a, 0x1208, 0x150000}};
  // -7969515
  s21_decimal dec_2 = {{0x799aeb, 0x0, 0x0, 0x80000000}};
  // -678722260.00550446846593118968
  s21_decimal dec_check = {{0x402ab2f8, 0xfaa9689, 0xdb4e96e8, 0x80140000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_88) {
  // -3.90
  s21_decimal dec_1 = {{0x186, 0x0, 0x0, 0x80020000}};
  // 15376407607
  s21_decimal dec_2 = {{0x94815c37, 0x3, 0x0, 0x0}};
  // DEFECT: При произведении убираем конечные нули
  // -59967989667.30
  // s21_decimal dec_check = {{0x3d127bca, 0x574, 0x0, 0x80020000}};
  s21_decimal dec_check = s21_dec_init("-59967989667.3");
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_89) {
  // 9852.91201207240631736984
  s21_decimal dec_1 = {{0x34635a98, 0xbe382178, 0xd0a4, 0x140000}};
  // -706637663695.7
  s21_decimal dec_2 = {{0x44de8a1d, 0x66d, 0x0, 0x80010000}};
  // -6962438724810143.8736914331193
  s21_decimal dec_check = {{0x14fe3639, 0x9e4125cb, 0xe0f7f17b, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_90) {
  // 42966907829317
  s21_decimal dec_1 = {{0x3473c45, 0x2714, 0x0, 0x0}};
  // -58
  s21_decimal dec_2 = {{0x3a, 0x0, 0x0, 0x80000000}};
  // -2492080654100386
  s21_decimal dec_check = {{0xbe23a7a2, 0x8da88, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_91) {
  // -669025367318
  s21_decimal dec_1 = {{0xc504f516, 0x9b, 0x0, 0x80000000}};
  // 9
  s21_decimal dec_2 = {{0x9, 0x0, 0x0, 0x0}};
  // -6021228305862
  s21_decimal dec_check = {{0xed2c9dc6, 0x579, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_92) {
  // -8922002.40171791
  s21_decimal dec_1 = {{0x8e624b0f, 0x32b73, 0x0, 0x80080000}};
  // -563.0143
  s21_decimal dec_2 = {{0x55e8bf, 0x0, 0x0, 0x80040000}};
  // 5023214936.801527896113
  s21_decimal dec_check = {{0x3b569831, 0x4f1c6ae3, 0x110, 0xc0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_93) {
  // -226780672.36915
  s21_decimal dec_1 = {{0x26245033, 0x14a0, 0x0, 0x80050000}};
  // -9786.583067937363037823196
  s21_decimal dec_2 = {{0x5bd4a0dc, 0xbb2e2dae, 0x81863, 0x80150000}};
  // 2219407888343.3739831545833715
  s21_decimal dec_check = {{0x4ce628f3, 0x16306558, 0x47b68303, 0x100000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_94) {
  // -636628314170604672021
  s21_decimal dec_1 = {{0x9eac5415, 0x82fe1ebc, 0x22, 0x80000000}};
  // 4105966.9169
  s21_decimal dec_2 = {{0x8f58d4b1, 0x9, 0x0, 0x40000}};
  // -2613974796346322245786801062.1
  s21_decimal dec_check = {{0x4a40c47d, 0x82b153c4, 0x54764af0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_95) {
  // 49347.00401
  s21_decimal dec_1 = {{0x26218d71, 0x1, 0x0, 0x50000}};
  // 93.88188
  s21_decimal dec_2 = {{0x8f409c, 0x0, 0x0, 0x50000}};
  // 4632789.5088263388
  s21_decimal dec_check = {{0xa1ed70dc, 0xa496f9, 0x0, 0xa0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_96) {
  // 0.7791
  s21_decimal dec_1 = {{0x1e6f, 0x0, 0x0, 0x40000}};
  // 70870544131
  s21_decimal dec_2 = {{0x8036af03, 0x10, 0x0, 0x0}};
  // 55215240932.4621
  s21_decimal dec_check = {{0x383c4d, 0x1f62e, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_97) {
  // 44
  s21_decimal dec_1 = {{0x2c, 0x0, 0x0, 0x0}};
  // 35106973021982911.019739
  s21_decimal dec_2 = {{0x5156badb, 0x271f46c7, 0x76f, 0x60000}};
  // 1544706812967248084.868516
  s21_decimal dec_check = {{0xfae81da4, 0xb9602a41, 0x1471a, 0x60000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_98) {
  // -94477940293994161
  s21_decimal dec_1 = {{0xa65586b1, 0x14fa72f, 0x0, 0x80000000}};
  // 38406500463.5
  s21_decimal dec_2 = {{0x6c0ee45b, 0x59, 0x0, 0x10000}};
  // -3628567057691812070712793623.5
  s21_decimal dec_check = {{0x560a84eb, 0x7ab9df1d, 0x753ecd9f, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_99) {
  // -29764330706182419417661.1
  s21_decimal dec_1 = {{0xe2f96663, 0x46a866e6, 0x3f07, 0x80010000}};
  // 278605.931490767742852123725
  s21_decimal dec_2 = {{0x2ab7cc4d, 0xcf3a34af, 0xe67519, 0x150000}};
  // DEFECT: Ожидаемое значение больше максимума dec
  // -8292519081595213815867252379.2
  // -8292519081595213815867252379 - корректное значение
  // s21_decimal dec_check = {{0x83e13210, 0xd24ed58a, 0xbf21c31, 0x80010000}};
  s21_decimal dec_check = s21_dec_init("-8292519081595213815867252379");
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_100) {
  // 3722392590629869602960
  s21_decimal dec_1 = {{0xbf6e4890, 0xca931318, 0xc9, 0x0}};
  // 68.8
  s21_decimal dec_2 = {{0x2b0, 0x0, 0x0, 0x10000}};
  // DEFECT: При произведении убираем конечные нули
  // 256100610235335028683648.0
  // s21_decimal dec_check = {{0x78630300, 0x6b435282, 0x21e50, 0x10000}};
  s21_decimal dec_check = s21_dec_init("256100610235335028683648");
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(fail_s21_mul_1) {
  // 372600821981579467122584815
  s21_decimal dec_1 = {{0xaf5cacef, 0x87a448a, 0x134354b, 0x0}};
  // 1204202650598928789203
  s21_decimal dec_2 = {{0xa4fbaed3, 0x47ab3a94, 0x41, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_2) {
  // -75913885816947
  s21_decimal dec_1 = {{0x14329873, 0x450b, 0x0, 0x80000000}};
  // -2741491739926706364.2
  s21_decimal dec_2 = {{0xc9fd375a, 0x7c755a1f, 0x1, 0x80010000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_3) {
  // -829529146
  s21_decimal dec_1 = {{0x31719c3a, 0x0, 0x0, 0x80000000}};
  // -39382420345485188046158855
  s21_decimal dec_2 = {{0xe767c07, 0x48e9ad27, 0x20938d, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_4) {
  // -2788793539025261
  s21_decimal dec_1 = {{0x983ed96d, 0x9e864, 0x0, 0x80000000}};
  // 91409974112473547019
  s21_decimal dec_2 = {{0xfda3810b, 0xf4917724, 0x4, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_5) {
  // -632240903589180373379196267
  s21_decimal dec_1 = {{0x2fa2256b, 0xf6e7847, 0x20afa38, 0x80000000}};
  // 508123538961908080.953870952
  s21_decimal dec_2 = {{0xdadd4a68, 0x3dde7d78, 0x1a44f58, 0x90000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_6) {
  // -840614906930775400818845460
  s21_decimal dec_1 = {{0x4f22a714, 0x6a789366, 0x2b75721, 0x80000000}};
  // -33365304057518400.716
  s21_decimal dec_2 = {{0x6b48a4cc, 0xcf095f43, 0x1, 0x80030000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_7) {
  // -62359333902313512779370425210
  s21_decimal dec_1 = {{0x8e636b7a, 0x94f50995, 0xc97e6e98, 0x80000000}};
  // -7802746
  s21_decimal dec_2 = {{0x770f7a, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_8) {
  // -36218325388
  s21_decimal dec_1 = {{0x6ec7c98c, 0x8, 0x0, 0x80000000}};
  // -1670399645780172518217402622
  s21_decimal dec_2 = {{0x9432c8fe, 0x3e62baf8, 0x565b8e2, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_9) {
  // -400571702301228700
  s21_decimal dec_1 = {{0x46bcfe9c, 0x58f1dd7, 0x0, 0x80000000}};
  // -5888396970011150287890073.44
  s21_decimal dec_2 = {{0x88613f0, 0xefcc9a8a, 0x1e713a7, 0x80020000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_10) {
  // 62009801166926775445666873503
  s21_decimal dec_1 = {{0x7fff409f, 0x7600512, 0xc85d4e29, 0x0}};
  // -329976356263157269
  s21_decimal dec_2 = {{0x6b57de15, 0x4944fbf, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_11) {
  // 49317584519729738412315
  s21_decimal dec_1 = {{0xcab7f11b, 0x82f920ee, 0xa71, 0x0}};
  // -1550830858236
  s21_decimal dec_2 = {{0x14b8effc, 0x169, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_12) {
  // 98413670292106164506592453.8
  s21_decimal dec_1 = {{0xcb9c2fba, 0x910547d5, 0x32e0f0d, 0x10000}};
  // -6557994872780137
  s21_decimal dec_2 = {{0x2ad4b569, 0x174c76, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_13) {
  // 57670233474802262265207
  s21_decimal dec_1 = {{0x2630cd77, 0x4f435357, 0xc36, 0x0}};
  // -35530303143472736
  s21_decimal dec_2 = {{0x59a0ee60, 0x7e3a9f, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_14) {
  // -136229521818709.6821304434
  s21_decimal dec_1 = {{0x84178c72, 0x2bf837c2, 0x1207a, 0x800a0000}};
  // -289115337231656709219
  s21_decimal dec_2 = {{0xda2a6c63, 0xac480369, 0xf, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_15) {
  // -8987456304207392245053227
  s21_decimal dec_1 = {{0x75d0772b, 0xfb859453, 0x76f2a, 0x80000000}};
  // 6685263.66
  s21_decimal dec_2 = {{0x27d8e71e, 0x0, 0x0, 0x20000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_16) {
  // 60551636235910027557008579
  s21_decimal dec_1 = {{0x524cf4c3, 0xc71911d3, 0x32164e, 0x0}};
  // -8440638040
  s21_decimal dec_2 = {{0xf719ea58, 0x1, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_17) {
  // -536530348641823228384516858
  s21_decimal dec_1 = {{0xeba41afa, 0x7ae7683a, 0x1bbceb8, 0x80000000}};
  // 792073276620878.5937008
  s21_decimal dec_2 = {{0xafd87270, 0x623fa506, 0x1ad, 0x70000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_18) {
  // -6791647818091
  s21_decimal dec_1 = {{0x4dc1716b, 0x62d, 0x0, 0x80000000}};
  // 39573939839033658984117.2541
  s21_decimal dec_2 = {{0xc4aa083d, 0xc60da136, 0x1475913, 0x40000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_19) {
  // -897254813752040489
  s21_decimal dec_1 = {{0xceb31c29, 0xc73b07f, 0x0, 0x80000000}};
  // -61756032947162139343619146
  s21_decimal dec_2 = {{0x4646844a, 0x4117d65c, 0x331559, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_20) {
  // 8690130404637484548855160003
  s21_decimal dec_1 = {{0x3d5fdcc3, 0x31cbb934, 0x1c144eb1, 0x0}};
  // 654587059198076449684370
  s21_decimal dec_2 = {{0xcd377b92, 0x3c4f2dc5, 0x8a9d, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_21) {
  // 38070012109289538125736751
  s21_decimal dec_1 = {{0x2016ab2f, 0x7de4c60e, 0x1f7da3, 0x0}};
  // -55527377207121701780
  s21_decimal dec_2 = {{0x8b9c6b94, 0x298df5f, 0x3, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_22) {
  // -6259429
  s21_decimal dec_1 = {{0x5f82e5, 0x0, 0x0, 0x80000000}};
  // 4162203151264265802018574980
  s21_decimal dec_2 = {{0x8e75d284, 0xf2431b8b, 0xd72e4cc, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_23) {
  // 551734291655666725503027869.98
  s21_decimal dec_1 = {{0x3b5725b6, 0x3d3739bb, 0xb2466414, 0x20000}};
  // -8839642896862606162
  s21_decimal dec_2 = {{0x58ccf352, 0x7aacb861, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_24) {
  // -656985925641234699439
  s21_decimal dec_1 = {{0x94fe54af, 0x9d82e282, 0x23, 0x80000000}};
  // -82218299816272
  s21_decimal dec_2 = {{0xf08df950, 0x4ac6, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_25) {
  // -41851419324.87
  s21_decimal dec_1 = {{0x6de5f1c7, 0x3ce, 0x0, 0x80020000}};
  // -68392574428028001460002
  s21_decimal dec_2 = {{0xf1ae1f22, 0x91a2b2e6, 0xe7b, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_26) {
  // -5414531315868353892
  s21_decimal dec_1 = {{0x5b8fc564, 0x4b24478b, 0x0, 0x80000000}};
  // 96227653461232906
  s21_decimal dec_2 = {{0x7e204d0a, 0x155de8a, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_27) {
  // -712868199986074599173854
  s21_decimal dec_1 = {{0x34922ede, 0xa99d45bd, 0x96f4, 0x80000000}};
  // -46854153291955334093314
  s21_decimal dec_2 = {{0x8f51a02, 0xf7ff4f17, 0x9eb, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_28) {
  // -2272561511965831835477670
  s21_decimal dec_1 = {{0xc5d4e6a6, 0xce7179ff, 0x1e13b, 0x80000000}};
  // -5994781951134442235915
  s21_decimal dec_2 = {{0x3b8ca80b, 0xfa4fd6d7, 0x144, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_29) {
  // 96935974324929030808032
  s21_decimal dec_1 = {{0x34ec61e0, 0xe8e1f3b8, 0x1486, 0x0}};
  // -972643.1
  s21_decimal dec_2 = {{0x9469df, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_30) {
  // -69792092334648544
  s21_decimal dec_1 = {{0xc7bcece0, 0xf7f389, 0x0, 0x80000000}};
  // 535695941832835669738513
  s21_decimal dec_2 = {{0x8c0c411, 0x229c3a39, 0x7170, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_31) {
  // 405256.85345607
  s21_decimal dec_1 = {{0x9f144d47, 0x24db, 0x0, 0x80000}};
  // -92663804905014805042494935
  s21_decimal dec_2 = {{0xb576fdd7, 0xedefbf3e, 0x4ca652, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_32) {
  // -48794141810336027344
  s21_decimal dec_1 = {{0x3d1d52d0, 0xa5279d74, 0x2, 0x80000000}};
  // 648387651848082628
  s21_decimal dec_2 = {{0x512794c4, 0x8ff8922, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_33) {
  // -743060553836757023385106.2337
  s21_decimal dec_1 = {{0xd0fb2841, 0x61093a29, 0x180273ed, 0x80040000}};
  // 2762603.2
  s21_decimal dec_2 = {{0x1a58a30, 0x0, 0x0, 0x10000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(invalid_dec_s21_div_1) {
  // ссылка на результат - NULL
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x0}};
  int result_value = s21_div(dec_1, dec_2, NULL);

  ck_assert_int_eq(result_value, 1);
}

START_TEST(invalid_dec_s21_div_2) {
  // степень 56 (допустимое значение от 0 до 28)
  // биты 0-15 не пустые
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x380000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_3) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_4) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_5) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C8000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_6) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_7) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0xA, 0x0, 0x0, 0x401C0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_8) {
  // Все биты имеют максимальное значение
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_9) {
  // степень 56 (допустимое значение от 0 до 28)
  // биты 0-15 не пустые
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x380000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_10) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_11) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_12) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_13) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C8000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_14) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_15) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x401C0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_16) {
  // Все биты имеют максимальное значение
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(s21_div_1) {
  // -8699284636549076411
  s21_decimal dec_1 = {{0x418555bb, 0x78ba1149, 0x0, 0x80000000}};
  // 5268979410240.75373073489200
  s21_decimal dec_2 = {{0xc3155d30, 0x9de80d5c, 0x1b3d6fa, 0xe0000}};
  // -1651037.8878386208914637219747
  s21_decimal dec_check = {{0x3d4267a3, 0x6cdd8e7e, 0x355910b8, 0x80160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_2) {
  // -87904847775
  s21_decimal dec_1 = {{0x7789879f, 0x14, 0x0, 0x80000000}};
  // 43359886245
  s21_decimal dec_2 = {{0x18735ba5, 0xa, 0x0, 0x0}};
  // -2.0273311437743141154774494035
  s21_decimal dec_check = {{0x6762ab53, 0x36bcb52a, 0x4181b0af, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_3) {
  // -63839664
  s21_decimal dec_1 = {{0x3ce1db0, 0x0, 0x0, 0x80000000}};
  // -0.85371343131728360004
  s21_decimal dec_2 = {{0xf4a73244, 0xa0c3f042, 0x4, 0x80140000}};
  // 74778797.730164694866456148223
  s21_decimal dec_check = {{0x88baf8ff, 0xbeb3f633, 0xf19f925b, 0x150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_4) {
  // 864347
  s21_decimal dec_1 = {{0xd305b, 0x0, 0x0, 0x0}};
  // 609458.86011
  s21_decimal dec_2 = {{0x30a86b3b, 0xe, 0x0, 0x50000}};
  // 1.4182204190845560172850696405
  s21_decimal dec_check = {{0x14b3d0d5, 0xb7a6cfc8, 0x2dd33e8d, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_5) {
  // 624350708008362610209036
  s21_decimal dec_1 = {{0x481b310c, 0x1ea4b5c8, 0x8436, 0x0}};
  // -28786376826.08988
  s21_decimal dec_2 = {{0x10824b5c, 0xa3a1b, 0x0, 0x80050000}};
  // -21689103556877.519268160498323
  s21_decimal dec_check = {{0x7ed46a93, 0xc80f5c79, 0x4614ce53, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_6) {
  // 6450571009.6148689075055
  s21_decimal dec_1 = {{0x37403b6f, 0xdc8e9e8c, 0xda8, 0xd0000}};
  // 13.5579919712
  s21_decimal dec_2 = {{0x91316560, 0x1f, 0x0, 0xa0000}};
  // DEFECT: При произведении убираем конечные нули
  // 475776281.86513355556053923030
  // s21_decimal dec_check = {{0xc23934d6, 0x138644dc, 0x99bb4aa8, 0x140000}};
  s21_decimal dec_check = s21_dec_init("475776281.8651335555605392303");
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_7) {
  // 2888928664518420291843351
  s21_decimal dec_1 = {{0xcbb2f517, 0x22ff8371, 0x263c1, 0x0}};
  // -92191499396551845457494
  s21_decimal dec_2 = {{0x7fe9ae56, 0xb610f9aa, 0x1385, 0x80000000}};
  // -31.336171810071159934025287525
  s21_decimal dec_check = {{0xfd194765, 0xb1627673, 0x6540ac7d, 0x801b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_8) {
  // 712914366852966572521
  s21_decimal dec_1 = {{0x7796e1e9, 0xa5ac9f78, 0x26, 0x0}};
  // 82040.7
  s21_decimal dec_2 = {{0xc84b7, 0x0, 0x0, 0x10000}};
  // DEFECT: Ожидаемое значение больше максимума dec
  // 8689764554092865.7668815600062
  // Корректное: 8689764554092865.766881560006
  // s21_decimal dec_check = {{0xd4c239be, 0xf7ae98d0, 0x18c80c33, 0xd0000}};
  s21_decimal dec_check = s21_dec_init("8689764554092865.766881560006");
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_9) {
  // -5521399.31391501471
  s21_decimal dec_1 = {{0x9ce6249f, 0x7a99857, 0x0, 0x800b0000}};
  // 0.6189403804648237
  s21_decimal dec_2 = {{0xdf25c32d, 0x15fd3a, 0x0, 0x100000}};
  // DEFECT: Ожидаемое значение больше максимума dec
  // -8920728.8588417005772614529099
  // Корректное: -8920728.858841700577261452910
  // s21_decimal dec_check = {{0x36a9f04b, 0x7484ed1b, 0x203e8a24, 0x80160000}};
  s21_decimal dec_check = s21_dec_init("-8920728.85884170057726145291");
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_10) {
  // 41773280266
  s21_decimal dec_1 = {{0xb9e1ac0a, 0x9, 0x0, 0x0}};
  // -802.613882514684240272
  s21_decimal dec_2 = {{0x6cdbe190, 0x828151b7, 0x2b, 0x80120000}};
  // -52046545.887194688555445911796
  s21_decimal dec_check = {{0xa94c00f4, 0x102a85ff, 0xa82be4ca, 0x80150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_11) {
  // -122835156872340.8923
  s21_decimal dec_1 = {{0x610d781b, 0x110bfb3e, 0x0, 0x80040000}};
  // 364.1465246823424687
  s21_decimal dec_2 = {{0x42d722af, 0x32891559, 0x0, 0x100000}};
  // -337323435887.50221409817868742
  s21_decimal dec_check = {{0xc12639c6, 0x18f74a79, 0x6cfebd9a, 0x80110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_12) {
  // 5789422585071580529790
  s21_decimal dec_1 = {{0x7744c47e, 0xd860cf72, 0x139, 0x0}};
  // -830
  s21_decimal dec_2 = {{0x33e, 0x0, 0x0, 0x80000000}};
  // -6975207933821181361.1927710843
  s21_decimal dec_check = {{0xc6f32c7b, 0xb18ae711, 0xe1619155, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_13) {
  // 5713369908642086756457979760
  s21_decimal dec_1 = {{0x55f91f70, 0x5bafe8f2, 0x1275fd23, 0x0}};
  // 438151874044664102741
  s21_decimal dec_2 = {{0xf7e63f55, 0xc0942803, 0x17, 0x0}};
  // 13039702.092109915664776889306
  s21_decimal dec_check = {{0xebf703da, 0xd76a682a, 0x2a223052, 0x150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_14) {
  // -608121149717526976222796
  s21_decimal dec_1 = {{0x655564c, 0x5046f827, 0x80c6, 0x80000000}};
  // -82305081482.3590
  s21_decimal dec_2 = {{0x73731ca6, 0x2ec8f, 0x0, 0x80040000}};
  // 7388622169675.7527652535761663
  s21_decimal dec_check = {{0x92edfaff, 0x4bcd36c, 0xeebd4008, 0x100000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

// DEFECT: dec_2 больше dec_max
// START_TEST(s21_div_15) {
//   // -83066287675420.48477223830796
//   s21_decimal dec_1 = {{0x2f13c50c, 0xca3c61d2, 0x1ad7150f, 0x800e0000}};
//   // -864157.88254391154260986306852
//   s21_decimal dec_2 = {{0xa3302124, 0x1f771db9, 0x173976f4, 0x80170000}};
//   // 96123971.502625890705534920387
//   s21_decimal dec_check = {{0xd598a6c3, 0x8dd88b18, 0x3697e2b8, 0x150000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_16) {
  // -12484515131423493724
  s21_decimal dec_1 = {{0xc17c8e5c, 0xad41e85d, 0x0, 0x80000000}};
  // 247162.34624582
  s21_decimal dec_2 = {{0xb2628e46, 0x167a, 0x0, 0x80000}};
  // -50511395934908.233858893935053
  s21_decimal dec_check = {{0xdb12f1cd, 0x65287fde, 0xa3360c24, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_17) {
  // -566706586030613338196661
  s21_decimal dec_1 = {{0xbf0f0ab5, 0x39c00eaa, 0x7801, 0x80000000}};
  // 526243
  s21_decimal dec_2 = {{0x807a3, 0x0, 0x0, 0x0}};
  // -1076891447545360865.9814211305
  s21_decimal dec_check = {{0xb9105ee9, 0x7ad8c1bc, 0x22cbd657, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_18) {
  // 86032804691693232649292.80
  s21_decimal dec_1 = {{0x4f76e00, 0xc4cd6003, 0x71dd0, 0x20000}};
  // -0.15773545132737798806793196
  s21_decimal dec_2 = {{0x26296bec, 0x98544130, 0xd0c2d, 0x801a0000}};
  // -545424658614842425431218.08257
  s21_decimal dec_check = {{0x29dc3b81, 0xfca46a9e, 0xb03c7866, 0x80050000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_19) {
  // -13336175199233959972059
  s21_decimal dec_1 = {{0x6a7accdb, 0xf49c0d9e, 0x2d2, 0x80000000}};
  // 80391324188360318
  s21_decimal dec_2 = {{0xc1453e7e, 0x11d9b7b, 0x0, 0x0}};
  // -165890.72681508181051874531852
  // Ошибка округления
  s21_decimal dec_check = {{0x3994da0c, 0xa61d212, 0x359a28c8, 0x80170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_20) {
  // -99438543747434961
  s21_decimal dec_1 = {{0x250c49d1, 0x16146d4, 0x0, 0x80000000}};
  // 368
  s21_decimal dec_2 = {{0x170, 0x0, 0x0, 0x0}};
  // -270213434096290.65489130434783
  s21_decimal dec_check = {{0x2037b0df, 0x68eaf2c9, 0x574f8809, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_21) {
  // -65.3
  s21_decimal dec_1 = {{0x28d, 0x0, 0x0, 0x80010000}};
  // -0.4637294157769789972223964063
  s21_decimal dec_2 = {{0x4725339f, 0x3f2618f, 0xefbe13c, 0x801c0000}};
  // 140.81487561143775870553436043
  s21_decimal dec_check = {{0x71202f8b, 0x47ee9905, 0x2d7feefa, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_22) {
  // 95854263424402216.41
  s21_decimal dec_1 = {{0x1d23bc9, 0x85064679, 0x0, 0x20000}};
  // -493969314
  s21_decimal dec_2 = {{0x1d715fa2, 0x0, 0x0, 0x80000000}};
  // -194049024.31733283013203528671
  s21_decimal dec_check = {{0x76ef0bdf, 0xaaeff030, 0x3eb35bec, 0x80140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_23) {
  // -8138868065705
  s21_decimal dec_1 = {{0xfa5705a9, 0x766, 0x0, 0x80000000}};
  // -2369551
  s21_decimal dec_2 = {{0x24280f, 0x0, 0x0, 0x80000000}};
  // DEFECT: При произведении убираем конечные нули
  // 3434772.2693898548712393191790
  // s21_decimal dec_check = {{0x1b88b16e, 0x3b93c3dd, 0x6efbc532, 0x160000}};
  s21_decimal dec_check = s21_dec_init("3434772.269389854871239319179");
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_24) {
  // -723663023730906672
  s21_decimal dec_1 = {{0x9a90d630, 0xa0af7af, 0x0, 0x80000000}};
  // 0.05572430439914
  s21_decimal dec_2 = {{0x6ebca5ea, 0x511, 0x0, 0xe0000}};
  // -12986488239448980037.621180657
  s21_decimal dec_check = {{0xc702e8f1, 0x1bc039f9, 0x29f62bda, 0x80090000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_25) {
  // 126454371963851913
  s21_decimal dec_1 = {{0xd1335489, 0x1c14194, 0x0, 0x0}};
  // -67.18
  s21_decimal dec_2 = {{0x1a3e, 0x0, 0x0, 0x80020000}};
  // -1882321702349686.1119380768086
  s21_decimal dec_check = {{0xe200c556, 0x8087bfa4, 0x3cd2333f, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_26) {
  // -1340687122502512356728740
  s21_decimal dec_1 = {{0x4ff99fa4, 0xcb671b3a, 0x11be6, 0x80000000}};
  // -0.051279
  s21_decimal dec_2 = {{0xc84f, 0x0, 0x0, 0x80060000}};
  // 26144954513592549712918348.642
  s21_decimal dec_check = {{0x3de60362, 0x2899260f, 0x547a9978, 0x30000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_27) {
  // -4299410249538433607185711434
  s21_decimal dec_1 = {{0x5af3c14a, 0xa5d644a6, 0xde46388, 0x80000000}};
  // -4904852474
  s21_decimal dec_2 = {{0x245a1bfa, 0x1, 0x0, 0x80000000}};
  // DEFECT: Ожидаемое значение больше максимума dec
  // 876562602510281659.32676560131
  // 876562602510281659.3267656013 - корректное
  // Ошибка округления
  // s21_decimal dec_check = {{0xdd803503, 0xce54657e, 0x1b3b8f1d, 0xb0000}};
  s21_decimal dec_check = s21_dec_init("876562602510281659.3267656013");
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_28) {
  // 62326336528455602772771290
  s21_decimal dec_1 = {{0x53d601da, 0x792e2ae4, 0x338e1d, 0x0}};
  // 15441060378015.11333
  s21_decimal dec_2 = {{0xa6b1e9a5, 0x156dc442, 0x0, 0x50000}};
  // 4036402617607.4964952124302933
  s21_decimal dec_check = {{0xeaf92655, 0x84a3013a, 0x826c5703, 0x100000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_29) {
  // 60
  s21_decimal dec_1 = {{0x3c, 0x0, 0x0, 0x0}};
  // -2
  s21_decimal dec_2 = {{0x2, 0x0, 0x0, 0x80000000}};
  // -30
  s21_decimal dec_check = {{0x1e, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_30) {
  // -9587190861631467284797362306
  s21_decimal dec_1 = {{0xe6b49082, 0x2bd463f, 0x1efa56a2, 0x80000000}};
  // -6.6
  s21_decimal dec_2 = {{0x42, 0x0, 0x0, 0x80010000}};
  // 1452604676004767770423842773.6
  s21_decimal dec_check = {{0x766e58, 0xbe55151b, 0x2eefaa0c, 0x10000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_31) {
  // -24896170970413131705
  s21_decimal dec_1 = {{0x8edde7b9, 0x5980f797, 0x1, 0x80000000}};
  // -713281578888.36336695
  s21_decimal dec_2 = {{0xe710fc37, 0xdde085af, 0x3, 0x80080000}};
  // 34903706.624827421757320768973
  s21_decimal dec_check = {{0x488adcd, 0x85900b96, 0x70c7ab5f, 0x150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_32) {
  // -68876755
  s21_decimal dec_1 = {{0x41af9d3, 0x0, 0x0, 0x80000000}};
  // -8.367348856
  s21_decimal dec_2 = {{0xf2bb9c78, 0x1, 0x0, 0x80090000}};
  // DEFECT: Ожидаемое значение больше максимума dec
  // 8231610.2968039079928138232271
  // 8231610.296803907992813823227 - корректное
  // s21_decimal dec_check = {{0x8466f1cf, 0x6ca6f3f9, 0x9fa48d3, 0x160000}};
  // Ошибка округления
  s21_decimal dec_check = s21_dec_init("8231610.296803907992813823227");
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_33) {
  // -8593590407289924581
  s21_decimal dec_1 = {{0xd3b86be5, 0x774290f1, 0x0, 0x80000000}};
  // 37169
  s21_decimal dec_2 = {{0x9131, 0x0, 0x0, 0x0}};
  // -231203164123057.50977965508892
  s21_decimal dec_check = {{0x81ccc91c, 0x23825d21, 0x4ab4ad70, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_34) {
  // 63463621564794023.465502069738
  s21_decimal dec_1 = {{0xa60353ea, 0xb7a62daf, 0xcd0fe09a, 0xc0000}};
  // -19276998656.231052
  s21_decimal dec_2 = {{0x13d868c, 0x447c54, 0x0, 0x80060000}};
  // -3292194.1167579108965642561546
  s21_decimal dec_check = {{0xf4ba680a, 0xd103a293, 0x6a606436, 0x80160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_35) {
  // 984890317146.372212498
  s21_decimal dec_1 = {{0xa7548712, 0x64194d45, 0x35, 0x90000}};
  // -0.1579676537998
  s21_decimal dec_2 = {{0xcc0f148e, 0x16f, 0x0, 0x800d0000}};
  // -6234759417232.1572100316047831
  s21_decimal dec_check = {{0x8a73a9d7, 0x8b353ecb, 0xc974b89c, 0x80100000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_36) {
  // 48794.939994804
  s21_decimal dec_1 = {{0xf510b2b4, 0x2c60, 0x0, 0x90000}};
  // 1045.0326183431196
  s21_decimal dec_2 = {{0x2bf34c1c, 0x252084, 0x0, 0xd0000}};
  // 46.692265043523233544823502835
  s21_decimal dec_check = {{0x7b31f7f3, 0xec3f756c, 0x96deefb7, 0x1b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_37) {
  // -93506974.08280127
  s21_decimal dec_1 = {{0xe56c363f, 0x213868, 0x0, 0x80080000}};
  // 635.453926651723518608
  s21_decimal dec_2 = {{0xb31c1290, 0x72b1db82, 0x22, 0x120000}};
  // -147149.88791634317054229358455
  s21_decimal dec_check = {{0x25cc2777, 0xccab4ad9, 0x2f8bf414, 0x80170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_38) {
  // 2783
  s21_decimal dec_1 = {{0xadf, 0x0, 0x0, 0x0}};
  // 54
  s21_decimal dec_2 = {{0x36, 0x0, 0x0, 0x0}};
  // 51.537037037037037037037037037
  s21_decimal dec_check = {{0x7bb425ed, 0xf3798526, 0xa6867017, 0x1b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_39) {
  // 9920108.2319508467494871
  s21_decimal dec_1 = {{0xa9ae2fd7, 0xb3921bbb, 0x1501, 0x100000}};
  // 57927
  s21_decimal dec_2 = {{0xe247, 0x0, 0x0, 0x0}};
  // 171.25188999863356896588982685
  s21_decimal dec_check = {{0xa94de99d, 0xe4d26afa, 0x37559fd3, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_40) {
  // 5392
  s21_decimal dec_1 = {{0x1510, 0x0, 0x0, 0x0}};
  // 275.660
  s21_decimal dec_2 = {{0x434cc, 0x0, 0x0, 0x30000}};
  // 19.560327940216208372632953639
  // 19.560327940216208372632953638
  // 19.5603279402162083726329536385
  s21_decimal dec_check = {{0xf9d0a327, 0x5d95c01d, 0x3f33ec8e, 0x1b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_41) {
  // 49783972528307263522646082
  s21_decimal dec_1 = {{0x8296a842, 0x8efa5877, 0x292e2a, 0x0}};
  // 374944181906870
  s21_decimal dec_2 = {{0x7ec5edb6, 0x15502, 0x0, 0x0}};
  // 132777023702.88489431767140264
  s21_decimal dec_check = {{0x7c3747a8, 0xc62dc013, 0x2ae70ed7, 0x110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_42) {
  // -75593552
  s21_decimal dec_1 = {{0x4817750, 0x0, 0x0, 0x80000000}};
  // -6552.793460
  s21_decimal dec_2 = {{0x8693b174, 0x1, 0x0, 0x80060000}};
  // DEFECT: При произведении убираем конечные нули
  // 11536.080369607742832779594430
  // s21_decimal dec_check = {{0xd7c20abe, 0xef4f5dd3, 0x25466c09, 0x180000}};
  s21_decimal dec_check = s21_dec_init("11536.08036960774283277959443");
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_43) {
  // -95240155006
  s21_decimal dec_1 = {{0x2cc16f7e, 0x16, 0x0, 0x80000000}};
  // -6.93136
  s21_decimal dec_2 = {{0xa9390, 0x0, 0x0, 0x80050000}};
  // 13740471567.773135430853396736
  s21_decimal dec_check = {{0x82250900, 0x3cdcfb85, 0x2c65da08, 0x120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_44) {
  // -6838919589869046912
  s21_decimal dec_1 = {{0x19acc80, 0x5ee8b922, 0x0, 0x80000000}};
  // 747870192802
  s21_decimal dec_2 = {{0x208984a2, 0xae, 0x0, 0x0}};
  // DEFECT: Ожидаемое значение больше максимума dec
  // -9144527.5606533811530169774640
  // -9144527.560653381153016977464 - корректное
  // s21_decimal dec_check = {{0xe25ef230, 0xce96724d, 0x2779c253, 0x80160000}};
  s21_decimal dec_check = s21_dec_init("-9144527.560653381153016977464");
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_45) {
  // 523784507758972341661
  s21_decimal dec_1 = {{0x72618d9d, 0x64f862ad, 0x1c, 0x0}};
  // -27686960449706823.265751198
  s21_decimal dec_2 = {{0x6093109e, 0x222a14f7, 0x16e6f1, 0x80090000}};
  // -18918.093544808696634833397028
  s21_decimal dec_check = {{0x3cec6524, 0x73d505b, 0x3d20ae22, 0x80180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_46) {
  // 9443205166295516288639916057
  s21_decimal dec_1 = {{0x45b15819, 0xd381a3cb, 0x1e833c79, 0x0}};
  // -3954133138161384581551.3
  s21_decimal dec_2 = {{0x1b1420d9, 0x8a34e0a0, 0x85f, 0x80010000}};
  // -2388185.9402150712053266246979
  s21_decimal dec_check = {{0x2535ed43, 0x571b301f, 0x4d2a9c70, 0x80160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_47) {
  // -2187069468823600.8801
  s21_decimal dec_1 = {{0x6b547561, 0x2f8450f1, 0x1, 0x80040000}};
  // -84017467
  s21_decimal dec_2 = {{0x502013b, 0x0, 0x0, 0x80000000}};
  // 26031128.370289964586768606104
  s21_decimal dec_check = {{0xad512398, 0x90dcf2ce, 0x541c71d8, 0x150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_48) {
  // 919636521360838265779548068
  s21_decimal dec_1 = {{0x642c6fa4, 0xb7c328bf, 0x2f8b49b, 0x0}};
  // 70558440717542
  s21_decimal dec_2 = {{0x2acb7ce6, 0x402c, 0x0, 0x0}};
  // 13033685438745.833222658910908
  s21_decimal dec_check = {{0xea7ceabc, 0x68b73aeb, 0x2a1d363f, 0xf0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_49) {
  // -7639557976066694269760.506
  s21_decimal dec_1 = {{0xf9fdf3fa, 0x44898fc5, 0x651bd, 0x80030000}};
  // 46.31224
  s21_decimal dec_2 = {{0x46aab8, 0x0, 0x0, 0x50000}};
  // -164957643509938069714.62632773
  s21_decimal dec_check = {{0xe48e4545, 0x4ecd5d98, 0x354cf9f9, 0x80080000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_50) {
  // -5700944850
  s21_decimal dec_1 = {{0x53cd83d2, 0x1, 0x0, 0x80000000}};
  // -72814972
  s21_decimal dec_2 = {{0x457117c, 0x0, 0x0, 0x80000000}};
  // 78.293580199412835041672473623
  s21_decimal dec_check = {{0xeff4ac17, 0x318e07c3, 0xfcfaee7f, 0x1b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_51) {
  // -852279353846308
  s21_decimal dec_1 = {{0xc022aa24, 0x30724, 0x0, 0x80000000}};
  // 0.59337959363059029495
  s21_decimal dec_2 = {{0x9bb295f7, 0x377ac7a7, 0x3, 0x140000}};
  // DEFECT: При произведении убираем конечные нули
  // -1436313892480934.0366035560960
  // s21_decimal dec_check = {{0x861f2a00, 0x4caa1028, 0x2e68e8f9, 0x800d0000}};
  s21_decimal dec_check = s21_dec_init("-1436313892480934.036603556096");
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_52) {
  // -6098955958895025771947612549
  s21_decimal dec_1 = {{0x8ad9d985, 0x6c02f09, 0x13b4f029, 0x80000000}};
  // -353.3948918016179041
  s21_decimal dec_2 = {{0x38bafb61, 0x310b1bd1, 0x0, 0x80100000}};
  // 17258189352433372316887955.229
  s21_decimal dec_check = {{0xab38371d, 0x74273376, 0x37c3a3bf, 0x30000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_53) {
  // -328695253114403887990782
  s21_decimal dec_1 = {{0x40c347fe, 0x9af9e576, 0x459a, 0x80000000}};
  // 3771082.90822403930053377
  s21_decimal dec_2 = {{0xf6c9db01, 0x14d7319e, 0x4fdb, 0x110000}};
  // DEFECT: Ожидаемое значение больше максимума dec
  // -87162033058880753.483335778949
  // -87162033058880753.48333577895
  // s21_decimal dec_check = {{0xc632c285, 0x8db1ee8, 0x19a2be70, 0x800c0000}};
  s21_decimal dec_check = s21_dec_init("-87162033058880753.48333577895");
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_54) {
  // 354645950082070190.30
  s21_decimal dec_1 = {{0xaf455c16, 0xec2b8d42, 0x1, 0x20000}};
  // -58.1926127904589271673
  s21_decimal dec_2 = {{0x792d279, 0x8bd8ea27, 0x1f, 0x80130000}};
  // -6094346568680222.4968921370645
  s21_decimal dec_check = {{0x3c19d015, 0xd2433aca, 0xc4eb40d6, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

// DEFECT: dec_1 больше dec_max
//  START_TEST(s21_div_55) {
//    // -9370814774243257510488390919.5
//    s21_decimal dec_1 = {{0xa700624b, 0x18ce7d6b, 0x2ec99024, 0x80010000}};
//    // 84371900528328558373397
//    s21_decimal dec_2 = {{0x51ea15, 0xcf551d07, 0x11dd, 0x0}};
//    // -111065.58837200697532013407996
//    s21_decimal dec_check = {{0xbba8eefc, 0x1ad8107, 0x23e32151, 0x80170000}};
//    s21_decimal result;
//    int return_value = s21_div(dec_1, dec_2, &result);
//    ck_assert_int_eq(return_value, 0);
//    ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//    ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//    ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//    ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
//  }
//  END_TEST

START_TEST(s21_div_56) {
  // 3206.8
  s21_decimal dec_1 = {{0x7d44, 0x0, 0x0, 0x10000}};
  // 5
  s21_decimal dec_2 = {{0x5, 0x0, 0x0, 0x0}};
  // 641.36
  s21_decimal dec_check = {{0xfa88, 0x0, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_57) {
  // -75523654015725819450558
  s21_decimal dec_1 = {{0x9928d4be, 0x253eb1d5, 0xffe, 0x80000000}};
  // 796.3828
  s21_decimal dec_2 = {{0x7984b4, 0x0, 0x0, 0x40000}};
  // DEFECT: Ожидаемое значение больше максимума dec
  // -94833356541258574959.878591049
  // -94833356541258574959.87859105 - корректное
  // s21_decimal dec_check = {{0xbd33d249, 0x4e664cf6, 0x326c505f, 0x80090000}};
  s21_decimal dec_check = s21_dec_init("-94833356541258574959.87859105");
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_58) {
  // 603449630623778026719153262
  s21_decimal dec_1 = {{0x17020c6e, 0x68034b3, 0x1f3296e, 0x0}};
  // -674735186961479
  s21_decimal dec_2 = {{0x722e447, 0x265ab, 0x0, 0x80000000}};
  // DEFECT: Ожидаемое значение больше максимума dec
  // -894350320369.80353213759172732
  // -894350320369.8035321375917273 - корректное
  // s21_decimal dec_check = {{0x5d97307c, 0x8a4d2102, 0x20faecb1, 0x80110000}};
  s21_decimal dec_check = s21_dec_init("-894350320369.8035321375917273");
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_59) {
  // 317.53883404701
  s21_decimal dec_1 = {{0x46f0c99d, 0x1ce1, 0x0, 0xb0000}};
  // -0.2324331882100
  s21_decimal dec_2 = {{0x2cf9e674, 0x21d, 0x0, 0x800d0000}};
  // -1366.1510066287017868032366564
  s21_decimal dec_check = {{0x1bca57e4, 0xaa40a066, 0x2c248948, 0x80190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_60) {
  // -13160814700578944888057724952
  s21_decimal dec_1 = {{0xeb658018, 0x80998952, 0x2a865eea, 0x80000000}};
  // 1207.3984507544984514416
  s21_decimal dec_2 = {{0x8c826f70, 0x8831eae6, 0x28e, 0x130000}};
  // -10900142113280669312681402.457
  s21_decimal dec_check = {{0x2d9e6059, 0xfb21a21a, 0x233862df, 0x80030000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_61) {
  // -5190718438790116892793
  s21_decimal dec_1 = {{0x831f6079, 0x63b06679, 0x119, 0x80000000}};
  // 60726573.63
  s21_decimal dec_2 = {{0x69f565d3, 0x1, 0x0, 0x20000}};
  // DEFECT: Ожидаемое значение больше максимума dec
  // -85476886451993.239072411667037
  // -85476886451993.23907241166704
  // s21_decimal dec_check = {{0x4f0eca5d, 0x6d69990d, 0x1430d2c3, 0x800f0000}};
  s21_decimal dec_check = s21_dec_init("-85476886451993.23907241166704");
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_62) {
  // -6751387458117.923943
  s21_decimal dec_1 = {{0x6e257467, 0x5db1bf1f, 0x0, 0x80060000}};
  // 54815.298335237770326
  s21_decimal dec_2 = {{0x78e88c56, 0xf8b70f69, 0x2, 0xf0000}};
  // -123166117.18188578376849782434
  s21_decimal dec_check = {{0x4acb76a2, 0x20431a58, 0x27cc0ffb, 0x80140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_63) {
  // 5870624217
  s21_decimal dec_1 = {{0x5dea9dd9, 0x1, 0x0, 0x0}};
  // -0.3
  s21_decimal dec_2 = {{0x3, 0x0, 0x0, 0x80010000}};
  // -19568747390
  // DEFECT: Неверное значение dec_check = -1956874739
  // s21_decimal dec_check = {{0x74a389f3, 0x0, 0x0, 0x80000000}};
  s21_decimal dec_check = s21_dec_init("-19568747390");
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_64) {
  // 65484.75
  s21_decimal dec_1 = {{0x63ebfb, 0x0, 0x0, 0x20000}};
  // 113
  s21_decimal dec_2 = {{0x71, 0x0, 0x0, 0x0}};
  // 579.51106194690265486725663717
  s21_decimal dec_check = {{0x5806cbe5, 0xb6088d31, 0xbb400811, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_65) {
  // 23569782603874036072207905
  s21_decimal dec_1 = {{0x1d425621, 0x79a7232b, 0x137f18, 0x0}};
  // 89819.0736511974692930114800
  s21_decimal dec_2 = {{0x8656d4f0, 0x6441fd30, 0x2e6f749, 0x160000}};
  // 262414002346591818388.69498117
  s21_decimal dec_check = {{0xd09c8905, 0x2c8859aa, 0x54ca60a5, 0x80000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_66) {
  // 706637613687313
  s21_decimal dec_1 = {{0xe3f2e211, 0x282ae, 0x0, 0x0}};
  // 0.02612678674571948088
  s21_decimal dec_2 = {{0x76197038, 0x24421969, 0x0, 0x140000}};
  // 27046479942776965.273915794706
  s21_decimal dec_check = {{0xb7e8a512, 0x9a2b1d39, 0x576452e7, 0xc0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_67) {
  // -671716290730690
  s21_decimal dec_1 = {{0x22e61ac2, 0x262ec, 0x0, 0x80000000}};
  // 36
  s21_decimal dec_2 = {{0x24, 0x0, 0x0, 0x0}};
  // -18658785853630.277777777777778
  s21_decimal dec_check = {{0x39185c72, 0xec2191b9, 0x3c4a2f97, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_68) {
  // -71621107118
  s21_decimal dec_1 = {{0xacf35dae, 0x10, 0x0, 0x80000000}};
  // -81.246376535
  s21_decimal dec_2 = {{0xeaa95257, 0x12, 0x0, 0x80090000}};
  // DEFECT: Ожидаемое значение больше максимума dec
  // 881529862.28433774914316552665
  // 881529862.2843377491431655266 - корректное
  // s21_decimal dec_check = {{0x61a049d9, 0xff64da20, 0x1cd670ee, 0x140000}};
  s21_decimal dec_check = s21_dec_init("881529862.2843377491431655266");
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_69) {
  // 197.9
  s21_decimal dec_1 = {{0x7bb, 0x0, 0x0, 0x10000}};
  // 5
  s21_decimal dec_2 = {{0x5, 0x0, 0x0, 0x0}};
  // 39.58
  s21_decimal dec_check = {{0xf76, 0x0, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_70) {
  // 456160633545354.7941
  s21_decimal dec_1 = {{0x2de14da5, 0x3f4e14cb, 0x0, 0x40000}};
  // 201
  s21_decimal dec_2 = {{0xc9, 0x0, 0x0, 0x0}};
  // DEFECT: При произведении убираем конечные нули
  // 2269455888285.3472343283582090
  // s21_decimal dec_check = {{0x6451c48a, 0x3830f243, 0x49547fc6, 0x100000}};
  s21_decimal dec_check = s21_dec_init("2269455888285.347234328358209");
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_71) {
  // -8432988439663726461925552475
  s21_decimal dec_1 = {{0x8515715b, 0x5767d055, 0x1b3f9ac3, 0x80000000}};
  // -895862302979560023
  s21_decimal dec_2 = {{0xa0c29257, 0xc6ebe04, 0x0, 0x80000000}};
  // DEFECT: Ожидаемое значение больше максимума dec
  // 9413264082.6791585216086947835
  // 9413264082.679158521608694783 - корректное
  // s21_decimal dec_check = {{0x3af837fb, 0x4f6cf5ca, 0x3028b20c, 0x130000}};
  s21_decimal dec_check = s21_dec_init("9413264082.679158521608694783");
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_72) {
  // -66706789494299592262327298
  s21_decimal dec_1 = {{0x97de9c02, 0x4df14382, 0x372db6, 0x80000000}};
  // 695700419692.239420
  s21_decimal dec_2 = {{0x81d89a3c, 0x9a79fd8, 0x0, 0x60000}};
  // DEFECT: Ожидаемое значение больше максимума dec
  // -95884360000543.076442333088603
  // -95884360000543.0764423330886
  // s21_decimal dec_check = {{0xbc258b5b, 0xffa0fe90, 0x35d1af02, 0x800f0000}};
  s21_decimal dec_check = s21_dec_init("-95884360000543.0764423330886");
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_73) {
  // 1129166787386849781440.77
  s21_decimal dec_1 = {{0x3d40234d, 0x39b51ea1, 0x17e9, 0x20000}};
  // 2012272325
  s21_decimal dec_2 = {{0x77f0d6c5, 0x0, 0x0, 0x0}};
  // 561140146568.80488650599018699
  s21_decimal dec_check = {{0xceb7b0cb, 0xe4c71c16, 0xb5506ccd, 0x110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_74) {
  // 294650411608645305234275
  s21_decimal dec_1 = {{0x818df363, 0x7e3c946, 0x3e65, 0x0}};
  // 48150482
  s21_decimal dec_2 = {{0x2deb7d2, 0x0, 0x0, 0x0}};
  // 6119365775168051.3859503005598
  s21_decimal dec_check = {{0xfc641f9e, 0xd5d7ab41, 0xc5ba3511, 0xd0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_75) {
  // 71022973637
  s21_decimal dec_1 = {{0x894c92c5, 0x10, 0x0, 0x0}};
  // -21714938.842541491
  s21_decimal dec_2 = {{0x30076db3, 0x4d259f, 0x0, 0x80090000}};
  // -3270.6964616386437116492261672
  s21_decimal dec_check = {{0xadac2928, 0x9fe812da, 0x69ae9128, 0x80190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_76) {
  // 3868458186555139002537
  s21_decimal dec_1 = {{0xb6db90a9, 0xb5a450b3, 0xd1, 0x0}};
  // 396459619442933898
  s21_decimal dec_2 = {{0x60aec08a, 0x58081ec, 0x0, 0x0}};
  // DEFECT: Ожидаемое значение больше максимума dec
  // 9757.5087016193889813524870640
  // 9757.508701619388981352487064 - корректное
  // s21_decimal dec_check = {{0xba5775f0, 0x2bc5300b, 0x3b483862, 0x190000}};
  s21_decimal dec_check = s21_dec_init("9757.508701619388981352487064");
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_77) {
  // 428818814699167830540694227
  s21_decimal dec_1 = {{0xc8fa32d3, 0x8664c038, 0x162b5ea, 0x0}};
  // -43.078
  s21_decimal dec_2 = {{0xa846, 0x0, 0x0, 0x80030000}};
  // DEFECT: Ожидаемое значение больше максимума dec
  // -9954473622247268455840434.2588
  // -9954473622247268455840434.259 - корректное значение
  // s21_decimal dec_check = {{0x738d33c, 0x98566949, 0x41a579d3, 0x80040000}};
  s21_decimal dec_check = s21_dec_init("-9954473622247268455840434.259");
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_78) {
  // -281290902768573715217
  s21_decimal dec_1 = {{0x95c79311, 0x3fb209b9, 0xf, 0x80000000}};
  // -26.8
  s21_decimal dec_2 = {{0x10c, 0x0, 0x0, 0x80010000}};
  // 10495929207782601314.067164179
  s21_decimal dec_check = {{0x49362c13, 0x7772f3ec, 0x21ea0776, 0x90000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_79) {
  // 77829
  s21_decimal dec_1 = {{0x13005, 0x0, 0x0, 0x0}};
  // 7999.660016702697494220
  s21_decimal dec_2 = {{0x3b7d6cc, 0xa995912d, 0x1b1, 0x120000}};
  // DEFECT: Ожидаемое значение больше максимума dec
  // 9.7290384638220641413696596033
  // 9.729038463822064141369659603 - корректное
  // s21_decimal dec_check = {{0xc3582841, 0x55e098ff, 0x3a5cb84f, 0x1c0000}};
  s21_decimal dec_check = s21_dec_init("9.729038463822064141369659603");
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_80) {
  // -908857051181.4
  s21_decimal dec_1 = {{0x190451c6, 0x844, 0x0, 0x80010000}};
  // -49799235.1806
  s21_decimal dec_2 = {{0xf2a8403e, 0x73, 0x0, 0x80040000}};
  // 18250.421876668864673796756916
  s21_decimal dec_check = {{0xf5c695b4, 0x5f81625f, 0x3af86528, 0x180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_81) {
  // 5253283049644261469664
  s21_decimal dec_1 = {{0xa2f56de0, 0xc7f28c90, 0x11c, 0x0}};
  // -740080666480
  s21_decimal dec_2 = {{0x503ec770, 0xac, 0x0, 0x80000000}};
  // -7098257375.9562284379484254082
  s21_decimal dec_check = {{0x9984ef82, 0xefbe6d61, 0xe55b68a9, 0x80130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_82) {
  // -567643926791319052
  s21_decimal dec_1 = {{0xd74dee0c, 0x7e0ad24, 0x0, 0x80000000}};
  // 5.2370
  s21_decimal dec_2 = {{0xcc92, 0x0, 0x0, 0x40000}};
  // -108391049606896897.46037807905
  s21_decimal dec_check = {{0x5cd01b21, 0x4f14a06d, 0x2305e5c1, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_83) {
  // 882313344653962758380
  s21_decimal dec_1 = {{0x2e3fc8ec, 0xd48eb044, 0x2f, 0x0}};
  // 63306187
  s21_decimal dec_2 = {{0x3c5f9cb, 0x0, 0x0, 0x0}};
  // 13937237203276.241520911692249
  s21_decimal dec_check = {{0x593b1d9, 0xb63ebdb2, 0x2d089cc6, 0xf0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_84) {
  // 900349192965679525693556
  s21_decimal dec_1 = {{0x3bcc8874, 0x70d8bd1, 0xbea8, 0x0}};
  // 552947400841534.0
  s21_decimal dec_2 = {{0xfe10fc6c, 0x13a506, 0x0, 0x10000}};
  // 1628272764.4536037842511909687
  s21_decimal dec_check = {{0xf06d337, 0x4f4e3e02, 0x349cc1b2, 0x130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_85) {
  // 45517042662441953
  s21_decimal dec_1 = {{0x571f03e1, 0xa1b582, 0x0, 0x0}};
  // -99406.3397425343560
  s21_decimal dec_2 = {{0xa7c16c48, 0xdcb9f64, 0x0, 0x800d0000}};
  // -457888730038.06970218995851161
  s21_decimal dec_check = {{0x15d1f99, 0x51cc012b, 0x93f3ab03, 0x80110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_86) {
  // 492977752673649.19788085230
  s21_decimal dec_1 = {{0x35ba9fee, 0xc08ecce5, 0x28c735, 0xb0000}};
  // 9884745.1725515047590
  s21_decimal dec_2 = {{0xcbe5c2a6, 0x5bc8b1a0, 0x5, 0xd0000}};
  // 49872580.837245708230130091558
  s21_decimal dec_check = {{0xdbbf4626, 0x8f5e9118, 0xa125a1c8, 0x150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_87) {
  // -6298454191509178382525776495
  s21_decimal dec_1 = {{0x171dc26f, 0xe3010208, 0x1459f58d, 0x80000000}};
  // -870576192528569.521327392927
  s21_decimal dec_2 = {{0x76d1489f, 0xf6724eb1, 0x2d01fad, 0x800c0000}};
  // 7234810974115.2648119321664536
  s21_decimal dec_check = {{0x4a609c18, 0xd430c813, 0xe9c4f427, 0x100000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_88) {
  // 81715693227170075914053
  s21_decimal dec_1 = {{0x29f22f45, 0xd10d19d0, 0x114d, 0x0}};
  // -36.7308763007862780978271677
  s21_decimal dec_2 = {{0xe9b415bd, 0xf0f95355, 0x12fd4a7, 0x80190000}};
  // -2224713958850495272672.7754312
  s21_decimal dec_check = {{0x2890248, 0xac19b16b, 0x47e2670d, 0x80070000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_89) {
  // -7988229971317636512
  s21_decimal dec_1 = {{0xe0843da0, 0x6edbe4d5, 0x0, 0x80000000}};
  // 41416
  s21_decimal dec_2 = {{0xa1c8, 0x0, 0x0, 0x0}};
  // -192877872593143.62835619084412
  s21_decimal dec_check = {{0xd2b4f87c, 0x7308294f, 0x3e527bd2, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_90) {
  // -76241844455663837137
  s21_decimal dec_1 = {{0xf86d9fd1, 0x22117195, 0x4, 0x80000000}};
  // -85039.00167137981893772
  s21_decimal dec_2 = {{0xfc600c8c, 0xff52726a, 0x1cc, 0x80110000}};
  // DEFECT: Ожидаемое значение больше максимума dec
  // 896551499396579.85638592854804
  // 896551499396579.856385928548 - корректное
  // s21_decimal dec_check = {{0xe58ebb14, 0xf45cd4c0, 0x21b10078, 0xe0000}};
  s21_decimal dec_check = s21_dec_init("896551499396579.856385928548");
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_91) {
  // -38195327811021668931.0
  s21_decimal dec_1 = {{0x1b73169e, 0xb4aaa2c4, 0x14, 0x80010000}};
  // -321298786.2972672394825866
  s21_decimal dec_2 = {{0x6302908a, 0x6bca9a5e, 0x2a860, 0x80100000}};
  // 118877908787.62660855568721288
  s21_decimal dec_check = {{0xcdfce588, 0xd723eebd, 0x266959a2, 0x110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_92) {
  // -9957832
  s21_decimal dec_1 = {{0x97f1c8, 0x0, 0x0, 0x80000000}};
  // -3287257.9
  s21_decimal dec_2 = {{0x1f59883, 0x0, 0x0, 0x80010000}};
  // 3.0292214066927940153402627765
  s21_decimal dec_check = {{0x45ea96b5, 0x9b7d88f, 0x61e121d7, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_93) {
  // 63433
  s21_decimal dec_1 = {{0xf7c9, 0x0, 0x0, 0x0}};
  // 1280
  s21_decimal dec_2 = {{0x500, 0x0, 0x0, 0x0}};
  // 49.55703125
  s21_decimal dec_check = {{0x27620755, 0x1, 0x0, 0x80000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_94) {
  // 36187.61
  s21_decimal dec_1 = {{0x3737c9, 0x0, 0x0, 0x20000}};
  // -0.30
  s21_decimal dec_2 = {{0x1e, 0x0, 0x0, 0x80020000}};
  // -120625.36666666666666666666667
  s21_decimal dec_check = {{0x916aaaab, 0xfbfb43e0, 0x26f9e57e, 0x80170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_95) {
  // 7612658626422340292764731243
  s21_decimal dec_1 = {{0xfa5b876b, 0xed147e6, 0x18990b2b, 0x0}};
  // 7.624599529
  s21_decimal dec_2 = {{0xc67627e9, 0x1, 0x0, 0x90000}};
  // DEFECT: Ожидаемое значение больше максимума dec
  // 998433897736891919161769164.05
  // 998433897736891919161769164 - корректное
  // s21_decimal dec_check = {{0xedfbfb5, 0xc2ba498, 0x429c842d, 0x20000}};
  s21_decimal dec_check = s21_dec_init("998433897736891919161769164");
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_96) {
  // -1895935280109.56863031649
  s21_decimal dec_1 = {{0xc19c961, 0xe2c06067, 0x2825, 0x800b0000}};
  // -8
  s21_decimal dec_2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // 236991910013.69607878956125
  s21_decimal dec_check = {{0xe897545d, 0xb7ef1250, 0x139a7f, 0xe0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_97) {
  // 84261460554310853064760363
  s21_decimal dec_1 = {{0x48e19c2b, 0xedf3024e, 0x45b30e, 0x0}};
  // -337700675001
  s21_decimal dec_2 = {{0xa0875db9, 0x4e, 0x0, 0x80000000}};
  // -249515226921182.01373994642145
  s21_decimal dec_check = {{0x4079eae1, 0x7b156f15, 0x509f6a73, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_98) {
  // 354331478551863071
  s21_decimal dec_1 = {{0x37d29f1f, 0x4ead69a, 0x0, 0x0}};
  // 807860.575
  s21_decimal dec_2 = {{0x3026f95f, 0x0, 0x0, 0x30000}};
  // 438604741358.82057494883940833
  s21_decimal dec_check = {{0x940339e1, 0x37e7c43d, 0x8db888ab, 0x110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_99) {
  // 5082333730922630358103070991
  s21_decimal dec_1 = {{0x2501990f, 0x9e3e0368, 0x106c0207, 0x0}};
  // 660573892
  s21_decimal dec_2 = {{0x275f8ec4, 0x0, 0x0, 0x0}};
  // 7693815623767689501.8779685453
  s21_decimal dec_check = {{0x53ac324d, 0xfef4ca19, 0xf899c04e, 0xa0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_100) {
  // 725113.7
  s21_decimal dec_1 = {{0x6ea4c1, 0x0, 0x0, 0x10000}};
  // -67
  s21_decimal dec_2 = {{0x43, 0x0, 0x0, 0x80000000}};
  // -10822.592537313432835820895522
  s21_decimal dec_check = {{0xe0d03d22, 0xb45a751, 0x22f83d1d, 0x80180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

// DEFECT No overflow
// >>> a = decimal.Decimal("-98557406550206450.12964")
// >>> b = decimal.Decimal("-6598267897643447629630")
// Decimal('0.00001493686041232214047268125559')
// 		 0.0000149368604123221404726813
// START_TEST(fail_s21_div_1) {
//   // -98557406550206450.12964
//   s21_decimal dec_1 = {{0x1143d5e4, 0x47e0a3ca, 0x216, 0x80050000}};
//   // -6598267897643447629630
//   s21_decimal dec_2 = {{0xfd34373e, 0xb15c9dc8, 0x165, 0x80000000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// DEFECT TEST CASE
// START_TEST(fail_s21_div_2) {
//   // 19
//   s21_decimal dec_1 = {{0x13, 0x0, 0x0, 0x0}};
//   // 7958417483
//   s21_decimal dec_2 = {{0xda5bd04b, 0x1, 0x0, 0x0}};
//   s21_decimal result;
//   // overflow
//   // Результат ок: 0.0000000023874093110327471872
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// DEFECT TEST CASE
// START_TEST(fail_s21_div_3) {
//   // 675053231.4
//   s21_decimal dec_1 = {{0x925cf2da, 0x1, 0x0, 0x10000}};
//   // -901685848
//   s21_decimal dec_2 = {{0x35bea258, 0x0, 0x0, 0x80000000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// DEFECT TEST CASE
// START_TEST(fail_s21_div_4) {
//   // 7
//   s21_decimal dec_1 = {{0x7, 0x0, 0x0, 0x0}};
//   // -52578420788359519460488
//   s21_decimal dec_2 = {{0xbf0edc88, 0x482abe99, 0xb22, 0x80000000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// DEFECT TEST CASE
// START_TEST(fail_s21_div_5) {
//   // 2712
//   s21_decimal dec_1 = {{0xa98, 0x0, 0x0, 0x0}};
//   // 43941.87
//   s21_decimal dec_2 = {{0x430ccb, 0x0, 0x0, 0x20000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// DEFECT TEST CASE
// START_TEST(fail_s21_div_6) {
//   // -65363.08
//   s21_decimal dec_1 = {{0x63bc74, 0x0, 0x0, 0x80020000}};
//   // -2673080.4190
//   s21_decimal dec_2 = {{0x3947b3de, 0x6, 0x0, 0x80040000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// DEFECT TEST CASE
// START_TEST(fail_s21_div_7) {
//   // 5112522916187
//   s21_decimal dec_1 = {{0x5a1cc15b, 0x4a6, 0x0, 0x0}};
//   // -1572023687874063
//   s21_decimal dec_2 = {{0x497e860f, 0x595bf, 0x0, 0x80000000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// DEFECT TEST CASE
// START_TEST(fail_s21_div_8) {
//   // 49083
//   s21_decimal dec_1 = {{0xbfbb, 0x0, 0x0, 0x0}};
//   // -1219813293371
//   s21_decimal dec_2 = {{0x289bd3b, 0x11c, 0x0, 0x80000000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// DEFECT TEST CASE
// START_TEST(fail_s21_div_9) {
//   // -32898.233
//   s21_decimal dec_1 = {{0x1f5fcb9, 0x0, 0x0, 0x80030000}};
//   // -9919358703996
//   s21_decimal dec_2 = {{0x87da197c, 0x905, 0x0, 0x80000000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// DEFECT TEST CASE
// START_TEST(fail_s21_div_10) {
//   // -239279666
//   s21_decimal dec_1 = {{0xe431e32, 0x0, 0x0, 0x80000000}};
//   // 276655298
//   s21_decimal dec_2 = {{0x107d6cc2, 0x0, 0x0, 0x0}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// DEFECT TEST CASE
// START_TEST(fail_s21_div_11) {
//   // 718
//   s21_decimal dec_1 = {{0x2ce, 0x0, 0x0, 0x0}};
//   // -6752608316
//   s21_decimal dec_2 = {{0x927ca03c, 0x1, 0x0, 0x80000000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// DEFECT TEST CASE
// START_TEST(fail_s21_div_12) {
//   // -741.99
//   s21_decimal dec_1 = {{0x121d7, 0x0, 0x0, 0x80020000}};
//   // -79675891.2389843
//   s21_decimal dec_2 = {{0xe3f1d2d3, 0x2d4a5, 0x0, 0x80070000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// DEFECT TEST CASE
// START_TEST(fail_s21_div_13) {
//   // -69597.767907035739317
//   s21_decimal dec_1 = {{0xaaf274b5, 0xc5dcf12a, 0x3, 0x800f0000}};
//   // -94050786.682680268
//   s21_decimal dec_2 = {{0x331133cc, 0x14e22b1, 0x0, 0x80090000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// DEFECT TEST CASE
// START_TEST(fail_s21_div_14) {
//   // -555
//   s21_decimal dec_1 = {{0x22b, 0x0, 0x0, 0x80000000}};
//   // -35658192567918627
//   s21_decimal dec_2 = {{0xed57e023, 0x7eaeef, 0x0, 0x80000000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// DEFECT TEST CASE
// START_TEST(fail_s21_div_15) {
//   // -0.77
//   s21_decimal dec_1 = {{0x4d, 0x0, 0x0, 0x80020000}};
//   // 6.81908933434594278259
//   s21_decimal dec_2 = {{0xe67bbb73, 0xf763320c, 0x24, 0x140000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// DEFECT TEST CASE
// START_TEST(fail_s21_div_16) {
//   // -66261695.64755
//   s21_decimal dec_1 = {{0xc67bae53, 0x606, 0x0, 0x80050000}};
//   // 91558626482
//   s21_decimal dec_2 = {{0x5151c4b2, 0x15, 0x0, 0x0}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// DEFECT TEST CASE
// START_TEST(fail_s21_div_17) {
//   // -2
//   s21_decimal dec_1 = {{0x2, 0x0, 0x0, 0x80000000}};
//   // -2218374740789178
//   s21_decimal dec_2 = {{0x9e6747ba, 0x7e199, 0x0, 0x80000000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// DEFECT TEST CASE
// START_TEST(fail_s21_div_18) {
//   // 2574.472
//   s21_decimal dec_1 = {{0x274888, 0x0, 0x0, 0x30000}};
//   // 1864898
//   s21_decimal dec_2 = {{0x1c74c2, 0x0, 0x0, 0x0}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// DEFECT TEST CASE
// START_TEST(fail_s21_div_19) {
//   // 88
//   s21_decimal dec_1 = {{0x58, 0x0, 0x0, 0x0}};
//   // 89719579808.107
//   s21_decimal dec_2 = {{0x77af116b, 0x5199, 0x0, 0x30000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// DEFECT TEST CASE
// START_TEST(fail_s21_div_20) {
//   // 8363.5475
//   s21_decimal dec_1 = {{0x4fc2d13, 0x0, 0x0, 0x40000}};
//   // -462494956145259790
//   s21_decimal dec_2 = {{0x5372b50e, 0x66b1cb6, 0x0, 0x80000000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// DEFECT TEST CASE
// START_TEST(fail_s21_div_21) {
//   // 905709
//   s21_decimal dec_1 = {{0xdd1ed, 0x0, 0x0, 0x0}};
//   // -54172511
//   s21_decimal dec_2 = {{0x33a9b5f, 0x0, 0x0, 0x80000000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// DEFECT TEST CASE
// START_TEST(fail_s21_div_22) {
//   // -860965288395
//   s21_decimal dec_1 = {{0x7587b9cb, 0xc8, 0x0, 0x80000000}};
//   // -47453857058533972
//   s21_decimal dec_2 = {{0x15323254, 0xa89708, 0x0, 0x80000000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// DEFECT TEST CASE
// START_TEST(fail_s21_div_23) {
//   // 38691016768.4176012045958853
//   s21_decimal dec_1 = {{0x92d3bec5, 0x37ce9151, 0x1400b6a, 0x100000}};
//   // -2112682601492644159541
//   s21_decimal dec_2 = {{0xdd34e035, 0x875c6095, 0x72, 0x80000000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// DEFECT TEST CASE
// START_TEST(fail_s21_div_24) {
//   // -541413821462.457
//   s21_decimal dec_1 = {{0xba8137b9, 0x1ec69, 0x0, 0x80030000}};
//   // 886849613359586.20187
//   s21_decimal dec_2 = {{0x4510c81b, 0xcec04676, 0x4, 0x50000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// DEFECT TEST CASE
// START_TEST(fail_s21_div_25) {
//   // -6
//   s21_decimal dec_1 = {{0x6, 0x0, 0x0, 0x80000000}};
//   // 468126168459800438867.638712
//   s21_decimal dec_2 = {{0xe2a639b8, 0x712b99c3, 0x1833992, 0x60000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// DEFECT TEST CASE
// START_TEST(fail_s21_div_26) {
//   // 1411247
//   s21_decimal dec_1 = {{0x1588af, 0x0, 0x0, 0x0}};
//   // -7981916.3831676
//   s21_decimal dec_2 = {{0x58e80d7c, 0x4898, 0x0, 0x80070000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// DEFECT TEST CASE
// START_TEST(fail_s21_div_27) {
//   // -97
//   s21_decimal dec_1 = {{0x61, 0x0, 0x0, 0x80000000}};
//   // 46963531991490063166229148143
//   s21_decimal dec_2 = {{0x819371ef, 0xa367ad92, 0x97bf52ba, 0x0}};
//   s21_decimal result;
//   // overflow; -21e-28
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// DEFECT TEST CASE
// START_TEST(fail_s21_div_28) {
//   // -338
//   s21_decimal dec_1 = {{0x152, 0x0, 0x0, 0x80000000}};
//   // -658
//   s21_decimal dec_2 = {{0x292, 0x0, 0x0, 0x80000000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// DEFECT TEST CASE
// START_TEST(fail_s21_div_29) {
//   // 74628
//   s21_decimal dec_1 = {{0x12384, 0x0, 0x0, 0x0}};
//   // 80630298845644416308.543
//   s21_decimal dec_2 = {{0x4033553f, 0xfa2da27b, 0x1112, 0x30000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// DEFECT TEST CASE
// START_TEST(fail_s21_div_30) {
//   // -458590879061.0213
//   s21_decimal dec_1 = {{0x186fc925, 0x104adc, 0x0, 0x80040000}};
//   // -9617424302134390108
//   s21_decimal dec_2 = {{0x8eeded5c, 0x8577f472, 0x0, 0x80000000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// DEFECT TEST CASE
// START_TEST(fail_s21_div_31) {
//   // 3962432
//   s21_decimal dec_1 = {{0x3c7640, 0x0, 0x0, 0x0}};
//   // -8024088242
//   s21_decimal dec_2 = {{0xde45deb2, 0x1, 0x0, 0x80000000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// DEFECT TEST CASE
// START_TEST(fail_s21_div_32) {
//   // 8402
//   s21_decimal dec_1 = {{0x20d2, 0x0, 0x0, 0x0}};
//   // 18715736358227392841.0567
//   s21_decimal dec_2 = {{0x2355b5c7, 0xd22dafde, 0x27a1, 0x40000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// DEFECT TEST CASE
// START_TEST(fail_s21_div_33) {
//   // -72
//   s21_decimal dec_1 = {{0x48, 0x0, 0x0, 0x80000000}};
//   // -3024.95113
//   s21_decimal dec_2 = {{0x1207b589, 0x0, 0x0, 0x80050000}};
//   s21_decimal result;
//   // overflow
//   int check = 2; // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

Suite *all_arithmetic_functions_cases(void) {
  Suite *c = suite_create("all_arithmetic_functions_cases");

  TCase *add = tcase_create("s21_add");
  tcase_add_test(add, invalid_dec_s21_add_1);
  tcase_add_test(add, invalid_dec_s21_add_2);
  tcase_add_test(add, invalid_dec_s21_add_3);
  tcase_add_test(add, invalid_dec_s21_add_4);
  tcase_add_test(add, invalid_dec_s21_add_5);
  tcase_add_test(add, invalid_dec_s21_add_6);
  tcase_add_test(add, invalid_dec_s21_add_7);
  tcase_add_test(add, invalid_dec_s21_add_8);
  tcase_add_test(add, invalid_dec_s21_add_9);
  tcase_add_test(add, invalid_dec_s21_add_10);
  tcase_add_test(add, invalid_dec_s21_add_11);
  tcase_add_test(add, invalid_dec_s21_add_12);
  tcase_add_test(add, invalid_dec_s21_add_13);
  tcase_add_test(add, invalid_dec_s21_add_14);
  tcase_add_test(add, invalid_dec_s21_add_15);
  tcase_add_test(add, invalid_dec_s21_add_16);
  // tcase_add_test(add, s21_add_1);
  tcase_add_test(add, s21_add_2);
  tcase_add_test(add, s21_add_3);
  tcase_add_test(add, s21_add_4);
  tcase_add_test(add, s21_add_5);
  tcase_add_test(add, s21_add_6);
  tcase_add_test(add, s21_add_7);
  // tcase_add_test(add, s21_add_8);
  tcase_add_test(add, s21_add_9);
  tcase_add_test(add, s21_add_10);
  tcase_add_test(add, s21_add_11);
  tcase_add_test(add, s21_add_12);
  tcase_add_test(add, s21_add_13);
  tcase_add_test(add, s21_add_14);
  tcase_add_test(add, s21_add_15);
  tcase_add_test(add, s21_add_16);
  tcase_add_test(add, s21_add_17);
  tcase_add_test(add, s21_add_18);
  tcase_add_test(add, s21_add_19);
  tcase_add_test(add, s21_add_20);
  tcase_add_test(add, s21_add_21);
  // tcase_add_test(add, s21_add_22);
  tcase_add_test(add, s21_add_23);
  tcase_add_test(add, s21_add_24);
  tcase_add_test(add, s21_add_25);
  tcase_add_test(add, s21_add_26);
  tcase_add_test(add, s21_add_27);
  tcase_add_test(add, s21_add_28);
  tcase_add_test(add, s21_add_29);
  tcase_add_test(add, s21_add_30);
  tcase_add_test(add, s21_add_31);
  tcase_add_test(add, s21_add_32);
  tcase_add_test(add, s21_add_33);
  tcase_add_test(add, s21_add_34);
  tcase_add_test(add, s21_add_35);
  tcase_add_test(add, s21_add_36);
  tcase_add_test(add, s21_add_37);
  tcase_add_test(add, s21_add_38);
  tcase_add_test(add, s21_add_39);
  tcase_add_test(add, s21_add_40);
  tcase_add_test(add, s21_add_41);
  tcase_add_test(add, s21_add_42);
  tcase_add_test(add, s21_add_43);
  tcase_add_test(add, s21_add_44);
  tcase_add_test(add, s21_add_45);
  // tcase_add_test(add, s21_add_46);
  // tcase_add_test(add, s21_add_47);
  tcase_add_test(add, s21_add_48);
  // tcase_add_test(add, s21_add_49);
  tcase_add_test(add, s21_add_50);
  tcase_add_test(add, s21_add_51);
  tcase_add_test(add, s21_add_52);
  tcase_add_test(add, s21_add_53);
  tcase_add_test(add, s21_add_54);
  tcase_add_test(add, s21_add_55);
  tcase_add_test(add, s21_add_56);
  // tcase_add_test(add, s21_add_57);
  tcase_add_test(add, s21_add_58);
  tcase_add_test(add, s21_add_59);
  // tcase_add_test(add, s21_add_60);
  tcase_add_test(add, s21_add_61);
  tcase_add_test(add, s21_add_62);
  tcase_add_test(add, s21_add_63);
  tcase_add_test(add, s21_add_64);
  tcase_add_test(add, s21_add_65);
  tcase_add_test(add, s21_add_66);
  tcase_add_test(add, s21_add_67);
  tcase_add_test(add, s21_add_68);
  // tcase_add_test(add, s21_add_69);
  tcase_add_test(add, s21_add_70);
  tcase_add_test(add, s21_add_71);
  tcase_add_test(add, s21_add_72);
  tcase_add_test(add, s21_add_73);
  tcase_add_test(add, s21_add_74);
  tcase_add_test(add, s21_add_75);
  tcase_add_test(add, s21_add_76);
  tcase_add_test(add, s21_add_77);
  tcase_add_test(add, s21_add_78);
  tcase_add_test(add, s21_add_79);
  tcase_add_test(add, s21_add_80);
  tcase_add_test(add, s21_add_81);
  tcase_add_test(add, s21_add_82);
  tcase_add_test(add, s21_add_83);
  // tcase_add_test(add, s21_add_84);
  // tcase_add_test(add, s21_add_85);
  tcase_add_test(add, s21_add_86);
  tcase_add_test(add, s21_add_87);
  tcase_add_test(add, s21_add_88);
  tcase_add_test(add, s21_add_89);
  tcase_add_test(add, s21_add_90);
  tcase_add_test(add, s21_add_91);
  tcase_add_test(add, s21_add_92);
  tcase_add_test(add, s21_add_93);
  tcase_add_test(add, s21_add_94);
  tcase_add_test(add, s21_add_95);
  tcase_add_test(add, s21_add_96);
  tcase_add_test(add, s21_add_97);
  tcase_add_test(add, s21_add_98);
  tcase_add_test(add, s21_add_99);
  tcase_add_test(add, s21_add_100);
  tcase_add_test(add, fail_s21_add_1);
  tcase_add_test(add, fail_s21_add_2);
  tcase_add_test(add, fail_s21_add_3);
  tcase_add_test(add, fail_s21_add_4);
  tcase_add_test(add, fail_s21_add_5);
  tcase_add_test(add, fail_s21_add_6);
  tcase_add_test(add, fail_s21_add_7);
  tcase_add_test(add, fail_s21_add_8);
  tcase_add_test(add, fail_s21_add_9);
  tcase_add_test(add, fail_s21_add_10);
  tcase_add_test(add, fail_s21_add_11);
  tcase_add_test(add, fail_s21_add_12);
  tcase_add_test(add, fail_s21_add_13);
  tcase_add_test(add, fail_s21_add_14);
  tcase_add_test(add, fail_s21_add_15);
  tcase_add_test(add, fail_s21_add_16);
  tcase_add_test(add, fail_s21_add_17);
  tcase_add_test(add, fail_s21_add_18);
  tcase_add_test(add, fail_s21_add_19);
  tcase_add_test(add, fail_s21_add_20);
  tcase_add_test(add, fail_s21_add_21);
  tcase_add_test(add, fail_s21_add_22);
  tcase_add_test(add, fail_s21_add_23);
  tcase_add_test(add, fail_s21_add_24);
  tcase_add_test(add, fail_s21_add_25);
  tcase_add_test(add, fail_s21_add_26);
  tcase_add_test(add, fail_s21_add_27);
  tcase_add_test(add, fail_s21_add_28);
  tcase_add_test(add, fail_s21_add_29);
  tcase_add_test(add, fail_s21_add_30);
  tcase_add_test(add, fail_s21_add_31);
  tcase_add_test(add, fail_s21_add_32);
  tcase_add_test(add, fail_s21_add_33);

  TCase *sub = tcase_create("s21_sub");
  tcase_add_test(sub, invalid_dec_s21_sub_1);
  tcase_add_test(sub, invalid_dec_s21_sub_2);
  tcase_add_test(sub, invalid_dec_s21_sub_3);
  tcase_add_test(sub, invalid_dec_s21_sub_4);
  tcase_add_test(sub, invalid_dec_s21_sub_5);
  tcase_add_test(sub, invalid_dec_s21_sub_6);
  tcase_add_test(sub, invalid_dec_s21_sub_7);
  tcase_add_test(sub, invalid_dec_s21_sub_8);
  tcase_add_test(sub, invalid_dec_s21_sub_9);
  tcase_add_test(sub, invalid_dec_s21_sub_10);
  tcase_add_test(sub, invalid_dec_s21_sub_11);
  tcase_add_test(sub, invalid_dec_s21_sub_12);
  tcase_add_test(sub, invalid_dec_s21_sub_13);
  tcase_add_test(sub, invalid_dec_s21_sub_14);
  tcase_add_test(sub, invalid_dec_s21_sub_15);
  tcase_add_test(sub, invalid_dec_s21_sub_16);
  tcase_add_test(sub, s21_sub_1);
  // tcase_add_test(sub, s21_sub_2);
  tcase_add_test(sub, s21_sub_3);
  tcase_add_test(sub, s21_sub_4);
  tcase_add_test(sub, s21_sub_5);
  tcase_add_test(sub, s21_sub_6);
  tcase_add_test(sub, s21_sub_7);
  tcase_add_test(sub, s21_sub_8);
  tcase_add_test(sub, s21_sub_9);
  tcase_add_test(sub, s21_sub_10);
  tcase_add_test(sub, s21_sub_11);
  tcase_add_test(sub, s21_sub_12);
  tcase_add_test(sub, s21_sub_13);
  tcase_add_test(sub, s21_sub_14);
  tcase_add_test(sub, s21_sub_15);
  tcase_add_test(sub, s21_sub_16);
  tcase_add_test(sub, s21_sub_17);
  tcase_add_test(sub, s21_sub_18);
  tcase_add_test(sub, s21_sub_19);
  tcase_add_test(sub, s21_sub_20);
  tcase_add_test(sub, s21_sub_21);
  tcase_add_test(sub, s21_sub_22);
  tcase_add_test(sub, s21_sub_23);
  // tcase_add_test(sub, s21_sub_24);
  tcase_add_test(sub, s21_sub_25);
  tcase_add_test(sub, s21_sub_26);
  tcase_add_test(sub, s21_sub_27);
  tcase_add_test(sub, s21_sub_28);
  // tcase_add_test(sub, s21_sub_29);
  tcase_add_test(sub, s21_sub_30);
  tcase_add_test(sub, s21_sub_31);
  tcase_add_test(sub, s21_sub_32);
  tcase_add_test(sub, s21_sub_33);
  tcase_add_test(sub, s21_sub_34);
  tcase_add_test(sub, s21_sub_35);
  tcase_add_test(sub, s21_sub_36);
  tcase_add_test(sub, s21_sub_37);
  tcase_add_test(sub, s21_sub_38);
  tcase_add_test(sub, s21_sub_39);
  // tcase_add_test(sub, s21_sub_40);
  tcase_add_test(sub, s21_sub_41);
  tcase_add_test(sub, s21_sub_42);
  tcase_add_test(sub, s21_sub_43);
  tcase_add_test(sub, s21_sub_44);
  tcase_add_test(sub, s21_sub_45);
  tcase_add_test(sub, s21_sub_46);
  tcase_add_test(sub, s21_sub_47);
  tcase_add_test(sub, s21_sub_48);
  tcase_add_test(sub, s21_sub_49);
  tcase_add_test(sub, s21_sub_50);
  // tcase_add_test(sub, s21_sub_51);
  tcase_add_test(sub, s21_sub_52);
  // tcase_add_test(sub, s21_sub_53);
  tcase_add_test(sub, s21_sub_54);
  tcase_add_test(sub, s21_sub_55);
  // tcase_add_test(sub, s21_sub_56);
  tcase_add_test(sub, s21_sub_57);
  tcase_add_test(sub, s21_sub_58);
  tcase_add_test(sub, s21_sub_59);
  tcase_add_test(sub, s21_sub_60);
  tcase_add_test(sub, s21_sub_61);
  tcase_add_test(sub, s21_sub_62);
  tcase_add_test(sub, s21_sub_63);
  tcase_add_test(sub, s21_sub_64);
  tcase_add_test(sub, s21_sub_65);
  tcase_add_test(sub, s21_sub_66);
  tcase_add_test(sub, s21_sub_67);
  // tcase_add_test(sub, s21_sub_68);
  tcase_add_test(sub, s21_sub_69);
  tcase_add_test(sub, s21_sub_70);
  tcase_add_test(sub, s21_sub_71);
  tcase_add_test(sub, s21_sub_72);
  tcase_add_test(sub, s21_sub_73);
  tcase_add_test(sub, s21_sub_74);
  tcase_add_test(sub, s21_sub_75);
  tcase_add_test(sub, s21_sub_76);
  tcase_add_test(sub, s21_sub_77);
  tcase_add_test(sub, s21_sub_78);
  tcase_add_test(sub, s21_sub_79);
  tcase_add_test(sub, s21_sub_80);
  tcase_add_test(sub, s21_sub_81);
  tcase_add_test(sub, s21_sub_82);
  tcase_add_test(sub, s21_sub_83);
  tcase_add_test(sub, s21_sub_84);
  tcase_add_test(sub, s21_sub_85);
  // tcase_add_test(sub, s21_sub_86);
  tcase_add_test(sub, s21_sub_87);
  tcase_add_test(sub, s21_sub_88);
  tcase_add_test(sub, s21_sub_89);
  tcase_add_test(sub, s21_sub_90);
  tcase_add_test(sub, s21_sub_91);
  tcase_add_test(sub, s21_sub_92);
  tcase_add_test(sub, s21_sub_93);
  // tcase_add_test(sub, s21_sub_94);
  tcase_add_test(sub, s21_sub_95);
  tcase_add_test(sub, s21_sub_96);
  tcase_add_test(sub, s21_sub_97);
  // tcase_add_test(sub, s21_sub_98);
  tcase_add_test(sub, s21_sub_99);
  tcase_add_test(sub, s21_sub_100);
  tcase_add_test(sub, fail_s21_sub_1);
  tcase_add_test(sub, fail_s21_sub_2);
  tcase_add_test(sub, fail_s21_sub_3);
  tcase_add_test(sub, fail_s21_sub_4);
  tcase_add_test(sub, fail_s21_sub_5);
  tcase_add_test(sub, fail_s21_sub_6);
  tcase_add_test(sub, fail_s21_sub_7);
  tcase_add_test(sub, fail_s21_sub_8);
  tcase_add_test(sub, fail_s21_sub_9);
  tcase_add_test(sub, fail_s21_sub_10);
  tcase_add_test(sub, fail_s21_sub_11);
  tcase_add_test(sub, fail_s21_sub_12);
  tcase_add_test(sub, fail_s21_sub_13);
  tcase_add_test(sub, fail_s21_sub_14);
  tcase_add_test(sub, fail_s21_sub_15);
  tcase_add_test(sub, fail_s21_sub_16);
  tcase_add_test(sub, fail_s21_sub_17);
  tcase_add_test(sub, fail_s21_sub_18);
  tcase_add_test(sub, fail_s21_sub_19);
  tcase_add_test(sub, fail_s21_sub_20);
  tcase_add_test(sub, fail_s21_sub_21);
  tcase_add_test(sub, fail_s21_sub_22);
  tcase_add_test(sub, fail_s21_sub_23);
  tcase_add_test(sub, fail_s21_sub_24);
  tcase_add_test(sub, fail_s21_sub_25);
  tcase_add_test(sub, fail_s21_sub_26);
  tcase_add_test(sub, fail_s21_sub_27);
  tcase_add_test(sub, fail_s21_sub_28);
  tcase_add_test(sub, fail_s21_sub_29);
  tcase_add_test(sub, fail_s21_sub_30);
  tcase_add_test(sub, fail_s21_sub_31);
  tcase_add_test(sub, fail_s21_sub_32);
  tcase_add_test(sub, fail_s21_sub_33);

  TCase *mul = tcase_create("s21_mul");
  tcase_add_test(mul, invalid_dec_s21_mul_1);
  tcase_add_test(mul, invalid_dec_s21_mul_2);
  tcase_add_test(mul, invalid_dec_s21_mul_3);
  tcase_add_test(mul, invalid_dec_s21_mul_4);
  tcase_add_test(mul, invalid_dec_s21_mul_5);
  tcase_add_test(mul, invalid_dec_s21_mul_6);
  tcase_add_test(mul, invalid_dec_s21_mul_7);
  tcase_add_test(mul, invalid_dec_s21_mul_8);
  tcase_add_test(mul, invalid_dec_s21_mul_9);
  tcase_add_test(mul, invalid_dec_s21_mul_10);
  tcase_add_test(mul, invalid_dec_s21_mul_11);
  tcase_add_test(mul, invalid_dec_s21_mul_12);
  tcase_add_test(mul, invalid_dec_s21_mul_13);
  tcase_add_test(mul, invalid_dec_s21_mul_14);
  tcase_add_test(mul, invalid_dec_s21_mul_15);
  tcase_add_test(mul, invalid_dec_s21_mul_16);
  tcase_add_test(mul, s21_mul_1);
  tcase_add_test(mul, s21_mul_2);
  tcase_add_test(mul, s21_mul_3);
  tcase_add_test(mul, s21_mul_4);
  tcase_add_test(mul, s21_mul_5);
  tcase_add_test(mul, s21_mul_6);
  tcase_add_test(mul, s21_mul_7);
  tcase_add_test(mul, s21_mul_8);
  tcase_add_test(mul, s21_mul_9);
  tcase_add_test(mul, s21_mul_10);
  tcase_add_test(mul, s21_mul_11);
  tcase_add_test(mul, s21_mul_12);
  tcase_add_test(mul, s21_mul_13);
  tcase_add_test(mul, s21_mul_14);
  tcase_add_test(mul, s21_mul_15);
  tcase_add_test(mul, s21_mul_16);
  tcase_add_test(mul, s21_mul_17);
  tcase_add_test(mul, s21_mul_18);
  tcase_add_test(mul, s21_mul_19);
  tcase_add_test(mul, s21_mul_20);
  tcase_add_test(mul, s21_mul_21);
  tcase_add_test(mul, s21_mul_22);
  tcase_add_test(mul, s21_mul_23);
  tcase_add_test(mul, s21_mul_24);
  tcase_add_test(mul, s21_mul_25);
  tcase_add_test(mul, s21_mul_26);
  tcase_add_test(mul, s21_mul_27);
  tcase_add_test(mul, s21_mul_28);
  tcase_add_test(mul, s21_mul_29);
  tcase_add_test(mul, s21_mul_30);
  tcase_add_test(mul, s21_mul_31);
  tcase_add_test(mul, s21_mul_32);
  tcase_add_test(mul, s21_mul_33);
  tcase_add_test(mul, s21_mul_34);
  tcase_add_test(mul, s21_mul_35);
  tcase_add_test(mul, s21_mul_36);
  tcase_add_test(mul, s21_mul_37);
  tcase_add_test(mul, s21_mul_38);
  tcase_add_test(mul, s21_mul_39);
  tcase_add_test(mul, s21_mul_40);
  tcase_add_test(mul, s21_mul_41);
  tcase_add_test(mul, s21_mul_42);
  tcase_add_test(mul, s21_mul_43);
  tcase_add_test(mul, s21_mul_44);
  tcase_add_test(mul, s21_mul_45);
  tcase_add_test(mul, s21_mul_46);
  tcase_add_test(mul, s21_mul_47);
  tcase_add_test(mul, s21_mul_48);
  tcase_add_test(mul, s21_mul_49);
  tcase_add_test(mul, s21_mul_50);
  tcase_add_test(mul, s21_mul_51);
  tcase_add_test(mul, s21_mul_52);
  tcase_add_test(mul, s21_mul_53);
  tcase_add_test(mul, s21_mul_54);
  tcase_add_test(mul, s21_mul_55);
  tcase_add_test(mul, s21_mul_56);
  tcase_add_test(mul, s21_mul_57);
  tcase_add_test(mul, s21_mul_58);
  tcase_add_test(mul, s21_mul_59);
  // tcase_add_test(mul, s21_mul_60);
  tcase_add_test(mul, s21_mul_61);
  tcase_add_test(mul, s21_mul_62);
  tcase_add_test(mul, s21_mul_63);
  tcase_add_test(mul, s21_mul_64);
  tcase_add_test(mul, s21_mul_65);
  tcase_add_test(mul, s21_mul_66);
  tcase_add_test(mul, s21_mul_67);
  tcase_add_test(mul, s21_mul_68);
  tcase_add_test(mul, s21_mul_69);
  tcase_add_test(mul, s21_mul_70);
  tcase_add_test(mul, s21_mul_71);
  tcase_add_test(mul, s21_mul_72);
  tcase_add_test(mul, s21_mul_73);
  tcase_add_test(mul, s21_mul_74);
  tcase_add_test(mul, s21_mul_75);
  tcase_add_test(mul, s21_mul_76);
  tcase_add_test(mul, s21_mul_77);
  tcase_add_test(mul, s21_mul_78);
  tcase_add_test(mul, s21_mul_79);
  tcase_add_test(mul, s21_mul_80);
  tcase_add_test(mul, s21_mul_81);
  tcase_add_test(mul, s21_mul_82);
  tcase_add_test(mul, s21_mul_83);
  tcase_add_test(mul, s21_mul_84);
  tcase_add_test(mul, s21_mul_85);
  tcase_add_test(mul, s21_mul_86);
  tcase_add_test(mul, s21_mul_87);
  tcase_add_test(mul, s21_mul_88);
  tcase_add_test(mul, s21_mul_89);
  tcase_add_test(mul, s21_mul_90);
  tcase_add_test(mul, s21_mul_91);
  tcase_add_test(mul, s21_mul_92);
  tcase_add_test(mul, s21_mul_93);
  tcase_add_test(mul, s21_mul_94);
  tcase_add_test(mul, s21_mul_95);
  tcase_add_test(mul, s21_mul_96);
  tcase_add_test(mul, s21_mul_97);
  tcase_add_test(mul, s21_mul_98);
  tcase_add_test(mul, s21_mul_99);
  tcase_add_test(mul, s21_mul_100);
  tcase_add_test(mul, fail_s21_mul_1);
  tcase_add_test(mul, fail_s21_mul_2);
  tcase_add_test(mul, fail_s21_mul_3);
  tcase_add_test(mul, fail_s21_mul_4);
  tcase_add_test(mul, fail_s21_mul_5);
  tcase_add_test(mul, fail_s21_mul_6);
  tcase_add_test(mul, fail_s21_mul_7);
  tcase_add_test(mul, fail_s21_mul_8);
  tcase_add_test(mul, fail_s21_mul_9);
  tcase_add_test(mul, fail_s21_mul_10);
  tcase_add_test(mul, fail_s21_mul_11);
  tcase_add_test(mul, fail_s21_mul_12);
  tcase_add_test(mul, fail_s21_mul_13);
  tcase_add_test(mul, fail_s21_mul_14);
  tcase_add_test(mul, fail_s21_mul_15);
  tcase_add_test(mul, fail_s21_mul_16);
  tcase_add_test(mul, fail_s21_mul_17);
  tcase_add_test(mul, fail_s21_mul_18);
  tcase_add_test(mul, fail_s21_mul_19);
  tcase_add_test(mul, fail_s21_mul_20);
  tcase_add_test(mul, fail_s21_mul_21);
  tcase_add_test(mul, fail_s21_mul_22);
  tcase_add_test(mul, fail_s21_mul_23);
  tcase_add_test(mul, fail_s21_mul_24);
  tcase_add_test(mul, fail_s21_mul_25);
  tcase_add_test(mul, fail_s21_mul_26);
  tcase_add_test(mul, fail_s21_mul_27);
  tcase_add_test(mul, fail_s21_mul_28);
  tcase_add_test(mul, fail_s21_mul_29);
  tcase_add_test(mul, fail_s21_mul_30);
  tcase_add_test(mul, fail_s21_mul_31);
  tcase_add_test(mul, fail_s21_mul_32);
  tcase_add_test(mul, fail_s21_mul_33);

  TCase *div = tcase_create("s21_div");
  tcase_add_test(div, invalid_dec_s21_div_1);
  tcase_add_test(div, invalid_dec_s21_div_2);
  tcase_add_test(div, invalid_dec_s21_div_3);
  tcase_add_test(div, invalid_dec_s21_div_4);
  tcase_add_test(div, invalid_dec_s21_div_5);
  tcase_add_test(div, invalid_dec_s21_div_6);
  tcase_add_test(div, invalid_dec_s21_div_7);
  tcase_add_test(div, invalid_dec_s21_div_8);
  tcase_add_test(div, invalid_dec_s21_div_9);
  tcase_add_test(div, invalid_dec_s21_div_10);
  tcase_add_test(div, invalid_dec_s21_div_11);
  tcase_add_test(div, invalid_dec_s21_div_12);
  tcase_add_test(div, invalid_dec_s21_div_13);
  tcase_add_test(div, invalid_dec_s21_div_14);
  tcase_add_test(div, invalid_dec_s21_div_15);
  tcase_add_test(div, invalid_dec_s21_div_16);
  tcase_add_test(div, s21_div_1);
  tcase_add_test(div, s21_div_2);
  tcase_add_test(div, s21_div_3);
  tcase_add_test(div, s21_div_4);
  tcase_add_test(div, s21_div_5);
  tcase_add_test(div, s21_div_6);
  tcase_add_test(div, s21_div_7);
  tcase_add_test(div, s21_div_8);
  tcase_add_test(div, s21_div_9);
  tcase_add_test(div, s21_div_10);
  tcase_add_test(div, s21_div_11);
  tcase_add_test(div, s21_div_12);
  tcase_add_test(div, s21_div_13);
  tcase_add_test(div, s21_div_14);
  // tcase_add_test(div, s21_div_15);
  tcase_add_test(div, s21_div_16);
  tcase_add_test(div, s21_div_17);
  tcase_add_test(div, s21_div_18);
  tcase_add_test(div, s21_div_19);
  tcase_add_test(div, s21_div_20);
  tcase_add_test(div, s21_div_21);
  tcase_add_test(div, s21_div_22);
  tcase_add_test(div, s21_div_23);
  tcase_add_test(div, s21_div_24);
  tcase_add_test(div, s21_div_25);
  tcase_add_test(div, s21_div_26);
  tcase_add_test(div, s21_div_27);
  tcase_add_test(div, s21_div_28);
  tcase_add_test(div, s21_div_29);
  tcase_add_test(div, s21_div_30);
  tcase_add_test(div, s21_div_31);
  tcase_add_test(div, s21_div_32);
  tcase_add_test(div, s21_div_33);
  tcase_add_test(div, s21_div_34);
  tcase_add_test(div, s21_div_35);
  tcase_add_test(div, s21_div_36);
  tcase_add_test(div, s21_div_37);
  tcase_add_test(div, s21_div_38);
  tcase_add_test(div, s21_div_39);
  tcase_add_test(div, s21_div_40);
  tcase_add_test(div, s21_div_41);
  tcase_add_test(div, s21_div_42);
  tcase_add_test(div, s21_div_43);
  tcase_add_test(div, s21_div_44);
  tcase_add_test(div, s21_div_45);
  tcase_add_test(div, s21_div_46);
  tcase_add_test(div, s21_div_47);
  tcase_add_test(div, s21_div_48);
  tcase_add_test(div, s21_div_49);
  tcase_add_test(div, s21_div_50);
  tcase_add_test(div, s21_div_51);
  tcase_add_test(div, s21_div_52);
  tcase_add_test(div, s21_div_53);
  tcase_add_test(div, s21_div_54);
  // tcase_add_test(div, s21_div_55);
  tcase_add_test(div, s21_div_56);
  tcase_add_test(div, s21_div_57);
  tcase_add_test(div, s21_div_58);
  tcase_add_test(div, s21_div_59);
  tcase_add_test(div, s21_div_60);
  tcase_add_test(div, s21_div_61);
  tcase_add_test(div, s21_div_62);
  tcase_add_test(div, s21_div_63);
  tcase_add_test(div, s21_div_64);
  tcase_add_test(div, s21_div_65);
  tcase_add_test(div, s21_div_66);
  tcase_add_test(div, s21_div_67);
  tcase_add_test(div, s21_div_68);
  tcase_add_test(div, s21_div_69);
  tcase_add_test(div, s21_div_70);
  tcase_add_test(div, s21_div_71);
  tcase_add_test(div, s21_div_72);
  tcase_add_test(div, s21_div_73);
  tcase_add_test(div, s21_div_74);
  tcase_add_test(div, s21_div_75);
  tcase_add_test(div, s21_div_76);
  tcase_add_test(div, s21_div_77);
  tcase_add_test(div, s21_div_78);
  tcase_add_test(div, s21_div_79);
  tcase_add_test(div, s21_div_80);
  tcase_add_test(div, s21_div_81);
  tcase_add_test(div, s21_div_82);
  tcase_add_test(div, s21_div_83);
  tcase_add_test(div, s21_div_84);
  tcase_add_test(div, s21_div_85);
  tcase_add_test(div, s21_div_86);
  tcase_add_test(div, s21_div_87);
  tcase_add_test(div, s21_div_88);
  tcase_add_test(div, s21_div_89);
  tcase_add_test(div, s21_div_90);
  tcase_add_test(div, s21_div_91);
  tcase_add_test(div, s21_div_92);
  tcase_add_test(div, s21_div_93);
  tcase_add_test(div, s21_div_94);
  tcase_add_test(div, s21_div_95);
  tcase_add_test(div, s21_div_96);
  tcase_add_test(div, s21_div_97);
  tcase_add_test(div, s21_div_98);
  tcase_add_test(div, s21_div_99);
  tcase_add_test(div, s21_div_100);
  // tcase_add_test(div, fail_s21_div_1);
  // tcase_add_test(div, fail_s21_div_2);
  // tcase_add_test(div, fail_s21_div_3);
  // tcase_add_test(div, fail_s21_div_4);
  // tcase_add_test(div, fail_s21_div_5);
  // tcase_add_test(div, fail_s21_div_6);
  // tcase_add_test(div, fail_s21_div_7);
  // tcase_add_test(div, fail_s21_div_8);
  // tcase_add_test(div, fail_s21_div_9);
  // tcase_add_test(div, fail_s21_div_10);
  // tcase_add_test(div, fail_s21_div_11);
  // tcase_add_test(div, fail_s21_div_12);
  // tcase_add_test(div, fail_s21_div_13);
  // tcase_add_test(div, fail_s21_div_14);
  // tcase_add_test(div, fail_s21_div_15);
  // tcase_add_test(div, fail_s21_div_16);
  // tcase_add_test(div, fail_s21_div_17);
  // tcase_add_test(div, fail_s21_div_18);
  // tcase_add_test(div, fail_s21_div_19);
  // tcase_add_test(div, fail_s21_div_20);
  // tcase_add_test(div, fail_s21_div_21);
  // tcase_add_test(div, fail_s21_div_22);
  // tcase_add_test(div, fail_s21_div_23);
  // tcase_add_test(div, fail_s21_div_24);
  // tcase_add_test(div, fail_s21_div_25);
  // tcase_add_test(div, fail_s21_div_26);
  // tcase_add_test(div, fail_s21_div_27);
  // tcase_add_test(div, fail_s21_div_28);
  // tcase_add_test(div, fail_s21_div_29);
  // tcase_add_test(div, fail_s21_div_30);
  // tcase_add_test(div, fail_s21_div_31);
  // tcase_add_test(div, fail_s21_div_32);
  // tcase_add_test(div, fail_s21_div_33);

  suite_add_tcase(c, add);
  suite_add_tcase(c, sub);
  suite_add_tcase(c, mul);
  suite_add_tcase(c, div);
  return c;
}
