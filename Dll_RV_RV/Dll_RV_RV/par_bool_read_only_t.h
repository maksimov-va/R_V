/*!
 * @file par_bool_read_only.h
 * @brief ������� �������� ��������� (������ ��� ������)
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
#define DEBUG
 //! ������� �������� ��������� (������ ��� ������)
class par_bool_read_only_t : public par_t {
public:
    /*!
     * ������� �������� ��������� (������ ��� ������, ����������)
     */
    virtual ~par_bool_read_only_t() = default;

    /*!
     * ���������� ��������
     * @return ��������
     */
    virtual bool get_value() const = 0;

    /*!
     * ������������� ��������
     * @param value ��������
     */
    virtual void set_value(const bool value) = 0;

    /*!
     * ���������� �������� �� ���������
     * @return �������� �� ���������
     */
    virtual bool get_default_value() const = 0;

#ifdef DEBUG
protected:
    bool* debug_value;          //!< �������� (��� �������)
    bool* debug_valid;          //!< ������������� (��� �������)
    par_status_t* debug_status; //!< ��������� (��� �������)
#endif
};

/*!
 * ������� ������� �������� ��������� (������ ��� ������)
 * @param list_id ������������� ������ ���������� (0 - �������� �� ����������� ������)
 * @param text_id ��������� ������������� ���������
 * @param name ��������
 * @param default_value �������� �� ���������
 */
extern "C" LIBIMIT_API par_bool_read_only_t * __stdcall create_par_bool_read_only(const unsigned char list_id, const char* text_id, const char* name, const bool default_value = false);

/*!
 * ���������� ������� �������� ��������� (������ ��� ������)
 * @par par ������������ ��������
 */
extern "C" LIBIMIT_API void __stdcall destroy_par_bool_read_only(par_bool_read_only_t * par);

#endif
