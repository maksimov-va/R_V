/*!
 * @file par_title.h
 * @brief ��������� ��� ������ ���������� ���������
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

 //! ��������� ��� ������ ���������� ���������
class par_title_t : public par_t {
public:
    /*!
     * ��������� ��� ������ ���������� ��������� (����������)
     */
    virtual ~par_title_t() = default;
};

/*!
 * ������� ��������� ��� ������ ���������� ���������
 * @param list_id ������������� ������ ���������� (0 - �������� �� ����������� ������)
 * @param name ����� ����������
 */
extern "C" LIBIMIT_API par_title_t * __stdcall create_par_title(const unsigned char list_id, const char* name);

/*!
 * ���������� ��������� ��� ������ ���������� ���������
 * @par par ������������ ���������
 */
extern "C" LIBIMIT_API void __stdcall destroy_par_title(par_title_t * par);

#endif
