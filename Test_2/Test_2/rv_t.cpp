/*!
 * @file rv.cpp
 * @brief ����� �� (���������������)
 * @copyright �� ��� "�����������������", ���-1
 * @details
 * #### ����-������������
 *    rv.h
 * #### ����� ����
 *    ���
 * #### �����������
 *    ���
 */
#include "rv_t.h"

 //! ��
rv_t rv;

//! ������ �������� ���� ������ (�����������������)
const unsigned char rv_t::out_words_addresses[out_words_count] = { 0340 };

//! ������������ ������� ��������� ��������� "�������� ��"
static par_change_handler_t out_test_change_handler;

/*!
 * ����� �� (���������������, �����������)
 */
rv_t::rv_t() :
    out_words{},
    out_altitude_test_value(15) {
    out_test->add_change_handler(out_test_change_handler);
}

/*!
 * ����� �� (���������������, ����������)
 */
rv_t::~rv_t() {
}

/*!
 * ��������� ����������
 */
void rv_t::unpack() {
}

/*!
 * ��������� ������ �������� �������
 */
void rv_t::update() {
    // ������ ������� � �������� ������ ���������� (���� ������ �������� �� �������� �������)
    name->set_list_status(on->get_value() ? PAR_LIST_STATUS_VALID : PAR_LIST_STATUS_INVALID);

    // ����-�������� (����������)
    if (out_test->get_value()) {
        out_altitude->set_status(PAR_STATUS_TEST);
        out_altitude->set_value(out_altitude_test_value);
    }

    // ����������� �������� ������ ��
    if (!on->get_value())
        out_mode->set_value(OUT_MODE_OFF);
    else if (out_test->get_value())
        out_mode->set_value(OUT_MODE_TEST);
    else if (out_altitude->get_valid())
        out_mode->set_value(OUT_MODE_NORMAL);
    else
        out_mode->set_value(OUT_MODE_NO_DATA);
}

/*!
 * ��������� ��������
 */
void rv_t::pack() {
    unsigned int* w = out_words;

    // �� 340 �����������
    *w++ =
        (out_altitude->get_status() == PAR_STATUS_TEST ? 01 : out_altitude->get_valid() ? 00 : 10);
    //    pack_u(out_altitude->get_value(), 8192., 26, 12);

    // �������� ���������� ���������� ����
   // assert(w - out_words == out_words_count);

    // ������ ������� ���� � 32-�� �������
    //md_set_addresses(out_words, out_words_addresses, out_words_count, 1);
}

/*!
 * ������������ ������� ��������� ��������� "�������� ��"
 * @param par ��������-�������� �������
 * @param change_flags �������� �������
 */
static void out_test_change_handler(par_t* par, const par_change_flags_t change_flags) {
    (void)par;
    if ((change_flags & PAR_VALUE_CHANGED) != 0) {
        // ���������� � �������������� ��������, ������������� �� ����-��������
        if (rv.out_test->get_value()) {
            rv.out_altitude->save();
        }
        else {
            rv.out_altitude->load();
        }
    }
}
