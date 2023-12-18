/*!
 * @file par_empty.h
 * @brief ������ �������� ���������
 * @author ���� �������
 * @copyright �� ��� "�����������������", ���-1
 * @details
 * #### ����� ����
 *    ���
 * #### �����������
 *    ���
 */
#pragma once
#ifdef __cplusplus
#include "par_t.h"

 //! ������ �������� ��������� (������������ ������ � ������ ����������)
class par_empty_t : public par_t {
public:
    /*!
     * ������ �������� ��������� (������������ ������ � ������ ����������, ����������)
     */
    virtual ~par_empty_t() = default;

    /*!
     * ���������� ������ �������
     * @return ������ �������
     */
    virtual unsigned char get_height() const = 0;
};

/*!
 * ������� ������ �������� ��������� (������������ ������ � ������ ����������)
 * @param list_id ������������� ������ ���������� (0 - �������� �� ����������� ������)
 * @param height ������ �������
 */
extern "C" LIBIMIT_API par_empty_t * __stdcall create_par_empty(const unsigned char list_id, const unsigned char height = 26);

/*!
 * ���������� ������ �������� ���������
 * @par par ������������ ��������
 */
extern "C" LIBIMIT_API void __stdcall destroy_par_empty(par_empty_t * par);

#endif
